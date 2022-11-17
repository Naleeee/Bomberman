/*
** EPITECH PROJECT, 2022
** src
** File description:
** SettingsManager
*/

#include "SettingsManager.hpp"

#include "AudioPlayer.hpp"
#include "FilePaths.hpp"
#include "IndieError.hpp"
#include "MapLoader/MapReader.hpp"
#include "nlohmann/json.hpp"
#include "raylib.h"

#include <fstream>

std::unique_ptr<indie::SettingsManager> indie::SettingsManager::instance = nullptr;

indie::SettingsManager::SettingsManager(ecs::Coordinator& coordinator) :
    coordinator(coordinator)
{
    if (indie::MapReader::doesExist(SETTINGS_PATH)) {
        std::ifstream reader(SETTINGS_PATH.data());
        nlohmann::json json;
        reader >> json;
        if (json.contains("FPS")) {
            this->fps = json.at("FPS").get<int>();
        }
        if (json.contains("Screen")) {
            this->monitor = json.at("Screen").get<int>();
        }
        if (json.contains("Audio")) {
            this->audio = json.at("Audio").get<bool>();
        }
        if (json.contains("FullScreen")) {
            this->fullscreen = json.at("FullScreen").get<bool>();
        }
    }

    this->applyFps();
    this->applyAudio();
    this->applyFullscreen();
    this->applyMonitor();
}

indie::SettingsManager::~SettingsManager() noexcept
{
    std::ofstream writer(SETTINGS_PATH.data());
    nlohmann::json json = {
        {"FPS", this->fps},
        {"Screen", this->monitor},
        {"Audio", this->audio},
        {"FullScreen", this->fullscreen}};
    writer << std::setw(4) << json << std::endl;
}

void indie::SettingsManager::init(ecs::Coordinator& coordinator) noexcept
{
    instance.reset(new SettingsManager(coordinator));
}

int indie::SettingsManager::getFps() noexcept
{
    if (instance == nullptr) {
        return 60;
    }
    return instance->fps;
}

int indie::SettingsManager::getMonitor() noexcept
{
    if (instance == nullptr) {
        return 0;
    }
    return instance->monitor;
}

bool indie::SettingsManager::getAudioState() noexcept
{
    if (instance == nullptr) {
        return true;
    }
    return instance->audio;
}

bool indie::SettingsManager::getFullscreenState() noexcept
{
    if (instance == nullptr) {
        return true;
    }
    return instance->fullscreen;
}

void indie::SettingsManager::setFps(int fps) noexcept
{
    if (instance != nullptr and fps > 0) {
        instance->fps = fps;
        instance->applyFps();
    }
}

void indie::SettingsManager::setMonitor(int monitorId) noexcept
{
    if (instance != nullptr and monitorId < GetMonitorCount()) {
        instance->monitor = monitorId;
        instance->applyMonitor();
    }
}

void indie::SettingsManager::setAudioState(bool state) noexcept
{
    if (instance != nullptr) {
        instance->audio = state;
        instance->applyAudio();
    }
}

void indie::SettingsManager::setFullscreenState(bool state) noexcept
{
    if (instance != nullptr) {
        instance->fullscreen = state;
        instance->applyFullscreen();
    }
}

void indie::SettingsManager::applyFps() const noexcept
{
    SetTargetFPS(this->fps);
}

void indie::SettingsManager::applyMonitor() const noexcept
{
    SetWindowMonitor(this->monitor);
}

void indie::SettingsManager::applyAudio() const noexcept
{
    this->coordinator.sendEvent((this->audio ? ecs::Events::AUDIO_ON : ecs::Events::AUDIO_OFF));
}

void indie::SettingsManager::applyFullscreen() const noexcept
{
    this->coordinator.sendEvent((this->fullscreen ? ecs::Events::FULLSCREEN_ON : ecs::Events::FULLSCREEN_OFF));
}

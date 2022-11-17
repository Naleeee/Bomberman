/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu
*/

#include "Scenes/MainMenuScene.hpp"

#include "AudioPlayer.hpp"
#include "FilePaths.hpp"
#include "PlayersManager.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/MapSelectionScene.hpp"
#include "Scenes/PlayerScene.hpp"
#include "Scenes/SettingsScene.hpp"
#include "Scenes/TutoScene.hpp"

graphic::MainMenuScene::MainMenuScene(game::Room& room, ecs::Coordinator& coordinator) :
    coordinator(coordinator), title(this->coordinator.createEntity()), lSolo(this->coordinator.createEntity()), lMulti(this->coordinator.createEntity()), settings(this->coordinator.createEntity()), h2p(this->coordinator.createEntity()), theme(this->coordinator.createEntity()), focus(0), maxFields(0)
{
    room.playMusic();

    coordinator.setComponent(this->title, ecs::component::Attributes{.position = {200, 0, 0}, .scale = 0.6});
    coordinator.setComponent(this->title, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/BomberTek.png", ASSETS_PATH)));

    coordinator.setComponent(this->lSolo, ecs::component::Attributes{.position = {200, 340, 0}});
    coordinator.setComponent(this->lSolo, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/LocalSolo.png", ASSETS_PATH)));
    this->maxFields += 1;

    coordinator.setComponent(this->lMulti, ecs::component::Attributes{.position = {175, 510, 0}});
    coordinator.setComponent(this->lMulti, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/LMultiUnselect.png", ASSETS_PATH)));
    this->maxFields += 1;

    // coordinator.setComponent(this->oMulti, ecs::component::Attributes{.position = {140, 680, 0}});
    // coordinator.setComponent(this->oMulti, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/OnlineMulti.png", ASSETS_PATH)));
    // this->maxFields += 1;

    coordinator.setComponent(this->settings, ecs::component::Attributes{.position = {1600, 20, 0}, .scale = 0.5});
    coordinator.setComponent(this->settings, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/Settings.png", ASSETS_PATH)));
    this->maxFields += 1;

    coordinator.setComponent(this->h2p, ecs::component::Attributes{.position = {350, 680, 0}});
    coordinator.setComponent(this->h2p, ecs::component::RenderableImage2d(fmt::format("{}Textures/Menu/TutoUnselect.png", ASSETS_PATH)));
    this->maxFields += 1;

    coordinator.setComponent(this->theme, ecs::component::MusicObject(fmt::format("{}audio/Musics/MainTheme.mp3", ASSETS_PATH)));
    // this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).play();
}

graphic::MainMenuScene::~MainMenuScene() noexcept
{
    coordinator.destroyEntity(this->title);
    coordinator.destroyEntity(this->lSolo);
    coordinator.destroyEntity(this->lMulti);
    // coordinator.destroyEntity(this->oMulti);
    coordinator.destroyEntity(this->settings);
    coordinator.destroyEntity(this->h2p);
    coordinator.destroyEntity(this->theme);
}

void graphic::MainMenuScene::update(graphic::ScenesManager& scenesManager, float /*dt*/)
{
    if (IsKeyPressed(KEY_ENTER)) {
        audio::AudioPlayer::playSound(fmt::format("{}audio/Sounds/Select.mp3", ASSETS_PATH));
        switch (this->focus) {
        case 0:
            this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).pause();
            indie::PlayersManager::setPlayerType(1, indie::PlayerType::KEYBOARD);
            indie::PlayersManager::setPlayerKeys(1, {.moveUp = KEY_W, .moveDown = KEY_S, .moveLeft = KEY_A, .moveRight = KEY_D, .putBomb = KEY_SPACE});
            indie::PlayersManager::setPlayerType(2, indie::PlayerType::AI);
            indie::PlayersManager::setPlayerType(3, indie::PlayerType::AI);
            indie::PlayersManager::setPlayerType(4, indie::PlayerType::AI);
            scenesManager.setScene<graphic::MapSelectionScene>(this->coordinator, 0);
            break;
        case 1:
            this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).pause();
            indie::PlayersManager::setPlayerType(1, indie::PlayerType::KEYBOARD);
            indie::PlayersManager::setPlayerKeys(1, {.moveUp = KEY_W, .moveDown = KEY_S, .moveLeft = KEY_A, .moveRight = KEY_D, .putBomb = KEY_SPACE});
            indie::PlayersManager::setPlayerType(2, indie::PlayerType::KEYBOARD);
            indie::PlayersManager::setPlayerKeys(2, {.moveUp = KEY_UP, .moveDown = KEY_DOWN, .moveLeft = KEY_LEFT, .moveRight = KEY_RIGHT, .putBomb = KEY_ENTER});
            indie::PlayersManager::setPlayerType(3, indie::PlayerType::AI);
            indie::PlayersManager::setPlayerType(4, indie::PlayerType::AI);
            scenesManager.setScene<graphic::MapSelectionScene>(this->coordinator, 1);
            break;
            // ici multi
        // case 2:
        // this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).pause();
        // scenesManager.setScene<graphic::PlayerScene>(this->coordinator);
        // break;
        case 2:
            this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).pause();
            scenesManager.setScene<graphic::TutoScene>(this->coordinator);
            break;
        case 3:
            this->coordinator.getComponent<ecs::component::MusicObject>(this->theme).pause();
            scenesManager.setScene<graphic::SettingsScene>(this->coordinator);
            break;
        }
    } else if (IsKeyPressed(KEY_UP)) {
        audio::AudioPlayer::playSound(fmt::format("{}audio/Sounds/MenuMove.mp3", ASSETS_PATH));
        switch (this->focus) {
        case 0:
            this->focus = maxFields - 1;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lSolo).setTexture(fmt::format("{}Textures/Menu/LSoloUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::Attributes>(this->settings).scale = 0.6;
            break;
        case 1:
            this->focus--;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lMulti).setTexture(fmt::format("{}Textures/Menu/LMultiUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lSolo).setTexture(fmt::format("{}Textures/Menu/LocalSolo.png", ASSETS_PATH));
            break;
        // case 2:
        // this->focus--;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->oMulti).scale = 1;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->lMulti).scale = 1.1;
        // break;
        // case 3:
        // this->focus--;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->h2p).scale = 1;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->oMulti).scale = 1.1;
        // break;
        case 2:
            this->focus--;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->h2p).setTexture(fmt::format("{}Textures/Menu/TutoUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lMulti).setTexture(fmt::format("{}Textures/Menu/LocalMulti.png", ASSETS_PATH));
            break;
        case 3:
            this->focus--;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->h2p).setTexture(fmt::format("{}Textures/Menu/Tuto.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::Attributes>(this->settings).scale = 0.5;
            break;
        }
    } else if (IsKeyPressed(KEY_DOWN)) {
        audio::AudioPlayer::playSound(fmt::format("{}audio/Sounds/MenuMove.mp3", ASSETS_PATH));
        switch (this->focus) {
        case 0:
            this->focus++;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lSolo).setTexture(fmt::format("{}Textures/Menu/LSoloUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lMulti).setTexture(fmt::format("{}Textures/Menu/LocalMulti.png", ASSETS_PATH));
            break;
        // case 1:
        // this->focus++;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->lMulti).scale = 1;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->oMulti).scale = 1.1;
        // break;
        // case 2:
        // this->focus++;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->oMulti).scale = 1;
        // this->coordinator.getComponent<ecs::component::Attributes>(this->h2p).scale = 1.1;
        // break;
        case 1:
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lMulti).setTexture(fmt::format("{}Textures/Menu/LMultiUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->h2p).setTexture(fmt::format("{}Textures/Menu/Tuto.png", ASSETS_PATH));
            this->focus++;
            break;
        case 2:
            this->focus++;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->h2p).setTexture(fmt::format("{}Textures/Menu/TutoUnselect.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::Attributes>(this->settings).scale = 0.6;
            break;
        case 3:
            this->focus = 0;
            this->coordinator.getComponent<ecs::component::RenderableImage2d>(this->lSolo).setTexture(fmt::format("{}Textures/Menu/LocalSolo.png", ASSETS_PATH));
            this->coordinator.getComponent<ecs::component::Attributes>(this->settings).scale = 0.5;
            break;
        }
    }
}

indie::Vector graphic::MainMenuScene::getCameraPosition() const noexcept
{
    return indie::Vector{5, 80, 20};
}

indie::Vector graphic::MainMenuScene::getCameraLooking() const noexcept
{
    return indie::Vector{6, 80, -100};
}

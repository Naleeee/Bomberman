/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu Scene
*/

#pragma once

#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/Music.hpp"
#include "ECS/Components/RenderableImage2d.hpp"
#include "ECS/Core/Coordinator.hpp"
#include "ECS/Core/Entities.hpp"
#include "MapLoader/MapReader.hpp"
#include "Scenes/IScene.hpp"
#include "Scenes/ScenesManager.hpp"
#include "Vector.hpp"
#include "raylib.h"

namespace graphic {

class PlayerSelectionScene final : public IScene {
   public:
    PlayerSelectionScene() noexcept = delete;
    PlayerSelectionScene(game::Room& room, ecs::Coordinator& coordinator, std::string_view path);
    PlayerSelectionScene(PlayerSelectionScene const& other) noexcept = delete;
    PlayerSelectionScene(PlayerSelectionScene&& other) noexcept = delete;
    ~PlayerSelectionScene() noexcept override;

    PlayerSelectionScene& operator=(PlayerSelectionScene const& other) noexcept = delete;
    PlayerSelectionScene& operator=(PlayerSelectionScene&& other) noexcept = delete;

    void update(ScenesManager& scenesManager, float dt) final;
    indie::Vector getCameraPosition() const noexcept final;
    indie::Vector getCameraLooking() const noexcept final;

   private:
    ecs::Coordinator& coordinator;
    ecs::Entity title{};
    ecs::Entity bomberman{};
    ecs::Entity left{};
    ecs::Entity right{};
    ecs::Entity choose{};
    indie::MapReader mapReader;
    std::vector<std::string> textures;
    int selectedTexture = 0;
};
} // namespace graphic

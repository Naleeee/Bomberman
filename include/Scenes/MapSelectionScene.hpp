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
#include "Scenes/IScene.hpp"
#include "Scenes/ScenesManager.hpp"
#include "Vector.hpp"
#include "raylib.h"

#include <filesystem>
#include <vector>

namespace graphic {

class MapSelectionScene final : public IScene {
   public:
    MapSelectionScene() noexcept = delete;
    explicit MapSelectionScene(ecs::Coordinator& coordinator, int type);
    MapSelectionScene(MapSelectionScene const& other) noexcept = delete;
    MapSelectionScene(MapSelectionScene&& other) noexcept = delete;
    ~MapSelectionScene() noexcept override;

    MapSelectionScene& operator=(MapSelectionScene const& other) noexcept = delete;
    MapSelectionScene& operator=(MapSelectionScene&& other) noexcept = delete;

    void update(ScenesManager& scenesManager, float dt) final;
    indie::Vector getCameraPosition() const noexcept final;
    indie::Vector getCameraLooking() const noexcept final;

   private:
    ecs::Coordinator& coordinator;
    ecs::Entity title{};
    std::vector<std::string> paths;
    ecs::Entity current;
    ecs::Entity map;
    int type = 0;
    int focus = 1;
};
} // namespace graphic

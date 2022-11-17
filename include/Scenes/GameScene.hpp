/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Game Scene
*/

#pragma once

#include "ECS/Components/Animation.hpp"
#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/Music.hpp"
#include "ECS/Components/Transform.hpp"
#include "ECS/Core/Coordinator.hpp"
#include "ECS/Core/Entities.hpp"
#include "HUD.hpp"
#include "MapLoader/Map.hpp"
#include "Scenes/IScene.hpp"
#include "Scenes/ScenesManager.hpp"
#include "Vector.hpp"
#include "raylib.h"

namespace graphic {

class GameScene : public IScene {
   public:
    GameScene() noexcept = delete;
    GameScene(game::Room& room, ecs::system::CollisionSystem& collisionSystem, ecs::Coordinator& coordinator, indie::MapReader mapReader);
    GameScene(GameScene const& other) noexcept = delete;
    GameScene(GameScene&& other) noexcept = delete;
    ~GameScene() noexcept override = default;

    GameScene& operator=(GameScene const& other) noexcept = delete;
    GameScene& operator=(GameScene&& other) noexcept = delete;

    void update(ScenesManager& scenesManager, float dt) final;
    indie::Vector getCameraPosition() const noexcept final;
    indie::Vector getCameraLooking() const noexcept final;

   private:
    ecs::Coordinator& coordinator;
    ecs::Entity theme{};
    bool gameEnded = false;
    indie::Map map;
    indie::Vector mapPosition;
    game::HUD hud;
};

} // namespace graphic

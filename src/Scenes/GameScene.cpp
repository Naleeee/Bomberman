/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu
*/

#include "Scenes/GameScene.hpp"

#include "ECS/Components/Bounds3d.hpp"
#include "ECS/Systems/CollisionSystem.hpp"
#include "MapLoader/MapLoader.hpp"
#include "Scenes/EndScene.hpp"

// NOLINTNEXTLINE
graphic::GameScene::GameScene(game::Room& room, ecs::system::CollisionSystem& collisionSystem, ecs::Coordinator& coordinator, indie::MapReader mapReader) :
    coordinator(coordinator), map(indie::MapLoader::loadMap(coordinator, collisionSystem, mapReader, room.getMapPosition())), mapPosition(room.getMapPosition()), hud(coordinator) { }

void graphic::GameScene::update(graphic::ScenesManager& scenesManager, float /*dt*/)
{
    if (this->map.isEnded()) {
        if (not this->gameEnded) {
            scenesManager.setScene<graphic::EndScene, true>(this->coordinator, std::move(this->map.extractPlayers()));
            this->gameEnded = true;
        }
    } else {
        this->map.update();

        this->hud.update(this->map.getPlayersStats());
    }
}

indie::Vector graphic::GameScene::getCameraPosition() const noexcept
{
    return (this->mapPosition + indie::Vector{-22, 43, 0});
}

indie::Vector graphic::GameScene::getCameraLooking() const noexcept
{
    return this->mapPosition;
}

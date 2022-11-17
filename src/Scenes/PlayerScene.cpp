/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu
*/

#include "Scenes/PlayerScene.hpp"

#include "FilePaths.hpp"
#include "Scenes/GameScene.hpp"

graphic::PlayerScene::PlayerScene(ecs::Coordinator& coordinator) :
    coordinator(coordinator), waiting(this->coordinator.createEntity())
{
    coordinator.setComponent(this->waiting, ecs::component::Attributes{.position = {700, 50, 0}});
    coordinator.setComponent(this->waiting, ecs::component::RenderableImage2d(fmt::format("{}Textures/Waiting/Waiting.png", ASSETS_PATH)));
}

graphic::PlayerScene::~PlayerScene() noexcept
{
    coordinator.destroyEntity(this->waiting);
}

void graphic::PlayerScene::update(graphic::ScenesManager& scenesManager, float /*dt*/)
{
    if (IsKeyPressed(KEY_ENTER)) {
        // scenesManager.setScene<graphic::GameScene, true, true, true>(this->coordinator, "playerscenePath");
    }
}

indie::Vector graphic::PlayerScene::getCameraPosition() const noexcept
{
    return indie::Vector{40, 28, 80};
}

indie::Vector graphic::PlayerScene::getCameraLooking() const noexcept
{
    return indie::Vector{60, 10, 60};
}

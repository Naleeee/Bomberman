/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu
*/

#include "Scenes/TutoScene.hpp"

#include "ECS/Components/RenderableText2d.hpp"
#include "FilePaths.hpp"
#include "Scenes/MainMenuScene.hpp"

graphic::TutoScene::TutoScene(ecs::Coordinator& coordinator) :
    coordinator(coordinator), returnButton(this->coordinator.createEntity()), tuto(this->coordinator.createEntity())
{
    coordinator.setComponent(this->returnButton, ecs::component::Attributes{.position = {0, 0, 0}});
    coordinator.setComponent(this->returnButton, ecs::component::RenderableImage2d(fmt::format("{}Textures/Tuto/Return.png", ASSETS_PATH)));

    coordinator.setComponent(this->tuto, ecs::component::Attributes{.position = {390, 0, 0}, .scale = 0.6});
    coordinator.setComponent(this->tuto, ecs::component::RenderableImage2d(fmt::format("{}Textures/Tuto/Tuto.png", ASSETS_PATH)));
}

graphic::TutoScene::~TutoScene() noexcept
{
    coordinator.destroyEntity(this->returnButton);
    coordinator.destroyEntity(this->tuto);
}

void graphic::TutoScene::update(graphic::ScenesManager& scenesManager, float /*dt*/)
{
    if (IsKeyPressed(KEY_ENTER)) {
        scenesManager.setScene<graphic::MainMenuScene, true>(this->coordinator);
    }
}

indie::Vector graphic::TutoScene::getCameraPosition() const noexcept
{
    return indie::Vector{-70, 50, -20};
}

indie::Vector graphic::TutoScene::getCameraLooking() const noexcept
{
    return indie::Vector{-71, 50, -120};
}

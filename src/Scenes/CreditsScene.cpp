/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Main Menu
*/

#include "Scenes/CreditsScene.hpp"

#include "ECS/Components/Transform.hpp"
#include "FilePaths.hpp"
#include "Scenes/IntroScene.hpp"

graphic::CreditsScene::CreditsScene(ecs::Coordinator& coordinator) :
    coordinator(coordinator), background(this->coordinator.createEntity()), credits(this->coordinator.createEntity())
{
    coordinator.setComponent(this->background, ecs::component::Attributes{.position = {0, 0, 0}, .scale = 1});
    coordinator.setComponent(this->background, ecs::component::RenderableImage2d(fmt::format("{}Textures/Credits/Background.png", ASSETS_PATH)));

    coordinator.setComponent(this->credits, ecs::component::Attributes{.position = {0, 1080, 0}});
    coordinator.setComponent(this->credits, ecs::component::Transform{.movement = {0, -200, 0}});
    coordinator.setComponent(this->credits, ecs::component::RenderableImage2d(fmt::format("{}Textures/Credits/Credits.png", ASSETS_PATH)));
}

graphic::CreditsScene::~CreditsScene() noexcept
{
    coordinator.destroyEntity(this->background);
    coordinator.destroyEntity(this->credits);
}

void graphic::CreditsScene::update(graphic::ScenesManager& scenesManager, float /*dt*/)
{
    if (IsKeyPressed(KEY_SPACE) or (this->coordinator.getComponent<ecs::component::Attributes>(this->credits).position.y < -3500 and not this->end)) {
        this->end = true;
        scenesManager.setScene<graphic::IntroScene>(this->coordinator);
    }
}

indie::Vector graphic::CreditsScene::getCameraPosition() const noexcept
{
    return indie::Vector{0, 100, 0};
}

indie::Vector graphic::CreditsScene::getCameraLooking() const noexcept
{
    return indie::Vector{0, 50, -10};
}

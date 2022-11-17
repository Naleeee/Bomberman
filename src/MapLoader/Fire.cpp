/*
** EPITECH PROJECT, 2022
** src
** File description:
** Fire
*/

#include "MapLoader/Fire.hpp"

#include "ECS/Components/Animation.hpp"
#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/RenderableObject3d.hpp"

indie::Fire::Fire(ecs::Coordinator& coordinator, const ModelInfos& modelInfos, const Vector& position) :
    coordinator(coordinator), entity(coordinator.createEntity())
{
    this->coordinator.setComponent(this->entity, ecs::component::Attributes{.position = position});
    this->coordinator.setComponent(this->entity, std::move(ecs::component::RenderableObject3d(modelInfos.modelPath, modelInfos.texturePath)));
    this->coordinator.setComponent(this->entity, std::move(ecs::component::Animation(modelInfos.animationPath, 1, modelInfos.animationFps)));
    this->coordinator.getComponent<ecs::component::Animation>(this->entity).addAnimation(1);
}

indie::Fire::Fire(Fire&& other) noexcept :
    coordinator(other.coordinator), entity(other.entity), valid(other.valid)
{
    other.valid = false;
}

indie::Fire::~Fire()
{
    if (this->valid) {
        this->coordinator.destroyEntity(this->entity);
    }
}

bool indie::Fire::noMoreBurning() const noexcept
{
    return this->coordinator.getComponent<ecs::component::Animation>(this->entity).isEnded();
}

indie::Vector indie::Fire::getPosition() const noexcept
{
    return this->coordinator.getComponent<ecs::component::Attributes>(this->entity).position;
}

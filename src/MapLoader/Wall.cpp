/*
** EPITECH PROJECT, 2022
** src
** File description:
** Wall
*/

#include "MapLoader/Wall.hpp"

#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/Bounds3d.hpp"
#include "ECS/Components/RenderableObject3d.hpp"

indie::Wall::Wall(ecs::Coordinator& coordinator, ecs::system::CollisionSystem& collisionSystem, std::string_view modelPath, std::string_view texturePath, const Vector& position) :
    coordinator(coordinator), entity(coordinator.createEntity())
{
    this->coordinator.setComponent(this->entity, ecs::component::Attributes{.position = position});
    this->coordinator.setComponent(this->entity, std::move(ecs::component::RenderableObject3d(modelPath, texturePath)));
    this->coordinator.setComponent(this->entity, ecs::component::Bounds3d{});
    collisionSystem.setEntityNotMoving(this->entity);
}

indie::Wall::Wall(Wall&& other) noexcept :
    coordinator(other.coordinator), entity(other.entity), valid(other.valid)
{
    other.valid = false;
}

indie::Wall::~Wall()
{
    if (this->valid) {
        this->coordinator.destroyEntity(this->entity);
    }
}

indie::Vector indie::Wall::getPosition() const noexcept
{
    return this->coordinator.getComponent<ecs::component::Attributes>(this->entity).position;
}

/*
** EPITECH PROJECT, 2022
** src
** File description:
** Ground
*/

#include "MapLoader/Ground.hpp"

#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/RenderableObject3d.hpp"

indie::Ground::Ground(ecs::Coordinator& coordinator, std::string_view modelPath, std::string_view texturePath, const Vector& position) :
    coordinator(coordinator), entity(coordinator.createEntity())
{
    this->coordinator.setComponent(this->entity, ecs::component::Attributes{.position = position});
    this->coordinator.setComponent(this->entity, std::move(ecs::component::RenderableObject3d(modelPath, texturePath)));
}

indie::Ground::Ground(Ground&& other) noexcept :
    coordinator(other.coordinator), entity(other.entity), valid(other.valid)
{
    other.valid = false;
}

indie::Ground::~Ground()
{
    if (this->valid) {
        this->coordinator.destroyEntity(this->entity);
    }
}

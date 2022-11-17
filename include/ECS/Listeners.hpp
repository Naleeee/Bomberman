/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** Listeners
*/

#pragma once

#include "ECS/Components/Animation.hpp"
#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/RenderableRelief3d.hpp"
#include "ECS/Components/Transform.hpp"
#include "Utils.hpp"
#include "Vector.hpp"

namespace ecs::listener {

void startWalkingAnimation(ecs::component::Animation& animation) noexcept;
void stopWalkingAnimation(ecs::component::Animation& animation) noexcept;
void startWalking(ecs::component::Attributes& attributes, ecs::component::Transform& transform, indie::Vector vec) noexcept;
void stopWalking(ecs::component::Attributes& attributes, ecs::component::Transform& transform, indie::Vector vec) noexcept;

} // namespace ecs::listener

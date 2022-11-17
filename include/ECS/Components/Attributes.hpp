/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** Attributes
*/

#pragma once

#include "Vector.hpp"

namespace ecs::component {

struct Attributes {
    indie::Vector position{0, 0, 0};

    indie::Vector rotationAxis{0, 0, 0};
    float rotationAngle = 0;

    float scale = 1;
};

} // namespace ecs::component

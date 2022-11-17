/*
** EPITECH PROJECT, 2022
** src
** File description:
** Position
*/

#include "MapLoader/Position.hpp"

#include <functional>

bool indie::Position::operator==(const Position& other) const noexcept
{
    return (this->x == other.x and this->y == other.y);
}

std::size_t indie::PositionHash::operator()(const Position& obj) const noexcept
{
    std::size_t h1 = std::hash<int>()(obj.x);
    std::size_t h2 = std::hash<int>()(obj.y);

    return (h1 ^ h2);
}

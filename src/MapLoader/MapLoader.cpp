/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** MapLoader
*/

#include "MapLoader/MapLoader.hpp"

indie::Map indie::MapLoader::loadMap(ecs::Coordinator& coordinator, ecs::system::CollisionSystem& collisionSystem, const MapReader& mapReader, const Vector& mapPosition)
{
    return {coordinator, collisionSystem, mapReader, mapPosition};
}

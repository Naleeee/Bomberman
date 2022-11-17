/*
** EPITECH PROJECT, 2022
** src
** File description:
** KeyBoardPlayer
*/

#include "MapLoader/KeyBoardPlayer.hpp"

#include "ECS/Components/Animation.hpp"
#include "ECS/Components/Attributes.hpp"
#include "ECS/Components/Transform.hpp"
#include "MapLoader/Map.hpp"
#include "raylib.h"

indie::KeyBoardPlayer::KeyBoardPlayer(ecs::Coordinator& coordinator, const PlayersInfos& playersInfos, std::string_view texturePath, const Vector& position, const PlayerId& id, const PlayerKeys& playerKeys, Map& map) noexcept :
    APlayer(coordinator, playersInfos, texturePath, position, id, PlayerType::KEYBOARD), playerKeys(playerKeys), map(map)
{
    auto& animation = coordinator.getComponent<ecs::component::Animation>(this->entity);
    auto& attributes = coordinator.getComponent<ecs::component::Attributes>(this->entity);
    auto& transform = coordinator.getComponent<ecs::component::Transform>(this->entity);
}

void indie::KeyBoardPlayer::update()
{
    if (this->alive) {
        if (this->movement.up) {
            if (IsKeyUp(this->playerKeys.moveUp)) {
                this->moveUp(false);
                this->movement.up = false;
            }
        } else {
            if (IsKeyDown(this->playerKeys.moveUp)) {
                this->moveUp();
                this->movement.up = true;
            }
        }
        if (this->movement.down) {
            if (IsKeyUp(this->playerKeys.moveDown)) {
                this->moveDown(false);
                this->movement.down = false;
            }
        } else {
            if (IsKeyDown(this->playerKeys.moveDown)) {
                this->moveDown();
                this->movement.down = true;
            }
        }
        if (this->movement.left) {
            if (IsKeyUp(this->playerKeys.moveLeft)) {
                this->moveLeft(false);
                this->movement.left = false;
            }
        } else {
            if (IsKeyDown(this->playerKeys.moveLeft)) {
                this->moveLeft();
                this->movement.left = true;
            }
        }
        if (this->movement.right) {
            if (IsKeyUp(this->playerKeys.moveRight)) {
                this->moveRight(false);
                this->movement.right = false;
            }
        } else {
            if (IsKeyDown(this->playerKeys.moveRight)) {
                this->moveRight();
                this->movement.right = true;
            }
        }
        if (this->puttingBomb) {
            if (IsKeyUp(this->playerKeys.putBomb)) {
                this->puttingBomb = false;
            }
        } else {
            if (IsKeyDown(this->playerKeys.putBomb)) {
                this->tryPutBomb(this->map, this->coordinator.getComponent<ecs::component::Attributes>(this->entity).position);
                this->puttingBomb = true;
            }
        }
    }
}

/*
** EPITECH PROJECT, 2022
** src
** File description:
** BombRangePowerUp
*/

#include "MapLoader/BombRangePowerUp.hpp"

indie::BombRangePowerUp::BombRangePowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept :
    APowerUp(coordinator, modelInfos, position) { }

void indie::BombRangePowerUp::doChangesOnPlayer(APlayer& player) noexcept
{
    this->playSound();
    player.addBombRange();
}

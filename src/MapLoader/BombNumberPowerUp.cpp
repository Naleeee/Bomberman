/*
** EPITECH PROJECT, 2022
** src
** File description:
** BombNumberPowerUp
*/

#include "MapLoader/BombNumberPowerUp.hpp"

indie::BombNumberPowerUp::BombNumberPowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept :
    APowerUp(coordinator, modelInfos, position) { }

void indie::BombNumberPowerUp::doChangesOnPlayer(APlayer& player) noexcept
{
    this->playSound();
    player.addBomb();
}

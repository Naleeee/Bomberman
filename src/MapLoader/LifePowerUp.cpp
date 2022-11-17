/*
** EPITECH PROJECT, 2022
** src
** File description:
** LifePowerUp
*/

#include "MapLoader/LifePowerUp.hpp"

indie::LifePowerUp::LifePowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept :
    APowerUp(coordinator, modelInfos, position)
{
}

void indie::LifePowerUp::doChangesOnPlayer(APlayer& player) noexcept
{
    this->playSound();
    player.addLife();
}

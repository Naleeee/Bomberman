/*
** EPITECH PROJECT, 2022
** src
** File description:
** SpeedPowerUp
*/

#include "MapLoader/SpeedPowerUp.hpp"

indie::SpeedPowerUp::SpeedPowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept :
    APowerUp(coordinator, modelInfos, position) { }

void indie::SpeedPowerUp::doChangesOnPlayer(APlayer& player) noexcept
{
    this->playSound();
    player.upgradeSpeed();
}

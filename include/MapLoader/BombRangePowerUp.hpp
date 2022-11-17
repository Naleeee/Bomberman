/*
** EPITECH PROJECT, 2022
** include
** File description:
** BombRangePowerUp
*/

#pragma once

#include "MapLoader/APowerUp.hpp"

namespace indie {

/*
 * Bomb range power up
 */
class BombRangePowerUp final : public APowerUp {
   public:
    BombRangePowerUp() noexcept = delete;
    BombRangePowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept;
    BombRangePowerUp(BombRangePowerUp const& other) noexcept = delete;
    BombRangePowerUp(BombRangePowerUp&& other) noexcept = default;
    ~BombRangePowerUp() noexcept final = default;

    BombRangePowerUp& operator=(BombRangePowerUp const& other) noexcept = delete;
    BombRangePowerUp& operator=(BombRangePowerUp&& other) noexcept = delete;

    /*
     * Change the given player according to the power up
     *
     * No return value
     *
     * player -> The player to do changes on
     */
    void doChangesOnPlayer(APlayer& player) noexcept final;
};

} // namespace indie

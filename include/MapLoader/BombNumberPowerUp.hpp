/*
** EPITECH PROJECT, 2022
** include
** File description:
** BombNumberPowerUp
*/

#pragma once

#include "MapLoader/APowerUp.hpp"

namespace indie {

/*
 * Bomb number power up
 */
class BombNumberPowerUp final : public APowerUp {
   public:
    BombNumberPowerUp() noexcept = delete;
    BombNumberPowerUp(ecs::Coordinator& coordinator, const ModelSoundInfos& modelInfos, const Vector& position) noexcept;
    BombNumberPowerUp(BombNumberPowerUp const& other) noexcept = delete;
    BombNumberPowerUp(BombNumberPowerUp&& other) noexcept = default;
    ~BombNumberPowerUp() noexcept final = default;

    BombNumberPowerUp& operator=(BombNumberPowerUp const& other) noexcept = delete;
    BombNumberPowerUp& operator=(BombNumberPowerUp&& other) noexcept = delete;

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

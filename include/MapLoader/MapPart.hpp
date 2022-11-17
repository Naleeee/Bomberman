/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** MapPart
*/

#pragma once

#include "ECS/Core/Coordinator.hpp"
#include "ECS/Systems/CollisionSystem.hpp"
#include "IMapPart.hpp"
#include "MapLoader/Bomb.hpp"
#include "PartType.hpp"
#include "Vector.hpp"

#include <memory>
#include <set>

namespace indie {

enum class PartState {
    FREE,
    BOMB,
    DANGER,
    FIRE,
    POWER_UP,
    UNFREE,
};

/*
 * Part of a map
 */
class MapPart {
   public:
    MapPart() noexcept = delete;
    explicit MapPart(PartType type) noexcept;
    MapPart(ecs::Coordinator& coordinator, ecs::system::CollisionSystem& collisionSystem, std::string_view modelPath, std::string_view texturePath, PartType type, const Vector& position) noexcept;
    MapPart(MapPart const& other) noexcept = delete;
    MapPart(MapPart&& other) noexcept = default;
    ~MapPart() noexcept = default;

    MapPart& operator=(MapPart const& other) noexcept = delete;
    MapPart& operator=(MapPart&& other) noexcept = delete;

    /*
     * Update the map part
     *
     * No return value
     */
    void update() noexcept;
    /*
     * Get the part state
     *
     * Return the part state
     */
    PartState getPartState() const noexcept;
    /*
     * Get the part type
     *
     * Return the part type
     */
    PartType getPartType() const noexcept;
    /*
     * Check if the map part is in danger
     *
     * Return true if the map part is in danger and false otherwise
     */
    bool isInDanger() const noexcept;
    /*
     * Set the state of a part
     *
     * No return value
     *
     * state -> The state to set
     */
    void setPartState(PartState state) noexcept;
    /*
     * Set a danger zone from the given bomb
     *
     * No return value
     *
     * id -> The id of the bomb that make this map part in danger
     */
    void setDanger(BombId id) noexcept;
    /*
     * Remove a danger zone from the given bomb
     *
     * No return value
     *
     * id -> The id of the bomb that make this map part no more in danger
     */
    void removeDanger(BombId id) noexcept;
    /*
     * Set the part on fire
     *
     * No return value
     *
     * coordinator -> The ECS coordinator
     *
     * modelInfos -> Information about the model
     *
     * position -> The position of the fire
     */
    void setOnFire(ecs::Coordinator& coordinator, const ModelInfos& ModelInfos, const Vector& position) noexcept;
    /*
     * Explose the map part, add maybe spawn a power up
     *
     * No return value
     *
     * coordinator -> The ECS coordinator
     *
<<<<<<< HEAD
     * powerUpsInfos -> Paths information about power ups
=======
     * powerUpsInfos -> Paths informations about power ups
     *
     * sound -> The sound of the explosion if the part is a box
>>>>>>> ace9f4a46972f4d1d174ee098075d2369a9d2d59
     */
    void explose(ecs::Coordinator& coordinator, const PowerUpsInfos& powerUpsInfos, std::string_view sound) noexcept;
    /*
     * Apply the contained power up
     *
     * No return value
     *
     * player -> The player to apply the power up on
     */
    void applyPowerUp(APlayer& player) noexcept;

   private:
    PartType type;
    PartState state = PartState::FREE;
    std::set<BombId> dangers;
    std::unique_ptr<IMapPart> part = nullptr;
};

} // namespace indie

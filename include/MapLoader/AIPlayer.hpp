/*
** EPITECH PROJECT, 2022
** include
** File description:
** AIPlayer
*/

#pragma once

#include "Clock.hpp"
#include "ECS/Core/Coordinator.hpp"
#include "MapLoader/APlayer.hpp"
#include "MapLoader/Map.hpp"
#include "MapLoader/ObjectsInfos.hpp"
#include "PlayersManager.hpp"
#include "Vector.hpp"

namespace indie {

class Map;

/*
 * AI managed player
 */
class AIPlayer final : public APlayer {
   public:
    AIPlayer() noexcept = delete;
    AIPlayer(ecs::Coordinator& coordinator, const PlayersInfos& playersInfos, const Vector& position, const PlayerId& id, Map& map) noexcept;
    AIPlayer(AIPlayer const& other) noexcept = delete;
    AIPlayer(AIPlayer&& other) noexcept = default;
    ~AIPlayer() noexcept final = default;

    AIPlayer& operator=(AIPlayer const& other) noexcept = delete;
    AIPlayer& operator=(AIPlayer&& other) noexcept = delete;

    /*
     * Update the AI player
     *
     * No return value
     */
    void update() final;

   private:
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        MIDDLE,
    };
    /*
     * Adds a Direction if possible
     *
     * states -> the states of the parts around the player
     *
     * newDirs -> A vector of directions
     *
     * partState -> The state expected of the parts around the player
     *
     * No return value
     */
    void addDirection(const AroundMapPartStates& states, std::vector<Direction>& newDirs, PartState partState) const noexcept;
    /*
     * Adds any Directions if possible
     *
     * states -> the states of the parts around the player
     *
     * newDirs -> A vector of directions
     *
     * partState -> The state expected of the parts around the player
     *
     * No return value
     */
    static void addAnyDirection(const AroundMapPartStates& states, std::vector<Direction>& newDirs, PartState partState) noexcept;
    /*
     * Adds the standing still position if available
     *
     * states -> the states of the parts around the player
     *
     * newDirs -> A vector of directions
     *
     * No return value
     */
    static void addStandStill(const AroundMapPartStates& states, std::vector<Direction>& newDirs, PartState partState) noexcept;
    /*
     * Places a bomb
     *
     * newDirs -> A vector of directions
     *
     * around -> the states of the parts around the player
     *
     * aroundType -> the types of the parts around the player
     *
     * No return value
     */
    void placeBomb(const std::vector<Direction>& newDirs, const AroundMapPartStates& around, const AroundMapPartTypes& aroundType) noexcept;
    /*
     * Returns true if a case state is next to the player
     *
     * around -> case state around the player
     *
     * partState -> the states of the parts around the player
     *
     * returns a bool
     */
    static bool isCaseStateAround(const AroundMapPartStates& around, PartState partState) noexcept;
    /*
     * Returns true if a case type is next to the player
     *
     * around -> case type around the player
     *
     * partType -> the states of the parts around the player
     *
     * returns a bool
     */
    static bool isCaseTypeAround(const indie::AroundMapPartTypes& around, indie::PartType partType) noexcept;
    /*
     * Get the PartState from a Direction
     *
     * dir -> The direction
     *
     * states -> the states of the parts around the player
     *
     * returns a PartState
     */
    static PartState getPartStateFromDirection(Direction dir, const AroundMapPartStates& states) noexcept;
    /*
     * Recenters the AI when it's stuck
     *
     * position -> the actual position of the AI
     *
     * No return value
     */
    void recenterAI(Vector& position) const noexcept;

    Map& map;
    Clock clock = Clock();
    std::chrono::steady_clock::time_point nextInstruction = std::chrono::steady_clock::now();
    Vector oldPosition = {};
    Direction oldDirection = Direction::MIDDLE;
};

} // namespace indie

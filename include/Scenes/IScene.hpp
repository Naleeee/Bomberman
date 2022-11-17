/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** IScene
*/

#pragma once

#include "ECS/Core/Coordinator.hpp"
#include "Vector.hpp"

namespace graphic {

class ScenesManager;

/*
 * The graphic scenes
 */
class IScene {
   public:
    IScene() noexcept = default;
    IScene(IScene const& other) noexcept = delete;
    IScene(IScene&& other) noexcept = delete;
    virtual ~IScene() noexcept = default;

    IScene& operator=(IScene const& other) noexcept = delete;
    IScene& operator=(IScene&& other) noexcept = delete;

    /*
     * Update the scene
     *
     * No return value
     *
     * coordinator -> The ECS coordinator to use
     *
     * dt -> The time elapsed since the last update
     */
    virtual void update(ScenesManager& scenesManager, float dt) = 0;
    /*
     * Get the position the camera should be, this will be used for camera movement between scenes
     *
     * Return the position as a vector
     */
    virtual indie::Vector getCameraPosition() const noexcept = 0;
    /*
     * Get the position the camera should look to, this will be used for camera movement between scenes
     *
     * Return the position as a vector
     */
    virtual indie::Vector getCameraLooking() const noexcept = 0;
};

} // namespace graphic

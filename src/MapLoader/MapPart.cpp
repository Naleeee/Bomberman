/*
** EPITECH PROJECT, 2022
** src
** File description:
** MapPart
*/

#include "MapLoader/MapPart.hpp"

#include "AudioPlayer.hpp"
#include "MapLoader/BombNumberPowerUp.hpp"
#include "MapLoader/BombRangePowerUp.hpp"
#include "MapLoader/Box.hpp"
#include "MapLoader/Fire.hpp"
#include "MapLoader/LifePowerUp.hpp"
#include "MapLoader/SpeedPowerUp.hpp"
#include "MapLoader/Wall.hpp"
#include "Randomizer.hpp"

#include <memory>

indie::MapPart::MapPart(PartType type) noexcept :
    type(type)
{
    switch (type) {
    case PartType::PLAYER:
    case PartType::GROUND:
        this->state = PartState::FREE;
        break;
    default:
        this->state = PartState::UNFREE;
        break;
    }
}

indie::MapPart::MapPart(ecs::Coordinator& coordinator, ecs::system::CollisionSystem& collisionSystem, std::string_view modelPath, std::string_view texturePath, PartType type, const Vector& position) noexcept :
    type(type)
{
    switch (this->type) {
    case indie::PartType::WALL:
        this->part = std::make_unique<Wall>(coordinator, collisionSystem, modelPath, texturePath, position);
        break;
    case indie::PartType::BOX:
        this->part = std::make_unique<Box>(coordinator, collisionSystem, modelPath, texturePath, position);
        break;
    default:
        break;
    }
    switch (this->type) {
    case PartType::PLAYER:
    case PartType::GROUND:
        this->state = PartState::FREE;
        break;
    default:
        this->state = PartState::UNFREE;
        break;
    }
}

void indie::MapPart::update() noexcept
{
    if (this->state == PartState::FIRE) {
        auto& part = dynamic_cast<Fire&>(*this->part);

        if (part.noMoreBurning()) {
            this->state = PartState::FREE;
            this->part.reset(nullptr);
        }
    }
}

void indie::MapPart::setPartState(PartState state) noexcept
{
    this->state = state;
}

indie::PartState indie::MapPart::getPartState() const noexcept
{
    return this->state;
}

indie::PartType indie::MapPart::getPartType() const noexcept
{
    return this->type;
}

void indie::MapPart::setDanger(BombId bombId) noexcept
{
    this->dangers.insert(bombId);
}

void indie::MapPart::removeDanger(BombId bombId) noexcept
{
    this->dangers.erase(bombId);
}

void indie::MapPart::setOnFire(ecs::Coordinator& coordinator, const ModelInfos& modelInfos, const Vector& position) noexcept
{
    this->part.reset(nullptr);
    this->part = std::make_unique<Fire>(coordinator, modelInfos, position);
    this->state = PartState::FIRE;
}

bool indie::MapPart::isInDanger() const noexcept
{
    return (not this->dangers.empty());
}

void indie::MapPart::explose(ecs::Coordinator& coordinator, const PowerUpsInfos& powerUpsInfos, std::string_view sound) noexcept
{
    if (this->type == PartType::BOX) {
        audio::AudioPlayer::playSound(sound);
        const auto position = this->part->getPosition();
        this->type = PartType::GROUND;
        this->state = PartState::FREE;
        this->part.reset(nullptr);
        if (indie::Randomizer::getRandomNumber(1, 3) == 3) {
            this->state = PartState::POWER_UP;
            int powerUp = indie::Randomizer::getRandomNumber(1, 9);

            switch (powerUp) {
            case 1:
                this->part = std::make_unique<LifePowerUp>(coordinator, powerUpsInfos.life, position);
                break;
            case 2:
                this->part = std::make_unique<SpeedPowerUp>(coordinator, powerUpsInfos.speed, position);
                break;
            case 3:
            case 4:
            case 5:
                this->part = std::make_unique<BombRangePowerUp>(coordinator, powerUpsInfos.bombRange, position);
                break;
            case 6:
            case 7:
            case 8:
            case 9:
                this->part = std::make_unique<BombNumberPowerUp>(coordinator, powerUpsInfos.bombNumber, position);
                break;
            default:
                break;
            }
        }
    }
}

void indie::MapPart::applyPowerUp(APlayer& player) noexcept
{
    if (this->state == PartState::POWER_UP) {
        dynamic_cast<APowerUp&>(*this->part).apply(player);
        this->state = PartState::FREE;
        this->part.reset(nullptr);
    }
}

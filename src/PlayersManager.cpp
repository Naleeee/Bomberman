/*
** EPITECH PROJECT, 2022
** src
** File description:
** PlayersManager
*/

#include "PlayersManager.hpp"

std::array<indie::PlayerType, 4> indie::PlayersManager::types{indie::PlayerType::AI, indie::PlayerType::AI, indie::PlayerType::AI, indie::PlayerType::AI};
std::array<indie::PlayerKeys, 4> indie::PlayersManager::keybinds;
std::array<std::string, 4> indie::PlayersManager::texturesPath;

void indie::PlayersManager::setPlayerType(PlayerId id, PlayerType type) noexcept
{
    if (id > 0 and id < 5) {
        types.at(id - 1) = type;
    }
}

void indie::PlayersManager::setPlayerKeys(PlayerId id, PlayerKeys keys) noexcept
{
    if (id > 0 and id < 5) {
        keybinds.at(id - 1) = keys;
    }
}

void indie::PlayersManager::setPlayerTexture(PlayerId id, const std::string& texture) noexcept
{
    if (id > 0 and id < 5) {
        texturesPath.at(id - 1) = texture;
    }
}

indie::PlayerType& indie::PlayersManager::getPlayerType(PlayerId id) noexcept
{
    return types.at(id - 1);
}

indie::PlayerKeys& indie::PlayersManager::getPlayerKeys(PlayerId id) noexcept
{
    return keybinds.at(id - 1);
}

std::string_view indie::PlayersManager::getPlayerTexture(PlayerId id) noexcept
{
    return texturesPath.at(id - 1);
}

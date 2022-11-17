/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** PlayersManagerTests
*/

#include "PlayersManager.hpp"

#include <gtest/gtest-matchers.h>
#include <gtest/gtest.h>

TEST(PlayersManager, setPlayerType)
{
    EXPECT_NO_THROW(indie::PlayersManager::setPlayerType(1, indie::PlayerType::KEYBOARD));
}

TEST(PlayersManager, setPlayersKeys)
{
    EXPECT_NO_THROW(indie::PlayersManager::setPlayerKeys(1, {.moveUp = KEY_W}));
}

TEST(PlayersManager, getPlayerType)
{
    indie::PlayerId playerId = 1;
    indie::PlayerType playerType = indie::PlayerType::KEYBOARD;

    EXPECT_NO_THROW(indie::PlayersManager::setPlayerType(playerId, playerType));
    indie::PlayerType& res = indie::PlayersManager::getPlayerType(playerId);
    EXPECT_EQ(static_cast<int>(res), static_cast<int>(playerType));
}

TEST(PlayersManager, getPlayersKeys)
{
    indie::PlayerKeys playerKeys = {.moveUp = KEY_W};
    indie::PlayersManager::setPlayerKeys(1, playerKeys);
    indie::PlayerKeys& res = indie::PlayersManager::getPlayerKeys(1);
    EXPECT_EQ(static_cast<int>(res.moveUp), static_cast<int>(playerKeys.moveUp));
}

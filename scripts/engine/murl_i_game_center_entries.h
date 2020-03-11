// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_I_GAME_CENTER_ENTRIES_H__
#define __MURL_I_GAME_CENTER_ENTRIES_H__

#include "murl_string.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IGameCenterPlayer
     * @brief The player entry interface.
     * Player entries are used by the #GameCenterPlayerEntries array.
     */
    class IGameCenterPlayer
    {
    public:
        /**
         * @brief Get the player identifier.
         * The player identifier should never be displayed to the player.
         * Use it only as a way to identify a particular player.\n
         * Do not make assumptions about the contents of the player identifier string.
         * Its format and length are subject to change.
         * @return The player identifier.
         */
        virtual const String& GetPlayerId() const = 0;

        /**
         * @brief Get the player alias.
         * A string chosen by the player to identify themselves to other players.
         * @return The player alias.
         */
        virtual const String& GetAlias() const = 0;

        /**
         * @brief Get the player name.
         * The display name for a player depends on whether the player is a friend
         * of the local player authenticated on the device.\n
         * If the player is a friend of the local player, then the display name is
         * the actual name of the player.\n
         * If the player is not a friend, then the display name is the player’s alias.
         * @return The player name.
         */
        virtual const String& GetDisplayName() const = 0;

    protected:
        ~IGameCenterPlayer() {}
    };

    /**
     * @ingroup MurlControlInterfaces
     * @brief Definition of the player array.
     * The player array is provided by IGameCenterControl::GetFriends().
     */
    typedef Array<const IGameCenterPlayer*> GameCenterPlayerEntries;

    /**
     * @ingroup MurlControlInterfaces
     * @interface IGameCenterLeaderboardEntry
     * @brief The leaderboard entry interface.
     * Leaderboard entries are used by the #GameCenterLeaderboardEntries array.
     */
    class IGameCenterLeaderboardEntry
    {
    public:
        /**
         * @brief Get the player identifier.
         * @return The player identifier.
         */
        virtual const IGameCenterPlayer& GetPlayer() const = 0;
        /**
         * @brief Get the player rank.
         * @return The player rank.
         */
        virtual UInt32 GetRank() const = 0;
        /**
         * @brief Get the player score.
         * @return The player score.
         */
        virtual UInt64 GetScore() const = 0;

    protected:
        ~IGameCenterLeaderboardEntry() {}
    };

    /**
     * @ingroup MurlControlInterfaces
     * @brief Definition of the leaderboard entries array.
     * The leaderboard array is provided by IGameCenterControl::GetLeaderboard().
     */
    typedef Array<const IGameCenterLeaderboardEntry*> GameCenterLeaderboardEntries;

    /**
     * @ingroup MurlControlInterfaces
     * @interface IGameCenterAchievementEntry
     * @brief The achievement entry interface.
     * Achievement entries are used by the #GameCenterAchievementEntries array.
     */
    class IGameCenterAchievementEntry
    {
    public:
        /**
         * @brief Get the achievement identifier.
         * @return The achievement identifier.
         */
        virtual const String& GetIdentifier() const = 0;
        /**
         * @brief Get the achievement precentage.
         * @return The achievement precentage.
         */
        virtual Double GetPercentage() const = 0;

    protected:
        ~IGameCenterAchievementEntry() {}
    };

    /**
     * @ingroup MurlControlInterfaces
     * @brief Definition of the achievement entries array.
     * The achievements array is provided by IGameCenterControl::GetAchievements().
     */
    typedef Array<const IGameCenterAchievementEntry*> GameCenterAchievementEntries;
}

#endif  // __MURL_I_GAME_CENTER_ENTRIES_H__

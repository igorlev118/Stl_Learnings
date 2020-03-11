// Copyright 2010-2016 Spraylight

#ifndef __MURL_I_GAME_CENTER_CONTROL_H__
#define __MURL_I_GAME_CENTER_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_game_center_entries.h"
#include "murl_enum.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IGameCenterControl
     * @brief The IGameCenterControl interface.
     * The game center is currently supported on iOS/OSX/tvOS only.
     */
    class IGameCenterControl : public IControlable
    {
    public:
        /**
         * @name Authentication
         * @brief Methods for authentication of the local player.
         * @{
         */
        /**
         * @brief Enumeration of the authentication status.
         * Use GetAuthenticationStatus() to get the current status.
         */
        enum AuthenticationStatus
        {
            /** The authentication is idle. */
            STATUS_AUTHENTICATION_IDLE,
            /** The authentication is in progress. */
            STATUS_AUTHENTICATING,
            /** The authentication is succesful. */
            STATUS_AUTHENTICATED,
            /** The authentication failed. */
            STATUS_AUTHENTICATION_FAILED,
            /** The authentication is not possible. */
            STATUS_AUTHENTICATION_IMPOSSIBLE
        };
        /**
         * @brief Get the game-center authentication status.
         * Authentication operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The game-center authentication status.
         */
        virtual AuthenticationStatus GetAuthenticationStatus() const = 0;
        /**
         * @brief Start authenticating the local user to the game-center.
         * When starting the authentication, the authentication status changes
         * to IGameCenterControl::STATUS_AUTHENTICATING immediately.
         * When the authentication is finished the authentication status
         * changes to IGameCenterControl::STATUS_AUTHENTICATED.
         * @return true if successful.
         */
        virtual Bool AuthenticateLocalPlayer() = 0;
        /**
         * @brief Get the game-center local user.
         * The local user is available when AuthenticateLocalPlayer() is finished.
         * @return The game-center local user.
         */
        virtual const IGameCenterPlayer& GetLocalPlayer() const = 0;
        /**
         * @brief Check if the game-center local user is underage.
         * The local user underage is available when AuthenticateLocalPlayer() is finished.
         * @return true if the game-center local user is underage.
         */
        virtual Bool IsLocalPlayerUnderage() const = 0;
        /**
         * @brief Check if the game-center authentication status is
         * IGameCenterControl::STATUS_AUTHENTICATION_IDLE.
         * @return true if the status is IGameCenterControl::STATUS_AUTHENTICATION_IDLE.
         */
        virtual Bool IsAuthenticationIdle() const = 0;
        /**
         * @brief Check if the game-center authentication status is
         * IGameCenterControl::STATUS_AUTHENTICATING.
         * @return true if the status is IGameCenterControl::STATUS_AUTHENTICATING.
         */
        virtual Bool IsAuthenticating() const = 0;
        /**
         * @brief Check if the game-center authentication status is
         * IGameCenterControl::STATUS_AUTHENTICATED.
         * @return true if the status is IGameCenterControl::STATUS_AUTHENTICATED.
         */
        virtual Bool IsAuthenticated() const = 0;
        /**
         * @brief Check if the game-center authentication status is
         * IGameCenterControl::STATUS_AUTHENTICATION_FAILED.
         * @return true if the status is IGameCenterControl::STATUS_AUTHENTICATION_FAILED.
         */
        virtual Bool IsAuthenticationFailed() const = 0;
        /**
         * @brief Check if the game-center authentication status is
         * IGameCenterControl::STATUS_AUTHENTICATION_IMPOSSIBLE.
         * @return true if the status is IGameCenterControl::STATUS_AUTHENTICATION_IMPOSSIBLE.
         */
        virtual Bool IsAuthenticationImpossible() const = 0;
        /** @} */

        /**
         * @name Friends
         * @brief Methods for loading friends.
         * @{
         */
        /**
         * @brief Enumeration of the load friends status.
         * Use GetLoadFriendsStatus() to get the current status.
         */
        enum LoadFriendsStatus
        {
            /** Loading friends is idle. */
            STATUS_LOAD_FRIENDS_IDLE,
            /** Loading friends is in progress. */
            STATUS_LOAD_FRIENDS_LOADING
        };
        /**
         * @brief Get the game-center load friends status.
         * Load friends operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The game-center load friends status.
         */
        virtual LoadFriendsStatus GetLoadFriendsStatus() const = 0;
        /**
         * @brief Load all game-center friends player entries.
         * When start loading, the load friends status changes to
         * IGameCenterControl::STATUS_LOAD_FRIENDS_LOADING immediately.
         * When the friends loading is finished the friends
         * status changes to IGameCenterControl::STATUS_LOAD_FRIENDS_IDLE.
         * The friends player entries can be accessed by GetFriends().
         * @return true if successful.
         */
        virtual Bool LoadFriends() = 0;
        /**
         * @brief Load specified game-center friends player entries.
         * When start loading, the load friends status changes to
         * IGameCenterControl::STATUS_LOAD_FRIENDS_LOADING immediately.
         * When the friends loading is finished the friends
         * status changes to IGameCenterControl::STATUS_LOAD_FRIENDS_IDLE.
         * The friends player entries can be accessed by GetFriends().
         * @param friendIds A string array containing the player identifiers to load.
         * @return true if successful.
         */
        virtual Bool LoadFriends(const StringArray& friendIds) = 0;
        /**
         * @brief Get an array of friends player entries.
         * The friends player entries are available when LoadFriends() is finished.
         * @return The array of friends player entries.
         */
        virtual const GameCenterPlayerEntries& GetFriends() const = 0;
        /**
         * @brief Check if the game-center load load friends status is
         * IGameCenterControl::STATUS_LOAD_FRIENDS_IDLE.
         * @return true if the status is IGameCenterControl::STATUS_LOAD_FRIENDS_IDLE.
         */
        virtual Bool IsLoadFriendsIdle() const = 0;
        /**
         * @brief Check if the game-center load load friends status is
         * IGameCenterControl::STATUS_LOAD_FRIENDS_LOADING.
         * @return true if the status is IGameCenterControl::STATUS_LOAD_FRIENDS_LOADING.
         */
        virtual Bool IsLoadFriendsLoading() const = 0;
        /** @} */

        /**
         * @name Leaderboard
         * @brief Methods for using the leaderboard.
         * @{
         */
        /**
         * @brief Enumeration of the leaderboard status.
         * Use GetLeaderboardStatus() to get the current status.
         */
        enum LeaderboardStatus
        {
            /** The leaderboard is idle. */
            STATUS_LEADERBOARD_IDLE,
            /** The leaderboard overlay is showing. */
            STATUS_LEADERBOARD_SHOWING,
            /** Reporting a leaderboard score is in progress. */
            STATUS_LEADERBOARD_REPORTING,
            /** Loading leaderboard scores is in progress. */
            STATUS_LEADERBOARD_LOADING
        };
        /**
         * @brief Get the game-center leaderboard status.
         * Leaderboard operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The game-center leaderboard status.
         */
        virtual LeaderboardStatus GetLeaderboardStatus() const = 0;
        /**
         * @brief Show the game-center leaderboard overlay.
         * When showing the leaderboard overlay, the leaderboard status changes
         * to IGameCenterControl::STATUS_LEADERBOARD_SHOWING immediately.
         * When the leaderboard overlay is closed the leaderboard
         * status changes to IGameCenterControl::STATUS_LEADERBOARD_IDLE.
         * @param category The name of the leaderboard category to show
         * or an empty string to show the default leaderboard.
         * @return true if successful.
         */
        virtual Bool ShowLeaderboard(const String& category) = 0;
        /**
         * @brief Report a score to the game-center leaderboard.
         * When start reporting, the leaderboard status changes to
         * IGameCenterControl::STATUS_LEADERBOARD_REPORTING immediately.
         * When the leaderboard reporting is finished the leaderboard
         * status changes to IGameCenterControl::STATUS_LEADERBOARD_IDLE.
         * @param category The name of the leaderboard category.
         * @param score The score to report.
         * @return true if successful.
         */
        virtual Bool ReportLeaderboard(const String& category, UInt64 score) = 0;
        /**
         * @brief Load the game-center leaderboard entries.
         * When start loading, the leaderboard status changes to
         * IGameCenterControl::STATUS_LEADERBOARD_LOADING immediately.
         * When the leaderboard loading is finished the leaderboard
         * status changes to IGameCenterControl::STATUS_LEADERBOARD_IDLE.
         * The leaderboard entries can be accessed by GetLeaderboard()
         * and GetLeaderboardCategory().
         * @param category The name of the leaderboard category.
         * @param startRank The first rank to load.
         * @param numberOfRanks The number of ranks to load.
         * @return true if successful.
         */
        virtual Bool LoadLeaderboard(const String& category, UInt32 startRank, UInt32 numberOfRanks) = 0;
        /**
         * @brief Get an array of leaderboard entries.
         * The leaderboard entries are available when LoadLeaderboard() is finished.
         * @return The array of leaderboard entries.
         */
        virtual const GameCenterLeaderboardEntries& GetLeaderboard() const = 0;
        /**
         * @brief Check if the game-center leaderboard status is
         * IGameCenterControl::STATUS_LEADERBOARD_IDLE.
         * @return true if the status is IGameCenterControl::STATUS_LEADERBOARD_IDLE.
         */
        virtual Bool IsLeaderboardIdle() const = 0;
        /**
         * @brief Check if the game-center leaderboard status is
         * IGameCenterControl::STATUS_LEADERBOARD_SHOWING.
         * @return true if the status is IGameCenterControl::STATUS_LEADERBOARD_SHOWING.
         */
        virtual Bool IsLeaderboardShowing() const = 0;
        /**
         * @brief Check if the game-center leaderboard status is
         * IGameCenterControl::STATUS_LEADERBOARD_REPORTING.
         * @return true if the status is IGameCenterControl::STATUS_LEADERBOARD_REPORTING.
         */
        virtual Bool IsLeaderboardReporting() const = 0;
        /**
         * @brief Check if the game-center leaderboard status is
         * IGameCenterControl::STATUS_LEADERBOARD_LOADING.
         * @return true if the status is IGameCenterControl::STATUS_LEADERBOARD_LOADING.
         */
        virtual Bool IsLeaderboardLoading() const = 0;
        /** @} */

        /**
         * @name Achievements
         * @brief Methods for using achievments.
         * @{
         */
        /**
         * @brief Enumeration of the achievement status.
         * Use GetAchievementStatus() to get the current status.
         */
        enum AchievementStatus
        {
            /** The achievement is idle. */
            STATUS_ACHIEVEMENT_IDLE,
            /** The achievements overlay is showing. */
            STATUS_ACHIEVEMENT_SHOWING,
            /** Reporting achievements is in progress. */
            STATUS_ACHIEVEMENT_REPORTING,
            /** Resetting all achievements is in progress. */
            STATUS_ACHIEVEMENT_RESETTING,
            /** Loading achievements is in progress. */
            STATUS_ACHIEVEMENT_LOADING
        };
        /**
         * @brief Get the game-center achievement status.
         * Achievement operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The game-center achievement status.
         */
        virtual AchievementStatus GetAchievementStatus() const = 0;
        /**
         * @brief Show the game-center achievements overlay.
         * When showing the achievements overlay, the achievement status changes
         * to IGameCenterControl::STATUS_ACHIEVEMENT_SHOWING immediately.
         * When the achievements overlay is closed the achievement
         * status changes to IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         * @return true if successful.
         */
        virtual Bool ShowAchievements() = 0;
        /**
         * @brief Report a game-center achievement.
         * When start reporting, the achievement status changes to
         * IGameCenterControl::STATUS_ACHIEVEMENT_REPORTING immediately.
         * When the achievement reporting is finished the achievement
         * status changes to IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         * @param identifier The achievement identifier.
         * @param percentComplete The percentage of achievement complete,
         *  report 0 to unhide achievement.
         * @param showsCompletionBanner If true, a banner will be momentarily displayed
         *  after reporting a completed achievement.
         * @return true if successful.
         */
        virtual Bool ReportAchievement(const String& identifier, Double percentComplete,
                                       Bool showsCompletionBanner = true) = 0;
        /**
         * @brief Reset all game-center achievements.
         * When start resetting, the achievement status changes to
         * IGameCenterControl::STATUS_ACHIEVEMENT_RESETTING immediately.
         * When the achievement resetting is finished the achievement
         * status changes to IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         * @return true if successful.
         */
        virtual Bool ResetAchievements() = 0;
        /**
         * @brief Load the game-center achievement entries.
         * When start loading, the achievement status changes to
         * IGameCenterControl::STATUS_ACHIEVEMENT_LOADING immediately.
         * When the achievement loading is finished the achievement
         * status changes to IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         * The achievement entries can be accessed by GetAchievements().
         * @return true if successful.
         */
        virtual Bool LoadAchievements() = 0;
        /**
         * @brief Get an array of achievement entries.
         * The achievements entries are available when LoadAchievements() is finished.
         * @return The array of achievement entries.
         */
        virtual const GameCenterAchievementEntries& GetAchievements() const = 0;
        /**
         * @brief Check if the game-center achievement status is
         * IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         * @return true if the status is IGameCenterControl::STATUS_ACHIEVEMENT_IDLE.
         */
        virtual Bool IsAchievementIdle() const = 0;
        /**
         * @brief Check if the game-center achievement status is
         * IGameCenterControl::STATUS_ACHIEVEMENT_SHOWING.
         * @return true if the status is IGameCenterControl::STATUS_ACHIEVEMENT_SHOWING.
         */
        virtual Bool IsAchievementShowing() const = 0;
        /**
         * @brief Check if the game-center achievement status is
         * IGameCenterControl::STATUS_ACHIEVEMENT_REPOTRING.
         * @return true if the status is IGameCenterControl::STATUS_ACHIEVEMENT_REPOTRING.
         */
        virtual Bool IsAchievementReporting() const = 0;
        /**
         * @brief Check if the game-center achievement status is
         * IGameCenterControl::STATUS_ACHIEVEMENT_RESETTING.
         * @return true if the status is IGameCenterControl::STATUS_ACHIEVEMENT_RESETTING.
         */
        virtual Bool IsAchievementResetting() const = 0;
        /**
         * @brief Check if the game-center achievement status is
         * IGameCenterControl::STATUS_ACHIEVEMENT_LOADING.
         * @return true if the status is IGameCenterControl::STATUS_ACHIEVEMENT_LOADING.
         */
        virtual Bool IsAchievementLoading() const = 0;
        /** @} */

        /**
         * @name Errors
         * @brief Methods for error handling.
         * @{
         */
        /**
         * @brief Enumeration of error status.
         * Use GetError() to get the current status.
         */
        enum Error
        {
            /** No error. */
            ERROR_NONE,

            /** Unknown error. */
            ERROR_UNKNOWN,
            /** Action is cancelled. */
            ERROR_CANCELLED,
            /** Communication failed. */
            ERROR_COMMUNICATIONS_FAILURE,
            /** User was denied. */
            ERROR_USER_DENIED,
            /** Invalid credentials. */
            ERROR_INVALID_CREDENTIALS,
            /** Not authenticated. */
            ERROR_NOT_AUTHENTICATED,
            /** Authentication is in progress. */
            ERROR_AUTHENTICATION_IN_PROGRESS,
            /** Player identifier is invalid. */
            ERROR_INVALID_PLAYER,
            /** Score was not set. */
            ERROR_SCORE_NOT_SET,
            /** Parental control block. */
            ERROR_PARENTAL_CONTROLS_BLOCKED,
            /** Player status exceeds maximum length. */
            ERROR_PLAYER_STATUS_EXCEEDS_MAXIMUM_LENGTH,
            /** Player status is invalid. */
            ERROR_PLAYER_STATUS_INVALID,
            /** Match request is invalid. */
            ERROR_MATCH_REQUEST_INVALID,
            /** Player is underage. */
            ERROR_UNDERAGE,
            /** Game is not recognized. */
            ERROR_GAME_UNRECOGNIZED,
            /** Not supported. */
            ERROR_NOT_SUPPORTED,
            /** Invalid parameter. */
            ERROR_INVALID_PARAMETER
        };
        /**
         * @brief Get the game-center error status.
         * @return The game-center error status.
         */
        virtual Error GetError() const = 0;
        /**
         * @brief Clear the last error status.
         * Set the error status to IGameCenterControl::ERROR_NONE.
         * @return true if successful.
         */
        virtual Bool ClearLastError() = 0;
        /** @} */

    protected:
        virtual ~IGameCenterControl() {}
    };

    /**
     * @brief Get the IGameCenterControl::AuthenticationStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IGameCenterControl::AuthenticationStatus>& GetIGameCenterAuthenticationStatusEnum();

    /**
     * @brief Get the IGameCenterControl::LoadFriendsStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IGameCenterControl::LoadFriendsStatus>& GetIGameCenterLoadFriendsStatusEnum();

    /**
     * @brief Get the IGameCenterControl::LeaderboardStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IGameCenterControl::LeaderboardStatus>& GetIGameCenterLeaderboardStatusEnum();

    /**
     * @brief Get the IGameCenterControl::AchievementStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IGameCenterControl::AchievementStatus>& GetIGameCenterAchievementStatusEnum();

    /**
     * @brief Get the IGameCenterControl::Error enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IGameCenterControl::Error>& GetIGameCenterControlErrorEnum();
}

#endif  // __MURL_I_GAME_CENTER_CONTROL_H__

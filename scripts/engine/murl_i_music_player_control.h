// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_MUSIC_PLAYER_CONTROL_H__
#define __MURL_I_MUSIC_PLAYER_CONTROL_H__

#include "murl_i_controlable.h"

#include "murl_change_controller.h"
#include "murl_enum.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IMusicPlayerControl
     * @brief The IMusicPlayerControl interface.
     * The music player's audio session category can be setup by the
     * IEngineConfiguration::SetAudioSessionCategory() during IApp::Configure().
     *
     * If the configured category is IEnums::AUDIO_SESSION_CATEGORY_DEFAULT the category
     * IEnums::AUDIO_SESSION_CATEGORY_MIX_AMBIENT is used when selecting a music player.
     *
     * The music player control is currently supported on iOS only.
     */
    class IMusicPlayerControl : public IControlable
    {
    public:

        /**
         * @brief Enumeration of the selected music player.
         * Use SelectMusicPlayer() to select the current music player,
         * see GetSelectedMusicPlayer() to get the current music player.
         */
        enum MusicPlayer
        {
            /** No music player. */
            PLAYER_NONE = 0,
            /**
            * The application music player plays music locally within your app.
            * It does not affect the iPod state. When your app moves to the background,
            * the music player stops if it was playing.
            */
            PLAYER_APPLICATION,
            /** 
             * The system (iPod) music player employs the iPod app on your behalf.
             * Music that is playing continues to play when your app moves to the background.
             * On instantiation, it takes on the current iPod app state and controls that state.
             * Specifically, the shared state includes the following:
             *  - Repeat mode (see GetRepeatMode())
             *  - Shuffle mode (see GetShuffleMode())
             *  - Current now-playing item (see HasCurrentItemChanged())
             *  - Playback state (see GetPlaybackState())
             */
            PLAYER_SYSTEM
        };

        /**
         * @brief Set the selected music player.
         * Changing between application and system player during runtime is not properly supported
         * by iOS, once a player is selected it should not change until the app is restarted.
         * @param musicPlayer The selected music player.
         * @return true if successful.
         */
        virtual Bool SelectMusicPlayer(MusicPlayer musicPlayer) = 0;

        /**
         * @brief Get the selected music player.
         * @return The selected music player.
         */
        virtual MusicPlayer GetSelectedMusicPlayer() const = 0;

        /**
         * @brief Show the media item picker.
         * The media item picker let a user choose media items from the device iPod library.
         * @param allowMultipleItems Specify multiple (true) or single (false) selection behavior.
         * @param prompt A prompt for the user that appears above the navigation bar buttons.
         * @return true if successful.
         */
        virtual Bool ShowMediaPicker(Bool allowMultipleItems, const String& prompt) = 0;
        /**
         * @brief Check if the media item picker is showing.
         * @return true if the media item picker is showing.
         */
        virtual Bool IsMediaPickerShowing() const = 0;

        /**
         * @brief Initiates playback of the current item.
         * @return true if successful.
         */
        virtual Bool Play() = 0;

        /**
         * @brief Pauses playback of the current item.
         * @return true if successful.
         */
        virtual Bool Pause() = 0;

        /**
         * @brief Ends playback of the current item.
         * @return true if successful.
         */
        virtual Bool Stop() = 0;

        /**
         * @brief Start playback of the next media item in the playback queue.
         * If the music player is not playing the next media item is designated
         * as the next to be played.
         * @return true if successful.
         */
        virtual Bool SkipToNextItem() = 0;

        /**
         * @brief Restart playback at the beginning of the currently playing media item.
         * @return true if successful.
         */
        virtual Bool SkipToBeginning() = 0;

        /**
         * @brief Start playback of the previous media item in the playback queue.
         * If the music player is not playing the previous media item is designated
         * as the next to be played.
         * @return true if successful.
         */
        virtual Bool SkipToPreviousItem() = 0;

        /**
         * @brief Begin seeking backward through the media content.
         * @return true if successful.
         */
        virtual Bool BeginSeekingBackward() = 0;

        /**
         * @brief Begin seeking forward through the media content.
         * @return true if successful.
         */
        virtual Bool BeginSeekingForward() = 0;

        /**
         * @brief End forward and backward seeking through the media content.
         * @return true if successful.
         */
        virtual Bool EndSeeking() = 0;

        /**
         * @brief Enumeration of the playback state.
         * Use GetPlaybackState() to get the current playback state.
         */
        enum PlaybackState
        {
            /** The music player is stopped. */
            PLAYBACK_STOPPED = 0,
            /** The music player is playing. */
            PLAYBACK_PLAYING,
            /** The music player is paused. */
            PLAYBACK_PAUSED,
            /** The music player has been interrupted, such as by an incoming phone call. */
            PLAYBACK_INTERRUPTED,
            /** The music player is seeking forward. */
            PLAYBACK_SEEKING_FORWARD,
            /** The music player is seeking backward. */
            PLAYBACK_SEEKING_BACKWARD
        };

        /**
         * @brief Check if the current playback state has changed.
         * @param inspector The change inspector.
         * @return true if the current playback state has changed.
         */
        virtual Bool HasPlaybackStateChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the current playback state.
         * @return The current playback state.
         */
        virtual PlaybackState GetPlaybackState() const = 0;

        /**
         * @brief Get the current playback time.
         * @return The current playback time in seconds.
         */
        virtual Double GetCurrentPlaybackTime() const = 0;

        /**
         * @brief Check if the current item has changed.
         * If the current item has changed one or more of the following properties changed:
         *  - The title (see GetCurrentTitle())
         *  - The album title (see GetCurrentAlbumTitle())
         *  - The artist (see GetCurrentArtist())
         *  - The duration (see GetCurrentDuration())
         *
         * @param inspector The change inspector.
         * @return true if the current item has changed.
         */
        virtual Bool HasCurrentItemChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the title of the current item.
         * @return The title of the current item.
         */
        virtual String GetCurrentTitle() const = 0;

        /**
         * @brief Get the album title of the current item.
         * @return The album title of the current item.
         */
        virtual String GetCurrentAlbumTitle() const = 0;

        /**
         * @brief Get the artist of the current item.
         * @return The artist of the current item.
         */
        virtual String GetCurrentArtist() const = 0;

        /**
         * @brief Get the duration of the current item.
         * @return The duration of the current item in seconds.
         */
        virtual Double GetCurrentDuration() const = 0;

        /**
         * @brief Enumeration of the repeat mode.
         * Use GetRepeatMode() to get the current repeat mode.
         */
        enum RepeatMode
        {
            /** The user’s preferred repeat mode. */
            REPEAT_DEFAULT = 0,
            /** The music player will not repeat the current song or playlist. */
            REPEAT_NONE,
            /** The music player will repeat the current song. */
            REPEAT_ONE,
            /** The music player will repeat the current playlist. */
            REPEAT_ALL
        };

        /**
         * @brief Set the current repeat mode.
         * @param repeatMode The current repeat mode.
         * @return true if successful.
         */
        virtual Bool SetRepeatMode(RepeatMode repeatMode) = 0;

        /**
         * @brief Get the current repeat mode.
         * @return The current repeat mode.
         */
        virtual RepeatMode GetRepeatMode() const = 0;

        /**
         * @brief Enumeration of the shuffle mode.
         * Use GetShuffleMode() to get the current shuffle mode.
         */
        enum ShuffleMode
        {
            /** The user’s preferred shuffle mode. */
            SHUFFLE_DEFAULT = 0,
            /** The playlist is not shuffled. */
            SHUFFLE_OFF,
            /** The playlist is shuffled by song. */
            SHUFFLE_SONGS,
            /** The playlist is shuffled by album. */
            SHUFFLE_ALBUMS
        };

        /**
         * @brief Set the current shuffle mode.
         * @param shuffleMode The current shuffle mode.
         * @return true if successful.
         */
        virtual Bool SetShuffleMode(ShuffleMode shuffleMode) = 0;

        /**
         * @brief Get the current shuffle mode.
         * @return The current shuffle mode.
         */
        virtual ShuffleMode GetShuffleMode() const = 0;
        
    protected:
        virtual ~IMusicPlayerControl() {}
    };

    /**
     * @brief Get the IMusicPlayerControl::MusicPlayer enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IMusicPlayerControl::MusicPlayer>& GetIMusicPlayerEnum();

    /**
     * @brief Get the IMusicPlayerControl::PlaybackState enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IMusicPlayerControl::PlaybackState>& GetIMusicPlayerPlaybackStateEnum();

    /**
     * @brief Get the IMusicPlayerControl::RepeatMode enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IMusicPlayerControl::RepeatMode>& GetIMusicPlayerRepeatModeEnum();

    /**
     * @brief Get the IMusicPlayerControl::ShuffleMode enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IMusicPlayerControl::ShuffleMode>& GetIMusicPlayerShuffleModeEnum();
}

#endif  // __MURL_I_MUSIC_PLAYER_CONTROL_H__

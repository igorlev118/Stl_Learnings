// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_SOUND_FADER_H__
#define __MURL_LOGIC_SOUND_FADER_H__

#include "murl_logic_animation.h"
#include "murl_logic_graph_sound_object.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Animation class for fading the volume of a GraphSoundObject.
         */
        class SoundFader : public AnimationReal
        {
        public:
            /**
             * @brief Create a SoundFader object.
             * @return The SoundFader shared pointer.
             */
            static SoundFaderPtr Create()
            {
                SoundFaderPtr ret = SoundFaderPtr(new SoundFader());
                ret->mSelf = ret;
                return ret;
            }

            /**
             * @brief Create a SoundFader object taking a GraphSoundObject.
             * Use Logic::GraphSoundObject::Create() to create the shared pointer.
             * @param soundObject The GraphSoundObject shared pointer.
             * @return The SoundFader shared pointer.
             */
            static SoundFaderPtr Create(GraphSoundObjectPtr soundObject)
            {
                SoundFaderPtr ret = SoundFaderPtr(new SoundFader(soundObject));
                ret->mSelf = ret;
                return ret;
            }

            /**
             * @brief The default constructor.
             * Allocates a new GraphSoundObject.
             */
            SoundFader()
            : mSound(new GraphSoundObject)
            , mPause(false)
            {
                AddKey(Real(0.0), Real(0.0), IEnums::INTERPOLATION_EASE_IN_OUT);
                AddKey(Real(0.5), Real(1.0));
            }

            /**
             * @brief The constructor taking a GraphSoundObject shared pointer.
             * Use Logic::GraphSoundObject::Create() to create the shared pointer.
             * @param soundObject The GraphSoundObject shared pointer.
             */
            SoundFader(GraphSoundObjectPtr soundObject)
            : mSound(soundObject)
            , mPause(false)
            {
                AddKey(Real(0.0), Real(0.0), IEnums::INTERPOLATION_EASE_IN_OUT);
                AddKey(Real(0.5), Real(1.0));
            }

            /**
             * @brief The destructor.
             */
            virtual ~SoundFader()
            {
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param root The graph root node.
             * @param timelinePath The full path to the graph timeline node instance.
             * @param sequencePath The full path to the graph audio sequence node instance.
             * @param index The index of the instance.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, const Graph::IRoot* root,
                              const String& timelinePath, const String& sequencePath, SInt32 index)
            {
                if (!mSound->Init(nodeObserver, root, timelinePath, sequencePath, index))
                {
                    return false;
                }

                return true;
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param namespaceNode The logic namespace node.
             * @param timelinePath The full path to the graph timeline node instance.
             * @param sequencePath The full path to the graph audio sequence node instance.
             * @param index The index of the instance.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INamespace* namespaceNode,
                              const String& timelinePath, const String& sequencePath, SInt32 index)
            {
                if (!mSound->Init(nodeObserver, namespaceNode, timelinePath, sequencePath, index))
                {
                    return false;
                }

                return true;
            }

            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit()
            {
                Bool ret = true;

                if (!mSound->DeInit())
                {
                    ret = false;
                }

                return ret;
            }

            /**
             * @brief Start and fade in the sound.
             * @param resume If true resume playing the sound, otherwise restart the sound.
             */
            virtual void FadeIn(Bool resume = false)
            {
                if (resume)
                {
                    if (mSound->mTimelineNode->IsPaused())
                    {
                        mSound->ContinuePlaying();
                    }
                    else
                    {
                        mSound->StartPlaying();
                    }
                }
                else
                {
                    mSound->StartPlaying();
                }
                StartForward();
            }

            /**
             * @brief Fade out the sound.
             * @param pause If true pause the sound after fade out, otherwise stop the sound.
             */
            virtual void FadeOut(Bool pause = false)
            {
                mPause = pause;
                StartBackward();
            }

            /**
             * @brief Set the fading duration.
             * @param duration The fading duration in seconds.
             * @return true if successful.
             */
            virtual Bool SetDuration(Real duration)
            {
                if (mKeys.GetCount() > 1)
                {
                    mKeys[1].mTime = duration;
                    return true;
                }
                return false;
            }

            /**
             * @brief Get the fading duration.
             * @return The fading duration in seconds.
             */
            virtual Real GetDuration() const
            {
                if (mKeys.GetCount() > 1)
                {
                    return mKeys[1].mTime;
                }
                return Real(0.0);
            }

            /**
             * @brief Set the start volume.
             * @param volume The volume in range [0.0 .. 1.0].
             * @return true if successful.
             */
            virtual Bool SetStartVolume(Real volume)
            {
                if (mKeys.GetCount() > 0)
                {
                    mKeys[0].mValue = volume;
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the end volume.
             * @param volume The volume in range [0.0 .. 1.0].
             * @return true if successful.
             */
            virtual Bool SetEndVolume(Real volume)
            {
                if (mKeys.GetCount() > 1)
                {
                    mKeys[1].mValue = volume;
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the start and end volume.
             * @param startVolume The start volume in range [0.0 .. 1.0].
             * @param endVolume The end volume in range [0.0 .. 1.0].
             * @return true if successful.
             */
            virtual Bool SetVolume(Real startVolume, Real endVolume)
            {
                if (mKeys.GetCount() > 1)
                {
                    mKeys[0].mValue = startVolume;
                    mKeys[1].mValue = endVolume;
                    return true;
                }
                return false;
            }

            /**
             * @brief Get the start volume.
             * @return The start volume.
             */
            virtual Real GetStartVolume() const
            {
                if (mKeys.GetCount() > 0)
                {
                    return mKeys[0].mValue;
                }
                return Real(0.0);
            }

            /**
             * @brief Get the end volume.
             * @return The end volume.
             */
            virtual Real GetEndVolume() const
            {
                if (mKeys.GetCount() > 1)
                {
                    return mKeys[1].mValue;
                }
                return Real(0.0);
            }

            /** @brief The GraphSoundObject shared pointer. */
            GraphSoundObjectPtr mSound;

            /**
             * @brief Overwrite of the Animation::Reset() method.
             * Reset the animation and stop playing.
             */
            virtual void Reset()
            {
                AnimationReal::Reset();
                mSound->StopPlaying();
            }

        protected:

            /**
             * @brief Overwrite of the Animation::OnEvaluateAnimation() method.
             * Set the volume to the current value and stop playing
             * if fade out was finished.
             * @param currentValue The current value.
             */
            virtual void OnEvaluateAnimation(const Real& currentValue)
            {
                mSound->SetVolume(currentValue);
                if (WasRunning())
                {
                    if (mKeys.GetCount() > 0)
                    {
                        if (GetCurrentTime() == mKeys[0].mTime)
                        {
                            if (mPause)
                            {
                                mSound->PausePlaying();
                            }
                            else
                            {
                                mSound->StopPlaying();
                            }
                        }
                    }
                }
            }

            /** The pause on stop state. */
            Bool mPause;
        };
    }
}

#endif  // __MURL_LOGIC_SOUND_FADER_H__

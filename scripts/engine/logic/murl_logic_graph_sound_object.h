// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_SOUND_OBJECT_H__
#define __MURL_LOGIC_GRAPH_SOUND_OBJECT_H__

#include "murl_logic_base_node_observer.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Class handling the play state and volume of a Graph::ITimelineNode
         * which is enclosing a Graph::IAudioSequenceNode node.
         *
         * e.g.
         * @code
         *  <Graph numberOfLoops="0" volume="1.0">
         *      <Namespace id="{soundId}">
         *          <Timeline id="timeline" autoRewind="yes" numberOfLoops="{numberOfLoops}">
         *              <AudioSource id="sound" audioResourceId="{package}:{soundId}"/>
         *              <AudioSequence id="sequence" audioSourceIds="sound" volume="{volume}"/>
         *          </Timeline>
         *      </Namespace>
         *  </Graph>
         * @endcode
         */
        class GraphSoundObject
        {
        public:
            /**
             * @brief Create a GraphSoundObject object.
             * The default master volume is 1.0.
             * @return The GraphSoundObject shared pointer.
             */
            static GraphSoundObjectPtr Create()
            {
                return GraphSoundObjectPtr(new GraphSoundObject());
            }

            /**
             * @brief Create a GraphSoundObject object with a given master volume.
             * @param masterVolume The master volume in range [0.0 .. 1.0].
             * @return The GraphSoundObject shared pointer.
             */
            static GraphSoundObjectPtr Create(Real masterVolume)
            {
                return GraphSoundObjectPtr(new GraphSoundObject(masterVolume));
            }

            /**
             * @brief The default constructor.
             * The default master volume is 1.0.
             */
            GraphSoundObject()
            : mMasterVolume(Real(1.0))
            {
            }

            /**
             * @brief Constructor taking a master volume.
             * @param masterVolume The master volume in range [0.0 .. 1.0].
             */
            GraphSoundObject(Real masterVolume)
            : mMasterVolume(masterVolume)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~GraphSoundObject()
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
                return Init(nodeObserver, root->GetRootNamespace(), timelinePath, sequencePath, index);
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param namespaceNode The graph namespace node.
             * @param timelinePath The relative path to the graph timeline node instance.
             * @param sequencePath The relative path to the graph audio sequence node instance.
             * @param index The index of the instance.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INamespace* namespaceNode,
                              const String& timelinePath, const String& sequencePath, SInt32 index)
            {
                nodeObserver->Add(mTimelineNode.GetReference(namespaceNode, timelinePath));
                nodeObserver->Add(mAudioSequenceNode.GetReference(namespaceNode, sequencePath));
                if (!mTimelineNode.IsValid() || !mAudioSequenceNode.IsValid())
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
                StopPlaying();
                return ret;
            }

            /**
             * @brief Start playing the sound.
             * @param startTime The start time in seconds.
             * @return true if successful.
             */
            virtual Bool StartPlaying(Real startTime = 0)
            {
                if (mTimelineNode.IsValid() && mAudioSequenceNode.IsValid())
                {
                    if (mAudioSequenceNode->IsEndlessLoopEnabled())
                    {
                        return mTimelineNode->Start(startTime, Math::Limits<Real>::Infinity());
                    }
                    else
                    {
                        return mTimelineNode->Start(startTime, mAudioSequenceNode->GetTotalDuration());
                    }
                }
                return false;
            }

            /**
             * @brief Start playing the sound.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool StartPlaying(Real startTime, Real endTime)
            {
                if (mTimelineNode.IsValid() && mAudioSequenceNode.IsValid())
                {
                    return mTimelineNode->Start(startTime, endTime);
                }
                return false;
            }

            /**
             * @brief Check if the sound is playing.
             * @return true if the sound is playing.
             */
            virtual Bool IsPlaying() const
            {
                if (mTimelineNode.IsValid())
                {
                    return mTimelineNode->IsRunning();
                }
                return false;
            }

            /**
             * @brief Pause playing the sound.
             * @return true successful.
             */
            virtual Bool PausePlaying()
            {
                if (mTimelineNode.IsValid())
                {
                    return mTimelineNode->Pause();
                }
                return false;
            }

            /**
             * @brief Continue playing the sound.
             * Continue if the sound is paused, otherwise start the sound.
             * @return true successful.
             */
            virtual Bool ContinuePlaying()
            {
                if (mTimelineNode.IsValid())
                {
                    if (mTimelineNode->IsPaused())
                    {
                        return mTimelineNode->Start();
                    }
                    else
                    {
                        return StartPlaying();
                    }
                }
                return false;
            }

            /**
             * @brief Stop playing the sound.
             * @return true successful.
             */
            virtual Bool StopPlaying()
            {
                if (mTimelineNode.IsValid())
                {
                    if (mTimelineNode->Stop())
                    {
                        mTimelineNode->Reset();
                        return true;
                    }
                }
                return false;
            }

            /**
             * @brief Set the sound volume.
             * The sound volume is multiplied by the master volume.
             * @param volume The volume in range [0.0 .. 1.0].
             */
            virtual void SetVolume(Real volume)
            {
                if (mAudioSequenceNode.IsValid())
                {
                    mAudioSequenceNode->SetVolume(volume * mMasterVolume);
                }
            }

            /**
             * @brief Set the master volume.
             * @param volume The master volume in range [0.0 .. 1.0].
             */
            virtual void SetMasterVolume(Real volume)
            {
                mMasterVolume = volume;
            }

            /**
             * @brief Get the master volume.
             * @return The master volume.
             */
            virtual Real GetMasterVolume() const
            {
                return mMasterVolume;
            }

            /** @brief The timeline node reference. */
            TimelineNode mTimelineNode;
            /** @brief The audio sequence node reference. */
            AudioSequenceNode mAudioSequenceNode;

        protected:
            Real mMasterVolume;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_SOUND_OBJECT_H__

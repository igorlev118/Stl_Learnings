// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_OBJECT_H__
#define __MURL_AUDIO_OBJECT_H__

#include "murl_audio_i_object.h"

namespace Murl
{
    namespace Audio
    {
        class Renderer;
        class State;

        /**
         * @ingroup MurlAudioObjectClasses
         * @brief The abstract base class for an audio renderer object.
         * Use this class to derive any custom audio renderer objects from.
         */
        class Object : public IObject
        {
            MURL_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(Murl::Audio::Object)
            
        public:
            virtual IObject* GetObjectInterface();
            virtual const IObject* GetObjectInterface() const;

            virtual Bool SetInitiallySuspended(Bool suspended);
            virtual Bool SetAutomaticallySuspendableEnabled(Bool enabled);
            virtual Bool SetManuallySuspendableEnabled(Bool enabled);

            virtual Bool Init();
            virtual Bool DeInit();

            virtual Bool Suspend();
            virtual Bool Resume();

            virtual Bool Evict();

            virtual Bool Update(Real localTime);

            virtual Bool IsInitialized() const;
            virtual Bool IsSuspended() const;

            virtual UInt32 GetRecentFrameCount() const;

        protected:
            enum ObjectFlags
            {
                OBJECT_FLAG_INITIALIZED                 = (1 << 0),
                OBJECT_FLAG_SUSPENDED                   = (1 << 1),

                OBJECT_FLAG_AUTOMATICALLY_SUSPENDABLE   = (1 << 8),
                OBJECT_FLAG_MANUALLY_SUSPENDABLE        = (1 << 9),
            };

            Object(IRenderer* renderer);
            virtual ~Object();

            virtual Bool InitResources();
            virtual Bool DeInitResources();

            virtual Bool SuspendResources();
            virtual Bool ResumeResources();

            virtual Bool EvictResources();

            UInt32 mObjectFlags;
            UInt32 mRecentFrameCount;

            IRenderer* mRenderer;
            State* mState;

            friend class Renderer;
        };
    }
}

#endif // __MURL_AUDIO_OBJECT_H__

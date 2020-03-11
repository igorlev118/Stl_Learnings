// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_RENDERER_REGISTRY_H__
#define __MURL_AUDIO_I_RENDERER_REGISTRY_H__

#include "murl_audio_i_object.h"

namespace Murl
{
    namespace Audio
    {
        /**
         * @ingroup MurlAudioRendererInterfaces
         * @interface IRendererRegistry
         * The IRendererRegistry interface provides methods to add, remove and query different
         * audio renderer objects that can be instantiated using the Audio::IRenderer implementing
         * this interface.
         */
        class IRendererRegistry
        {
        public:
            /**
             * @brief Register an object class.
             * @param classInfo The ClassInfo structure of the object to register.
             * @return true if successful.
             */
            virtual Bool RegisterObjectClass(const IObject::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered object class.
             * @param classInfo The ClassInfo structure of the object to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterObjectClass(const IObject::ClassInfo& classInfo) = 0;

            /**
             * @brief Query the index of a registered object class, by its ClassInfo structure.
             * @param classInfo The class info structure of the object class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredObjectClassInfoIndex(const IObject::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered object class, by its class name.
             * @param className The name of the object class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredObjectClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered object classes.
             * @return The number of registered object classes.
             */
            virtual UInt32 GetNumberOfRegisteredObjectClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered object class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredObjectClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IObject::ClassInfo* GetRegisteredObjectClassInfo(UInt32 index) const = 0;

        protected:
            virtual ~IRendererRegistry() {}
        };
    }
}

#endif // __MURL_AUDIO_I_RENDERER_REGISTRY_H__

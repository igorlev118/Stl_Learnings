// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_BONE_H__
#define __MURL_VIDEO_I_BONE_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IBone
         * @brief The IBone video object interface.
         * This interface represents a single bone of a skeleton used for 
         * vertex skinning.
         *
         * Used internally by Graph::Bone.
         */
        class IBone
        {
        public:
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Enable the bone at a given unit.
             * @param unit The bone unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Enable(UInt32 unit) = 0;
            /**
             * @brief Disable the bone at a given unit.
             * @param unit The bone unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Disable(UInt32 unit) = 0;

            /**
             * @brief Attach the bone to the current GPU program at a given unit.
             * @param currentProgram The current GPU program.
             * @param unit The bone unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, UInt32 unit) = 0;

            /**
             * @brief Get the actual bone transform matrix.
             * The returned matrix is the result of the matrix multiplication of
             * world and offset transform.
             * @return The actual bone transform.
             */
            virtual const Matrix& GetTransform() const = 0;

            /**
             * @brief Set the bone's current world transform.
             * @param transform The world transform.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& transform) = 0;
            /**
             * @brief Get the bone's current world transform.
             * @return The world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;

            /**
             * @brief Set the bone's offset transform.
             * @param transform The offset transform.
             * @return true if successful.
             */
            virtual Bool SetOffsetTransform(const Matrix& transform) = 0;
            /**
             * @brief Get the bone's offset transform.
             * @return The offset transform.
             */
            virtual const Matrix& GetOffsetTransform() const = 0;
            
        protected:
            virtual ~IBone() {}
        };
    }
}

#endif // __MURL_VIDEO_I_BONE_H__

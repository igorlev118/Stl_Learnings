// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_VIEW_H__
#define __MURL_VIDEO_I_VIEW_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IFrameBuffer;
        class IProgram;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IView
         * @brief The IView video object interface.
         * This interface represents a viewport used for rendering a scene.
         *
         * Used internally by Graph::View.
         */
        class IView
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
             * @brief Enable the view.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the view.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;

            /**
             * @brief Attach the view to the current GPU program.
             * @param currentProgram The current GPU program.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram) = 0;

            /**
             * @brief Set the view's absolute depth order.
             * @param depthOrder The absolute order of this view within its render target.
             * @return true if successful.
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the view's absolute depth order.
             * @return The absolute order of this view within its render target.
             */
            virtual SInt32 GetDepthOrder() const = 0;
            
            /**
             * @brief Set the view mask.
             * @param x1 The left mask coordinate in pixels.
             * @param y1 The bottom mask coordinate in pixels.
             * @param x2 The right mask coordinate in pixels.
             * @param y2 The top mask coordinate in pixels.
             * @return true if successful.
             */
            virtual Bool SetMask(SInt32 x1, SInt32 x2, SInt32 y1, SInt32 y2) = 0;
            /**
             * @brief Get the view mask's left border coordinate.
             * @return The left mask coordinate in pixels.
             */
            virtual SInt32 GetMaskX1() const = 0;
            /**
             * @brief Get the view mask's right border coordinate.
             * @return The right mask coordinate in pixels.
             */
            virtual SInt32 GetMaskX2() const = 0;
            /**
             * @brief Get the view mask's bottom border coordinate.
             * @return The bottom mask coordinate in pixels.
             */
            virtual SInt32 GetMaskY1() const = 0;
            /**
             * @brief Get the view mask's top border coordinate.
             * @return The top mask coordinate in pixels.
             */
            virtual SInt32 GetMaskY2() const = 0;

            /**
             * @brief Set the view frame buffer.
             * @param frameBuffer The frame buffer to use, or null if rendering to the back buffer.
             * @return true if successful.
             */
            virtual Bool SetFrameBuffer(IFrameBuffer* frameBuffer) = 0;
            /**
             * @brief Get the view frame buffer.
             * @return The frame buffer used, or null if rendering to the back buffer.
             */
            virtual IFrameBuffer* GetFrameBuffer() const = 0;

        protected:
            virtual ~IView() {}
        };
    }
}

#endif // __MURL_VIDEO_I_VIEW_H__

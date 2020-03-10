// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_TOUCHABLE_HANDLER_H__
#define __MURL_INPUT_I_TOUCHABLE_HANDLER_H__

#include "murl_i_enums.h"
#include "murl_input_types.h"
#include "murl_graph_types.h"

namespace Murl
{
    namespace Input
    {
        class IMouseButtons;
        class ITouchArea;
        class IProjection;
        class IScreenArea;
        
        /**
         * @ingroup MurlInputInterfaces
         * @interface ITouchableHandler
         * @brief The ITouchableHandler interface.
         * The touchable handler is used by Graph::ICamera and Graph::IButton to track the
         * input positions and buttons on the display surface depending on the scene graph.
         */
        class ITouchableHandler
        {
        public:
            /**
             * @brief Initialize the touchable handler.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the touchable handler.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Create a screen area object.
             * @return The created screen area object
             */
            virtual IScreenArea* CreateScreenArea() = 0;
            /**
             * @brief Destroy a screen area object.
             * @param screenArea A reference to the screen area object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyScreenArea(IScreenArea*& screenArea) = 0;
            
            /**
             * @brief Create a projection object.
             * @return The created projection object
             */
            virtual IProjection* CreateProjection() = 0;
            /**
             * @brief Destroy a projection object.
             * @param screenProjection A reference to the projection object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyProjection(IProjection*& screenProjection) = 0;
            
            /**
             * @brief Create a touch area object.
             * @param type The kind of touch area to create.
             * @return The created touch area object
             */
            virtual ITouchArea* CreateTouchArea(IEnums::TouchAreaShape type) = 0;
            /**
             * @brief Destroy a touch area object.
             * @param touchArea A reference to the touch area pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyTouchArea(ITouchArea*& touchArea) = 0;
            
            /**
             * @brief Reset all screen projections.
             * @return true if successful.
             */
            virtual Bool Reset() = 0;
            
            /**
             * @brief Set the current transformation.
             * @param transform The current transformation matrix.
             * @param depthOrder The current depth order.
             * @return true if successful.
             */
            virtual Bool SetCurrentTransform(const Matrix* transform, SInt32 depthOrder) = 0;
            /**
             * @brief Set the current layer.
             * @param layer The current layer.
             * @return true if successful.
             */
            virtual Bool SetCurrentLayer(UInt32 layer) = 0;
            
            /**
             * @brief Add and set the current projection.
             * @param projection The current projection to add or null.
             * @param screenArea The screen area the projection belongs to, or null for default.
             * @return true if successful, false if null is added.
             */
            virtual Bool AddCurrentProjection(IProjection* projection, IScreenArea* screenArea) = 0;
            /**
             * @brief Add a touch area to the current screen projection
             * considering the current tansformation, depth order and layer.
             * @param touchArea The touch area to add.
             * @param subScreenArea The optional screen area to delegate input to, or null if
             *      no delegation is desired.
             * @return true if successful.
             */
            virtual Bool AddTouchArea(ITouchArea* touchArea, IScreenArea* subScreenArea) = 0;
            
            /**
             * @brief Begin reporting device inputs.
             * @return true if successful.
             */
            virtual Bool ReportBegin() = 0;
            /**
             * @brief Report a device input.
             * @param deviceType The device type.
             * @param deviceId The device identifier.
             * @param hasUpdate true if the device has received new data since the last report.
             * @param buttons The mouse buttons interface.
             * @param posX The device x-position on the display surface.
             * @param posY The device y-position on the display surface.
             * @param inRangeX true if posX was not clamped to the window area.
             * @param inRangeY true if posY was not clamped to the window area.
             * @param moved true if the device was moved.
             * @param cancelled true if the device input was cancelled.
             * @return true if successful.
             */
            virtual Bool ReportDevice(IEnums::InputDeviceType deviceType,
                                      UInt32 deviceId, Bool hasUpdate, const IMouseButtons* buttons,
                                      Real posX, Real posY,
                                      Bool inRangeX, Bool inRangeY,
                                      Bool moved, Bool cancelled) = 0;
            /**
             * @brief End reporting device inputs.
             * @return true if successful.
             */
            virtual Bool ReportEnd() = 0;
            
        protected:
            virtual ~ITouchableHandler() {}
        };
    }
}

#endif  // __MURL_INPUT_I_TOUCHABLE_HANDLER_H__

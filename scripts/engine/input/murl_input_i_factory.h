// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_FACTORY_H__
#define __MURL_INPUT_I_FACTORY_H__

#include "murl_input_types.h"

namespace Murl
{
    class IPlatform;
    
    namespace Input
    {
        class IDeviceHandler;
        class ITouchableHandler;
        
        /**
         * @ingroup MurlInputInterfaces
         * @interface IFactory
         * @brief The Factory to create input classes.
         */
        class IFactory
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Create the device handler object.
             * @param platform A pointer to the platform.
             * @return The created device handler object, or null if failed.
             */
            virtual IDeviceHandler* CreateDeviceHandler(IPlatform* platform) = 0;
            
            /**
             * @brief Destroy the device handler object.
             * @param deviceHandler A reference to the device handler pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyDeviceHandler(IDeviceHandler*& deviceHandler) = 0;
            
            /**
             * @brief Create the touchable handler object.
             * @param platform A pointer to the platform.
             * @return The created touchable handler object, or null if failed.
             */
            virtual ITouchableHandler* CreateTouchableHandler(IPlatform* platform) = 0;
            
            /**
             * @brief Destroy the touchable handler object.
             * @param touchableHandler A reference to the touchable handler pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyTouchableHandler(ITouchableHandler*& touchableHandler) = 0;
            
        protected:
            /**
             * @brief The destructor.
             */
            virtual ~IFactory() {}
        };
        
        /**
         * @ingroup MurlInputClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the input factory object.
             * @return The created input factory object, or null if failed.
             */
            static IFactory* CreateFactory();
            /**
             * @brief Destroy the input factory object.
             * @param factory A reference to the input factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_INPUT_I_FACTORY_H__

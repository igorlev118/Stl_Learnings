// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_GAME_CONTROLLER_MAPPING_H__
#define __MURL_I_GAME_CONTROLLER_MAPPING_H__

#include "murl_i_enums.h"
#include "murl_shared_array.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IGameControllerMapping
     * @brief The game controller mapping interface.
     *  The IGameControllerMapping interface can be accessed by the
     *  Logic::IDeviceHandler::GetGameControllerMapping() method or
     *  the Input::IGameControllerDevice::GetMapping() method.\n
     *  The RawData is supplied directly from the controller device
     *  and can be used to create an interactive mapping setup.\n
     *  Use GetRawData() to determine the raw data on the game controller,
     *  afterwards use SetRawMapping() to setup a corresponding mapping.\n
     *  Use Logic::IDeviceHandler::GetGameControllerDeviceInfo() or
     *  Input::IGameControllerDevice::GetDeviceInfo() to identify the controller.
     */
    class IGameControllerMapping
    {
    public:
        /**
         * @brief Device information data.
         */
        class DeviceInfo
        {
        public:
            /**
             * @brief The default constructor.
             */
            DeviceInfo()
            : mVendorId(0)
            , mProductId(0)
            {
            }

            /**
             * @brief The vendor identifier.
             */
            UInt32 mVendorId;
            /**
             * @brief The product identifier.
             */
            UInt32 mProductId;
            /**
             * @brief The device name.
             */
            String mName;
            /**
             * @brief The product name.
             */
            String mProductName;
        };

        /**
         * @brief Definition of raw data axis types.
         */
        enum AxisType
        {
            /** The raw data's x-axis. */
            AXIS_X,
            /** The raw data's y-axis. */
            AXIS_Y,
            /** The raw data's z-axis. */
            AXIS_Z,
            /** The raw data's right x-axis. */
            AXIS_RX,
            /** The raw data's right y-axis. */
            AXIS_RY,
            /** The raw data's right z-axis. */
            AXIS_RZ
        };

        /**
         * @brief The raw axis data.
         */
        class AxisRawData
        {
        public:
            /**
             * @brief The default constructor.
             */
            AxisRawData()
            : mAxisType()
            , mValue(0)
            {
            }
            /**
             * @brief Constructor taking initialization values.
             * @param axisType The axis type.
             * @param value The axis raw value.
             * The axis raw value range is [-1.0 .. 1.0].
             */
            AxisRawData(AxisType axisType, Float value)
            : mAxisType(axisType)
            , mValue(value)
            {
            }

            /**
             * @brief The axis type.
             */
            AxisType mAxisType;
            /**
             * @brief The axis raw value.
             * The axis raw value range is [-1.0 .. 1.0].
             */
            Float mValue;

            /**
             * @brief The "equal to" comparison operator.
             * @param rhs The right hand side raw axis data to compare.
             * @return true if all members are exactly the same.
             */
            bool operator==(const AxisRawData& rhs) const
            {
                return (mAxisType == rhs.mAxisType) && (mValue == rhs.mValue);
            }
            /**
             * @brief The "not equal to" comparison operator.
             * @param rhs The right hand side raw axis data to compare.
             * @return true if the objects differ.
             */
            bool operator!=(const AxisRawData& rhs) const
            {
                return !((mAxisType == rhs.mAxisType) && (mValue == rhs.mValue));
            }
        };

        /**
         * @brief Definition of an array holding AxisRawData values.
         */
        typedef SharedArray<AxisRawData> AxisRawDataArray;

        /**
         * @brief The game controller raw data.
         * A collection of all game controller raw data.
         */
        class RawData
        {
        public:
            /**
             * @brief The axis raw data array.
             */
            AxisRawDataArray mAxis;
            /**
             * @brief The buttons raw data.
             * The button raw data is false (released) or true (pressed).
             */
            SharedArray<Bool> mButtons;
            /**
             * @brief The point of view raw data.
             * The point of view raw data range is [0.0 .. 360.0).
             */
            SharedArray<Float> mPovs;
        };

        /**
         * @brief Get the current raw data.
         * @param rawData The raw data return value.
         * @return true if successful.
         */
        virtual Bool GetRawData(RawData& rawData) const = 0;

        /**
         * @brief Set the current raw data.
         * Automatically posts the game controller's events based on the raw data and mapping.\n
         * This is typically used by the device implementation only.
         * @param rawData The raw data to set.
         * @return true if successful.
         */
        virtual Bool SetRawData(const RawData& rawData) = 0;

        /**
         * @brief Definition of axis events.
         */
        enum AxisEvent
        {
            /** No axis. */
            AXIS_EVENT_NONE = 0,

            /** Left stick x-axis. The range is [-1.0 left .. 1.0 right] */
            AXIS_EVENT_LEFT_STICK_X,
            /** Left stick y-axis. The range is [-1.0 bottom .. 1.0 top] */
            AXIS_EVENT_LEFT_STICK_Y,

            /** Right stick x-axis. The range is [-1.0 left .. 1.0 right] */
            AXIS_EVENT_RIGHT_STICK_X,
            /** Right stick y-axis. The range is [-1.0 bottom .. 1.0 top] */
            AXIS_EVENT_RIGHT_STICK_Y,

            /** Left shoulder button (1st row) value. The range is [0.0 not pressed .. 1.0 full pressed]. */
            AXIS_EVENT_L1_BUTTON,
            /** Right shoulder button (1st row) value. The range is [0.0 not pressed .. 1.0 full pressed]. */
            AXIS_EVENT_R1_BUTTON,

            /** Left shoulder button (2nd row) value. The range is [0.0 not pressed .. 1.0 full pressed]. */
            AXIS_EVENT_L2_BUTTON,
            /** Right shoulder button (2nd row) value. The range is [0.0 not pressed .. 1.0 full pressed]. */
            AXIS_EVENT_R2_BUTTON,

            NUM_AXIS_EVENTS
        };

        /**
         * @brief The raw axis mapping.
         * Describes how to map the axis raw data to a game controller axis event.
         */
        class AxisMapping
        {
        public:
            /**
             * @brief The default constructor.
             */
            AxisMapping()
            : mAxisType()
            , mRangeStart(0)
            , mRangeEnd(0)
            , mDestinationEvent(AXIS_EVENT_NONE)
            {
            }
            /**
             * @brief Constructor taking initialization values.
             * @param axisType The axis type to read the raw value from.
             * @param rangeStart The axis raw data range start value.
             *  Represents the raw data value for the lowest destination value.
             * @param rangeEnd The axis raw data range end value.
             *  Represents the raw data value for the highest destination value.
             * @param destinationEvent The destination axis event to post the scaled axis value.
             */
            AxisMapping(AxisType axisType, Float rangeStart, Float rangeEnd, AxisEvent destinationEvent)
            : mAxisType(axisType)
            , mRangeStart(rangeStart)
            , mRangeEnd(rangeEnd)
            , mDestinationEvent(destinationEvent)
            {
            }

            /**
             * @brief The axis type to read the raw value from.
             */
            AxisType mAxisType;
            /**
             * @brief The axis raw data range start value.
             * Represents the raw data value for the lowest destination value.
             */
            Float mRangeStart;
            /**
             * @brief The axis raw data range end value.
             * Represents the raw data value for the highest destination value.
             */
            Float mRangeEnd;
            /**
             * @brief The destination axis event to post the scaled axis value.
             */
            AxisEvent mDestinationEvent;

            /**
             * @brief The "equal to" comparison operator.
             * @param rhs The right hand side raw axis mapping to compare.
             * @return true if all members are exactly the same.
             */
            bool operator==(const AxisMapping& rhs) const
            {
                return ((mAxisType == rhs.mAxisType) &&
                        (mRangeStart == rhs.mRangeStart) &&
                        (mRangeEnd == rhs.mRangeEnd) &&
                        (mDestinationEvent == rhs.mDestinationEvent));
            }
            /**
             * @brief The "not equal to" comparison operator.
             * @param rhs The right hand side raw axis mapping to compare.
             * @return true if the objects differ.
             */
            bool operator!=(const AxisMapping& rhs) const
            {
                return !((mAxisType == rhs.mAxisType) &&
                         (mRangeStart == rhs.mRangeStart) &&
                         (mRangeEnd == rhs.mRangeEnd) &&
                         (mDestinationEvent == rhs.mDestinationEvent));
            }
        };

        /**
         * @brief The button mapping.
         * Describes how to map the button raw data to a game controller button.
         */
        class ButtonMapping
        {
        public:
            /**
             * @brief The default constructor.
             */
            ButtonMapping()
            : mButtonIndex(0)
            , mDestinationButton()
            {
            }
            /**
             * @brief Constructor taking initialization values.
             * @param buttonIndex The button index to read the raw button value from.
             * @param destinationButton The destination button to post the button state.
             */
            ButtonMapping(UInt32 buttonIndex, IEnums::GameControllerButton destinationButton)
            : mButtonIndex(buttonIndex)
            , mDestinationButton(destinationButton)
            {
            }

            /**
             * @brief The button index to read the raw button value from.
             */
            UInt32 mButtonIndex;
            /**
             * @brief The destination button to post the button state.
             */
            IEnums::GameControllerButton mDestinationButton;

            /**
             * @brief The "equal to" comparison operator.
             * @param rhs The right hand side button mapping to compare.
             * @return true if all members are exactly the same.
             */
            bool operator==(const ButtonMapping& rhs) const
            {
                return ((mButtonIndex == rhs.mButtonIndex) &&
                        (mDestinationButton == rhs.mDestinationButton));
            }
            /**
             * @brief The "not equal to" comparison operator.
             * @param rhs The right hand side button mapping to compare.
             * @return true if the objects differ.
             */
            bool operator!=(const ButtonMapping& rhs) const
            {
                return !((mButtonIndex == rhs.mButtonIndex) &&
                         (mDestinationButton == rhs.mDestinationButton));
            }
        };

        /**
         * @brief The point of view mapping.
         * Describes how to map the pov raw data to a game controller button.
         */
        class PovMapping
        {
        public:
            /**
             * @brief The default constructor.
             */
            PovMapping()
            : mPovIndex(0)
            , mRangeStart(0)
            , mRangeEnd(0)
            , mDestinationButton()
            {
            }
            /**
             * @brief Constructor taking initialization values.
             * @param povIndex The pov index to read the raw pov value from.
             * @param rangeStart The pov raw data range start value (excluding).
             * @param rangeEnd The pov raw data range end value (excluding).
             * @param destinationButton The destination button to post if the
             *  raw pov value is in range.
             */
            PovMapping(UInt32 povIndex, Float rangeStart, Float rangeEnd,
                       IEnums::GameControllerButton destinationButton)
            : mPovIndex(povIndex)
            , mRangeStart(rangeStart)
            , mRangeEnd(rangeEnd)
            , mDestinationButton(destinationButton)
            {
            }

            /**
             * @brief The pov index to read the raw pov value from.
             */
            UInt32 mPovIndex;
            /**
             * @brief The pov raw data range start value (excluding).
             */
            Float mRangeStart;
            /**
             * @brief The pov raw data range end value (excluding).
             */
            Float mRangeEnd;
            /**
             * @brief The destination button to post if the raw pov value is in range.
             */
            IEnums::GameControllerButton mDestinationButton;

            /**
             * @brief The "equal to" comparison operator.
             * @param rhs The right hand side point of view mapping to compare.
             * @return true if all members are exactly the same.
             */
            bool operator==(const PovMapping& rhs) const
            {
                return ((mPovIndex == rhs.mPovIndex) &&
                        (mRangeStart == rhs.mRangeStart) &&
                        (mRangeEnd == rhs.mRangeEnd) &&
                        (mDestinationButton == rhs.mDestinationButton));
            }
            /**
             * @brief The "not equal to" comparison operator.
             * @param rhs The right hand side point of view mapping to compare.
             * @return true if the objects differ.
             */
            bool operator!=(const PovMapping& rhs) const
            {
                return !((mPovIndex == rhs.mPovIndex) &&
                         (mRangeStart == rhs.mRangeStart) &&
                         (mRangeEnd == rhs.mRangeEnd) &&
                         (mDestinationButton == rhs.mDestinationButton));
            }
        };

        /**
         * @brief Definition of an array holding AxisMapping values.
         */
        typedef SharedArray<AxisMapping> AxisMappingArray;

        /**
         * @brief Definition of an array holding ButtonMapping values.
         */
        typedef SharedArray<ButtonMapping> ButtonMappingArray;

        /**
         * @brief Definition of an array holding PovMapping values.
         */
        typedef SharedArray<PovMapping> PovMappingArray;

        /**
         * @brief The game controller mapping data.
         * A collection of all game controller mapping data.
         */
        class RawMapping
        {
        public:
            /**
             * @brief The axis mappings array.
             */
            AxisMappingArray mAxis;
            /**
             * @brief The button mappings array.
             */
            ButtonMappingArray mButtons;
            /**
             * @brief The point of view mappings array.
             */
            PovMappingArray mPovs;
        };

        /**
         * @brief Get the mapping data.
         * @param rawMapping The mapping data return value.
         * @return true if successful.
         */
        virtual Bool GetRawMapping(RawMapping& rawMapping) const = 0;

        /**
         * @brief Set the mapping data.
         * Automatically sets the game controller's available controls based on the raw mapping.
         * @param rawMapping The mapping data to set.
         * @return true if successful.
         */
        virtual Bool SetRawMapping(const RawMapping& rawMapping) = 0;
        
    protected:
        virtual ~IGameControllerMapping() {}
    };

    /** @brief The IGameControllerMapping shared pointer type. */
    typedef SharedPointer<IGameControllerMapping> IGameControllerMappingPtr;
}

#endif  // __MURL_I_GAME_CONTROLLER_MAPPING_H__

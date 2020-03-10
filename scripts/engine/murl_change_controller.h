// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_CHANGE_CONTROLLER_H__
#define __MURL_CHANGE_CONTROLLER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief Inspector for observing ChangeController classes.
     * The inspector is used by the ChangeController::WasChanged()
     * method to determine a change in the controller.
     */
    class ChangeInspector
    {
    public:
        /**
         * @brief The default constructor.
         */
        ChangeInspector()
        : mFrame(0)
        {
        }

        /**
         * @brief Check and store the current frame.
         * @param frame The current frame.
         * @return true if the frame was different.
         */
        Bool CheckFrame(UInt32 frame)
        {
            if (mFrame != frame)
            {
                mFrame = frame;
                return true;
            }
            return false;
        }

    protected:
        UInt32 mFrame;
    };

    /**
     * @ingroup MurlClasses
     * @brief The change controller template class to control changes of an object's value.
     * The change controller counts a frame at each values's change and
     * can check a frame change regarding to the ChangeInspector.
     */
    template<class DataType>
    class ChangeController
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         */
        ChangeController()
        : mFrame(0)
        , mValue()
        {
        }

        /**
         * @brief Constructor taking a default value.
         * @param value The default value.
         */
        ChangeController(const DataType& value)
        : mFrame(0)
        , mValue(value)
        {
        }

        /**
         * @brief Set a value and increment the current frame
         * if the value has been changed.
         * @param value The value to set.
         * @return true if the value has been changed.
         */
        Bool SetValue(const DataType& value)
        {
            if (!(mValue == value))
            {
                mValue = value;
                SetChanged();
                return true;
            }
            return false;
        }

        /**
         * @brief Get the current value.
         * @return The current value.
         */
        const DataType& GetValue() const
        {
            return mValue;
        }

        /**
         * @brief Check if the inspector's frame is different to
         * the controller's frame.
         * @param inspector The inspector to check.
         * @return true if the instpector's frame was dfifferent.
         */
        Bool WasChanged(ChangeInspector& inspector) const
        {
            return inspector.CheckFrame(mFrame);
        }

        /**
         * @brief Increment the current frame.
         */
        void SetChanged()
        {
            mFrame++;
        }

        /**
         * @brief Assignment operator.
         * Calls SetValue().
         * @param value The value to assign.
         * @return The object itself.
         */
        ChangeController& operator=(const DataType& value)
        {
            SetValue(value);
            return *this;
        }

        /**
         * @brief Conversion operator.
         * @return The value object.
         */
        operator const DataType&() const
        {
            return GetValue();
        }

    protected:
        UInt32 mFrame;
        DataType mValue;
    };

    /**
     * @brief A boolean change controller type.
     */
    typedef ChangeController<Bool> BoolChangeController;

    /**
     * @brief A signed 32 bit integer change controller type.
     */
    typedef ChangeController<SInt32> SInt32ChangeController;

    /**
     * @brief A string change controller type.
     */
    typedef ChangeController<String> StringChangeController;
}

#endif  // __MURL_CHANGE_CONTROLLER_H__

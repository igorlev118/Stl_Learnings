// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_TIMEFRAME_H__
#define __MURL_LOGIC_BASE_TIMEFRAME_H__

#include "murl_logic_timeframe.h"
#include "murl_logic_base_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the ITimeframe object.
         * A timeframe is created at object instantiation.
         */
        class BaseTimeframe : public Timeframe, NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             * Creates a ITimeframe object.
             */
            BaseTimeframe()
            {
            }

            /**
             * @brief The destructor.
             * Destroys the ITimeframe object.
             */
            virtual ~BaseTimeframe()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStepable interface.
             */
            operator IStepablePtr()
            {
                return GetStepable();
            }

            /**
             * @brief Conversion operator.
             * @return The ITimeframe interface.
             */
            operator ITimeframePtr()
            {
                return ITimeframePtr(this, NoDeleter());
            }
        };
    }
}

#endif  // __MURL_LOGIC_BASE_TIMEFRAME_H__

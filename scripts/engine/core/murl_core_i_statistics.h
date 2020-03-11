// Copyright 2014 Spraylight GmbH

#ifndef __MURL_CORE_I_STATISTICS_H__
#define __MURL_CORE_I_STATISTICS_H__

#include "murl_core_types.h"

namespace Murl
{
    namespace Core
    {
        /**
         * @ingroup MurlCoreClasses
         * @brief The StatisticsItem object stores a specific time value
         * in two variants: as recent exact value as well as averaged value.
         */
        class StatisticsItem
        {
        public:
            /**
             * @brief The default constructor.
             */
            StatisticsItem()
            : mRecentUSec()
            , mAveragedUSec()
            {
            }

            /**
             * @brief Addition operator.
             * @param rhs The right hand side item.
             * @return The added item.
             */
            StatisticsItem operator+(const StatisticsItem& rhs) const
            {
                StatisticsItem ret(*this);
                ret.mRecentUSec += rhs.mRecentUSec;
                ret.mAveragedUSec += rhs.mAveragedUSec;
                return ret;
            }

            /** @brief The exact time value in &micro;sec of the recent frame. */
            Double mRecentUSec;
            
            /** @brief The averaged time value in &micro;sec of the last frames (averaging factor is 0.1). */
            Double mAveragedUSec;
        };

        /**
         * @ingroup MurlCoreInterfaces
         * @interface IStatistics
         * @brief The statistics interface.
         */
        class IStatistics
        {
        public:
            /**
             * @brief Get the total time used for processing the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual StatisticsItem GetTotal() const = 0;

            /**
             * @brief Get the time used for processing ProcessGraphLogic during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetProcessGraphLogic() const = 0;

            /**
             * @brief Get the time used for processing FinishGraphLogic during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetFinishGraphLogic() const = 0;

            /**
             * @brief Get the time used for processing ProcessGraphInput during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetProcessGraphInput() const = 0;

            /**
             * @brief Get the time used for processing FinishGraphInput during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetFinishGraphInput() const = 0;

            /**
             * @brief Get the time used for processing ProcessLogicTick during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetProcessLogicTick() const = 0;

            /**
             * @brief Get the time used for processing FinishLogicTick during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetFinishLogicTick() const = 0;

            /**
             * @brief Get the time used for processing ProcessLogicFrame during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetProcessLogicFrame() const = 0;

            /**
             * @brief Get the time used for processing FinishLogicFrame during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetFinishLogicFrame() const = 0;

            /**
             * @brief Get the time used for processing GraphOutput during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetProcessGraphOutput() const = 0;

            /**
             * @brief Get the time used for processing FinishGraphOutput during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetFinishGraphOutput() const = 0;

            /**
             * @brief Get the time used for processing the simulator during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetSimulator() const = 0;

            /**
             * @brief Get the time used for processing the Video- and AudioRenderer during the last frame.
             * @return The time value in &micro;sec as StatisticsItem.
             */
            virtual const StatisticsItem& GetRenderer() const = 0;

            /**
             
             * @brief Get the system debug info message which can be configured by the Murl::IAppConfiguration::SetSystemDebugInfoItems method.
             * @return The system debug info message as String.
             */
            virtual String GetMessage() const = 0;

        protected:
            virtual ~IStatistics() {}
        };
    }
}

#endif  // __MURL_CORE_I_STATISTICS_H__

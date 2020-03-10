// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_TIMELINE_H__
#define __MURL_LOGIC_BASE_TIMELINE_H__

#include "murl_logic_timeline.h"
#include "murl_logic_base_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the ITimeline object.
         * The BaseTimeline class implements the IAppTimeline app interface.\n
         * A logic timeline is created and initialized at object instantiation.
         */
        class BaseTimeline : public IAppTimeline, public Timeline, NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             * Creates a ITimeline object and setup the timeline app interface.
             */
            BaseTimeline()
            {
                SetAppTimeline(IAppTimelinePtr(this, NoDeleter()));
            }

            /**
             * @brief The destructor.
             * Destroys the ITimeline object.
             */
            virtual ~BaseTimeline()
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
             * @return The ITimeline interface.
             */
            operator ITimelinePtr()
            {
                return ITimelinePtr(this, NoDeleter());
            }

        protected:  // IAppTimeline

            /**
             * @brief Default implementation of IAppTimeline::OnEvaluate() method,
             * this method is empty and can be overwritten.
             * @param currentTime The current timeline time.
             */
            virtual void OnEvaluate(Double currentTime)
            {
            }
        };
    }
}

#endif  // __MURL_LOGIC_BASE_TIMELINE_H__

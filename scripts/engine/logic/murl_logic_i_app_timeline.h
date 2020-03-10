// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_APP_TIMELINE_H__
#define __MURL_LOGIC_I_APP_TIMELINE_H__

#include "murl_logic_types.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicAppInterfaces
         * @interface IAppTimeline
         * @brief The IAppTimeline interface.
         * This interface is used by the ITimeline object to callback the app.
         */
        class IAppTimeline
        {
        public:
            /**
             * @brief Called if the current time is set.
             * See ITimeline::SetAppTimeline().
             * @param currentTime The current timeline time.
             */
            virtual void OnEvaluate(Double currentTime) = 0;

        protected:
            virtual ~IAppTimeline() {}
        };
    }
}

#endif // __MURL_LOGIC_I_APP_TIMELINE_H__

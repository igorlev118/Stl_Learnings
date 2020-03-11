// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_I_FACTORY_H__
#define __MURL_LOGIC_I_FACTORY_H__

#include "murl_logic_i_node_observer.h"
#include "murl_logic_i_processor.h"
#include "murl_logic_i_stage.h"
#include "murl_logic_i_stage_processor.h"
#include "murl_logic_i_stage_timeline.h"
#include "murl_logic_i_stepable.h"
#include "murl_logic_i_stepable_observer.h"
#include "murl_logic_i_timeframe.h"
#include "murl_logic_i_timeline.h"
#include "murl_logic_i_scroll_processor.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IFactory
         * @brief The IFactory interface to create logic classes.
         */
        class IFactory
        {
        public:
            /**
             * @brief Create a processor object.
             * @return The created processor object, or null if failed.
             */
            virtual IProcessorPtr CreateProcessor() = 0;
            /**
             * @brief Destroy a processor object.
             * @param processor A reference to the processor pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyProcessor(IProcessorPtr& processor) = 0;

            /**
             * @brief Create a stage object.
             * @return The created stage object, or null if failed.
             */
            virtual IStagePtr CreateStage() = 0;
            /**
             * @brief Destroy a stage object.
             * @param stage A reference to the stage pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyStage(IStagePtr& stage) = 0;

            /**
             * @brief Create a stage processor object.
             * @return The created stage processor object, or null if failed.
             */
            virtual IStageProcessorPtr CreateStageProcessor() = 0;
            /**
             * @brief Destroy a stage processor object.
             * @param stageProcessor A reference to the stage processor pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyStageProcessor(IStageProcessorPtr& stageProcessor) = 0;

            /**
             * @brief Create a stage timeline object.
             * @return The created stage timeline object, or null if failed.
             */
            virtual IStageTimelinePtr CreateStageTimeline() = 0;
            /**
             * @brief Destroy a stage timeline object.
             * @param stageTimeline A reference to the stage timeline pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyStageTimeline(IStageTimelinePtr& stageTimeline) = 0;

            /**
             * @brief Create a stepable object.
             * @return The created stepable object, or null if failed.
             */
            virtual IStepablePtr CreateStepable() = 0;
            /**
             * @brief Destroy a stepable object.
             * @param stepable A reference to the stepable pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyStepable(IStepablePtr& stepable) = 0;

            /**
             * @brief Create a stepable observer object.
             * @return The created stepable observer object, or null if failed.
             */
            virtual IStepableObserverPtr CreateStepableObserver() = 0;
            /**
             * @brief Destroy a stepable observer object.
             * @param stepableObserver A reference to the stepable observer pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyStepableObserver(IStepableObserverPtr& stepableObserver) = 0;

            /**
             * @brief Create a scroll processor object.
             * @return The created scroll processor, or null if failed.
             */
            virtual IScrollProcessorPtr CreateScrollProcessor() = 0;
            /**
             * @brief Destroy a scroll processor object.
             * @param scrollProcessor A reference to the scroll processor pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyScrollProcessor(IScrollProcessorPtr& scrollProcessor) = 0;

            /**
             * @brief Create a timeframe object.
             * @return The created timeframe object, or null if failed.
             */
            virtual ITimeframePtr CreateTimeframe() = 0;
            /**
             * @brief Destroy a timeframe object.
             * @param timeframe A reference to the timeframe pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyTimeframe(ITimeframePtr& timeframe) = 0;

            /**
             * @brief Create a timeline object.
             * @return The created timeline  object, or null if failed.
             */
            virtual ITimelinePtr CreateTimeline() = 0;
            /**
             * @brief Destroy a timeline object.
             * @param timeline A reference to the timeline pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyTimeline(ITimelinePtr& timeline) = 0;

            /**
             * @brief Create a node observer object.
             * @return The created node observer object, or null if failed.
             */
            virtual INodeObserverPtr CreateNodeObserver() = 0;
            /**
             * @brief Destroy a node observer object.
             * @param nodeObserver A reference to the node observer pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyNodeObserver(INodeObserverPtr& nodeObserver) = 0;

        protected:
            virtual ~IFactory() {}
        };

        /**
         * @ingroup MurlLogicClasses
         * @interface StaticFactory
         * @brief The StaticFactory class to create logic classes.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create a stepable object.
             * @return The created stepable object, or null if failed.
             */
            static IStepablePtr CreateStepable();
            /**
             * @brief Destroy a stepable object.
             * @param stepable A reference to the stepable pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyStepable(IStepablePtr& stepable);

            /**
             * @brief Create a stepable observer object.
             * @return The created stepable observer object, or null if failed.
             */
            static IStepableObserverPtr CreateStepableObserver();
            /**
             * @brief Destroy a stepable observer object.
             * @param stepableObserver A reference to the stepable observer pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyStepableObserver(IStepableObserverPtr& stepableObserver);

            /**
             * @brief Create a timeframe object.
             * @return The created timeframe object, or null if failed.
             */
            static ITimeframePtr CreateTimeframe();
            /**
             * @brief Destroy a timeframe object.
             * @param timeframe A reference to the timeframe pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyTimeframe(ITimeframePtr& timeframe);

            /**
             * @brief Create a timeline object.
             * @return The created timeline object, or null if failed.
             */
            static ITimelinePtr CreateTimeline();
            /**
             * @brief Destroy a timeline object.
             * @param timeline A reference to the timeline pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyTimeline(ITimelinePtr& timeline);

            /**
             * @brief Create a node observer object.
             * @return The created node observer object, or null if failed.
             */
            static INodeObserverPtr CreateNodeObserver();
            /**
             * @brief Destroy a node observer object.
             * @param nodeObserver A reference to the node observer pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyNodeObserver(INodeObserverPtr& nodeObserver);
        };
    }
}

#endif  // __MURL_LOGIC_I_FACTORY_H__

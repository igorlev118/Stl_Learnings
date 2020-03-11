// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STAGE_TIMELINE_H__
#define __MURL_LOGIC_I_STAGE_TIMELINE_H__

#include "murl_logic_types.h"

namespace Murl
{
    namespace Graph
    {
        class IRoot;
        class ITimeline;
    }

    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IStageTimeline
         * @brief The IStageTimeline interface.
         * The IStageTimeline encapsulates a reference to a Graph::ITimeline,
         * an intro and an outro (start / end) time pair.
         * \n
         * This object is typically used by the IStage object to create an
         * intro and outro animation behaviour for stages.
         * \n
         * (!) Do not confuse with Graph::ITimeline intro / loop / outro feature.
         * When using StartIntro() or StartOutro() the Graph::ITimeline is simply
         * started with the corresponding (start / end) time pair by calling
         * Graph::ITimeline::Start(Real startTime, Real endTime).
         */
        class IStageTimeline
        {
        public:
            /**
             * @brief Set the intro start time.
             * @param startTime The intro start time in seconds.
             */
            virtual void SetIntroStartTime(Real startTime) = 0;

            /**
             * @brief Set the intro end time.
             * @param endTime The intro end time in seconds.
             */
            virtual void SetIntroEndTime(Real endTime) = 0;

            /**
             * @brief Set the intro start and end time.
             * @param startTime The intro start time in seconds.
             * @param endTime The intro end time in seconds.
             */
            virtual void SetIntroTime(Real startTime, Real endTime) = 0;

            /**
             * @brief Get the intro start time.
             * @return The intro start time in seconds.
             */
            virtual Real GetIntroStartTime() const = 0;

            /**
             * @brief Get the intro end time.
             * @return The intro end time in seconds.
             */
            virtual Real GetIntroEndTime() const = 0;

            /**
             * @brief Set the outro start time.
             * @param startTime The outro start time in seconds.
             */
            virtual void SetOutroStartTime(Real startTime) = 0;

            /**
             * @brief Set the outro end time.
             * @param endTime The outro end time in seconds.
             */
            virtual void SetOutroEndTime(Real endTime) = 0;

            /**
             * @brief Set the outro start and end time.
             * @param startTime The outro start time in seconds.
             * @param endTime The outro end time in seconds.
             */
            virtual void SetOutroTime(Real startTime, Real endTime) = 0;

            /**
             * @brief Get the outro start time.
             * @return The outro start time in seconds.
             */
            virtual Real GetOutroStartTime() const = 0;

            /**
             * @brief Get the outro end time.
             * @return The outro end time in seconds.
             */
            virtual Real GetOutroEndTime() const = 0;

            /**
             * @brief Get the Graph::ITimeline object.
             * @return The Graph::ITimeline object.
             */
            virtual Graph::ITimeline* GetTimeline() const = 0;

        public: // Typically used by the IStage object.

            /**
             * @brief Initialize the IStageTimeline object.
             * @param root The graph root node.
             * @param timeline The full path to the graph &lt;Timeline&gt; instance.
             * @return true if successful.
             */
            virtual Bool Init(const Graph::IRoot* root, const String& timeline) = 0;

            /**
             * @brief Deinitialize the IStageTimeline object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Start the intro.
             * @return true if successful.
             */
            virtual Bool StartIntro() = 0;

            /**
             * @brief Start the outro.
             * @return true if successful.
             */
            virtual Bool StartOutro() = 0;

            /**
             * @brief Check if the timeline is running.
             * @return true if running.
             */
            virtual Bool IsRunning() const = 0;

        protected:
            virtual ~IStageTimeline() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STAGE_TIMELINE_H__

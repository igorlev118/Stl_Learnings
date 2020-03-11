// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TIME_EVALUATOR_H__
#define __MURL_GRAPH_I_TIME_EVALUATOR_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        class INode;

        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface ITimeEvaluator
         * @brief The ITimeEvaluator interface.
         * This interface provides a generic way to manipulate an individual property of a given
         * Graph::INode, by attaching a Graph::ITimeEvaluator object to a given Graph::ITimeController instance.
         */
        class ITimeEvaluator
        {
        public:
            virtual ~ITimeEvaluator() {}

            /**
             * @brief Get the mutable ITimeEvaluator interface.
             * @return The mutable ITimeEvaluator interface.
             */
            virtual ITimeEvaluator* GetTimeEvaluatorInterface() = 0;
            /**
             * @brief Get the constant ITimeEvaluator interface.
             * @return The constant ITimeEvaluator interface.
             */
            virtual const ITimeEvaluator* GetTimeEvaluatorInterface() const = 0;

            /**
             * @brief Evaluate the node's property to set.
             * @param clipIndex The zero-based animation clip index.
             * @param clipTime The current animation time within the given clip for which the 
             *      property should be evaluated.
             * @return true if successful.
             */
            virtual Bool Evaluate(UInt32 clipIndex, Double clipTime) = 0;

            /**
             * @brief Evaluate the node's property to set according to multiple blended time values.
             * @param clipIndices An array of zero-based animation clip indices.
             * @param clipTimes An array of the current animation times within the given clips
             *      for which the property should be evaluated.
             * @param blendFactors An array of the blend factors to apply.
             * @param numAnimations The number of clip, time & blend entries to process.
             * @return true if successful.
             */
            virtual Bool Evaluate(const UInt32* clipIndices, const Double* clipTimes, const Real* blendFactors, UInt32 numAnimations) = 0;
        };
    }
}

#endif // __MURL_GRAPH_I_TIME_EVALUATOR_H__

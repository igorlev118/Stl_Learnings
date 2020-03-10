// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_TYPES_H__
#define __MURL_LOGIC_TYPES_H__

#include "murl_shared_pointer.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;

        template<class DataType>
        class StaticVector;

        template<class DataType>
        class Matrix;

        template<class DataType>
        class Limits;
    }

    /**
     * @ingroup MurlLogicNamespaces
     * @brief Namespace containing logic related interfaces.
     */
    namespace Logic
    {
        /**
         * @brief Generic floating point data type for the Murl::Logic namespace.
         */
        typedef LogicReal Real;

        /**
         * @brief Math::Vector data type for the Murl::Logic namespace.
         */
        typedef Math::Vector<Real> Vector;

        /**
         * @brief Math::StaticVector data type for the Murl::Logic namespace.
         */
        typedef Math::StaticVector<Real> StaticVector;

        /**
         * @brief Math::Matrix data type for the Murl::Logic namespace.
         */
        typedef Math::Matrix<Real> Matrix;

        /**
         * @brief Math::Limits data type for the Murl::Logic namespace.
         */
        typedef Math::Limits<Real> Limits;

        class GraphSoundObject;
        /** The GraphSoundObject shared pointer type. */
        typedef SharedPointer<GraphSoundObject> GraphSoundObjectPtr;

        class IAppGraph;
        /** @brief The IAppGraph shared pointer type. */
        typedef SharedPointer<IAppGraph> IAppGraphPtr;

        class IAppProcessor;
        /** @brief The IAppProcessor shared pointer type. */
        typedef SharedPointer<IAppProcessor> IAppProcessorPtr;

        class IAppStage;
        /** @brief The IAppStage shared pointer type. */
        typedef SharedPointer<IAppStage> IAppStagePtr;

        class IAppStepable;
        /** @brief The IAppStepable shared pointer type. */
        typedef SharedPointer<IAppStepable> IAppStepablePtr;

        class IAppTimeline;
        /** @brief The IAppTimeline shared pointer type. */
        typedef SharedPointer<IAppTimeline> IAppTimelinePtr;

        class INodeObserver;
        /** @brief The INodeObserver shared pointer type. */
        typedef SharedPointer<INodeObserver> INodeObserverPtr;

        class IObservableNode;
        /** @brief The IObservableNode shared pointer type. */
        typedef SharedPointer<IObservableNode> IObservableNodePtr;

        class IProcessor;
        /** @brief The IProcessor shared pointer type. */
        typedef SharedPointer<IProcessor> IProcessorPtr;

        class IStage;
        /** @brief The IStage shared pointer type. */
        typedef SharedPointer<IStage> IStagePtr;

        class IStageProcessor;
        /** @brief The IStageProcessor shared pointer type. */
        typedef SharedPointer<IStageProcessor> IStageProcessorPtr;

        class IStageTimeline;
        /** @brief The IStageTimeline shared pointer type. */
        typedef SharedPointer<IStageTimeline> IStageTimelinePtr;

        class IState;

        class IStepable;
        /** @brief The IStepable shared pointer type. */
        typedef SharedPointer<IStepable> IStepablePtr;

        class IStepableObserver;
        /** @brief The IStepableObserver shared pointer type. */
        typedef SharedPointer<IStepableObserver> IStepableObserverPtr;

        class ITimeframe;
        /** @brief The ITimeframe shared pointer type. */
        typedef SharedPointer<ITimeframe> ITimeframePtr;

        class ITimeline;
        /** @brief The shared pointer type definition. */
        typedef SharedPointer<ITimeline> ITimelinePtr;

        class IScrollProcessor;
        /** @brief The IScrollProcessor shared pointer type. */
        typedef SharedPointer<IScrollProcessor> IScrollProcessorPtr;

        class SoundFader;
        /** The SoundFader shared pointer type. */
        typedef SharedPointer<SoundFader> SoundFaderPtr;
    }
}

#endif  // __MURL_LOGIC_TYPES_H__

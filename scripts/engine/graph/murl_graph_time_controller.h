// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_TIME_CONTROLLER_H__
#define __MURL_GRAPH_TIME_CONTROLLER_H__

#include "murl_graph_controller.h"
#include "murl_graph_i_time_controller.h"
#include "murl_i_attributes.h"
#include "murl_array.h"
#include "murl_string.h"

namespace Murl
{
    namespace Graph
    {
        class ITimeEvaluator;

        /**
         * @ingroup MurlGraphControllerClasses
         * @brief The abstract base class of all time-based scene graph node controllers.
         * This class represents the internal base class of all different controllers implemented
         * in the framework's core library acting on the current animation time ofGraph::ITimeline 
         * nodes.
         *
         * @xmlelements
         *
         * @graphatts
         * @graphatt{timeShift,Double,, The time shift value. See Murl::Graph::ITimeController::SetTimeShift().}
         * @graphatt{timeOffset,Double,, The time offset value. See Murl::Graph::ITimeController::SetTimeOffset().}
         * @graphatt{timeScale,Double,, The time scale value. See Murl::Graph::ITimeController::SetTimeScale().}
         * @graphatt{timelineUnits,UInt32,0, The timeline slots used.
         *      See Murl::Graph::ITimeController::SetTimelineUnitEnabled(). }
         * @graphatt{normalizeBlendFactors,Bool,true, Enable/disable blend factor normalization. 
         *      See Murl::Graph::ITimeController::SetBlendFactorNormalizationEnabled().}
         * @graphatt{responseGroups,String,0..31, A comma-separated list of timeline response group
         *      indices. See Murl::Graph::ITimeController::SetResponseGroupMask().}
         */
        class TimeController : public Controller, public ITimeController
        {
            MURL_FACTORY_OBJECT_ABSTRACT_DERIVED_CLASS(Murl::Graph::TimeController, Murl::Graph::Controller)

            MURL_FACTORY_OBJECT_PROPERTIES(Murl::Graph::TimeController,
                                           (PROPERTY_TIME_SHIFT,     mTimeShift,     0.0,                          DoubleProperty),
                                           (PROPERTY_TIME_OFFSET,    mTimeOffset,    0.0,                          DoubleProperty),
                                           (PROPERTY_TIME_SCALE,     mTimeScale,     1.0,                          DoubleProperty),
                                           (PROPERTY_TIMELINE_UNITS, mTimelineUnits, 1,                            UInt32MaskProperty),
                                           (PROPERTY_FLAGS,          mFlags,         FLAG_NORMALIZE_BLEND_FACTORS, UInt32MaskProperty),
                                           (PROPERTY_RESPONSE_MASK,  mResponseMask,  0xffffffff,                   UInt32MaskProperty))

            MURL_FACTORY_OBJECT_ATTRIBUTES(Murl::Graph::TimeController,
                                           (ATTRIBUTE_TIME_SHIFT,              "timeShift",             mTimeShift,     COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_TIME_OFFSET,             "timeOffset",            mTimeOffset,    COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_TIME_SCALE,              "timeScale",             mTimeScale,     COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_TIMELINE_UNITS,          "timelineUnits",         mTimelineUnits, COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_ALL),
                                           (ATTRIBUTE_NORMALIZE_BLEND_FACTORS, "normalizeBlendFactors", mFlags,         COMPONENT_NONE + FLAG_NORMALIZE_BLEND_FACTORS, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_RESPONSE_GROUPS,         "responseGroups",        mResponseMask,  COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_ALL))
            
        public:
            virtual IController* GetControllerInterface();
            virtual const IController* GetControllerInterface() const;
            
            virtual ITimeController* GetTimeControllerInterface();
            virtual const ITimeController* GetTimeControllerInterface() const;

            virtual Bool DeserializeAttribute(IDeserializeAttributeTracker* tracker);
            
            virtual Bool PreInit(IInitTracker* tracker);
            virtual Bool PostInit(IInitTracker* tracker);

            virtual Bool PreDeInit(IDeInitTracker* tracker);
            virtual Bool PostDeInit(IDeInitTracker* tracker);

            virtual Bool PreConfigChangedLogic(IConfigChangedTracker* tracker);
            virtual Bool PostConfigChangedLogic(IConfigChangedTracker* tracker);

            virtual Bool PreProcessLogic(IProcessLogicTracker* tracker);
            virtual Bool PostProcessLogic(IProcessLogicTracker* tracker);

            virtual Bool SetTimeShift(Double timeShift);
            virtual Double GetTimeShift() const;
            
            virtual Bool SetTimeOffset(Double timeOffset);
            virtual Double GetTimeOffset() const;
            
            virtual Bool SetTimeScale(Double timeScale);
            virtual Double GetTimeScale() const;

            virtual Bool SetTimelineUnitEnabled(UInt32 unit, Bool enabled);
            virtual Bool IsTimelineUnitEnabled(UInt32 unit) const;

            virtual Bool SetBlendFactorNormalizationEnabled(Bool enabled);
            virtual Bool IsBlendFactorNormalizationEnabled() const;

            virtual Bool SetResponseGroupMask(UInt32 mask);
            virtual UInt32 GetResponseGroupMask() const;

        protected:
            enum Flags
            {
                FLAG_NORMALIZE_BLEND_FACTORS = (1 << 0)
            };

            TimeController(const IFactory* factory, INode* owner);
            virtual ~TimeController();
            
            virtual Bool DeserializeBaseAttribute(IDeserializeAttributeTracker* tracker);
            virtual Bool DeserializeChildAttribute(IDeserializeAttributeTracker* tracker);
            
            virtual Bool AddEvaluator(ITimeEvaluator* evaluator);
            virtual Bool ProcessEvaluators(UInt32 clipIndex, Double clipTime);
            virtual Bool ProcessEvaluators(UInt32 clipIndex, Double clipTime, Real blendFactor);
            virtual Bool ProcessEvaluators(const UInt32* clipIndices, const Double* clipTimes, const Real* blendFactors, UInt32 numAnimations);

            virtual Bool UpdateTimelineUnits();

            SInt32 mSingleTimelineUnit;

            Double mCurrentAnimationTime;
            UInt32 mCurrentAnimationClip;

            Array<ITimeEvaluator*> mEvaluators;

            Array<UInt32> mRecentClipIndices;
            Array<Double> mRecentClipTimes;
            Array<Real> mRecentBlendFactors;
        };
    }
}

#endif // __MURL_GRAPH_TIME_CONTROLLER_H__

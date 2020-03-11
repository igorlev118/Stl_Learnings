// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_NODE_H__
#define __MURL_GRAPH_NODE_H__

#include "murl_graph_i_node.h"
#include "murl_graph_i_controller.h"
#include "murl_graph_property.h"
#include "murl_graph_tracker_result.h"
#include "murl_math_vector.h"
#include "murl_math_matrix.h"
#include "murl_string.h"
#include "murl_array.h"

namespace Murl
{
    namespace Resource
    {
        class IAnimation;
        class IGraphNode;
    }

    namespace Graph
    {
        class INamespace;
        class IController;
        class IHandle;

        /**
         * @ingroup MurlGraphNodeClasses
         * @brief The base class of all scene graph nodes.
         * This class represents the internal base class of all different nodes that are
         * implemented in the framework's core library. Custom nodes may derive from this
         * class, make use of the default method implementations, and override any of these
         * methods if desired.
         *
         * The following example shows how to create a simple scene graph made up from individual
         * nodes, via an XML scene graph description:
         *
         * @code
         * <Node>
         *   <MaterialState materialId="/main_materials/mat_1"/>
         *   <TextureState textureId="/main_materials/tex_2" unit="0"/>
         *   <Timeline startTime="0.0" endTime="10.0" numberOfLoops="-1" startOnActivate="yes">
         *     <Transform controller.animationResourceId="main:walk_anim">
         *       <ResourceMeshGeometry meshResourceId="main:model_0"/>
         *     </Transform>
         *   </Timeline>
         * </Node>
         * @endcode
         *
         * To find out the actual XML tag and available attribute names for all of the different graph
         * nodes derived from Murl::Graph::Node, see the "XML Graph Resource Tag" and "XML Graph Resource
         * Attributes" sections in the respective node's class reference.
         *
         * It is possible to attach exactly one Murl::Graph::IController to a node, which is then responsible
         * for manipulating one or more properties of the node, depending on the actual node class
         * and controller purpose. The following example creates a Murl::Graph::PlaneSequenceGeometry node
         * and attaches an animation controller referencing the "Anim1" animation resource within
         * the "Main" package, at 75% speed:
         *
         * @code
         * <PlaneSequenceGeometry
         *   controller="AnimationTimeController"
         *   controller.timeScale="0.75"
         *   controller.animationResourceId="Main:Anim1"
         * />
         * @endcode
         *
         * Here, the "controller" attribute specifies which type of controller to attach; if this
         * attribute is not specified, a Murl::Graph::AnimationTimeController will be created by default.
         * In this example, "timeScale" is a common parameter for the Murl::Graph::TimeController base class,
         * and "animationResourceId" is specific to Murl::Graph::AnimationTimeController.
         *
         * Custom nodes might allow more than one controller to be attached, in this case the different
         * controller properties must be prefixed with a unique attribute identifier similar to
         * "controller." in the example, to uniquely define the parameters for each attached controller.
         *
         * See the "XML Animation Resource Tags" section in a specific node class reference to find
         * out which types of animation key frames are accepted by that node.
         *
         * @xmlelements
         *
         * @graphtags
         * @graphtag{Node}
         *
         * @graphatts
         * @graphatt{id,String,, The node ID. This must be unique within the current namespace.
         *      See Murl::Graph::INode::SetId().}
         * @graphatt{active,Bool,true, If true\, logic traversals will be carried out on this node.
         *      See Murl::Graph::INode::SetActive().}
         * @graphatt{visible,Bool,true, If true\, output traversals will be carried out on this node.
         *      See Murl::Graph::INode::SetVisible().}
         * @graphatt{activeAndVisible,Bool,true, If true\, both logic and output traversals will be
         *      carried out on this node. See Murl::Graph::INode::SetActiveAndVisible().}
         * @graphatt{controller,String,, Specifies the type of the optional controller for this node (see above).
         *      If the controller is not specified but a "controller.animationResourceId" is given\,
         *      a Murl::Graph::AnimationTimeController will be created by default.
         *      See also Murl::Graph::TimeController.}
         * @graphatt{swapped,Bool,false, If true\, The node is initially in the swapped state.
         *      See Murl::Graph::INode::SetSwapped().}
         * @graphatt{enableAutomaticSwapping,Bool,false, If true\, auto-swapping is enabled for this
         *      node. See Murl::Graph::INode::SetAutomaticSwappingEnabled().}
         * @graphatt{enableManualSwapping,Bool,false, If true\, manual swapping is enabled for this
         *      node. See Murl::Graph::INode::SetManualSwappingEnabled().}
         * @graphatt{includeForLanguages,String,, A list of comma-separated language identifier strings
         *      from the Murl::IEnums::Language enumeration. If specified\, the node is only created when the
         *      current app language matches one of the given identifiers.}
         * @graphatt{includeForTargetClasses,String,, A list of comma-separated target class identifier
         *      strings from the Murl::IEnums::TargetClass enumeration. If specified\, the node is only created
         *      when the actual platform target class matches one of the given identifiers.}
         * @graphatt{includeForTargetDevices,String,, A list of comma-separated target device identifier
         *      strings from the Murl::IEnums::TargetDevice enumeration. If specified\, the node is only created
         *      when the actual platform target device matches one of the given identifiers.}
         * @graphatt{includeForTargetHosts,String,, A list of comma-separated target host identifier
         *      strings from the Murl::IEnums::TargetHost enumeration. If specified\, the node is only created
         *      when the actual platform target host matches one of the given identifiers.}
         * @graphatt{includeForOperatingSystems,String,, A list of comma-separated operating system identifier
         *      strings from the Murl::IEnums::OperatingSystem enumeration. If specified\, the node is only created
         *      when the platform OS matches one of the given identifiers.}
         * @graphatt{includeForGpus,String,, A list of comma-separated GPU identifier strings from the
         *      Murl::IEnums::Gpu enumeration. If specified\, the node is only created when the platform GPU
         *      matches one of the given identifiers.}
         * @graphatt{includeForVideoApis,String,, A list of comma-separated video API identifier strings
         *      from the Murl::IEnums::VideoApi enumeration. If specified\, the node is only created when the
         *      chosen video API matches one of the given identifiers.}
         * @graphatt{includeForAudioApis,String,, A list of comma-separated audio API identifier strings
         *      from the Murl::IEnums::AudioApi enumeration. If specified\, the node is only created when the
         *      chosen audio API matches one of the given identifiers.}
         * @graphatt{includeForPrescaleFactors,String,, A list of comma-separated integer values for
         *      possible textures prescale factors. If specified\, the node is only created when the
         *      actually used prescale factor matches one of the given values.}
         * @graphatt{includeForFeatures,String,, A list of comma-separated feature identifier strings
         *      from the Murl::IEnums::Feature enumeration. If specified\, the node is only created when ALL
         *      of the given engine features are available.}
         * @graphatt{includeForCondition,Bool,TRUE, A bool value to specify if this node/subtree should
         *      be created or not. Usually used in combination with the expression evaluator.}
         * @graphatt{includeForUserConfigurations,String,, A comma-separated list of user configuration strings.
         *      If specified\, the node/subtree is only created if at least one value evaluates to TRUE in
         *      the method Murl::IApp::IsUserConfigurationMatching method. Override this method in your
         *      Murl::App::AppBase class to use user configurations.}
         * @graphatt{excludeForLanguages,String,, A list of comma-separated language identifier strings
         *      from the Murl::IEnums::Language enumeration. If specified\, the node is only created when the
         *      current app language does not match any of the given identifiers.}
         * @graphatt{excludeForTargetClasses,String,, A list of comma-separated target class identifier
         *      strings from the Murl::IEnums::TargetClass enumeration. If specified\, the node is only created
         *      when the actual platform target class does not match any of the given identifiers.}
         * @graphatt{excludeForTargetDevices,String,, A list of comma-separated target device identifier
         *      strings from the Murl::IEnums::TargetDevice enumeration. If specified\, the node is only created
         *      when the actual platform target device does not match any of the given identifiers.}
         * @graphatt{excludeForTargetHosts,String,, A list of comma-separated target host identifier
         *      strings from the Murl::IEnums::TargetHost enumeration. If specified\, the node is only created
         *      when the actual platform target host does not match any of the given identifiers.}
         * @graphatt{excludeForOperatingSystems,String,, A list of comma-separated operating system identifier
         *      strings from the Murl::IEnums::OperatingSystem enumeration. If specified\, the node is only created
         *      when the platform OS does not match any of the given identifiers.}
         * @graphatt{excludeForGpus,String,, A list of comma-separated GPU identifier strings from the
         *      Murl::IEnums::Gpu enumeration. If specified\, the node is only created when the platform GPU
         *      does not match any of the given identifiers.}
         * @graphatt{excludeForVideoApis,String,, A list of comma-separated video API identifier strings
         *      from the Murl::IEnums::VideoApi enumeration. If specified\, the node is only created when the
         *      chosen video API does not match any of the given identifiers.}
         * @graphatt{excludeForAudioApis,String,, A list of comma-separated audio API identifier strings
         *      from the Murl::IEnums::AudioApi enumeration. If specified\, the node is only created when the
         *      chosen audio API does not match any of the given identifiers.}
         * @graphatt{excludeForPrescaleFactors,String,, A list of comma-separated integer values for
         *      possible textures prescale factors. If specified\, the node is only created when the
         *      actually used prescale factor does not match any of the given values.}
         * @graphatt{excludeForFeatures,String,, A list of comma-separated feature identifier strings
         *      from the Murl::IEnums::Feature enumeration. If specified\, the node is only created when at least
         *      one of the given engine features is not available.}
         * @graphatt{excludeForCondition,Bool,TRUE, A bool value to specify if this node/subtree should
         *      be created or not. Usually used in combination with the expression evaluator.}
         * @graphatt{excludeForUserConfigurations,String,, A comma-separated list of user configuration strings.
         *      If specified\, the node/subtree is not created if any value evaluates to TRUE in
         *      the method Murl::IApp::IsUserConfigurationMatching method. Override this method in your
         *      Murl::App::AppBase class to use user configurations.}
         *
         * @animtags
         * @animtag{ActiveKey,BoolKey,CONSTANT, The animation key acting on Murl::Graph::ITraversable::SetActive().}
         * @animtag{VisibleKey,BoolKey,CONSTANT, The animation key acting on Murl::Graph::ITraversable::SetVisible().}
         */
        class Node : public INode
        {
            MURL_FACTORY_OBJECT_BASE_CLASS(Murl::Graph::Node)

            MURL_FACTORY_OBJECT_PROPERTIES(Murl::Graph::Node,
                                           (PROPERTY_ID,         mId,        "",                                                                   IdProperty),
                                           (PROPERTY_NODE_FLAGS, mNodeFlags, (NODE_FLAG_IS_ACTIVE | NODE_FLAG_IS_VISIBLE | NODE_FLAG_IS_UNLOCKED), UInt32MaskProperty))

            MURL_FACTORY_OBJECT_ATTRIBUTES(Murl::Graph::Node,
                                           (ATTRIBUTE_ID,                              "id",                            mId,           COMPONENT_SINGLE,                                      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ACTIVE,                          "active",                        mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_ACTIVE,                  ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_VISIBLE,                         "visible",                       mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_VISIBLE,                 ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ACTIVE_AND_VISIBLE,              "activeAndVisible",              mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_ACTIVE + NODE_FLAG_IS_VISIBLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_CONTROLLER,                      "controller",                    sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlEnumController
                                           (ATTRIBUTE_SWAPPED,                         "swapped",                       mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_SWAPPED,                 ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ENABLE_AUTOMATIC_SWAPPING,       "enableAutomaticSwapping",       mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_AUTOMATICALLY_SWAPPABLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ENABLE_MANUAL_SWAPPING,          "enableManualSwapping",          mNodeFlags,    COMPONENT_NONE + NODE_FLAG_IS_MANUALLY_SWAPPABLE,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_INCLUDE_FOR_CONDITION,           "includeForCondition",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE),
                                           (ATTRIBUTE_INCLUDE_FOR_USER_CONFIGURATIONS, "includeForUserConfigurations",  sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), 
                                           (ATTRIBUTE_INCLUDE_FOR_LANGUAGES,           "includeForLanguages",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskLanguage
                                           (ATTRIBUTE_INCLUDE_FOR_TARGET_CLASSES,      "includeForTargetClasses",       sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetClass
                                           (ATTRIBUTE_INCLUDE_FOR_TARGET_DEVICES,      "includeForTargetDevices",       sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetDevice
                                           (ATTRIBUTE_INCLUDE_FOR_TARGET_HOSTS,        "includeForTargetHosts",         sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetHost
                                           (ATTRIBUTE_INCLUDE_FOR_OPERATING_SYSTEMS,   "includeForOperatingSystems",    sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskOperatingSystem
                                           (ATTRIBUTE_INCLUDE_FOR_GPUS,                "includeForGpus",                sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskGpu
                                           (ATTRIBUTE_INCLUDE_FOR_VIDEO_APIS,          "includeForVideoApis",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskVideoApi
                                           (ATTRIBUTE_INCLUDE_FOR_AUDIO_APIS,          "includeForAudioApis",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskAudioApi
                                           (ATTRIBUTE_INCLUDE_FOR_PRESCALE_FACTORS,    "includeForPrescaleFactors",     sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), 
                                           (ATTRIBUTE_INCLUDE_FOR_FEATURES,            "includeForFeatures",            sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskFeature
                                           (ATTRIBUTE_EXCLUDE_FOR_CONDITION,           "excludeForCondition",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE),
                                           (ATTRIBUTE_EXCLUDE_FOR_USER_CONFIGURATIONS, "excludeForUserConfigurations",  sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE),
                                           (ATTRIBUTE_EXCLUDE_FOR_LANGUAGES,           "excludeForLanguages",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskLanguage
                                           (ATTRIBUTE_EXCLUDE_FOR_TARGET_CLASSES,      "excludeForTargetClasses",       sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetClass
                                           (ATTRIBUTE_EXCLUDE_FOR_TARGET_DEVICES,      "excludeForTargetDevices",       sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetDevice
                                           (ATTRIBUTE_EXCLUDE_FOR_TARGET_HOSTS,        "excludeForTargetHosts",         sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskTargetHost
                                           (ATTRIBUTE_EXCLUDE_FOR_OPERATING_SYSTEMS,   "excludeForOperatingSystems",    sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskOperatingSystem
                                           (ATTRIBUTE_EXCLUDE_FOR_GPUS,                "excludeForGpus",                sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskGpu
                                           (ATTRIBUTE_EXCLUDE_FOR_VIDEO_APIS,          "excludeForVideoApis",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskVideoApi
                                           (ATTRIBUTE_EXCLUDE_FOR_AUDIO_APIS,          "excludeForAudioApis",           sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), // MurlMaskAudioApi
                                           (ATTRIBUTE_EXCLUDE_FOR_PRESCALE_FACTORS,    "excludeForPrescaleFactors",     sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE), 
                                           (ATTRIBUTE_EXCLUDE_FOR_FEATURES,            "excludeForFeatures",            sNullProperty, COMPONENT_NONE, ACCESS_NONE, ELEMENT_NONE)) // MurlMaskFeature

            static INode* Create(const IFactory* factory);

        public:
            virtual INode* GetNodeInterface();
            virtual const INode* GetNodeInterface() const;

            virtual Bool DeserializeNode(IDeserializeAttributeTracker* tracker);
            virtual Bool DeserializeAttribute(IDeserializeAttributeTracker* tracker);

            virtual Bool AddChild(INode* child);
            virtual Bool InsertChild(INode* child, UInt32 index);
            virtual INode* RemoveChild(INode* child);
            virtual INode* RemoveChild(UInt32 index);

            virtual const INodeArray& GetChildren() const;
            virtual INode* GetChild(UInt32 index);
            virtual INode* GetChild(const String& id);
            virtual const INode* GetChild(UInt32 index) const;
            virtual const INode* GetChild(const String& id) const;
            virtual SInt32 GetChildIndex(const INode* node) const;
            virtual SInt32 GetChildIndex(const String& id) const;
            virtual UInt32 GetNumberOfChildren() const;

            virtual Bool AddParent(INode* parent);
            virtual Bool InsertParent(INode* parent, UInt32 index);
            virtual INode* RemoveParent(INode* parent);
            virtual INode* RemoveParent(UInt32 index);

            virtual const INodeArray& GetParents() const;
            virtual INode* GetParent(UInt32 index);
            virtual INode* GetParent(const String& id);
            virtual const INode* GetParent(UInt32 index) const;
            virtual const INode* GetParent(const String& id) const;
            virtual SInt32 GetParentIndex(const INode* node) const;
            virtual SInt32 GetParentIndex(const String& id) const;
            virtual UInt32 GetNumberOfParents() const;

            virtual Bool AddController(IController* controller);
            virtual Bool InsertController(IController* controller, UInt32 index);
            virtual IController* RemoveController(IController* controller);
            virtual IController* RemoveController(UInt32 index);

            virtual const IControllerArray& GetControllers() const;
            virtual IController* GetController(UInt32 index);
            virtual const IController* GetController(UInt32 index) const;
            virtual SInt32 GetControllerIndex(const IController* controller) const;
            virtual UInt32 GetNumberOfControllers() const;

            virtual INamespace* GetCurrentNamespace();
            virtual const INamespace* GetCurrentNamespace() const;
            virtual INamespace* GetParentNamespace();
            virtual const INamespace* GetParentNamespace() const;
            virtual INamespace* GetRootNamespace();
            virtual const INamespace* GetRootNamespace() const;

            virtual Bool SetId(const String& id);
            virtual const String& GetId() const;
            virtual String GetPath() const;

            virtual Bool IsPrivate() const;

            virtual Bool SetHead(Bool isHead);
            virtual Bool IsHead() const;

            virtual Bool SetLocked(Bool isLocked);
            virtual Bool IsLocked() const;

            virtual Bool SetSwapped(Bool isSwapped);
            virtual Bool IsSwapped() const;

            virtual Bool SetAutomaticSwappingEnabled(Bool enabled);
            virtual Bool IsAutomaticSwappingEnabled() const;

            virtual Bool SetManualSwappingEnabled(Bool enabled);
            virtual Bool IsManualSwappingEnabled() const;

            virtual Bool SetStateRecordingEnabled(Bool enabled);
            virtual Bool IsStateRecordingEnabled() const;

            virtual Bool SetInitialized(Bool isInitialized);
            virtual Bool IsInitialized() const;

            virtual Bool SetFinishLogicPending(Bool pending);
            virtual Bool IsFinishLogicPending() const;

            virtual Bool SetFinishInputPending(Bool pending);
            virtual Bool IsFinishInputPending() const;

            virtual Bool SetFinishOutputPending(Bool pending);
            virtual Bool IsFinishOutputPending() const;

            virtual Bool SetActive(Bool isActive);
            virtual Bool IsActive() const;

            virtual Bool SetVisible(Bool isVisible);
            virtual Bool IsVisible() const;

            virtual Bool SetActiveAndVisible(Bool enabled);
            virtual Bool IsActiveAndVisible() const;

            virtual Bool SetBoundingVolumeModified(Bool isModified);
            virtual Bool IsBoundingVolumeModified() const;

            virtual Bool SetActiveModified();
            virtual Bool SetVisibleModified();

            virtual Bool SetModifiedFlags(UInt32 flags);
            virtual Bool ClearModifiedFlags(UInt32 flags);

            virtual Bool AddReference();
            virtual Bool RemoveReference();

            virtual Bool Init(IInitTracker* tracker);
            virtual Bool DeInit(IDeInitTracker* tracker);
            virtual Bool Suspend(IDeInitTracker* tracker);
            virtual Bool Resume(IInitTracker* tracker);

            virtual Bool ConfigChangedLogic(IConfigChangedTracker* tracker);
            virtual Bool ConfigChangedOutput(IConfigChangedTracker* tracker);

            virtual Bool ProcessLogic(IProcessLogicTracker* tracker);
            virtual Bool ProcessInput(IProcessInputTracker* tracker);
            virtual Bool ProcessOutput(IProcessOutputTracker* tracker);

            virtual Bool FinishLogic(IFinishLogicTracker* tracker);
            virtual Bool FinishInput(IFinishInputTracker* tracker);
            virtual Bool FinishOutput(IFinishOutputTracker* tracker);

            virtual Bool WasParentActiveSet(IProcessLogicTracker* tracker) const;
            virtual Bool WasParentVisibleSet(IProcessOutputTracker* tracker) const;

            virtual Bool SetHandle(IHandle* handle);
            virtual IHandle* GetHandle();
            virtual const IHandle* GetHandle() const;

            virtual Bool SetUserData(void* userData);
            virtual void* GetUserData();
            virtual const void* GetUserData() const;

            virtual IBoundingVolume* CreateBoundingVolume() const;
            virtual Bool DestroyBoundingVolume(IBoundingVolume*& boundingVolume) const;
            virtual IBoundingVolume* GetBoundingVolume();
            virtual const IBoundingVolume* GetBoundingVolume() const;

            virtual Bool SetNodeFlags(UInt32 flags);
            virtual UInt32 GetNodeFlags() const;

            virtual UInt32 GetConfigChangedTriggers(UInt32 mask) const;
            virtual UInt32 GetProcessLogicTriggers(UInt32 mask) const;
            virtual UInt32 GetProcessInputTriggers(UInt32 mask) const;
            virtual UInt32 GetProcessOutputTriggers(UInt32 mask) const;

            virtual UInt32 GetConfigChangedResponse() const;
            virtual UInt32 GetProcessLogicResponse() const;
            virtual UInt32 GetProcessInputResponse() const;
            virtual UInt32 GetProcessOutputResponse() const;

            virtual Bool AddChildConfigChangedResponse(UInt32 mask);
            virtual Bool AddChildProcessLogicResponse(UInt32 mask);
            virtual Bool AddChildProcessInputResponse(UInt32 mask);
            virtual Bool AddChildProcessOutputResponse(UInt32 mask);

            virtual UInt32 GetModifiedTraversalStates() const;

            virtual Bool PrintTree(UInt32 indent, UInt32 includeNodeFlags, UInt32 excludeNodeFlags) const;

            virtual const IController::ClassInfo& GetDefaultControllerClassInfo() const;

        protected:
            Node(const IFactory* factory);
            virtual ~Node();

            virtual UInt32 GetSelfConfigChangedResponse() const;
            virtual UInt32 GetSelfProcessLogicResponse() const;
            virtual UInt32 GetSelfProcessInputResponse() const;
            virtual UInt32 GetSelfProcessOutputResponse() const;

            virtual Bool DeserializeBaseAttribute(IDeserializeAttributeTracker* tracker);
            virtual Bool DeserializeChildAttribute(IDeserializeAttributeTracker* tracker);

            virtual Bool InitSelf(IInitTracker* tracker);
            virtual Bool InitChildren(IInitTracker* tracker);

            virtual Bool DeInitSelf(IDeInitTracker* tracker);
            virtual Bool DeInitChildren(IDeInitTracker* tracker);

            virtual Bool SuspendSelf(IDeInitTracker* tracker);
            virtual Bool SuspendChildren(IDeInitTracker* tracker);

            virtual Bool ResumeSelf(IInitTracker* tracker);
            virtual Bool ResumeChildren(IInitTracker* tracker);

            virtual Bool ConfigChangedLogicSelf(IConfigChangedTracker* tracker);
            virtual Bool ConfigChangedLogicChildren(IConfigChangedTracker* tracker);

            virtual Bool ConfigChangedOutputSelf(IConfigChangedTracker* tracker);
            virtual Bool ConfigChangedOutputChildren(IConfigChangedTracker* tracker);

            virtual Bool ProcessLogicSelf(IProcessLogicTracker* tracker);
            virtual Bool ProcessLogicChildren(IProcessLogicTracker* tracker);

            virtual Bool ProcessInputSelf(IProcessInputTracker* tracker);
            virtual Bool ProcessInputChildren(IProcessInputTracker* tracker);

            virtual Bool ProcessOutputSelf(IProcessOutputTracker* tracker);
            virtual Bool ProcessOutputChildren(IProcessOutputTracker* tracker);

            virtual Bool UpdateInclusion(IDeserializeAttributeTracker* tracker, Bool isConditionTrue);
            virtual Bool UpdateExclusion(IDeserializeAttributeTracker* tracker, Bool isConditionTrue);

            void ClearChildrenModifiedFlags(UInt32 flags);
            void SetParentsModifiedFlags(UInt32 flags);

            void SetConfigChangedResponseDirty();
            void SetProcessLogicResponseDirty();
            void SetProcessInputResponseDirty();
            void SetProcessOutputResponseDirty();

            void UpdateParentConfigChangedResponse();
            void UpdateParentProcessLogicResponse();
            void UpdateParentProcessInputResponse();
            void UpdateParentProcessOutputResponse();

            // Members
            UInt32 mModifiedTraversalStates;
            UInt32 mReferenceCount;

            UInt32 mConfigChangedResponse;
            UInt32 mProcessLogicResponse;
            UInt32 mProcessInputResponse;
            UInt32 mProcessOutputResponse;

            UInt32 mChildConfigChangedResponse;
            UInt32 mChildProcessLogicResponse;
            UInt32 mChildProcessInputResponse;
            UInt32 mChildProcessOutputResponse;

            UInt32 mConfigChangedTriggers;
            UInt32 mProcessLogicTriggers;
            UInt32 mProcessInputTriggers;
            UInt32 mProcessOutputTriggers;

            INodeArray mChildren;
            INodeArray mParents;

            IControllerArray mControllers;

            INamespace* mParentNamespace;
            INamespace* mRootNamespace;

            IHandle* mHandle;
            void* mUserData;

            static NullProperty sNullProperty;

        private:
            const IFactory* mFactory;

            friend class Factory;
        };
    }
}

#endif // __MURL_GRAPH_NODE_H__

// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NODE_H__
#define __MURL_GRAPH_I_NODE_H__

#include "murl_graph_i_traversable.h"
#include "murl_graph_i_controller.h"
#include "murl_graph_i_generic_node_target.h"
#include "murl_i_factory_object.h"
#include "murl_index.h"
#include "murl_string.h"

namespace Murl
{
    class IAttributes;

    namespace Resource
    {
        class IGraphNode;
    }

    namespace Graph
    {
        class IBoundingVolume;
        class IProcessLogicTracker;
        class IProcessInputTracker;
        class IProcessOutputTracker;
        class IFinishLogicTracker;
        class IFinishInputTracker;
        class IFinishOutputTracker;
        class IInitTracker;
        class IDeInitTracker;
        class IConfigChangedTracker;
        class IDeserializeAttributeTracker;
        class IHandle;
        class INamespace;
        class INode;
        class IController;
        class IFactory;

        typedef Array<INode*> INodeArray;
        typedef Index<INode*> INodeIndex;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface INode
         * @brief The basic scene graph node interface.
         * Any class that is supposed to be part of a scene graph hierarchy must implement this interface.
         *
         * See SetId() for a description of valid node IDs.\n
         * See Graph::INamespace for details about the hierarchical organization of node IDs.
         */
        class INode : public IFactoryObject<INode>, public ITraversable
        {
        public:
            typedef INode* (*CreateFunction)(const IFactory* factory);

        public:
            enum NodeFlags
            {
                NODE_FLAG_IS_HEAD                               = (1 << 0),
                NODE_FLAG_IS_UNLOCKED                           = (1 << 1),
                NODE_FLAG_IS_INITIALIZED                        = (1 << 2),
                NODE_FLAG_IS_ACTIVE                             = (1 << 3),
                NODE_FLAG_IS_VISIBLE                            = (1 << 4),
                NODE_FLAG_IS_SWAPPED                            = (1 << 7),
                NODE_FLAG_IS_AUTOMATICALLY_SWAPPABLE            = (1 << 8),
                NODE_FLAG_IS_MANUALLY_SWAPPABLE                 = (1 << 9),
                NODE_FLAG_IS_STATE_RECORDING_ENABLED            = (1 << 10),
                NODE_FLAG_IS_FINISH_LOGIC_PENDING               = (1 << 11),
                NODE_FLAG_IS_FINISH_INPUT_PENDING               = (1 << 12),
                NODE_FLAG_IS_FINISH_OUTPUT_PENDING              = (1 << 13),

                NODE_FLAG_IS_BOUNDING_VOLUME_MODIFIED           = (1 << 16),
                NODE_FLAG_IS_PROCESS_LOGIC_TRIGGER_MODIFIED     = (1 << 24),
                NODE_FLAG_IS_PROCESS_INPUT_TRIGGER_MODIFIED     = (1 << 25),
                NODE_FLAG_IS_PROCESS_OUTPUT_TRIGGER_MODIFIED    = (1 << 26),
                NODE_FLAG_IS_MODIFIED                           = NODE_FLAG_IS_BOUNDING_VOLUME_MODIFIED
                                                                + NODE_FLAG_IS_PROCESS_LOGIC_TRIGGER_MODIFIED
                                                                + NODE_FLAG_IS_PROCESS_INPUT_TRIGGER_MODIFIED
                                                                + NODE_FLAG_IS_PROCESS_OUTPUT_TRIGGER_MODIFIED,
            };

            enum ConfigChangedTriggers
            {
                CONFIG_CHANGED_TRIGGER_NONE                     = 0,

                CONFIG_CHANGED_TRIGGER_ALWAYS                   = (1 << 0),
                CONFIG_CHANGED_TRIGGER_SURFACE_SIZE             = (1 << 1),
                CONFIG_CHANGED_TRIGGER_LANGUAGE                 = (1 << 2),

                CONFIG_CHANGED_TRIGGER_DIRTY                    = (1 << 31)
            };

            enum ProcessLogicTriggers
            {
                PROCESS_LOGIC_TRIGGER_NONE                      = 0,

                PROCESS_LOGIC_TRIGGER_ALWAYS                    = (1 << 0),
                PROCESS_LOGIC_TRIGGER_ACTIVE_SET                = (1 << 1),
                PROCESS_LOGIC_TRIGGER_UPDATE_TRANSFORM          = (1 << 2),
                PROCESS_LOGIC_TRIGGER_UPDATE_BOUNDING_VOLUME    = (1 << 3),

                PROCESS_LOGIC_TRIGGER_TIMELINE_0_RUNNING        = (1 << 8),
                PROCESS_LOGIC_TRIGGER_TIMELINE_1_RUNNING        = (1 << 9),
                PROCESS_LOGIC_TRIGGER_TIMELINE_2_RUNNING        = (1 << 10),
                PROCESS_LOGIC_TRIGGER_TIMELINE_3_RUNNING        = (1 << 11),
                PROCESS_LOGIC_TRIGGER_TIMELINE_4_RUNNING        = (1 << 12),
                PROCESS_LOGIC_TRIGGER_TIMELINE_5_RUNNING        = (1 << 13),
                PROCESS_LOGIC_TRIGGER_TIMELINE_6_RUNNING        = (1 << 14),
                PROCESS_LOGIC_TRIGGER_TIMELINE_7_RUNNING        = (1 << 15),
                PROCESS_LOGIC_TRIGGER_TIMELINE_8_RUNNING        = (1 << 16),
                PROCESS_LOGIC_TRIGGER_TIMELINE_9_RUNNING        = (1 << 17),
                PROCESS_LOGIC_TRIGGER_TIMELINE_10_RUNNING       = (1 << 18),
                PROCESS_LOGIC_TRIGGER_TIMELINE_11_RUNNING       = (1 << 19),
                PROCESS_LOGIC_TRIGGER_TIMELINE_12_RUNNING       = (1 << 20),
                PROCESS_LOGIC_TRIGGER_TIMELINE_13_RUNNING       = (1 << 21),
                PROCESS_LOGIC_TRIGGER_TIMELINE_14_RUNNING       = (1 << 22),
                PROCESS_LOGIC_TRIGGER_TIMELINE_15_RUNNING       = (1 << 23),

                PROCESS_LOGIC_TRIGGER_TIMELINE_RUNNING          = PROCESS_LOGIC_TRIGGER_TIMELINE_0_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_1_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_2_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_3_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_4_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_5_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_6_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_7_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_8_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_9_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_10_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_11_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_12_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_13_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_14_RUNNING
                                                                + PROCESS_LOGIC_TRIGGER_TIMELINE_15_RUNNING,

                PROCESS_LOGIC_TRIGGER_DIRTY                     = (1 << 31)
            };

            enum ProcessInputTriggers
            {
                PROCESS_INPUT_TRIGGER_NONE                      = 0,

                PROCESS_INPUT_TRIGGER_ALWAYS                    = (1 << 0),
                PROCESS_INPUT_TRIGGER_ACTIVE_SET                = (1 << 1),
                PROCESS_INPUT_TRIGGER_UPDATE_TRANSFORM          = (1 << 2),
                PROCESS_INPUT_TRIGGER_UPDATE_BOUNDING_VOLUME    = (1 << 3),

                PROCESS_INPUT_TRIGGER_DIRTY                     = (1 << 31)
            };

            enum ProcessOutputTriggers
            {
                PROCESS_OUTPUT_TRIGGER_NONE                     = 0,

                PROCESS_OUTPUT_TRIGGER_ALWAYS                   = (1 << 0),
                PROCESS_OUTPUT_TRIGGER_VISIBLE_SET              = (1 << 1),
                PROCESS_OUTPUT_TRIGGER_UPDATE_TRANSFORM         = (1 << 2),
                PROCESS_OUTPUT_TRIGGER_UPDATE_BOUNDING_VOLUME   = (1 << 3),

                PROCESS_OUTPUT_TRIGGER_DIRTY                    = (1 << 31)
            };

        public:
            /**
             * @brief Get the mutable INode interface.
             * @return The mutable INode interface.
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant INode interface.
             * @return The constant INode interface.
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Deserialize the node.
             * If a node is created from a read-only Resource::IGraph object, the factory calls
             * this method once so that the newly created node can obtain the respective
             * Resource::IGraphNode it was created from via the given tracker.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool DeserializeNode(IDeserializeAttributeTracker* tracker) = 0;
            /**
             * @brief Deserialize a node attribute.
             * A scene graph (or actually its individual nodes) may be created and initialized
             * from e.g. a read-only Resource::IGraph object that can be retrieved from a
             * Resource::ICollection instance. Setting all relevant node attributes from this
             * resource object can be done by iterating over all given attributes and calling
             * this method on the newly created node.
             * @param tracker The tracker used.
             * @return true if the given attribute was recognized.
             */
            virtual Bool DeserializeAttribute(IDeserializeAttributeTracker* tracker) = 0;

            /**
             * @brief Add a child node.
             * Add a given node as the next child of the current node.
             * @param child The child node to add.
             * @return true if successful.
             */
            virtual Bool AddChild(INode* child) = 0;
            /**
             * @brief Insert a child node at a given position.
             * Insert a given node at a given position of the current node's children.
             * @param child The child node to add.
             * @param index The zero-based index where to insert the node.
             * @return true if successful.
             */
            virtual Bool InsertChild(INode* child, UInt32 index) = 0;
            /**
             * @brief Remove a child.
             * Remove the first instance of a given child node from this node's children.
             * @param child The child node to remove.
             * @return The input node if successful, or null if the given node is not a child.
             */
            virtual INode* RemoveChild(INode* child) = 0;
            /**
             * @brief Remove a child from a given position.
             * Remove the child node specified by a given index.
             * @param index The zero-based index of the child to remove.
             * @return The removed child node if successful, or null if the index was out of range.
             */
            virtual INode* RemoveChild(UInt32 index) = 0;

            /**
             * @brief Get this node's children.
             * This returns a constant reference to this node's internal array of child nodes.
             * @return A reference to the child array.
             */
            virtual const INodeArray& GetChildren() const = 0;
            /**
             * @brief Return the child at a given position.
             * This returns a mutable pointer to this node's child at a given index.
             * @param index The zero-based index of the child.
             * @return A pointer to the child node, or null if the index was out of range.
             */
            virtual INode* GetChild(UInt32 index) = 0;
            /**
             * @brief Return the first child with a given ID.
             * This returns a mutable pointer to this node's child that has a given ID.
             * @param id The ID of the child to search for.
             * @return A pointer to the child node, or null if the ID was not found among the children.
             */
            virtual INode* GetChild(const String& id) = 0;
            /**
             * @brief Return the child at a given position.
             * This returns a constant pointer to this node's child at a given index.
             * @param index The zero-based index of the child.
             * @return A pointer to the child node, or null if the index was out of range.
             */
            virtual const INode* GetChild(UInt32 index) const = 0;
            /**
             * @brief Return the first child with a given ID.
             * This returns a constant pointer to this node's child that has a given ID.
             * @param id The ID of the child to search for.
             * @return A pointer to the child node, or null if the ID was not found among the children.
             */
            virtual const INode* GetChild(const String& id) const = 0;
            /**
             * @brief Return the index of a given child.
             * @param node The child node to query.
             * @return The zero-based index of the child, or -1 if not present.
             */
            virtual SInt32 GetChildIndex(const INode* node) const = 0;
            /**
             * @brief Return the index of a child with a given ID.
             * @param id The ID of the child node to query.
             * @return The zero-based index of the child, or -1 if not present.
             */
            virtual SInt32 GetChildIndex(const String& id) const = 0;
            /**
             * @brief Return the number of this node's children.
             * @return The number of this node's children.
             */
            virtual UInt32 GetNumberOfChildren() const = 0;

            /**
             * @brief Add a node parent at the end of the array of current parents.
             * By convention, the node's parent at index 0 represents the "real" parent, which is
             * defined during scene graph creation. Any parents at an index greater than 0 are
             * considered "virtual" parents, which result from a node being referenced multiple times
             * by e.g. a Graph::IReference node.
             * @param parent The parent to add.
             * @return true if successful.
             */
            virtual Bool AddParent(INode* parent) = 0;
            /**
             * @brief Insert a node parent at a given index.
             * @param parent The parent to add.
             * @param index The zero-based index into the array of parents.
             * @return true if successful.
             */
            virtual Bool InsertParent(INode* parent, UInt32 index) = 0;
            /**
             * @brief Remove a given parent.
             * @param parent The parent to remove from the node's array of parents.
             * @return The removed node, or a null pointer if failed.
             */
            virtual INode* RemoveParent(INode* parent) = 0;
            /**
             * @brief Remove the parent from a given index.
             * @param index The index into the node's array of parents.
             * @return The removed node, or a null pointer if failed.
             */
            virtual INode* RemoveParent(UInt32 index) = 0;

            /**
             * @brief Get a constant array of the node's parents.
             * @return The array of parents.
             */
            virtual const INodeArray& GetParents() const = 0;
            /**
             * @brief Get a mutable pointer to the node's parent at a given index.
             * @param index The index into the node's array of parents.
             * @return The parent at the given index.
             */
            virtual INode* GetParent(UInt32 index) = 0;
            /**
             * @brief Get a mutable pointer to the node's parent with the given node ID.
             * @param id The node ID of the parent to retrieve.
             * @return The parent with the given ID, or a null pointer if not found.
             */
            virtual INode* GetParent(const String& id) = 0;
            /**
             * @brief Get a constant pointer to the node's parent at a given index.
             * @param index The index into the node's array of parents.
             * @return The parent at the given index.
             */
            virtual const INode* GetParent(UInt32 index) const = 0;
            /**
             * @brief Get a constant pointer to the node's parent with the given node ID.
             * @param id The node ID of the parent to retrieve.
             * @return The parent with the given ID, or a null pointer if not found.
             */
            virtual const INode* GetParent(const String& id) const = 0;
            /**
             * @brief Return the index of a given parent.
             * @param node The parent node to query.
             * @return The zero-based index of the parent, or -1 if not present.
             */
            virtual SInt32 GetParentIndex(const INode* node) const = 0;
            /**
             * @brief Return the index of a parent with a given ID.
             * @param id The ID of the parent node to query.
             * @return The zero-based index of the parent, or -1 if not present.
             */
            virtual SInt32 GetParentIndex(const String& id) const = 0;
            /**
             * @brief Return the number of this node's parents.
             * @return The number of this node's parents.
             */
            virtual UInt32 GetNumberOfParents() const = 0;

            /**
             * @brief Add a node controller.
             * @param controller The controller to add
             * @return true if successful.
             */
            virtual Bool AddController(IController* controller) = 0;
            /**
             * @brief Insert a node controller at a given position.
             * Insert a given controller at a given position of the current node's controller array.
             * @param controller The controller to insert.
             * @param index The zero-based index where to insert the controller.
             * @return true if successful.
             */
            virtual Bool InsertController(IController* controller, UInt32 index) = 0;
            /**
             * @brief Remove a node controller.
             * Remove the first instance of a given controller from this node's controller array.
             * @param controller The controller to remove.
             * @return The input controller if successful, or null if the given controller is not present.
             */
            virtual IController* RemoveController(IController* controller) = 0;
            /**
             * @brief Remove a node controller from a given position.
             * Remove the controller specified by a given index.
             * @param index The zero-based index of the controller to remove.
             * @return The removed controller if successful, or null if the index was out of range.
             */
            virtual IController* RemoveController(UInt32 index) = 0;

            /**
             * @brief Get a constant array of the node's controllers.
             * @return The array of controllers.
             */
            virtual const IControllerArray& GetControllers() const = 0;
            /**
             * @brief Get a mutable pointer to the node's controller at a given index.
             * @param index The index into the node's array of controllers.
             * @return The controller at the given index, or null if the index is out of range.
             */
            virtual IController* GetController(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the node's controller at a given index.
             * @param index The index into the node's array of controllers.
             * @return The controller at the given index, or null if the index is out of range.
             */
            virtual const IController* GetController(UInt32 index) const = 0;
            /**
             * @brief Return the index of a given controller.
             * @param controller The controller to query.
             * @return The zero-based index of the controller, or -1 if not present.
             */
            virtual SInt32 GetControllerIndex(const IController* controller) const = 0;
            /**
             * @brief Return the number of this node's controllers.
             * @return The number of this node's controllers.
             */
            virtual UInt32 GetNumberOfControllers() const = 0;

            /**
             * @brief Get a mutable pointer to the namespace node this node belongs to.
             * @return A pointer to the current namespace node.
             */
            virtual INamespace* GetCurrentNamespace() = 0;
            /**
             * @brief Get a constant pointer to the namespace node this node belongs to.
             * @return A pointer to the current namespace node.
             */
            virtual const INamespace* GetCurrentNamespace() const = 0;
            /**
             * @brief Get a mutable pointer to the namespace node this node's parent belongs to.
             * @return A pointer to the parent namespace node.
             */
            virtual INamespace* GetParentNamespace() = 0;
            /**
             * @brief Get a constant pointer to the namespace node this node's parent belongs to.
             * @return A pointer to the parent namespace node.
             */
            virtual const INamespace* GetParentNamespace() const = 0;
            /**
             * @brief Get a mutable pointer to the root namespace node.
             * @return A pointer to the root namespace node.
             */
            virtual INamespace* GetRootNamespace() = 0;
            /**
             * @brief Get a constant pointer to the root namespace node.
             * @return A pointer to the root namespace node.
             */
            virtual const INamespace* GetRootNamespace() const = 0;

            /**
             * @brief Set the node ID.
             * A node may have an optional ID, by which it can later be referenced from another node in the
             * scene graph, or from a Logic::IProcessor to directly manipulate the node's properties from code.
             * A valid node ID can only contain underscores ('_'), digits ('0'..'9') and/or alphabetic characters
             * ('a'..'z' and 'A'..'Z'), and must not begin with a digit. In addition, node IDs must be unique
             * within a common namespace.\n
             * See Graph::INamespace for examples of how to refer to individual nodes by their ID.
             * @param id The node ID to set.
             * @return true if successful.
             */
            virtual Bool SetId(const String& id) = 0;
            /**
             * @brief Get the node ID.
             * @return The node ID.
             */
            virtual const String& GetId() const = 0;

            /**
             * @brief Calculate the absolute path to the node.
             * @return The node path.
             */
            virtual String GetPath() const = 0;

            /**
             * @brief Check if this node is considered private.
             * If a node is marked private, it is not possible to reference that node or any of its
             * children from outside the sub-graph beneath that node.
             * @return true if private.
             */
            virtual Bool IsPrivate() const = 0;

            /**
             * @brief Define whether this node represents the head of a sub-graph.
             * When a sub-graph is created and added as a child of an existing scene graph node, this
             * method must be called on the sub-graph's top node with isHead set to true. This must
             * be done in order to detect any sub-graphs that were not correctly detached and destroyed
             * before their respective parent graph is destroyed. Failing to do so may result in memory
             * leaks or invalid node pointers.
             * @param isHead If true, the node is set to be a head node.
             * @return true if successful.
             */
            virtual Bool SetHead(Bool isHead) = 0;
            /**
             * @brief Check whether this node represents the head of a sub-graph.
             * @return true if the node is a head node.
             */
            virtual Bool IsHead() const = 0;

            /**
             * @brief Lock/unlock the node.
             * Creating and destroying sub-graphs is usually an asynchronous task that is carried out
             * in multiple stages. To prevent interference with regular graph traversals, it is necessary
             * to have a sub-graph locked whenever it being initialized or deinitialized while it is
             * linked to another scene graph node. Therefore, this method must be called with isLocked
             * set to true prior to inserting it into the scene graph or prior to deinitializing it.
             * The sub-graph may only be safely unlocked after it has been fully initialized, or detached
             * from its parent.
             * @param isLocked If true, the node gets locked for regular traversals.
             * @return true if successful.
             */
            virtual Bool SetLocked(Bool isLocked) = 0;
            /**
             * @brief Check if this node is locked for regular traversals.
             * See SetLocked().
             * @return true if locked.
             */
            virtual Bool IsLocked() const = 0;

            /**
             * @brief Set/clear the node's initial swap state.
             * The node's swapped state is used as a hint to the engine, so that the node may decide
             * to delay creation of any internal objects until they are actually used. This is usually
             * the case for e.g. textures, which consume a large amount of video memory. Here, setting
             * the node's swapped state results in not creating the video memory resources until the
             * texture is referenced for the first time. By default, the swapped state is disabled.
             * Note that this property can only be set before the node is initialized, after that the
             * method returns false.
             * @param isSwapped The swap state of the node.
             * @return true if successful.
             */
            virtual Bool SetSwapped(Bool isSwapped) = 0;
            /**
             * @brief Check if this node is initially in the swapped state.
             * See SetSwapped().
             * @return true if in the swapped state.
             */
            virtual Bool IsSwapped() const = 0;

            /**
             * @brief Enable/disable auto-swapping for this node.
             * When enabled, the engine may decide to swap-out any node-specific resources when they
             * have not been used during the last frame. Like the initial swap state set via
             * SetSwapped(), this is only a hint and applies to certain nodes only, such as textures.
             * By default, this feature is disabled. Note also that auto-swapping can only be set before
             * the node is initialized.
             * When auto-swapping is enabled, it is usually a good idea to also set the initial swap
             * state to true (via SetSwapped()), as otherwise the node's resources are created at
             * initialization and possibly immediately swapped out when the node is not being used
             * in the following frame.
             * @param enabled If true, auto swapping is enabled.
             * @return true if successful.
             */
            virtual Bool SetAutomaticSwappingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if auto-swapping is enabled for this node.
             * See SetSwappable().
             * @return true if enabled.
             */
            virtual Bool IsAutomaticSwappingEnabled() const = 0;

            /**
             * @brief Enable/disable manual swapping for this node.
             * When enabled, the user can trigger a swap-out of any node-specific resources when they
             * have not been used during the last frame, by calling the TriggerSwapping() method on
             * the Graph::IRoot object that can be accessed e.g. via the Logic::IState object.
             * See SetAutomaticSwappingEnabled().
             * @param enabled If true, manual swapping is enabled.
             * @return true if successful.
             */
            virtual Bool SetManualSwappingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if manual swapping is enabled for this node.
             * See SetManualSwappingEnabled().
             * @return true if enabled.
             */
            virtual Bool IsManualSwappingEnabled() const = 0;

            /**
             * @brief Enable/disable state recording for this node.
             * @param enabled If true, state recording is enabled.
             * @return true if successful.
             */
            virtual Bool SetStateRecordingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if state recording is enabled for this node.
             * See SetStateRecordingEnabled().
             * @return true if enabled.
             */
            virtual Bool IsStateRecordingEnabled() const = 0;

            /**
             * @brief Set/reset the initialized state of the node.
             * @param isInitialized If true, the node is set to the initialized state.
             * @return true if successful.
             */
            virtual Bool SetInitialized(Bool isInitialized) = 0;
            /**
             * @brief Check if this node is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;

            /**
             * @brief Set/reset whether the finish logic traversal is pending.
             * @param pending The pending state.
             * @return true if successful.
             */
            virtual Bool SetFinishLogicPending(Bool pending) = 0;
            /**
             * @brief Check whether the finish logic traversal is pending.
             * @return true if pending.
             */
            virtual Bool IsFinishLogicPending() const = 0;

            /**
             * @brief Set/reset whether the finish input traversal is pending.
             * @param pending The pending state.
             * @return true if successful.
             */
            virtual Bool SetFinishInputPending(Bool pending) = 0;
            /**
             * @brief Check whether the finish input traversal is pending.
             * @return true if pending.
             */
            virtual Bool IsFinishInputPending() const = 0;

            /**
             * @brief Set/reset whether the finish output traversal is pending.
             * @param pending The pending state.
             * @return true if successful.
             */
            virtual Bool SetFinishOutputPending(Bool pending) = 0;
            /**
             * @brief Check whether the finish output traversal is pending.
             * @return true if pending.
             */
            virtual Bool IsFinishOutputPending() const = 0;

            /**
             * @brief Set/reset the "bounding volume modified" state of the node.
             * The "bounding volume modified" state signals that there was some modification of one
             * or more of the nodes within this node's sub-graph which affects this node's overall
             * bounding volume.
             * If isModified is true, the change is propagated to all of the node's parents, whereas
             * a value of false clears this state in all of the node's child sub-graphs. This propagation
             * is only done when the node is not locked.
             * See SetModifiedFlags() and ClearModifiedFlags(), together with NODE_FLAG_IS_BOUNDING_VOLUME_MODIFIED.
             * @param isModified If true, the bounding volume is flagged as modified.
             * @return true if successful.
             */
            virtual Bool SetBoundingVolumeModified(Bool isModified) = 0;
            /**
             * @brief Check if the overall bounding volume was modified.
             * @return true if modified.
             */
            virtual Bool IsBoundingVolumeModified() const = 0;

            /**
             * @brief Set the "active modified" state of the node.
             * @return true if successful.
             */
            virtual Bool SetActiveModified() = 0;
            /**
             * @brief Set the "visible modified" state of the node.
             * @return true if successful.
             */
            virtual Bool SetVisibleModified() = 0;

            /**
             * @brief Set a combination of "modified" flags.
             * This method sets the given flag bits in the node's internal state. The change is propagated
             * to all of the node's parents when the node is unlocked.
             * See SetBoundingVolumeModified().
             * @param flags The bit mask of flags to set.
             * @return true if successful.
             */
            virtual Bool SetModifiedFlags(UInt32 flags) = 0;
            /**
             * @brief Clear a combination of "modified" flags.
             * This method clears the given flag bits in the node's internal state. The change is propagated
             * to all of the node's child sub-graphs when the node is unlocked.
             * See SetBoundingVolumeModified().
             * @param flags The bit mask of flags to clear.
             * @return true if successful.
             */
            virtual Bool ClearModifiedFlags(UInt32 flags) = 0;

            /**
             * @brief set current flags.
             * (!) Use with caution! Messing around with node flags may cause undefined behavior.
             * @param flags The flags bit mask.
             * @return true if successful.
             */
            virtual Bool SetNodeFlags(UInt32 flags) = 0;
            /**
             * @brief Get current flags.
             * @return A bit mask made up from individual NodeFlags values.
             */
            virtual UInt32 GetNodeFlags() const = 0;
            /**
             * @brief Get the traversal states that are modified by the node and its sub-graph.
             * @return A bit mask of individual IEnums::TraversalState values.
             */
            virtual UInt32 GetModifiedTraversalStates() const = 0;

            /**
             * @brief Increment the node's internal reference counter by 1.
             * Whenever a node is persistently referenced from a different location in the application,
             * this method must be called to indicate that it must not be destroyed, to prevent existing
             * pointers to become invalid. Using a Graph::IReference node automatically performs this
             * task together with its counterpart RemoveReference(), as do the individual Logic::GraphNodeT
             * helpers. If a node is directly referenced from user code, it is up to the user to correctly
             * increment/decrement the node's reference counter.
             * A sub-graph can only be correctly destroyed when all of its children have a reference
             * counter of 0.
             * @return true if successful.
             */
            virtual Bool AddReference() = 0;
            /**
             * @brief Increment the node's internal reference counter by 1.
             * See AddReference().
             * @return true if successful.
             */
            virtual Bool RemoveReference() = 0;

            /**
             * @brief Initialize the node and its sub-graph.
             * @param tracker The tracker used for initialization.
             * @return true if successful.
             */
            virtual Bool Init(IInitTracker* tracker) = 0;
            /**
             * @brief Deinitialize the node and its sub-graph.
             * @param tracker The tracker used for deinitialization.
             * @return true if successful.
             */
            virtual Bool DeInit(IDeInitTracker* tracker) = 0;
            /**
             * @brief Suspend the node and its sub-graph.
             * @param tracker The tracker used for suspension.
             * @return true if successful.
             */
            virtual Bool Suspend(IDeInitTracker* tracker) = 0;
            /**
             * @brief Resume the node and its sub-graph.
             * @param tracker The tracker used for resumption.
             * @return true if successful.
             */
            virtual Bool Resume(IInitTracker* tracker) = 0;

            /**
             * @brief Signal a configuration change relevant for the node's logic traversal.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool ConfigChangedLogic(IConfigChangedTracker* tracker) = 0;
            /**
             * @brief Signal a configuration change relevant for the node's output traversal.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool ConfigChangedOutput(IConfigChangedTracker* tracker) = 0;

            /**
             * @brief Perform a logic traversal on the node and its sub-graph.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool ProcessLogic(IProcessLogicTracker* tracker) = 0;
            /**
             * @brief Perform an input traversal on the node and its sub-graph.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool ProcessInput(IProcessInputTracker* tracker) = 0;
            /**
             * @brief Perform an output traversal on the node and its sub-graph.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool ProcessOutput(IProcessOutputTracker* tracker) = 0;

            /**
             * @brief Finalize the logic traversal if requested by the node.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool FinishLogic(IFinishLogicTracker* tracker) = 0;
            /**
             * @brief Finalize the input traversal if requested by the node.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool FinishInput(IFinishInputTracker* tracker) = 0;
            /**
             * @brief Finalize the output traversal if requested by the node.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool FinishOutput(IFinishOutputTracker* tracker) = 0;

            /**
             * @brief Check if a parent was recently activated.
             * @param tracker The tracker used.
             * @return true if at least one of the node's parents was recently activated.
             */
            virtual Bool WasParentActiveSet(IProcessLogicTracker* tracker) const = 0;
            /**
             * @brief Check if a parent was recently set visible.
             * @param tracker The tracker used.
             * @return true if at least one of the node's parents was recently set visible.
             */
            virtual Bool WasParentVisibleSet(IProcessOutputTracker* tracker) const = 0;

            /**
             * @brief Set the node handle used to store unique information during traversal.
             * @param handle The node handle to set.
             * @return true if successful.
             */
            virtual Bool SetHandle(IHandle* handle) = 0;
            /**
             * @brief Get the node handle used during traversal, or null if not used.
             * @return A mutable pointer to the optional node handle.
             */
            virtual IHandle* GetHandle() = 0;
            /**
             * @brief Get the node handle used during traversal, or null if not used.
             * @return A constant pointer to the optional node handle.
             */
            virtual const IHandle* GetHandle() const = 0;

            /**
             * @brief Set a custom user data object.
             * @param userData The user data object to set, or null to remove.
             * @return true if successful.
             */
            virtual Bool SetUserData(void* userData) = 0;
            /**
             * @brief Get the node's user data object, or null if not set.
             * @return A mutable pointer to the user data object.
             */
            virtual void* GetUserData() = 0;
            /**
             * @brief Get the node's user data object, or null if not set.
             * @return A constant pointer to the user data object.
             */
            virtual const void* GetUserData() const = 0;

            /**
             * @brief Create a bounding volume.
             * @return The bounding volume.
             */
            virtual IBoundingVolume* CreateBoundingVolume() const = 0;
            /**
             * @brief Destroy a given bounding volume.
             * @param boundingVolume A reference to the bounding volume pointer. After
             *      destruction, the pointer will be set to null.
             * @return true if successful.
             */
            virtual Bool DestroyBoundingVolume(IBoundingVolume*& boundingVolume) const = 0;
            /**
             * @brief Get the node's bounding volume, if present.
             * @return The bounding volume, or null if the node does not have one.
             */
            virtual IBoundingVolume* GetBoundingVolume() = 0;
            /**
             * @brief Get the node's bounding volume, if present.
             * @return The bounding volume, or null if the node does not have one.
             */
            virtual const IBoundingVolume* GetBoundingVolume() const = 0;

            /**
             * @brief Get the node's active triggers for config change traversal.
             * @param mask A bit mask of triggers to check, from the ConfigChangedTriggers enumeration.
             * @return A bit mask of traversal triggers initiated by this node with respect
             *  to the given mask.
             */
            virtual UInt32 GetConfigChangedTriggers(UInt32 mask) const = 0;
            /**
             * @brief Get the node's active triggers for logic traversal.
             * @param mask A bit mask of triggers to check, from the ProcessLogicTriggers enumeration.
             * @return A bit mask of traversal triggers initiated by this node with respect
             *  to the given mask.
             */
            virtual UInt32 GetProcessLogicTriggers(UInt32 mask) const = 0;
            /**
             * @brief Get the node's active triggers for input traversal.
             * @param mask A bit mask of triggers to check, from the ProcessInputTriggers enumeration.
             * @return A bit mask of traversal triggers initiated by this node with respect
             *  to the given mask.
             */
            virtual UInt32 GetProcessInputTriggers(UInt32 mask) const = 0;
            /**
             * @brief Get the node's active triggers for output traversal.
             * @param mask A bit mask of triggers to check, from the ProcessOutputTriggers enumeration.
             * @return A bit mask of traversal triggers initiated by this node with respect
             *  to the given mask.
             */
            virtual UInt32 GetProcessOutputTriggers(UInt32 mask) const = 0;

            /**
             * @brief Get the node's active response for config change traversal.
             * @return A bit mask of traversal triggers this node will respond to, from the
             *  ConfigChangedTriggers enumeration.
             */
            virtual UInt32 GetConfigChangedResponse() const = 0;
            /**
             * @brief Get the node's active response for logic traversal.
             * @return A bit mask of traversal triggers this node will respond to, from the
             *  ProcessLogicTriggers enumeration.
             */
            virtual UInt32 GetProcessLogicResponse() const = 0;
            /**
             * @brief Get the node's active response for input traversal.
             * @return A bit mask of traversal triggers this node will respond to, from the
             *  ProcessInputTriggers enumeration.
             */
            virtual UInt32 GetProcessInputResponse() const = 0;
            /**
             * @brief Get the node's active response for output traversal.
             * @return A bit mask of traversal triggers this node will respond to, from the
             *  ProcessOutputTriggers enumeration.
             */
            virtual UInt32 GetProcessOutputResponse() const = 0;

            /**
             * @brief Add the response of a node's child to a config change traversal.
             * @param mask A bit mask of triggers to add to the traversal response, from the
             *  ConfigChangedTriggers enumeration.
             * @return true if successful.
             */
            virtual Bool AddChildConfigChangedResponse(UInt32 mask) = 0;
            /**
             * @brief Add the response of a node's child to a logic traversal.
             * @param mask A bit mask of triggers to add to the traversal response, from the
             *  ProcessLogicTriggers enumeration.
             * @return true if successful.
             */
            virtual Bool AddChildProcessLogicResponse(UInt32 mask) = 0;
            /**
             * @brief Add the response of a node's child to a input traversal.
             * @param mask A bit mask of triggers to add to the traversal response, from the
             *  ProcessInputTriggers enumeration.
             * @return true if successful.
             */
            virtual Bool AddChildProcessInputResponse(UInt32 mask) = 0;
            /**
             * @brief Add the response of a node's child to a output traversal.
             * @param mask A bit mask of triggers to add to the traversal response, from the
             *  ProcessOutputTriggers enumeration.
             * @return true if successful.
             */
            virtual Bool AddChildProcessOutputResponse(UInt32 mask) = 0;

            /**
             * @brief Get the class info structure of the default controller for this node.
             * @return The default controller class info.
             */
            virtual const IController::ClassInfo& GetDefaultControllerClassInfo() const = 0;

            /**
             * @brief Print the node and its sub-graph to the system console.
             * @param indent The number of spaces to add in front of each output text line.
             * @param includeNodeFlags A bit mask made up from individual NodeFlags values
             *  specifying the nodes to include into the output (default is all flags).
             * @param excludeNodeFlags A bit mask made up from individual NodeFlags values
             *  specifying the nodes to exclude from the output (default is no flags).
             * @return true if successful.
             */
            virtual Bool PrintTree(UInt32 indent = 0, UInt32 includeNodeFlags = UInt32(~0),
                                   UInt32 excludeNodeFlags = 0) const = 0;

        protected:
            virtual ~INode() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::INode nodes.
         */
        typedef IGenericNodeTarget<INode> INodeTarget;
    }
}

#endif // __MURL_GRAPH_I_NODE_H__

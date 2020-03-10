// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ROOT_H__
#define __MURL_GRAPH_I_ROOT_H__

#include "murl_graph_types.h"

namespace Murl
{
    class IAttributes;

    namespace Resource
    {
        class IGraph;
    };

    namespace Graph
    {
        class IController;
        class INode;
        class INamespace;
        class ITrackerResult;

        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface IRoot
         * @brief The IRoot interface.
         * This interface represents the root of a scene graph, containing exactly one Graph::INode
         * as the actual root of the graph where other nodes can be inserted.
         * The root object holds a reference to a Graph::IFactory object, so it is possible to create
         * or destroy individual nodes or sub-graphs via respective methods.
         */
        class IRoot
        {
        public:
            /**
             * @brief Get the actual root node.
             * @return The root node.
             */
            virtual INode* GetRootNode() const = 0;

            /**
             * @brief Get the actual root namespace node.
             * @return The root namespace node.
             */
            virtual INamespace* GetRootNamespace() const = 0;

            /**
             * @brief Find a node in the graph by its ID.
             * Named nodes in the scene graph can be hierarchically organized using Graph::INamespace
             * nodes. Namespaces provide a means of accessing individual named nodes using a file-system
             * like path scheme, with the '/' character serving as a namespace delimiter.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return A pointer to the requested node, or null if not found.
             */
            virtual INode* FindNode(const String& nodeIdPath) const = 0;

            /**
             * @brief Check if graph modifications are currently allowed.
             * When the engine is in the middle of a scene graph traversal, it is usually a bad idea to
             * perform any structural modifications (e.g. adding or removing nodes) of the graph from
             * within a different thread context. Modifications should only occur when this method
             * returns true, i.e. the graph is currently idle.
             * @return true if modifications are allowed.
             */
            virtual Bool CanModifyGraph() const = 0;

            /**
             * @brief Create a single unnamed node by its class name.
             * This method creates a single node using the underlying graph factory. The newly created
             * node is not yet inserted into the graph; instead, it is possible to create a number of
             * individual nodes and create an entire sub-graph (e.g. using Graph::INode::AddChild())
             * before actually adding them to the graph. Adding (and initializing) such a sub-graph
             * must be done via InitGraph().
             * @param className The node class name.
             * @return A pointer to the newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className) = 0;
            /**
             * @brief Create a single named node by its class name, using a given node ID.
             * This is equivalent to calling CreateNode(className) followed by a call to
             * Graph::INode::SetId(nodeId).
             * @param className The node class name.
             * @param nodeId The node ID.
             * @return A pointer to the newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className, const String& nodeId) = 0;
            /**
             * @brief Create a single node by its class name, given attributes and optional parameters.
             * @param className The node class name.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return A pointer to the newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Create a single node by its class name, with given base resource path, attributes and optional parameters.
             * @param className The class name of the node to create.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Destroy a single node.
             * This method fails if the given node has children attached. Use DestroyGraph() when
             * it is desired to recursively destroy an entire sub-graph.
             * This method also fails when the given node is still initialized. Use DeInitGraph()
             * on that node before actually destroying it.
             * @param node The node to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyNode(INode* node) = 0;

            /**
             * @brief Create a sub-graph from a given graph resource template.
             * This method creates a sub-graph using the instantiation information present in a given
             * graph resource template, which can be obtained from e.g. a Resource::ICollection object.
             * If successful, the root node of the newly created sub-graph is returned.
             * @param graphResource The graph resource template from which to create the sub-graph.
             * @return A pointer to the root of the newly created sub-graph, or null if failed.
             */
            virtual INode* CreateGraph(const Resource::IGraph* graphResource) = 0;
            /**
             * @brief Create a sub-graph from a given graph resource template, with given parameters.
             * This method can be used to create a sub-graph in the same way as CreateGraph(graphResource),
             * with an additional set of user-defined parameters.
             * @param graphResource The graph resource template from which to create the sub-graph.
             * @param params An attributes object containing custom parameters used for instantiation.
             * @return A pointer to the root of the newly created sub-graph, or null if failed.
             */
            virtual INode* CreateGraph(const Resource::IGraph* graphResource, const IAttributes* params) = 0;
            /**
             * @brief Destroy an entire sub-graph.
             * The sub-graph represented by the given node must be de-initialized using DeInitGraph()
             * before it can be destroyed.
             * @param node The root node of the sub-graph to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyGraph(INode* node) = 0;

            /**
             * @brief Deserialize a given node from a set of attributes and optional parameters.
             * @param node The node to deserialize.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeNodeAttributes(INode* node, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Deserialize a given node from a set of attributes and optional parameters, with a given base resource path.
             * @param node The node to deserialize.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeNodeAttributes(INode* node, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) = 0;

            /**
             * @brief Attach a sub-graph to the scene graph and initialize it.
             * After creating a single node or sub-graph, it must be attached and initialized in order
             * to get processed. This method adds the sub-graph represented by rootNode as a child of
             * the given parentNode and recursively calls Init() on that node.
             * If it is desired to add the given sub-graph right at the scene graph root, the parentNode
             * parameter may be obtained by calling GetRootNode().
             * @param rootNode The root of the sub-graph to add and initialize.
             * @param parentNode The parent node where to insert.
             * @param index The position within the parent node, or -1 if appending at the end.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool InitGraph(INode* rootNode, INode* parentNode, SInt32 index = -1, Bool releaseLock = true) = 0;
            /**
             * @brief De-initialize a sub-graph and detach it from the scene graph.
             * Before destroying a previously created node or sub-graph, it must be de-initialzed and
             * detached using this method.
             * @param rootNode The root of the sub-graph to de-init.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool DeInitGraph(INode* rootNode, Bool releaseLock = true) = 0;

            /**
             * @brief Initialize a single node and its sub-graph.
             * This method performs initialization of a node that is already attached to a parent.
             * @param rootNode The root of the sub-graph to initialize.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool InitNode(INode* rootNode, Bool releaseLock = true) = 0;
            /**
             * @brief De-initialize a sub-graph.
             * @param rootNode The root of the sub-graph to de-init.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool DeInitNode(INode* rootNode, Bool releaseLock = true) = 0;

            /**
             * @brief Create a node controller by its class name.
             * This method creates a node controller using the underlying graph factory.
             * The "owner" parameter specifies which graph node shall be controlled, without having to
             * add the controller to that node in the first place. This way, any number of controllers
             * can be prepared for a node, and dynamically added/removed to/from the node during program 
             * execution without having to re-initialize the controllers.
             * The controller must manually be added to the owner (even when an owner was given
             * in this call) to be processed. If it is added before the node gets initialized, it is
             * automatically initialized together with the controlled node. Otherwise the controller
             * must explicitly be initialized via InitController().
             * The same applies when de-initializing/destroying the owner: If the controller is still
             * attached, it gets automatically de-initialized/destroyed together with the owner.
             * Otherwise, DeInitController()/DestroyController() must be called manually.
             * The owner may be a null pointer at creation time, but in this case an explicit owner
             * must be set via Graph::IController::SetOwner() before InitController() can be called.
             * Theoretically it is possible to add the controller to a node that is different to the
             * specified owner, but such a setup should be used with care. In practice, one should take
             * care that the controller is only added to its defined owner.
             * @param className The controller class name.
             * @param owner The owning node.
             * @return A pointer to the newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, Graph::INode* owner) = 0;
            /**
             * @brief Create a node controller by its class name, given attributes and optional parameters.
             * See CreateController(const String& className, Graph::INode* owner).
             * @param className The controller class name.
             * @param owner The owning node.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return A pointer to the newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, Graph::INode* owner, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Create a node controller by its class name, with given base resource path, attributes and optional parameters.
             * See CreateController(const String& className, Graph::INode* owner).
             * @param className The class name of the controller to create.
             * @param owner The owning node.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, Graph::INode* owner, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Destroy a node controller.
             * See CreateController(const String& className, Graph::INode* owner).
             * @param controller The controller to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyController(IController* controller) = 0;

            /**
             * @brief Deserialize a given controller from a set of attributes and optional parameters.
             * @param controller The controller to deserialize.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeControllerAttributes(IController* controller, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Deserialize a given controller from a set of attributes and optional parameters, with a given base resource path.
             * @param controller The controller to deserialize.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeControllerAttributes(IController* controller, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) = 0;

            /**
             * @brief Initialize a node controller.
             * See CreateController(const String& className, Graph::INode* owner).
             * This method performs initialization of a controller that is not yet added to
             * an owning node.
             * @param controller The controller to initialize.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool InitController(IController* controller, Bool releaseLock = true) = 0;
            /**
             * @brief De-initialize a node controller.
             * See CreateController(const String& className, Graph::INode* owner).
             * @param controller The controller to de-init.
             * @param releaseLock If false, it is implicitly assumed that the logic state is unlocked.
             *  Use with caution! This only works when it is ensured that this method is executed
             *  outside a single frame loop.
             * @return true if successful.
             */
            virtual Bool DeInitController(IController* controller, Bool releaseLock = true) = 0;

            /**
             * @brief Acquire a unique ID for pushing/popping user data objects on a tracker.
             * @param uniqueName A unique name string for which to acquire an ID.
             * @return The unique ID, or -1 if failed.
             */
            virtual SInt32 AcquireUserDataId(const String& uniqueName) = 0;
            /**
             * @brief Release a previously acquired unique user data ID.
             * @param uniqueName The unique name string of the ID to release.
             * @return true if the released ID is still in use by another class,
             *      or false if this was the last instance or the ID was unknown.
             */
            virtual Bool ReleaseUserDataId(const String& uniqueName) = 0;

            /**
             * @brief Push a user data object with given ID for initialization/deinitialization.
             * @param id The unique user data ID previously acquired via AcquireUserDataId().
             * @param userData The user data object.
             * @return true if successful.
             */
            virtual Bool PushUserData(SInt32 id, void* userData) = 0;
            /**
             * @brief Pop a user data object with a given ID.
             * @param id The unique user data ID previously acquired via AcquireUserDataId().
             * @return true if successful.
             */
            virtual Bool PopUserData(SInt32 id) = 0;
            /**
             * @brief Get the most recent user data object with a given ID.
             * @param id The unique user data ID previously acquired via AcquireUserDataId().
             * @return The user data object, or null if none is present.
             */
            virtual void* GetRecentUserData(SInt32 id) const = 0;

            /**
             * @brief Trigger swapping of scene graph nodes.
             * Certain memory-intensive nodes (e.g. Graph::FlatTexture) support on-demand swapping of
             * their internal data storage when they are not currently active. This method triggers
             * such a single swapping process on the whole scene graph; any nodes that have manual
             * swapping enabled (e.g. by calling Graph::INode::SetManualSwappingEnabled()) react
             * on this event and try to release any currently unused memory resources.
             * Calling this method is useful after e.g. a memory warning from the OS, or if the
             * application hides a certain scene.
             * @return true if successful.
             */
            virtual Bool TriggerSwapping() = 0;

            /**
             * @brief Print the entire scene graph to the system console.
             * @return true if successful.
             */
            virtual Bool PrintTree() const = 0;

            /**
             * @brief Lock the scene graph to prevent modifications.
             * @return true if successful.
             */
            virtual Bool Lock() = 0;
            /**
             * @brief Unlock the scene graph after it has been locked.
             * @return true if successful.
             */
            virtual Bool Unlock() = 0;

            /**
             * @brief Cancel the finish logic traversal for a given node.
             * @param node The node to cancel.
             * @return true if successful.
             */
            virtual Bool CancelFinishLogic(INode* node) = 0;
            /**
             * @brief Cancel the finish input traversal for a given node.
             * @param node The node to cancel.
             * @return true if successful.
             */
            virtual Bool CancelFinishInput(INode* node) = 0;
            /**
             * @brief Cancel the finish outout traversal for a given node.
             * @param node The node to cancel.
             * @return true if successful.
             */
            virtual Bool CancelFinishOutput(INode* node) = 0;

            /**
             * @brief Get the array of result messages added during the last call to
             *  InitGraph() or InitNode().
             * @return The array of messages.
             */
            virtual const Array<const ITrackerResult*>& GetInitResults() const = 0;
            /**
             * @brief Get the array of result messages added during the last call to
             *  DeInitGraph() or DeInitNode().
             * @return The array of messages.
             */
            virtual const Array<const ITrackerResult*>& GetDeInitResults() const = 0;

        protected:
            virtual ~IRoot() {}
        };
    }
}

#endif // __MURL_GRAPH_I_ROOT_H__

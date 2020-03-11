// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FACTORY_H__
#define __MURL_GRAPH_I_FACTORY_H__

#include "murl_graph_i_factory_registry.h"

namespace Murl
{
    class IAppConfiguration;
    
    namespace Video
    {
        class IRenderer;
    }
    namespace Audio
    {
        class IRenderer;
    }
    
    namespace Input
    {
        class ITouchableHandler;
    }
    
    namespace Output
    {
        class IDeviceHandler;
    }
    
    namespace Physics
    {
        class ISimulator;
    }
    
    namespace Resource
    {
        class ICollection;
        class IGraph;
        class IGraphNode;
    }
    
    namespace Graph
    {
        class IProcessInputTracker;
        class IFinishInputTracker;
        class IProcessOutputTracker;
        class IFinishOutputTracker;
        class IInitTracker;
        class IDeInitTracker;
        class IConfigChangedTracker;
        class IMultiTouchable;
        class ITouchableTarget;
        class IRoot;
        
        /**
         * @ingroup MurlGraphFactoryInterfaces
         * @interface IFactory
         * @brief The factory class used to create and destroy graph objects.
         * Use the Graph::IFactoryRegistry base interface for managing registered
         * node classes.
         */
        class IFactory : public IFactoryRegistry
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Set the graph root object.
             * @param root The root object.
             * @return true if successful.
             */
            virtual Bool SetRoot(IRoot* root) = 0;
            /**
             * @brief Get the graph root object.
             * @return The root object, or null if not set.
             */
            virtual const IRoot* GetRoot() const = 0;
            
            /**
             * @brief Create the multi-touchable object.
             * @param touchableTarget The ITouchableTarget interface.
             * @return The created multi-touchable object, or null if failed.
             */
            virtual IMultiTouchable* CreateMultiTouchable(ITouchableTarget* touchableTarget) = 0;
            /**
             * @brief Destroy the multi-touchable object.
             * @param multiTouchable A reference to the multi-touchable pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyMultiTouchable(IMultiTouchable*& multiTouchable) = 0;
            
            /**
             * @brief Create a single node by its class info.
             * @param classInfo The class info structure of the node to create.
             * @return The newly created node, or null if failed.
             */
            virtual INode* CreateNode(const INode::ClassInfo& classInfo) const = 0;
            /**
             * @brief Create a single node by its class name.
             * @param className The class name of the node to create.
             * @return The newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className) const = 0;
            /**
             * @brief Create a single node by its class name, with given attributes and optional parameters.
             * @param className The class name of the node to create.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className, const IAttributes* attributes, const IAttributes* parameters) const = 0;
            /**
             * @brief Create a single node by its class name, with given base resource path, attributes and optional parameters.
             * @param className The class name of the node to create.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created node, or null if failed.
             */
            virtual INode* CreateNode(const String& className, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) const = 0;

            /**
             * @brief Create a node graph from a given graph resource.
             * @param graphResource The graph resource object holding the graph
             *      creation template.
             * @param params Optional parameters used for graph node deserialization,
             *      or null if no parameters should be used.
             * @return The root node of the newly created graoh, or null if failed.
             */
            virtual INode* CreateGraph(const Resource::IGraph* graphResource, const IAttributes* params) const = 0;
            /**
             * @brief Create a node graph from a given graph resource node.
             * @param graphResourceNode The graph resource node object holding the graph
             *      creation template.
             * @param params Optional parameters used for graph node deserialization,
             *      or null if no parameters should be used.
             * @return The root node of the newly created graoh, or null if failed.
             */
            virtual INode* CreateGraph(const Resource::IGraphNode* graphResourceNode, const IAttributes* params) const = 0;
            /**
             * @brief Recursively destroy a node graph, starting at the given root node.
             * @param rootNode A reference to the root node pointer. After destruction,
             *      the pointer will be set to null.
             * @return true if successful.
             */
            virtual Bool DestroyGraph(INode*& rootNode) const = 0;

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
             * @brief Create a node controller by its class info.
             * @param classInfo The class info structure of the controller to create.
             * @param owner The owner node of the controller.
             * @return The newly created controller, or null if failed.
             */
            virtual IController* CreateController(const IController::ClassInfo& classInfo, INode* owner) const = 0;
            /**
             * @brief Create a node controller by its class name.
             * @param className The class name of the controller to create.
             * @param owner The owner node of the controller.
             * @return The newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, INode* owner) const = 0;
            /**
             * @brief Create a node controller by its class name, with given attributes and optional parameters.
             * @param className The class name of the controller to create.
             * @param owner The owner node of the controller.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, INode* owner, const IAttributes* attributes, const IAttributes* parameters) const = 0;
            /**
             * @brief Create a node controller by its class name, with given base resource path, attributes and optional parameters.
             * @param className The class name of the controller to create.
             * @param owner The owner node of the controller.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes to deserialize.
             * @param parameters The optional parameters.
             * @return The newly created controller, or null if failed.
             */
            virtual IController* CreateController(const String& className, INode* owner, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) const = 0;
            /**
             * @brief Destroy a given node controller.
             * @param controller A reference to the controller pointer. After destruction,
             *      the pointer will be set to null.
             * @return true if successful.
             */
            virtual Bool DestroyController(IController*& controller) const = 0;

            /**
             * @brief Deserialize a given controller from a set of attributes and optional parameters.
             * @param controller The controller to deserialize.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeControllerAttributes(IController* controller, const IAttributes* attributes, const IAttributes* parameters) = 0;
            /**
             * @brief Deserialize a given controller from a set of attributes and optional parameters.
             * @param controller The controller to deserialize.
             * @param baseResourcePath The base path for referencing relative resource IDs.
             * @param attributes The attributes.
             * @param parameters The optional parameters.
             * @return true if successful.
             */
            virtual Bool DeserializeControllerAttributes(IController* controller, const String& baseResourcePath, const IAttributes* attributes, const IAttributes* parameters) = 0;

        protected:
            virtual ~IFactory() {}
        };
        
        /**
         * @ingroup MurlGraphFactoryClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the graph factory object.
             * @param appConfig The application's configuration.
             * @return The created graph factory object, or null if failed.
             */
            static IFactory* CreateFactory(const IAppConfiguration* appConfig);
            /**
             * @brief Destroy the graph factory object.
             * @param factory A reference to the graph factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_GRAPH_I_FACTORY_H__

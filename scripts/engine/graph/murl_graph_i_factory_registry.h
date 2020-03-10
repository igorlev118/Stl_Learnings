// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FACTORY_REGISTRY_H__
#define __MURL_GRAPH_I_FACTORY_REGISTRY_H__

#include "murl_graph_i_node.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphFactoryInterfaces
         * @interface IFactoryRegistry
         * @brief The registry interface for managing individual graph node classes.
         * The IFactoryRegistry interface provides methods to add, remove and query different 
         * graph node and controller classes. The Graph::IFactory interfaces derives from this 
         * interface, in order to be able to actually instantiate any nodes or controllers from
         * the set of classes present in the registry.
         */
        class IFactoryRegistry
        {
        public:
            /**
             * @brief Register a node class.
             * @param classInfo The node class' ClassInfo structure, containing a function
             *      pointer to the node's Create() method, and the human-readable class name
             *      string.
             * @return true if successful.
             */
            virtual Bool RegisterNodeClass(const INode::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a node class.
             * @param classInfo The node class' ClassInfo structure.
             * @return true if successful.
             */
            virtual Bool UnregisterNodeClass(const INode::ClassInfo& classInfo) = 0;

            /**
             * @brief Get the index of a registered node class, by its class info structure.
             * @param classInfo The class info structure of the node class to query.
             * @return The zero-based index of the class, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredNodeClassInfoIndex(const INode::ClassInfo& classInfo) const = 0;
            /**
             * @brief Get the index of a registered node class, by its class name.
             * @param className The name of the node class to query.
             * @return The zero-based index of the class, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredNodeClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered node classes.
             * @return The number of registered node classes.
             */
            virtual UInt32 GetNumberOfRegisteredNodeClassInfos() const = 0;
            /**
             * @brief Get the class info structure of a registered node class at a given index.
             * @param index The index in the range for 0 to GetNumberOfRegisteredNodeClassInfos()-1.
             * @return A pointer to the class info, or 0 if the index is out of range.
             */
            virtual const INode::ClassInfo* GetRegisteredNodeClassInfo(UInt32 index) const = 0;

            /**
             * @brief Register a controller class.
             * @param classInfo The controller class' ClassInfo structure, containing a function
             *      pointer to the controller's Create() method, and the human-readable class name
             *      string.
             * @return true if successful.
             */
            virtual Bool RegisterControllerClass(const IController::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a controller class.
             * @param classInfo The controller class' ClassInfo structure.
             * @return true if successful.
             */
            virtual Bool UnregisterControllerClass(const IController::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Get the index of a registered controller class, by its class info structure.
             * @param classInfo The class info structure of the controller class to query.
             * @return The zero-based index of the class, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredControllerClassInfoIndex(const IController::ClassInfo& classInfo) const = 0;
            /**
             * @brief Get the index of a registered controller class, by its class name.
             * @param className The name of the controller class to query.
             * @return The zero-based index of the class, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredControllerClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered controller classes.
             * @return The number of registered controller classes.
             */
            virtual UInt32 GetNumberOfRegisteredControllerClassInfos() const = 0;
            /**
             * @brief Get the class info structure of a registered controller class at a given index.
             * @param index The index in the range for 0 to GetNumberOfRegisteredControllerClassInfos()-1.
             * @return A pointer to the class info, or 0 if the index is out of range.
             */
            virtual const IController::ClassInfo* GetRegisteredControllerClassInfo(UInt32 index) const = 0;
            
        protected:
            virtual ~IFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_GRAPH_I_FACTORY_REGISTRY_H__

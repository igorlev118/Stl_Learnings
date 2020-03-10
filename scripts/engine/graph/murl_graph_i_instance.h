// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_INSTANCE_H__
#define __MURL_GRAPH_I_INSTANCE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_template.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IInstance
         * @brief The IInstance graph node interface.
         * This interface provides a means to instantiate zero, one, or more sub-graphs in the
         * current scene graph. The source object (i.e. graph template) can either be a
         * Resource::IGraph object from the resource collection set via GetGraphResourceTarget(),
         * or an already instantiated Graph::ITemplate node referenced via GetTemplateNodeTarget().
         */
        class IInstance
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Get a mutable Graph::IGraphResourceTarget container.
             * This method returns a mutable pointer to a Graph::IGraphResourceTarget
             * container, which allows to add, remove or query the graph resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IGraphResourceTarget container, or null if not available
             */
            virtual IGraphResourceTarget* GetGraphResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IGraphResourceTarget container.
             * This method returns a constant pointer to a Graph::IGraphResourceTarget
             * container, which allows to query the graph resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IGraphResourceTarget container, or null if not available
             */
            virtual const IGraphResourceTarget* GetGraphResourceTarget() const = 0;

            /**
             * @brief Get the mutable Graph::ITemplateNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ITemplateNodeTarget
             * container, which allows to set or query the template graph node used for
             * instantiaton.
             * @return The mutable Graph::ITemplateNodeTarget container, or null if not available.
             */
            virtual ITemplateNodeTarget* GetTemplateNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITemplateNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ITemplateNodeTarget
             * container, which allows to query the template graph node used for instantiaton.
             * @return The mutable Graph::ITemplateNodeTarget container, or null if not available.
             */
            virtual const ITemplateNodeTarget* GetTemplateNodeTarget() const = 0;

            /**
             * @brief Set the number of replications.
             * This method sets the number of times the referenced graph resource should
             * be instantiated. By default, this value is set to 1; it is also possible to set
             * it to zero to not instantiate any graphs at all, useful e.g. when the instance
             * node itself is used from within a parameterized sub-graph.
             * @param numberOfReplications The number of replications of the graph to create.
             * @return true if successful.
             */
            virtual Bool SetNumberOfReplications(UInt32 numberOfReplications) = 0;
            /**
             * @brief Get the number of replications.
             * @return The number of replications of the graph to create.
             */
            virtual UInt32 GetNumberOfReplications() const = 0;

            /**
             * @brief Return the replication at a given position.
             * This returns a mutable pointer to this node's replication at a given index.
             * @param index The zero-based index of the replication.
             * @return A pointer to the replication node, or null if the index was out of range.
             */
            virtual INode* GetReplicationNode(UInt32 index) = 0;
            /**
             * @brief Return the replication at a given position.
             * This returns a constant pointer to this node's replication at a given index.
             * @param index The zero-based index of the replication.
             * @return A pointer to the replication node, or null if the index was out of range.
             */
            virtual const INode* GetReplicationNode(UInt32 index) const = 0;

            /**
             * @brief Add a user-defined instance parameter.
             * It is possible to parameterize a graph instance by adding individual parameter
             * name/value pairs, which are then evaluated during creation of the given sub-graph.
             * If a node attribute from the given graph resource contains an identifier name
             * enclosed in curly braces, e.g. "{myVariable}", that sequence is replaced by the
             * value of the parameter with the given name if present, otherwise a default value
             * is used that can be defined in the graph resource (or an empty string if that
             * default value is also not present).
             * @param name The parameter name.
             * @param value The parameter value.
             * @return true if successful.
             */
            virtual Bool AddParameter(const String& name, const String& value) = 0;
            /**
             * @brief Get the total number of user-defined instance parameters.
             * @return The number of parameters.
             */
            virtual UInt32 GetNumberOfParameters() const = 0;
            /**
             * @brief Get the name of a user-defined instance parameter at a given index.
             * @param index The zero-based index of the parameter to query.
             * @return The parameter name at the given index.
             */
            virtual String GetParameterName(UInt32 index) const = 0;
            /**
             * @brief Get the value of a user-defined instance parameter at a given index.
             * @param index The zero-based index of the parameter to query.
             * @return The parameter value at the given index.
             */
            virtual String GetParameterValue(UInt32 index) const = 0;

        protected:
            virtual ~IInstance() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IInstance nodes.
         */
        typedef IGenericNodeTarget<IInstance> IInstanceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_INSTANCE_H__

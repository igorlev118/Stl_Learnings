// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PROGRAM_H__
#define __MURL_GRAPH_I_PROGRAM_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Video
    {
        class IProgram;
    }

    namespace Graph
    {
        class IProgram;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IProgram nodes.
         */
        typedef IGenericNodeTarget<IProgram> IProgramNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IProgram
         * @brief The IProgram graph node interface.
         * This interface represents a generic GPU shader program used to render
         * geometry.
         *
         * See Graph::IMaterial for attaching a program to a given material.
         * See Graph::IParameters for defining actual program parameters.
         */
        class IProgram
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
             * @brief Get the mutable Graph::IShaderProgram container storing an optional fallback program.
             * This method returns a mutable pointer to the node's Graph::IShaderProgram container that
             * stores an optional reference to another shader program node that is used instead, if linking
             * of the shader objects failed.
             * @return The mutable Graph::IShaderProgram fallback container, or null if not available.
             */
            virtual IProgramNodeTarget* GetFallbackProgramNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IProgram container storing an optional fallback program.
             * This method returns a constant pointer to the node's Graph::IProgram container that
             * stores an optional reference to another shader program node that is used instead, if linking
             * of the shader objects failed.
             * @return The constant Graph::IProgram fallback container, or null if not available.
             */
            virtual const IProgramNodeTarget* GetFallbackProgramNodeTarget() const = 0;

            /**
             * @brief Get the program's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the program's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::IProgram* GetVideoProgramObject(UInt32 stage) const = 0;

            /**
             * @brief Check if the program is valid.
             * If linking of the program object fails, this method returns false.
             * @param checkFallbacks If false, only the current program is considered. Otherwise,
             *      the method returns true if any of its fallback programs is valid.
             * @return true if program linking succeeded during initialization.
             */
            virtual Bool IsValid(Bool checkFallbacks) const = 0;
            /**
             * @brief Get the shader linker log.
             * If linking of the program object fails, this method returns the output
             * provided by the OS/video API. Otherwise, an empty string is returned.
             * @return The linker log message.
             */
            virtual const String& GetLinkerLog() const = 0;

        protected:
            virtual ~IProgram() {}
        };
    }
}

#endif // __MURL_GRAPH_I_PROGRAM_H__

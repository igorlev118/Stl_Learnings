// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SHADER_PROGRAM_H__
#define __MURL_GRAPH_I_SHADER_PROGRAM_H__

#include "murl_graph_i_program.h"
#include "murl_graph_i_shader.h"

namespace Murl
{
    namespace Graph
    {
        class IShaderProgram;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IShaderProgram nodes.
         */
        typedef IGenericNodeTarget<IShaderProgram> IShaderProgramNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IShaderProgram
         * @brief The IShaderProgram graph node interface.
         * An IShaderProgram node provides a means to link a pair of vertex and fragment
         * shaders together, each of which must be defined via a Graph::IShader node.
         *
         * See Graph::IMaterial for attaching a shader program to a given material.
         * See Graph::IGenericParameters for defining actual user-defined program parameters.
         */
        class IShaderProgram : public IProgram
        {
        public:
            /**
             * @brief Get the mutable Graph::IShaderNodeTarget vertex shader container.
             * This method returns a mutable pointer to the node's Graph::IShaderNodeTarget
             * container for the program's vertex shader, which allows to set or query the
             * vertex shader this program refers to.
             * @return The mutable Graph::IShaderNodeTarget vertex shader container.
             */
            virtual IShaderNodeTarget* GetVertexShaderNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IShaderNodeTarget vertex shader container.
             * This method returns a constant pointer to the node's Graph::IShaderNodeTarget
             * container for the program's vertex shader, which allows to query the
             * vertex shader this program refers to.
             * @return The constant Graph::IShaderNodeTarget vertex shader container.
             */
            virtual const IShaderNodeTarget* GetVertexShaderNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::IShaderNodeTarget fragment shader container.
             * This method returns a mutable pointer to the node's Graph::IShaderNodeTarget
             * container for the program's fragment shader, which allows to set or query the
             * fragment shader this program refers to.
             * @return The mutable Graph::IShaderNodeTarget fragment shader container.
             */
            virtual IShaderNodeTarget* GetFragmentShaderNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IShaderNodeTarget fragment shader container.
             * This method returns a constant pointer to the node's Graph::IShaderNodeTarget
             * container for the program's fragment shader, which allows to query the
             * fragment shader this program refers to.
             * @return The constant Graph::IShaderNodeTarget fragment shader container.
             */
            virtual const IShaderNodeTarget* GetFragmentShaderNodeTarget() const = 0;

        protected:
            virtual ~IShaderProgram() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SHADER_PROGRAM_H__

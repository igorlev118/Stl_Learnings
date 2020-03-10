// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SHADER_H__
#define __MURL_GRAPH_I_SHADER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IShader;
    }
    
    namespace Graph
    {
        class IShader;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IShader nodes.
         */
        typedef IGenericNodeTarget<IShader> IShaderNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IShader
         * @brief The IShader graph node interface.
         * This interface represents a node that holds the source code for either a vertex shader
         * or a fragment shader of a GPU program, or both. 
         * If the node is set to a single type (either vertex or fragment shader) and the selected
         * video API allows for runtime shader compilation, the actual shader code may be set
         * directly via SetSource(). Otherwise, a valid Resource::IShader object must be provided,
         * which contains the necessary type(s) of shader data.
         *
         * See Graph::IShaderProgram for attaching a shader to a program.
         */
        class IShader
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
             * @brief Get a mutable Graph::IShaderResourceTarget container.
             * This method returns a mutable pointer to a Graph::IShaderResourceTarget
             * container, which allows to add, remove or query the shader resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IShaderResourceTarget container, or null if not available
             */
            virtual IShaderResourceTarget* GetShaderResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IShaderResourceTarget container.
             * This method returns a constant pointer to a Graph::IShaderResourceTarget
             * container, which allows to query the shader resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IShaderResourceTarget container, or null if not available
             */
            virtual const IShaderResourceTarget* GetShaderResourceTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IShader container storing an optional fallback shader.
             * This method returns a mutable pointer to the node's Graph::IShader container that
             * stores an optional reference to another shader node that is used instead, if compilation
             * of the shader object(s) failed.
             * @return The mutable Graph::IShader fallback container, or null if not available.
             */
            virtual IShaderNodeTarget* GetFallbackShaderNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IShader container storing an optional fallback shader.
             * This method returns a constant pointer to the node's Graph::IShader container that
             * stores an optional reference to another shader node that is used instead, if compilation
             * of the shader object(s) failed.
             * @return The constant Graph::IShader fallback container, or null if not available.
             */
            virtual const IShaderNodeTarget* GetFallbackShaderNodeTarget() const = 0;

            /**
             * @brief Directly set the shader's source code from a given string.
             * @param source The shader source code.
             * @return true if successful.
             */
            virtual Bool SetSource(const String& source) = 0;
            /**
             * @brief Get the shader's source code, if it was explicitly set via SetSource().
             * @return The shader source code.
             */
            virtual const String& GetSource() const = 0;
            
            /**
             * @brief Set the shader type.
             * If set to IEnums::SHADER_TYPE_ALL, the given shader resource must contain both
             * vertex and fragment shader data valid for the selected video API.
             * @param type The shader type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::ShaderType type) = 0;
            /**
             * @brief Get the shader type.
             * @return The shader type.
             */
            virtual IEnums::ShaderType GetType() const = 0;
            
            /**
             * @brief Get the shader's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the shader's internal video renderer object for a given type.
             * @param stage The stage to query.
             * @param type The shader type, either SHADER_TYPE_VERTEX or SHADER_TYPE_FRAGMENT.
             * @return The video renderer object.
             */
            virtual Video::IShader* GetVideoShaderObject(UInt32 stage, IEnums::ShaderType type) const = 0;

            /**
             * @brief Check if the shader is valid.
             * If creation/compilation of the shader object fails, this method returns false.
             * @param checkFallbacks If false, only the current shader is considered. Otherwise,
             *      the method returns true if any of its fallback shaders is valid.
             * @return true if shader compilation succeeded during initialization.
             */
            virtual Bool IsValid(Bool checkFallbacks) const = 0;
            /**
             * @brief Get the shader compiler log.
             * If creation/compilation of the shader object fails, this method returns the output
             * provided by the OS/video API. Otherwise, an empty string is returned.
             * @return The compiler log message.
             */
            virtual const String& GetCompilerLog() const = 0;

        protected:
            virtual ~IShader() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SHADER_H__

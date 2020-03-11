// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_SHADER_TECHNIQUE_H__
#define __MURL_VIDEO_I_SHADER_TECHNIQUE_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IShader;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IShaderTechnique
         * @brief The IShaderTechnique video object interface.
         * This interface represents a generic GPU shader program.
         *
         * Used internally by Graph::ShaderProgram.
         */
        class IShaderTechnique
        {
        public:
            /**
             * @struct UniformVariableDeclaration
             * @brief A declaration of a predefined uniform variable.
             */
            struct UniformVariableDeclaration
            {
                /**
                 * @brief The constructor.
                 * @param item The predefined item.
                 */
                UniformVariableDeclaration(IEnums::UniformItem item)
                : mItem(item)
                , mType(IEnums::GetUniformItemDataType(item))
                , mName(IEnums::GetUniformItemName(item))
                , mAlternativeName(IEnums::GetUniformItemAlternativeName(item))
                {
                }

                /// The predefined item.
                IEnums::UniformItem mItem;
                /// The data type.
                IEnums::UniformType mType;
                /// The primary name.
                const Char* mName;
                /// The alternative name.
                const Char* mAlternativeName;
            };
            
            /**
             * @struct AttributeVariableDeclaration
             * @brief A declaration of a predefined attribute variable.
             */
            struct AttributeVariableDeclaration
            {
                /**
                 * @brief The constructor.
                 * @param item The predefined item.
                 */
                AttributeVariableDeclaration(IEnums::AttributeItem item)
                : mItem(item)
                , mType(IEnums::GetAttributeItemDataType(item))
                , mName(IEnums::GetAttributeItemName(item))
                , mAlternativeName(IEnums::GetAttributeItemAlternativeName(item))
                {
                }
                
                /// The predefined item.
                IEnums::AttributeItem mItem;
                /// The data type.
                IEnums::AttributeType mType;
                /// The primary name.
                const Char* mName;
                /// The alternative name.
                const Char* mAlternativeName;
            };
            
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Add a shader.
             * @param shader The shader to add.
             * @return true if successful.
             */
            virtual Bool AddShader(IShader* shader) = 0;
            /**
             * @brief Get the number of referenced shaders.
             * @return The number of shaders.
             */
            virtual UInt32 GetNumberOfShaders() const = 0;
            /**
             * @brief Get the shader at a given index.
             * @param index The shader index, from 0 to GetNumberOfShaders()-1.
             * @return The shader, or null if the index is out of range.
             */
            virtual IShader* GetShader(UInt32 index) const = 0;
            
            /**
             * @brief Add a set of predefined uniform variable declarations.
             * @param declarations An array of declarations.
             * @param numberOfDeclarations The actual number of declarations to add.
             * @return true if successful.
             */
            virtual Bool AddUniformVariableDeclarations(const UniformVariableDeclaration* declarations, UInt32 numberOfDeclarations) = 0;
            /**
             * @brief Add a set of predefined attribute variable declarations.
             * @param declarations An array of declarations.
             * @param numberOfDeclarations The actual number of declarations to add.
             * @return true if successful.
             */
            virtual Bool AddAttributeVariableDeclarations(const AttributeVariableDeclaration* declarations, UInt32 numberOfDeclarations) = 0;
            
            /**
             * @brief Remove a set of previously added predefined uniform variable declarations.
             * @param declarations An array of declarations.
             * @param numberOfDeclarations The actual number of declarations to add.
             * @return true if successful.
             */
            virtual Bool RemoveUniformVariableDeclarations(const UniformVariableDeclaration* declarations, UInt32 numberOfDeclarations) = 0;
            /**
             * @brief Remove a set of previously added predefined attribute variable declarations.
             * @param declarations An array of declarations.
             * @param numberOfDeclarations The actual number of declarations to add.
             * @return true if successful.
             */
            virtual Bool RemoveAttributeVariableDeclarations(const AttributeVariableDeclaration* declarations, UInt32 numberOfDeclarations) = 0;
            
        protected:
            virtual ~IShaderTechnique() {}
        };
    }
}

#endif // __MURL_VIDEO_I_SHADER_TECHNIQUE_H__

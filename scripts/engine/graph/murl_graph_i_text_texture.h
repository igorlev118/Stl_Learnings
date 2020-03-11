// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEXT_TEXTURE_H__
#define __MURL_GRAPH_I_TEXT_TEXTURE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_text.h"
#include "murl_color.h"

namespace Murl
{
    namespace Graph
    {
        class ITexture;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITextTexture
         * @brief The ITextTexture graph node interface.
         * This interface represents a texture used as a target for rendering text using
         * a predefined system font, referenced by its identifier.
         *
         * Use the Graph::IText base interface to access common text properties, such as spacing or
         * leading, or the actual text to be shown.
         */
        class ITextTexture : public IText
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
             * @brief Get the mutable Graph::ITexture interface.
             * This method returns a mutable pointer to the node's Graph::ITexture interface,
             * to be able to query or modify the node's texture properties.
             * @return The mutable Graph::ITexture interface, or null if not available
             */
            virtual ITexture* GetTextureInterface() = 0;
            /**
             * @brief Get the constant Graph::ITexture interface.
             * This method returns a constant pointer to the node's Graph::ITexture interface,
             * to be able to query the node's texture properties.
             * @return The constant Graph::ITexture interface, or null if not available
             */
            virtual const ITexture* GetTextureInterface() const = 0;
            
            /**
             * @brief Set the text position within the texture.
             * @param posX The horizontal text position.
             * @param posY The vertical text position.
             * @return true if successful.
             */
            virtual Bool SetTextPosition(Real posX, Real posY) = 0;
            /**
             * @brief Set the horizontal text position within the texture.
             * @param posX The horizontal text position.
             * @return true if successful.
             */
            virtual Bool SetTextPositionX(Real posX) = 0;
            /**
             * @brief Set the vertical text position within the texture.
             * @param posY The vertical text position.
             * @return true if successful.
             */
            virtual Bool SetTextPositionY(Real posY) = 0;
            /**
             * @brief Get the horizontal text position within the texture.
             * @return The horizontal text position.
             */
            virtual Real GetTextPositionX() const = 0;
            /**
             * @brief Get the vertical text position within the texture.
             * @return The vertical text position.
             */
            virtual Real GetTextPositionY() const = 0;
            
            /**
             * @brief Set the output text rectangle's size.
             * @param sizeX The horizontal text size.
             * @param sizeY The vertical text size.
             * @return true if successful.
             */
            virtual Bool SetTextSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the output text rectangle's horizontal size.
             * @param sizeX The horizontal text size.
             * @return true if successful.
             */
            virtual Bool SetTextSizeX(Real sizeX) = 0;
            /**
             * @brief Set the output text rectangle's vertical size.
             * @param sizeY The vertical text size.
             * @return true if successful.
             */
            virtual Bool SetTextSizeY(Real sizeY) = 0;
            /**
             * @brief Get the output text rectangle's horizontal size.
             * @return The horizontal text size.
             */
            virtual Real GetTextSizeX() const = 0;
            /**
             * @brief Get the output text rectangle's vertical size.
             * @return The vertical text size.
             */
            virtual Real GetTextSizeY() const = 0;
            
        protected:
            virtual ~ITextTexture() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITextTexture nodes.
         */
        typedef IGenericNodeTarget<ITextTexture> ITextTextureNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TEXT_TEXTURE_H__

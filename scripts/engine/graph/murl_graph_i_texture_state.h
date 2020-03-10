// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEXTURE_STATE_H__
#define __MURL_GRAPH_I_TEXTURE_STATE_H__

#include "murl_graph_i_texture.h"
#include "murl_graph_i_state_slot.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITextureState
         * @brief The ITextureState graph node interface.
         * Texture state nodes are used to activate and/or quickly switch between textures
         * during scene graph traversal. For each distinct texture unit, as soon as a specific
         * texture is activated at a given slot via a texture state node, it stays active during
         * traversal until a different texture state node using the same slot is encountered.
         *
         * Use the base interface's IStateSlot::SetSlot() method to set the actual slot index
         * the referenced texture should be attached to.
         * Use the base interface's IStateUnit::SetUnit() method to set the actual unit index
         * the referenced texture should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene
         * graph traversal.\n
         * See Graph::ITexture for defining a specific texture for rendering.\n
         */
        class ITextureState : public IStateSlot, public IStateUnit
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
             * @brief Get the mutable Graph::ITextureNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * container, which allows to set or query the texture this state node refers to.
             * @return The mutable Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual ITextureNodeTarget* GetTextureNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITextureNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * container, which allows to query the texture this state node refers to.
             * @return The mutable Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual const ITextureNodeTarget* GetTextureNodeTarget() const = 0;
            
        protected:
            virtual ~ITextureState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITextureState nodes.
         */
        typedef IGenericNodeTarget<ITextureState> ITextureStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TEXTURE_STATE_H__

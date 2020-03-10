// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FIELD_H__
#define __MURL_GRAPH_I_FIELD_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IField
         * @brief The IField graph node interface.
         * This interface represents a generic field object in the framework's physics
         * simulator, that permanently acts on any Graph::IBody nodes that are present
         * in the field's defined influence groups.
         *
         * Fields come in different shapes (planar, spherical, ...) and can be controlled
         * to apply either a force or an acceleration to the bodies within its range.
         * There is also a nuber of factors (constant, linear and quadratic) that can
         * be set to control the actual field strength acting on a body depending on its
         * distance to the field.
         *
         * See Graph::IBody to define a body to act on.
         */
        class IField
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
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;
            
            /**
             * @brief Set the individual body groups this field is influencing.
             * This method sets the field's influence on a number of individual body groups.
             * Each bit in the given mask represents one of 32 possible groups; see
             * Graph::IBody::SetResponseGroupMask() for assigning a body to any of these
             * groups.
             * @param mask The group influence bit mask.
             * @return true if successful.
             */
            virtual Bool SetInfluenceGroupMask(UInt32 mask) = 0;
            /**
             * @brief Get the individual body groups this field is influencing.
             * @return The bit mask specifying the group influence.
             */
            virtual UInt32 GetInfluenceGroupMask() const = 0;
            
            /**
             * @brief Set the field's constant influence factor.
             * The given value represents the constant field influence factor, i.e. the
             * amount of influence on any body independent of its distance.
             * @param factor The field's constant influence factor.
             * @return true if successful.
             */
            virtual Bool SetConstantFactor(Real factor) = 0;
            /**
             * @brief Get the field's constant influence factor.
             * @return The field's constant influence factor.
             */
            virtual Real GetConstantFactor() const = 0;
            
            /**
             * @brief Set the field's linear influence factor.
             * The given value represents the linear field influence factor, i.e. the
             * amount of influence on any body degrading linearly in proportion to that body's
             * distance to the field.
             * @param factor The field's linear influence factor.
             * @return true if successful.
             */
            virtual Bool SetLinearFactor(Real factor) = 0;
            /**
             * @brief Get the field's linear influence factor.
             * @return The field's linear influence factor.
             */
            virtual Real GetLinearFactor() const = 0;
            
            /**
             * @brief Set the field's quadratic influence factor.
             * The given value represents the quadratic field influence factor, i.e. the
             * amount of influence on any body degrading in a quadratic curve in a proportion to
             * that body's distance to the field.
             * @param factor The field's quadratic influence factor.
             * @return true if successful.
             */
            virtual Bool SetQuadraticFactor(Real factor) = 0;
            /**
             * @brief Get the field's quadratic influence factor.
             * @return The field's quadratic influence factor.
             */
            virtual Real GetQuadraticFactor() const = 0;
            
            /**
             * @brief Set the field type.
             * @param type The field type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::FieldType type) = 0;
            /**
             * @brief Get the field type.
             * @return The field type.
             */
            virtual IEnums::FieldType GetType() const = 0;
            
            /**
             * @brief Set the field shape.
             * @param shape The field shape.
             * @return true if successful.
             */
            virtual Bool SetShape(IEnums::FieldShape shape) = 0;
            /**
             * @brief Get the field shape.
             * @return The field shape.
             */
            virtual IEnums::FieldShape GetShape() const = 0;
            
        protected:
            virtual ~IField() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IField nodes.
         */
        typedef IGenericNodeTarget<IField> IFieldNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_FIELD_H__

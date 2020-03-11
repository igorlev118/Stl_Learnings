// Copyright 2011-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_POSITION_OBJECT_H__
#define __MURL_LOGIC_GRAPH_POSITION_OBJECT_H__

#include "murl_logic_base_node_observer.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Base class handling position for Graph::ITransform node.
         */
        class GraphPositionObject
        {
        public:
            /**
             * @brief The default constructor.
             * @param baseDepth The base depth order.
             */
            GraphPositionObject(SInt32 baseDepth = 0)
            : mBaseSortDepth(baseDepth)
            , mCurrentSortDepth(0)
            , mPosition(Vector::ZERO_POSITION)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~GraphPositionObject()
            {
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param root The graph root node.
             * @param nodeIdPath The full path to the graph transform node instance.
             * @param baseDepth The base depth order.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, const Graph::IRoot* root,
                              const String& nodeIdPath, SInt32 baseDepth)
            {
                return Init(nodeObserver, root->GetRootNamespace(), nodeIdPath, baseDepth);
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The relative path to the graph transform node instance.
             * @param baseDepth The base depth order.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INamespace* namespaceNode,
                              const String& nodeIdPath, SInt32 baseDepth)
            {
                if (!nodeObserver->Add(mTransformNode.GetReference(namespaceNode, nodeIdPath)))
                {
                    return false;
                }

                mBaseSortDepth = baseDepth;
                mCurrentSortDepth = mTransformNode->GetDepthOrder();
                ApplySortDepth();
                mPosition = mTransformNode->GetPosition();
                ApplyPosition();
                return true;
            }

            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit()
            {
                Bool ret = true;
                return ret;
            }

            /**
             * @brief Get the position vector.
             * @return The position vector.
             */
            virtual const Vector& GetPosition() const
            {
                return mPosition;
            }

            /**
             * @brief Set the position vector.
             * @param position The position vector.
             */
            virtual void SetPosition(const Vector& position)
            {
                mPosition = position;
                ApplyPosition();
            }

            /**
             * @brief Set the x/y positionr.
             * @param x The x-position.
             * @param y The y-position.
             */
            virtual void SetPosition(Real x, Real y)
            {
                mPosition.x = x;
                mPosition.y = y;
                ApplyPosition();
            }

            /**
             * @brief Set the x/y/z positionr.
             * @param x The x-position.
             * @param y The y-position.
             * @param z The z-position.
             */
            virtual void SetPosition(Real x, Real y, Real z)
            {
                mPosition.x = x;
                mPosition.y = y;
                mPosition.z = z;
                ApplyPosition();
            }

            /**
             * @brief Add a vector to the position.
             * @param position The vector to add.
             */
            virtual void AddPosition(const Vector& position)
            {
                mPosition += position;
                ApplyPosition();
            }

            /**
             * @brief Set the current depth sort order.
             * @param sortDepth The current depth sort order.
             */
            virtual void SetSortDepth(SInt32 sortDepth)
            {
                mCurrentSortDepth = sortDepth;
                ApplySortDepth();
            }

            /**
             * @brief Get the current depth sort order.
             * @return The current depth sort order.
             */
            virtual SInt32 GetSortDepth() const
            {
                return mCurrentSortDepth;
            }

            /**
             * @brief Set the base depth sort order.
             * The base depth order is added to the current depht sort order
             * when applying the depth sort order to the transformation.
             * @param sortDepth The base depth sort order.
             */
            virtual void SetBaseSortDepth(SInt32 sortDepth)
            {
                mBaseSortDepth = sortDepth;
                ApplySortDepth();
            }

            /**
             * @brief Get the base depth sort order.
             * @return The base depth sort order.
             */
            virtual SInt32 GetBaseSortDepth() const
            {
                return mBaseSortDepth;
            }

        protected:
            /**
             * @brief Apply the depth sort order to the transformation.
             * This method can be overwritten for custom behaviour.
             */
            virtual void ApplySortDepth()
            {
                mTransformNode->SetDepthOrder(mBaseSortDepth + mCurrentSortDepth);
            }

            /**
             * @brief Apply the position vector to the transformation.
             * This method can be overwritten for custom behaviour.
             */
            virtual void ApplyPosition()
            {
                mTransformNode->SetPosition(mPosition);
            }

            SInt32 mBaseSortDepth;
            SInt32 mCurrentSortDepth;
            Vector mPosition;

            TransformNode mTransformNode;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_POSITION_OBJECT_H__

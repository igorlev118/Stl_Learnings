// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ALIGNER_H__
#define __MURL_GRAPH_I_ALIGNER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IBoundingVolume;
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IAligner
         * @brief The IAligner graph node interface.
         * IAligner nodes allow to automatically arrange a number of child sub-graphs along
         * one dedicated main axis (see SetAxis()), in either ascending or descending order
         * (see SetOrder()). By design, each individual child represents a closed sub-graph
         * for which the common bounding volume is calculated when the aligner performs its 
         * layout procedure. In other words, if for example five plane geometry nodes should 
         * be arranged, each of these planes must be in a separate child sub-graph. If two or
         * more planes are within the same child sub-graph, their bounding volumes are 
         * combined, and this combined volume is used for arranging the respective child graph.
         *
         * For the remaining two axes and the dedicated main axis set via SetAxis(),
         * it is possible to specify an alignment mode so that the linearly aligned children
         * are also aligned to either side or center of the aligner. By default, these object
         * alignment modes (which can be set via SetObjectAlignment()) are set to UNDEFINED,
         * which means that no alignment is done for any axis other than the main axis.
         *
         * It is also possible to specify a minimum and maximum container size (see 
         * SetMinContainerSize() and SetMaxContainerSize(), respectively), together with a
         * container alignment property (see SetContainerAlignment()) to control the actual
         * size and pivot point of the resulting layout container.
         *
         * Aligned objects can be arranged with an optional spacing parameter (see SetSpacing()),
         * which represents the space left out between two consecutive child sub-graphs.
         *
         * In addition, it is possible to specify padding values (see SetPadding()) to add
         * an extra border to the resulting container after layouting.
         *
         * See also Graph::IBoundingBox.
         */
        class IAligner
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
             * @brief Enable/disable instance processing.
             * If enabled, child nodes that implement the IInstance interface are processed
             * separately, so that all their individual replications are treated as if they
             * were direct children of the aligner. Note that in this case, activating or 
             * deactivating the instance node itself has no effect; if all replications of an
             * instance should be made invisible, one must iterate over all the instance's
             * children manually.
             * By default, instance processing is enabled.
             * @param enabled If true, instance processing is enabled.
             * @return true if successful.
             */
            virtual Bool SetInstanceProcessingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if instance processing is enabled.
             * @return true if enabled.
             */
            virtual Bool IsInstanceProcessingEnabled() const = 0;

            /**
             * @brief Set the alignment axis.
             * This method can be used to set the aligner's main axis. When performing its
             * layout operation, the position of each child sub-graph is increased or decreased
             * (depending on the order defined by SetOrder()), but only for the given axis.
             * The other two coordinates of each sub-graph are left unchanged, unless explicitly
             * set via SetObjectAlignment().
             * @param axis The alignment axis.
             * @return true if successful.
             */
            virtual Bool SetAxis(IEnums::Axis axis) = 0;
            /**
             * @brief Get the alignment axis.
             * @return The alignment axis.
             */
            virtual IEnums::Axis GetAxis() const = 0;
            
            /**
             * @brief Set the alignment order.
             * This method sets the alignment order to either ascending or descending,
             * along the main axis. See SetAxis().
             * @param order The alignment order.
             * @return true if successful.
             */
            virtual Bool SetOrder(IEnums::SortOrder order) = 0;
            /**
             * @brief Get the alignment order.
             * @return The alignment order.
             */
            virtual IEnums::SortOrder GetOrder() const = 0;
            
            /**
             * @brief Set the alignment spacing.
             * This method defines the size of the empty space between two consecutive
             * sub-graphs, along the main axis defined via SetAxis().
             * @param spacing The spacing value.
             * @return true if successful.
             */
            virtual Bool SetSpacing(Real spacing) = 0;
            /**
             * @brief Get the alignment spacing.
             * @return The spacing value.
             */
            virtual Real GetSpacing() const = 0;
            
            /**
             * @brief Set the alignment padding.
             * This method defines the "border size", added to both sides of each axis
             * to effectively enlarge the alignment container by twice the given values,
             * individually for each of the three axes.
             * @param padding A vector containing three individual padding values, one 
             *      for each axis (X, Y and Z).
             * @return true if successful.
             */
            virtual Bool SetPadding(const Vector& padding) = 0;
            /**
             * @brief Set the alignment padding.
             * See SetPadding(const Vector&).
             * @param paddingX The X axis padding value.
             * @param paddingY The Y axis padding value.
             * @param paddingZ The Z axis padding value.
             * @return true if successful.
             */
            virtual Bool SetPadding(Real paddingX, Real paddingY, Real paddingZ) = 0;
            /**
             * @brief Set the alignment padding in X direction.
             * See SetPadding(const Vector&).
             * @param paddingX The X axis padding value.
             * @return true if successful.
             */
            virtual Bool SetPaddingX(Real paddingX) = 0;
            /**
             * @brief Set the alignment padding in Y direction.
             * See SetPadding(const Vector&).
             * @param paddingY The Y axis padding value.
             * @return true if successful.
             */
            virtual Bool SetPaddingY(Real paddingY) = 0;
            /**
             * @brief Set the alignment padding in Z direction.
             * See SetPadding(const Vector&).
             * @param paddingZ The Z axis padding value.
             * @return true if successful.
             */
            virtual Bool SetPaddingZ(Real paddingZ) = 0;
            /**
             * @brief Get the alignment padding as a vector.
             * @return A vector containing the 3 padding values, for X, Y and Z axis.
             */
            virtual const Vector& GetPadding() const = 0;
            /**
             * @brief Get the alignment padding in X direction.
             * @return The X axis padding value.
             */
            virtual Real GetPaddingX() const = 0;
            /**
             * @brief Get the alignment padding in Y direction.
             * @return The Y axis padding value.
             */
            virtual Real GetPaddingY() const = 0;
            /**
             * @brief Get the alignment padding in Z direction.
             * @return The Z axis padding value.
             */
            virtual Real GetPaddingZ() const = 0;
            
            /**
             * @brief Set the exact container size used for layouting.
             * This method sets both minimum and maximum size values for the layout
             * container to the given ones, effectively restricting the container to
             * always have constant dimensions. See SetMinContainerSize() and 
             * SetMaxContainerSize(). The exact container size cannot be queried 
             * directly, use both GetMinContainerSize() and GetMaxContainerSize(), which
             * return the same values when an exact container size was specified.
             * @param size A vector containing the container size for X, Y and Z axes.
             * @return true if successful.
             */
            virtual Bool SetContainerSize(const Vector& size) = 0;
            /**
             * @brief Set the exact container size used for layouting.
             * See SetContainerSize(const Vector&).
             * @param sizeX The container size in X direction.
             * @param sizeY The container size in Y direction.
             * @param sizeZ The container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetContainerSize(Real sizeX, Real sizeY, Real sizeZ) = 0;
            /**
             * @brief Set the exact container size used for layouting, in X direction.
             * See SetContainerSize(const Vector&).
             * @param sizeX The container size in X direction.
             * @return true if successful.
             */
            virtual Bool SetContainerSizeX(Real sizeX) = 0;
            /**
             * @brief Set the exact container size used for layouting, in Y direction.
             * See SetContainerSize(const Vector&).
             * @param sizeY The container size in Y direction.
             * @return true if successful.
             */
            virtual Bool SetContainerSizeY(Real sizeY) = 0;
            /**
             * @brief Set the exact container size used for layouting, in Z direction.
             * See SetContainerSize(const Vector&).
             * @param sizeZ The container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetContainerSizeZ(Real sizeZ) = 0;
            
            /**
             * @brief Set the minimum container size used for layouting.
             * This method sets the minimum overall container size used for layouting.
             * Using a minimum container size is usually useful when an aligner is
             * itself embedded into another (parent) aligner. When the total size of 
             * the aligned contents is smaller than the size values given here, the 
             * container maintains that minimum size. If the contents are larger, then
             * also the container is enlarged, unless a maximum size is defined via
             * SetMaxContainerSize(). If any of the three axis values is negative, this
             * axis is considered unrestricted. See also SetContainerSize() to set 
             * an exact container size.
             * @param size A vector containing the minimum container size for X, Y and Z.
             * @return true if successful.
             */
            virtual Bool SetMinContainerSize(const Vector& size) = 0;
            /**
             * @brief Set the minimum container size used for layouting.
             * See SetMinContainerSize(const Vector&).
             * @param sizeX The minimum container size in X direction.
             * @param sizeY The minimum container size in Y direction.
             * @param sizeZ The minimum container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetMinContainerSize(Real sizeX, Real sizeY, Real sizeZ) = 0;
            /**
             * @brief Set the minimum container size used for layouting, in X direction.
             * See SetMinContainerSize(const Vector&).
             * @param sizeX The minimum container size in X direction.
             * @return true if successful.
             */
            virtual Bool SetMinContainerSizeX(Real sizeX) = 0;
            /**
             * @brief Set the minimum container size used for layouting, in Y direction.
             * See SetMinContainerSize(const Vector&).
             * @param sizeY The minimum container size in Y direction.
             * @return true if successful.
             */
            virtual Bool SetMinContainerSizeY(Real sizeY) = 0;
            /**
             * @brief Set the minimum container size used for layouting, in Z direction.
             * See SetMinContainerSize(const Vector&).
             * @param sizeZ The minimum container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetMinContainerSizeZ(Real sizeZ) = 0;
            /**
             * @brief Get the minimum container size used for layouting.
             * @return A vector containing the minimum container size for X, Y and Z.
             */
            virtual const Vector& GetMinContainerSize() const = 0;
            /**
             * @brief Get the minimum container size in X direction used for layouting.
             * @return The minimum container size in X direction.
             */
            virtual Real GetMinContainerSizeX() const = 0;
            /**
             * @brief Get the minimum container size in Y direction used for layouting.
             * @return The minimum container size in Y direction.
             */
            virtual Real GetMinContainerSizeY() const = 0;
            /**
             * @brief Get the minimum container size in Z direction used for layouting.
             * @return The minimum container size in Z direction.
             */
            virtual Real GetMinContainerSizeZ() const = 0;
            
            /**
             * @brief Set the maximum container size used for layouting.
             * This method sets the maximum overall container size used for layouting.
             * Using a minimum container size is usually useful when an aligner is
             * itself embedded into another (parent) aligner. When the total size of
             * the aligned contents is higher than the size values given here, the
             * container is restricted to that maximum size. If the contents are smaller,
             * this smaller size is accepted, unless a minimum size is defined via
             * SetMinContainerSize(). If any of the three axis values is negative, this
             * axis is considered unrestricted. See also SetContainerSize() to set
             * an exact container size.
             * @param size A vector containing the maximum container size for X, Y and Z.
             * @return true if successful.
             */
            virtual Bool SetMaxContainerSize(const Vector& size) = 0;
            /**
             * @brief Set the maximum container size used for layouting.
             * See SetMaxContainerSize(const Vector&).
             * @param sizeX The maximum container size in X direction.
             * @param sizeY The maximum container size in Y direction.
             * @param sizeZ The maximum container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetMaxContainerSize(Real sizeX, Real sizeY, Real sizeZ) = 0;
            /**
             * @brief Set the maximum container size used for layouting, in X direction.
             * See SetMaxContainerSize(const Vector&).
             * @param sizeX The maximum container size in X direction.
             * @return true if successful.
             */
            virtual Bool SetMaxContainerSizeX(Real sizeX) = 0;
            /**
             * @brief Set the maximum container size used for layouting, in Y direction.
             * See SetMaxContainerSize(const Vector&).
             * @param sizeY The maximum container size in Y direction.
             * @return true if successful.
             */
            virtual Bool SetMaxContainerSizeY(Real sizeY) = 0;
            /**
             * @brief Set the maximum container size used for layouting, in Z direction.
             * See SetMaxContainerSize(const Vector&).
             * @param sizeZ The maximum container size in Z direction.
             * @return true if successful.
             */
            virtual Bool SetMaxContainerSizeZ(Real sizeZ) = 0;
            /**
             * @brief Get the maximum container size used for layouting.
             * @return A vector containing the maximum container size for X, Y and Z.
             */
            virtual const Vector& GetMaxContainerSize() const = 0;
            /**
             * @brief Get the maximum container size in X direction used for layouting.
             * @return The maximum container size in X direction.
             */
            virtual Real GetMaxContainerSizeX() const = 0;
            /**
             * @brief Get the maximum container size in Y direction used for layouting.
             * @return The maximum container size in Y direction.
             */
            virtual Real GetMaxContainerSizeY() const = 0;
            /**
             * @brief Get the maximum container size in Z direction used for layouting.
             * @return The maximum container size in Z direction.
             */
            virtual Real GetMaxContainerSizeZ() const = 0;
            
            /**
             * @brief Set the container alignment for all three axes.
             * The container alignment properties specify the actual pivot (or anchor) point
             * for handling the aligner. For example, using IEnums::ALIGNMENT_X_LEFT for the 
             * X axis and IEnums::ALIGNMENT_Y_TOP will layout the aligner's contents to the
             * right (positive X axis) and bottom (negative Y axis) from the aligner's origin.
             * By default, the aligner's container alignment is set to CENTER for all three
             * axes.
             * @param alignX The container alignment in X direction.
             * @param alignY The container alignment in Y direction.
             * @param alignZ The container alignment in Z direction.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignment(IEnums::AlignmentX alignX, IEnums::AlignmentY alignY, IEnums::AlignmentZ alignZ) = 0;
            /**
             * @brief Set the container alignment for the X axis.
             * @param alignX The container alignment in X direction.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentX(IEnums::AlignmentX alignX) = 0;
            /**
             * @brief Set the container alignment for the Y axis.
             * @param alignY The container alignment in Y direction.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentY(IEnums::AlignmentY alignY) = 0;
            /**
             * @brief Set the container alignment for the Z axis.
             * @param alignZ The container alignment in Z direction.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentZ(IEnums::AlignmentZ alignZ) = 0;
            /**
             * @brief Get the container alignment for the X axis.
             * @return The container alignment in X direction.
             */
            virtual IEnums::AlignmentX GetContainerAlignmentX() const = 0;
            /**
             * @brief Get the container alignment for the Y axis.
             * @return The container alignment in Y direction.
             */
            virtual IEnums::AlignmentY GetContainerAlignmentY() const = 0;
            /**
             * @brief Get the container alignment for the Z axis.
             * @return The container alignment in Z direction.
             */
            virtual IEnums::AlignmentZ GetContainerAlignmentZ() const = 0;
            
            /**
             * @brief Set the object alignment for all three axes.
             * The object alignment properties specify how the contents of the aligner are
             * arranged for each axis. If for example the main axis is set to X in ascending 
             * order, the X alignment is set to LEFT, and the Y object alignment value is
             * set to BOTTOM, all sub-graphs are aligned in their given order from left to
             * right, and their Y start coordinates are aligned at the bottom of the container.
             * Note that for all axes with object alignment set to UNDEFINED, the respective
             * sub-graphs' coordinate along that axis remains unchanged.
             * @param alignX The object alignment in X direction.
             * @param alignY The object alignment in Y direction.
             * @param alignZ The object alignment in Z direction.
             * @return true if successful.
             */
            virtual Bool SetObjectAlignment(IEnums::AlignmentX alignX, IEnums::AlignmentY alignY, IEnums::AlignmentZ alignZ) = 0;
            /**
             * @brief Set the object alignment on the X axis.
             * @param alignX The object alignment in X direction.
             * @return true if successful.
             */
            virtual Bool SetObjectAlignmentX(IEnums::AlignmentX alignX) = 0;
            /**
             * @brief Set the object alignment on the Y axis.
             * @param alignY The object alignment in Y direction.
             * @return true if successful.
             */
            virtual Bool SetObjectAlignmentY(IEnums::AlignmentY alignY) = 0;
            /**
             * @brief Set the object alignment on the Z axis.
             * @param alignZ The object alignment in Z direction.
             * @return true if successful.
             */
            virtual Bool SetObjectAlignmentZ(IEnums::AlignmentZ alignZ) = 0;
            /**
             * @brief Get the object alignment on the X axis.
             * @return The object alignment in X direction.
             */
            virtual IEnums::AlignmentX GetObjectAlignmentX() const = 0;
            /**
             * @brief Get the object alignment on the Y axis.
             * @return The object alignment in Y direction.
             */
            virtual IEnums::AlignmentY GetObjectAlignmentY() const = 0;
            /**
             * @brief Get the object alignment on the Z axis.
             * @return The object alignment in Z direction.
             */
            virtual IEnums::AlignmentZ GetObjectAlignmentZ() const = 0;

            /**
             * @brief Set the object alignment unit.
             * This method sets the alignment unit for all three axes, which can be used to round the
             * aligner container's positions to some given values, in order to e.g. position the resulting
             * container on integer pixel coordinates. By default, the alignment units for all axes are
             * set to -1.0, which means "no rounding".
             * @param unitX The alignment unit in X direction.
             * @param unitY The alignment unit in Y direction.
             * @param unitZ The alignment unit in Z direction.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnit(Real unitX, Real unitY, Real unitZ) = 0;
            /**
             * @brief Set the object alignment unit along the X axis.
             * See SetAlignmentUnit().
             * @param unitX The alignment unit in X direction.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnitX(Real unitX) = 0;
            /**
             * @brief Set the object alignment unit along the Y axis.
             * See SetAlignmentUnit().
             * @param unitY The alignment unit in Y direction.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnitY(Real unitY) = 0;
            /**
             * @brief Set the object alignment unit along the Z axis.
             * See SetAlignmentUnit().
             * @param unitZ The alignment unit in Z direction.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnitZ(Real unitZ) = 0;
            /**
             * @brief Set the object alignment unit along the X axis.
             * @return The alignment unit in X direction.
             */
            virtual Real GetAlignmentUnitX() const = 0;
            /**
             * @brief Set the object alignment unit along the Y axis.
             * @return The alignment unit in Y direction.
             */
            virtual Real GetAlignmentUnitY() const = 0;
            /**
             * @brief Set the object alignment unit along the Z axis.
             * @return The alignment unit in Z direction.
             */
            virtual Real GetAlignmentUnitZ() const = 0;

            /**
             * @brief Get the aligner's bounding volume.
             * @return The bounding volume.
             */
            virtual IBoundingVolume* GetBoundingVolume() = 0;
            /**
             * @brief Get the aligner's bounding volume.
             * @return The bounding volume.
             */
            virtual const IBoundingVolume* GetBoundingVolume() const = 0;
            
        protected:
            virtual ~IAligner() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAligner nodes.
         */
        typedef IGenericNodeTarget<IAligner> IAlignerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ALIGNER_H__

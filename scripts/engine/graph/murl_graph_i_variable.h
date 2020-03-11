// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VARIABLE_H__
#define __MURL_GRAPH_I_VARIABLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IVariable;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVariable nodes.
         */
        typedef IGenericNodeTarget<IVariable> IVariableNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IVariable
         * @brief The IVariable graph node interface.
         * Variable nodes provide a generic bridge between user logic code and certain scene graph 
         * nodes as well as a means for simple arithmetic operations within the scene graph.
         * Variable nodes serve as input for e.g. controllers that implement the 
         * Graph::IVariableController interface, or Graph::IClipTransition nodes.
         *
         * Depending on the actual operation given (IEnums::ALU_OPERATION_*), certain constraints 
         * apply to the given input and output data types (inType and outType: IEnums::VARIABLE_TYPE_*)
         * as well as number of constant and variable inputs and outputs (numIn and numOut):
         *
         *  - COPY and REPLACE: 
         *      numIn==1, numOut==0, inType==outType
         *      Result equals input operand #0.
         *
         *  - ADD, SUBTRACT, SUBTRACT_REVERSE, MULTIPLY, DIVIDE, DIVIDE_REVERSE:
         *      numIn>=2, numOut==0, inType==outType, inType==SINT32||REAL
         *      Result is the combined operation over all input operands.
         *
         *  - MAP, MAP_CLAMPED:
         *      numIn>=3, numIn==numOut, inType==REAL
         *      Input operands 1..N represent an either strictly ascending or descending sequence of
         *      values that map input operand 0 linearly to their corresponding output values (not 
         *      necessarily in strict order). MAP_CLAMPED clamps the result to the given first or 
         *      last output operand, if input #0 is outside the range of inputs 1..N.
         *      Output #0 is ignored.
         *
         *  - LESS, LESS_OR_EQUAL, GREATER, GREATER_OR_EQUAL:
         *      numIn==2, numOut==0, outType==BOOL, inType==SINT32||REAL
         *      Result is boolean true or false depending on comparison outcome.
         *
         *  - EQUAL, NOT_EQUAL:
         *      numIn==2, numOut==0, outType==BOOL, inType==SINT32||REAL||BOOL
         *      Result is boolean true or false depending on comparison outcome.
         *
         *  - NEGATE:
         *      numIn==1, numOut==0, inType==outType, inType==SINT32||REAL
         *      Result is the negated input #0 (-value).
         *
         *  - INVERT:
         *      numIn==1, numOut==0, inType==outType, inType==SINT32||BOOL
         *      Result is bitwise (SINT32) or logically (BOOL) inverted.
         *
         *  - AND, OR, XOR:
         *      numIn>=2, numOut==0, inType==outType, inType==SINT32||BOOL
         *      Result is the bitwise (SINT32) or logical (BOOL) outcome of operation.
         */
        class IVariable
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
             * @brief Set the data type for all constant input operands.
             * @param type The data type.
             * @return true if successful.
             */
            virtual Bool SetInputType(IEnums::VariableType type) = 0;
            /**
             * @brief Get the data type for all constant input operands.
             * @return The data type.
             */
            virtual IEnums::VariableType GetInputType() const = 0;

            /**
             * @brief Set the output data type.
             * @param type The data type.
             * @return true if successful.
             */
            virtual Bool SetOutputType(IEnums::VariableType type) = 0;
            /**
             * @brief Get the output data type.
             * @return The data type.
             */
            virtual IEnums::VariableType GetOutputType() const = 0;

            /**
             * @brief Set the arithmetic/logic operation to perform.
             * @param operation The operation.
             * @return true if successful.
             */
            virtual Bool SetOperation(IEnums::AluOperation operation) = 0;
            /**
             * @brief Get the arithmetic/logic operation performed.
             * @return The operation.
             */
            virtual IEnums::AluOperation GetOperation() const = 0;

            /**
             * @brief Enable/disable auto-resetting.
             * @param enabled If true, auto-resetting is enabled.
             * @return true if successful.
             */
            virtual Bool SetAutoResetEnabled(Bool enabled) = 0;
            /**
             * @brief Check if auto-resetting is enabled.
             * @return true if auto-resetting is enabled.
             */
            virtual Bool IsAutoResetEnabled() const = 0;

            /**
             * @brief Get the mutable Graph::IVariableNodeTarget container referencing the input variables.
             * This method returns a mutable pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to set or query references to the input variables.
             * @return The mutable Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual IVariableNodeTarget* GetVariableInputOperandNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVariableNodeTarget container referencing the input variables.
             * This method returns a constant pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to query references to the input variables.
             * @return The constant Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual const IVariableNodeTarget* GetVariableInputOperandNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IVariableNodeTarget container referencing the output variables.
             * This method returns a mutable pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to set or query references to the output variables.
             * @return The mutable Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual IVariableNodeTarget* GetVariableOutputOperandNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVariableNodeTarget container referencing the output variables.
             * This method returns a constant pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to query references to the output variables.
             * @return The constant Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual const IVariableNodeTarget* GetVariableOutputOperandNodeTarget() const = 0;

            /**
             * @brief Set a constant string input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantInputOperand(UInt32 index, const String& value) = 0;
            /**
             * @brief Set a constant boolean input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantInputOperand(UInt32 index, Bool value) = 0;
            /**
             * @brief Set a constant floating-point input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantInputOperand(UInt32 index, Real value) = 0;
            /**
             * @brief Set a constant integer input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantInputOperand(UInt32 index, SInt32 value) = 0;
            /**
             * @brief Get a constant boolean input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantInputOperand(UInt32 index, Bool& value) const = 0;
            /**
             * @brief Get a constant floating-point input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantInputOperand(UInt32 index, Real& value) const = 0;
            /**
             * @brief Get a constant integer input value at a given index.
             * See class description.
             * @param index The input operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantInputOperand(UInt32 index, SInt32& value) const = 0;

            /**
             * @brief Set a constant string output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantOutputOperand(UInt32 index, const String& value) = 0;
            /**
             * @brief Set a constant boolean output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantOutputOperand(UInt32 index, Bool value) = 0;
            /**
             * @brief Set a constant floating-point output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantOutputOperand(UInt32 index, Real value) = 0;
            /**
             * @brief Set a constant integer output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The value to apply.
             * @return true if successful.
             */
            virtual Bool SetConstantOutputOperand(UInt32 index, SInt32 value) = 0;
            /**
             * @brief Get a constant boolean output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantOutputOperand(UInt32 index, Bool& value) const = 0;
            /**
             * @brief Get a constant floating-point output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantOutputOperand(UInt32 index, Real& value) const = 0;
            /**
             * @brief Get a constant integer output value at a given index.
             * See class description.
             * @param index The output operand index.
             * @param value The return value to retrieve.
             * @return true if successful.
             */
            virtual Bool GetConstantOutputOperand(UInt32 index, SInt32& value) const = 0;

            /**
             * @brief Try to get the result as a boolean value.
             * @param value A reference to a boolean variable to receive the result.
             * @return true if successful.
             */
            virtual Bool GetValue(Bool& value) const = 0;
            /**
             * @brief Try to get the result as a floating-point value.
             * @param value A reference to a floating-point variable to receive the result.
             * @return true if successful.
             */
            virtual Bool GetValue(Real& value) const = 0;
            /**
             * @brief Try to get the result as a integer value.
             * @param value A reference to a integer variable to receive the result.
             * @return true if successful.
             */
            virtual Bool GetValue(SInt32& value) const = 0;

        protected:
            virtual ~IVariable() {}
        };
    }
}

#endif // __MURL_GRAPH_I_VARIABLE_H__

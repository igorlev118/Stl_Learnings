// Copyright 2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TRACKER_RESULT_H__
#define __MURL_GRAPH_I_TRACKER_RESULT_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        class INode;
        class IController;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface ITrackerResult
         * @brief The tracker result interface.
         */
        class ITrackerResult
        {
        public:
            /**
             * @brief The result type.
             */
            enum Type
            {
                /// Info result.
                TYPE_INFO,
                /// A warning.
                TYPE_WARNING,
                /// An error.
                TYPE_ERROR,

                NUM_TYPES
            };

            virtual ~ITrackerResult() {}

            /**
             * @brief Clone the result object.
             * @return The newly created clone.
             */
            virtual const ITrackerResult* Clone() const = 0;

            /**
             * @brief Get the graph node the result applies to.
             * @return The affected node, or null if not a node.
             */
            virtual const INode* GetNode() const = 0;
            /**
             * @brief Get the graph controller the result applies to.
             * @return The affected controller, or null if not a controller.
             */
            virtual const IController* GetController() const = 0;

            /**
             * @brief Get the result type.
             * @return The result type.
             */
            virtual Type GetType() const = 0;

            /**
             * @brief Get the fully qualified name of the function/method that posted this result.
             * @return The function.
             */
            virtual const String& GetFunction() const = 0;
            /**
             * @brief Get the line number within the source file where the result was posted
             * @return The line number.
             */
            virtual UInt32 GetLine() const = 0;

            /**
             * @brief Get the result message string.
             * This method returns the plain message string, which may optionally contain any
             * number of parameter place holders in the form {N}, with N being a number between 0
             * and GetParameters().GetCount()-1. To obtain the full message, use 
             * Util::FillInParameters(GetMessage(), GetParameters()).
             * @return The plain message string.
             */
            virtual const String& GetMessage() const = 0;
            /**
             * @brief Get the array of result parameter strings.
             * This method returns the array of parameters to be inserted into the plain message
             * string. See GetMessage().
             * @return The array of parameter strings.
             */
            virtual const StringArray& GetParameters() const = 0;
        };
    }
}

#endif // __MURL_GRAPH_I_TRACKER_RESULT_H__

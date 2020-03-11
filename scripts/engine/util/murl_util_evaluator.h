// Copyright 2014-2015 Spraylight GmbH

#ifndef __MURL_UTIL_EVALUATOR_H__
#define __MURL_UTIL_EVALUATOR_H__

#include "murl_i_attributes.h"
#include "murl_map.h"
#include "murl_string.h"

namespace Murl
{
    namespace Util
    {
        class EvaluatorVariables;
        class EvaluatorExpression;

        /**
         * @ingroup MurlUtilClasses
         * @brief An expression evaluator.
         */
        class Evaluator
        {
        public:
            /**
             * @brief The constructor.
             */
            Evaluator();
            /**
             * @brief The destructor.
             */
            virtual ~Evaluator();

            /**
             * @brief Add a set of user-defined constants used during evaluation.
             * @param constants The user-defined constants.
             * @return true if successful.
             */
            virtual Bool AddConstants(const IAttributes* constants);
            /**
             * @brief Add a set of user-defined variables used during evaluation.
             * @param variables The user-defined variables.
             * @return true if successful.
             */
            virtual Bool AddVariables(IAttributes* variables);

            /**
             * @brief Update the evaluator.
             * Whenever an input constant or variable has changed, this method must
             * be called prior to Evaluate() to reflect the actual changes.
             * @return true if successful.
             */
            virtual Bool Update();

            /**
             * @brief Evaluate a given expression string.
             * @param expression The expression string to evaluate
             * @param result A reference to a string receiving the result.
             * @return true if successful.
             */
            virtual Bool Evaluate(const String& expression, String& result);

        protected:
            Array<EvaluatorVariables*> mConstants;
            Array<EvaluatorVariables*> mVariables;

            Map<String, EvaluatorExpression*> mExpressions;

            Bool mIsInitialized;
            Bool mIsDirty;
        };
    }
}

#endif // __MURL_UTIL_EVALUATOR_H__

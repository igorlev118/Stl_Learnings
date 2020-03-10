// Copyright 2012-2015 Spraylight

#ifndef __MURL_LOGIC_BASE_STEPABLE_H__
#define __MURL_LOGIC_BASE_STEPABLE_H__

#include "murl_logic_stepable.h"
#include "murl_logic_i_factory.h"
#include "murl_logic_i_device_handler.h"

#include "murl_logic_graph_node_types.h"

#include "murl_i_app_configuration.h"
#include "murl_i_engine_configuration.h"
#include "murl_i_platform_configuration.h"

#include "murl_i_loader.h"
#include "murl_i_package.h"
#include "murl_resource_i_collection.h"
#include "murl_resource_i_text.h"

#include "murl_object_index.h"
#include "murl_object_map.h"
#include "murl_object_queue.h"
#include "murl_util.h"
#include "murl_util_rng.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the IStepable object.
         * A stepable object is created at object instantiation.
         */
        class BaseStepable : public IAppStepable, public Stepable, NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             * Creates a IStepable object.
             */
            BaseStepable()
            {
                SetAppStepable(IAppStepablePtr(this, NoDeleter()));
            }

            /**
             * @brief The destructor.
             * Destroys the IStepable object.
             */
            virtual ~BaseStepable()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStepable interface.
             */
            operator IStepablePtr()
            {
                return IStepablePtr(this, NoDeleter());
            }

        protected: // IAppStepable

            /**
             * @brief Default implementation of IAppStepable::OnSetEnabled() method,
             * this method is empty and can be overwritten.
             * @param isEnabled true if enabled.
             */
            virtual void OnSetEnabled(Bool isEnabled)
            {
            }

            /**
             * @brief Default implementation of IAppStepable::OnReset() method,
             * this method is empty and can be overwritten.
             */
            virtual void OnReset()
            {
            }

            /**
             * @brief Default implementation of IAppStepable::OnProcessTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnProcessTick(const Logic::IState* state)
            {
            }

            /**
             * @brief Default implementation of IAppStepable::OnFinishTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnFinishTick(const Logic::IState* state)
            {
            }
        };
    }
}

#endif  // __MURL_LOGIC_BASE_STEPABLE_H__

// Copyright 2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_APP_GRAPH_H__
#define __MURL_LOGIC_I_APP_GRAPH_H__

#include "murl_logic_i_state.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IPackage;

    namespace Logic
    {
        /**
         * @ingroup MurlLogicAppInterfaces
         * @interface IAppGraph
         * @brief The IAppGraph interface.
         * This interface is used by the Graph::ILogicController object to callback the app.
         */
        class IAppGraph
        {
        public:
            /**
             * @brief Called by Graph::ILogicController at initialization.
             * Perform initializaton before the node and its children are being initialized.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnPreInit(const Logic::IState* state) = 0;
            /**
             * @brief Called by Graph::ILogicController at initialization.
             * Perform initializaton after the node and its children have been initialized.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnPostInit(const Logic::IState* state) = 0;

            /**
             * @brief Called by Graph::ILogicController at deinitialization.
             * Perform de-initializaton step before the node and its children are being de-initialized.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnPreDeInit(const Logic::IState* state) = 0;
            /**
             * @brief Called by Graph::ILogicController at deinitialization.
             * Perform de-initializaton step after the node and its children have been de-initialized.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnPostDeInit(const Logic::IState* state) = 0;

            /**
             * @brief Called by Graph::ILogicController each logic tick.
             * Performed by graph logic traversal, before the node is being processed.
             * @param state The IState object.
             */
            virtual void OnPreProcessTick(const Logic::IState* state) = 0;
            /**
             * @brief Called by Graph::ILogicController each logic tick.
             * Performed by graph logic traversal, after the node's children have been processed.
             * @param state The IState object.
             */
            virtual void OnPostProcessTick(const Logic::IState* state) = 0;

            /**
             * @brief Called by Graph::ILogicController if the configuration changed.
             * Signal a configuration change, before the node is being processed.
             * @param state The IState object.
             */
            virtual void OnPreConfigChanged(const Logic::IState* state) = 0;
            /**
             * @brief Called by Graph::ILogicController if the configuration changed.
             * Signal a configuration change, after the node's children have been processed.
             * @param state The IState object.
             */
            virtual void OnPostConfigChanged(const Logic::IState* state) = 0;

            /**
             * @brief Called by Graph::IScriptLogicController if the configuration changed.
             * Signal a configuration change, before the node is being processed.
             *
             * If a new configuration dependent controller script is created the following is called:
             * - New controller: OnPreInitConfigChanged() or OnPreInit() if no recent controller is available
             * - Recent controller: OnPreDeInit()
             *
             * If no new configuration dependent controller script is created the OnPreConfigChanged()
             * method of the recent controller is called.
             *
             * @param state The IState object.
             * @param recentAppGraph The recent IAppGraph interface object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnPreInitConfigChanged(const Logic::IState* state, Logic::IAppGraphPtr recentAppGraph) = 0;
            /**
             * @brief Called by Graph::IScriptLogicController if the configuration changed.
             * Signal a configuration change, after the node's children have been processed.
             *
             * If a new configuration dependent controller script is created the following is called:
             * - New controller: OnPostInitConfigChanged() or OnPostInit() if no recent controller is available
             * - Recent controller: OnPostDeInit()
             *
             * If no new configuration dependent controller script is created the OnPostConfigChanged()
             * method of the recent controller is called.
             *
             * @param state The IState object.
             * @param recentAppGraph The recent IAppGraph interface object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnPostInitConfigChanged(const Logic::IState* state, Logic::IAppGraphPtr recentAppGraph) = 0;

        protected:
            virtual ~IAppGraph() {}
        };
    }
}

#endif // __MURL_LOGIC_I_APP_GRAPH_H__

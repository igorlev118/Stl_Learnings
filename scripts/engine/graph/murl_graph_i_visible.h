// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VISIBLE_H__
#define __MURL_GRAPH_I_VISIBLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IVisible
         * @brief The IVisible property interface.
         * This interface provides setting and retrieving common properties of a visible
         * object (e.g. a movie).
         */
        class IVisible
        {
        public:
            /**
             * @brief Set the pixel format used for output.
             * @param pixelFormat The internal pixel format to use.
             * @return true if successful.
             */
            virtual Bool SetPixelFormat(IEnums::PixelFormat pixelFormat) = 0;
            /**
             * @brief Get the pixel format used for output.
             * @return The pixel format.
             */
            virtual IEnums::PixelFormat GetPixelFormat() const = 0;
            
        protected:
            virtual ~IVisible() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVisible nodes.
         */
        typedef IGenericNodeTarget<IVisible> IVisibleNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VISIBLE_H__

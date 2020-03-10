// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_FRUSTUM_H__
#define __MURL_MATH_FRUSTUM_H__

#include "murl_math_vector.h"
#include "murl_math_plane.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Matrix;

        /**
         * @ingroup MurlMathClasses
         * @brief A frustum describing 6 planes.
         */
        template<class DataType>
        class Frustum
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief Enumeration of the frustum planes.
             */
            enum ClipPlane
            {
                /** The left plane. */
                CLIP_PLANE_LEFT = 0,
                /** The right plane. */
                CLIP_PLANE_RIGHT,
                /** The top plane. */
                CLIP_PLANE_TOP,
                /** The bottom plane. */
                CLIP_PLANE_BOTTOM,
                /** The near plane. */
                CLIP_PLANE_NEAR,
                /** The far plane. */
                CLIP_PLANE_FAR,
                /** The number of planes. */
                NUM_CLIP_PLANES
            };

            /**
             * @brief The default constructor.
             */
            Frustum()
            {
            }

            /**
             * @brief Constructor taking a projection matrix.
             * @param projectionMatrix The projection matrix.
             */
            Frustum(const Matrix<DataType>& projectionMatrix)
            {
                Set(projectionMatrix);
            }

            /**
             * @brief The copy constructor using a frustum of different type.
             * @param f The frustum to copy.
             */
            template<class DataType2>
            Frustum(const Frustum<DataType2>& f)
            {
                for (UInt32 i = 0; i < NUM_CLIP_PLANES; i++)
                {
                    mClipPlanes[i] = f.GetClipPlane(static_cast<typename Frustum<DataType2>::ClipPlane>(i));
                }
            }

            /**
             * @brief Set the frustum planes by a projection matrix.
             * @param projectionMatrix The projection matrix.
             */
            void Set(const Matrix<DataType>& projectionMatrix)
            {
                const Matrix<DataType>& p = projectionMatrix;

                Plane<DataType>& lc = mClipPlanes[CLIP_PLANE_LEFT];
                lc.Set(p.GetWX() + p.GetXX(), p.GetWY() + p.GetXY(), p.GetWZ() + p.GetXZ(), p.GetWW() + p.GetXW());
                lc.NormalizeSelf();

                Plane<DataType>& rc = mClipPlanes[CLIP_PLANE_RIGHT];
                rc.Set(p.GetWX() - p.GetXX(), p.GetWY() - p.GetXY(), p.GetWZ() - p.GetXZ(), p.GetWW() - p.GetXW());
                rc.NormalizeSelf();

                Plane<DataType>& tc = mClipPlanes[CLIP_PLANE_TOP];
                tc.Set(p.GetWX() - p.GetYX(), p.GetWY() - p.GetYY(), p.GetWZ() - p.GetYZ(), p.GetWW() - p.GetYW());
                tc.NormalizeSelf();

                Plane<DataType>& bc = mClipPlanes[CLIP_PLANE_BOTTOM];
                bc.Set(p.GetWX() + p.GetYX(), p.GetWY() + p.GetYY(), p.GetWZ() + p.GetYZ(), p.GetWW() + p.GetYW());
                bc.NormalizeSelf();

                Plane<DataType>& nc = mClipPlanes[CLIP_PLANE_NEAR];
                nc.Set(p.GetWX() + p.GetZX(), p.GetWY() + p.GetZY(), p.GetWZ() + p.GetZZ(), p.GetWW() + p.GetZW());
                nc.NormalizeSelf();

                Plane<DataType>& fc = mClipPlanes[CLIP_PLANE_FAR];
                fc.Set(p.GetWX() - p.GetZX(), p.GetWY() - p.GetZY(), p.GetWZ() - p.GetZZ(), p.GetWW() - p.GetZW());
                fc.NormalizeSelf();
            }

            /**
             * @brief Get a plane by identifier.
             * @param plane The enumerated plane identifer.
             * @return The plane.
             */
            const Plane<DataType>& GetClipPlane(ClipPlane plane) const
            {
                return mClipPlanes[plane];
            }

        protected:
            /** @brief The plane storage array. */
            Plane<DataType> mClipPlanes[NUM_CLIP_PLANES];
        };
    }
}

#endif // __MURL_MATH_FRUSTUM_H__

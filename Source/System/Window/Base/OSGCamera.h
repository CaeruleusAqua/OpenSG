/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

#ifndef _OSGCAMERA_H_
#define _OSGCAMERA_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGMatrix.h"
#include "OSGFrustumVolume.h"
#include "OSGCameraBase.h"

OSG_BEGIN_NAMESPACE

class Viewport;
class FrustumVolume;
class Line;

/*! \brief Camera base class. See \ref PageSystemWindowCamera for a
    description.

  \ingroup GrpSystemWindowCamera
  \ingroup GrpLibOSGSystem
  \includebasedoc
*/

class OSG_SYSTEM_DLLMAPPING Camera : public CameraBase
{
     /*==========================  PUBLIC  =================================*/

 public:

    typedef CameraBase Inherited;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   transformation                             */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         detail);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Setup Rendering                            */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Access Parameters                           */
    /*! \{                                                                 */

    virtual void    getProjection              (Matrix        &result,
                                                UInt32         width,
                                                UInt32         height);

    virtual void    getProjectionTranslation   (Matrix        &result,
                                                UInt32         width,
                                                UInt32         height);

    virtual void    getViewing                 (Matrix        &result,
                                                UInt32         width,
                                                UInt32         height);

	virtual void    getFrustum                 (FrustumVolume &result,
                                                UInt32         width, 
                                                UInt32         height);

	virtual void    getDecoration              (Matrix        &result, 
                                                UInt32         width, 
                                                UInt32         height);

    // Getters
    virtual Matrix  getProjectionVal           (UInt32         width,
                                                UInt32         height);

    virtual Matrix  getProjectionTranslationVal(UInt32         width,
                                                UInt32         height);

    virtual Matrix  getViewingVal              (UInt32         width,
                                                UInt32         height);

	virtual Matrix  getDecorationVal           (UInt32         width,
                                                UInt32         height);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Access Parameters                           */
    /*! \{                                                                 */

    void          calcFrustum         (      FrustumVolume &result,
                                       const Viewport      &port  );

    void          calcWorldToScreen   (      Matrix        &result,
                                       const Viewport      &port  );


    FrustumVolume calcFrustumVal      (const Viewport      &port  );

    Matrix        calcWorldToScreenVal(const Viewport      &port  );

#ifdef OSG_1_COMPAT
    void          getFrustum          (      FrustumVolume &result,
                                       const Viewport      &port  );

    void          getWorldToScreen    (      Matrix        &result,
                                       const Viewport      &port  );

    FrustumVolume getFrustumVal       (const Viewport      &port  );

    Matrix        getWorldToScreenVal (const Viewport      &port  );
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Tile Information                             */
    /*! \{                                                                 */

    virtual Vec2u tileGetFullSize(void) const;
    virtual Vec4f tileGetRegion  (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Intersection Helper                          */
    /*! \{                                                                 */

    bool calcViewRay(      Line     &line, 
                           Int32     x, 
                           Int32     y, 
                     const Viewport &port,
                           Real32   *t   = NULL );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    dump                                      */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0,
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

 protected:

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    Camera(void);
    Camera(const Camera &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Camera(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Init                                   */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

 private:

    friend class FieldContainer;
    friend class CameraBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const Camera &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

typedef Camera *CameraP;

OSG_END_NAMESPACE

#include "OSGCameraBase.inl"
#include "OSGCamera.inl"

#endif /* _OSGCAMERA_H_ */

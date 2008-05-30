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
#include "OSGNode.h"

#include "OSGCameraBase.h"

OSG_BEGIN_NAMESPACE

class Viewport;
class FrustumVolume;
class Line;

/*! \brief Camera base class. See \ref PageSystemWindowCamera for a
    description.
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

#ifdef OSG_OLD_RENDER_ACTION
    virtual void setup          (DrawActionBase *action, const Viewport &port);

    virtual void setupProjection(DrawActionBase *action, const Viewport &port);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Access Parameters                           */
    /*! \{                                                                 */

    virtual void getProjection           (      Matrixr       &result,
                                                UInt32         width,
                                                UInt32         height);

    virtual void getProjectionTranslation(      Matrixr       &result,
                                                UInt32         width,
                                                UInt32         height);

    virtual void getViewing              (      Matrixr       &result,
                                                UInt32         width,
                                                UInt32         height);

    virtual void getFrustum              (      FrustumVolume &result,
                                          const Viewport      &port  );

	virtual void getFrustum              (      FrustumVolume &result,
                                                UInt32         width, 
                                                UInt32         height);

    virtual void getWorldToScreen        (      Matrixr       &result,
                                          const Viewport      &port  );

	virtual void getDecoration           (      Matrixr       &result, 
                                                UInt32         width, 
                                                UInt32         height);

    // Getters
    virtual Matrixr getProjectionVal           (      UInt32         width,
                                                      UInt32         height);

    virtual Matrixr getProjectionTranslationVal(      UInt32         width,
                                                      UInt32         height);

    virtual Matrixr getViewingVal              (      UInt32         width,
                                                      UInt32         height);
    virtual Matrixr getWorldToScreenVal        (const Viewport      &port  );

	virtual Matrixr getDecorationVal           (      UInt32         width,
                                                      UInt32         height);

    virtual FrustumVolume getFrustumVal        (const Viewport      &port  );



    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Intersection Helper                          */
    /*! \{                                                                 */

#ifndef OSG_WINCE
    bool calcViewRay(      Line     &line, 
                           Int32     x, 
                           Int32     y, 
                     const Viewport &port,
                           Real32   *t   = NULL );
#endif

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

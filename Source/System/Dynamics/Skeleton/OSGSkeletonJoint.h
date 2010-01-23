/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

#ifndef _OSGSKELETONJOINT_H_
#define _OSGSKELETONJOINT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGSkeletonJointBase.h"
#include "OSGSkeletonFields.h"

OSG_BEGIN_NAMESPACE

// forward decl
class Skeleton;

/*! \brief SkeletonJoint class. See \ref
           PageDrawableSkeletonJoint for a description.
*/

class OSG_DYNAMICS_DLLMAPPING SkeletonJoint : public SkeletonJointBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef SkeletonJointBase Inherited;
    typedef SkeletonJoint     Self;

    static const Int16 INVALID_JOINT_ID = -1;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Skeleton                                */
    /*! \{                                                                 */

    const SFParentSkeletonPtr *getSFSkeleton(void) const;
    Skeleton                  *getSkeleton  (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Render                                  */
    /*! \{                                                                 */

    Action::ResultE renderEnter  (Action *action);
    Action::ResultE renderLeave  (Action *action);

    Action::ResultE animBindEnter(Action *action);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Transformation                             */
    /*! \{                                                                 */

    virtual void accumulateMatrix(Matrixr &result);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Volume                                  */
    /*! \{                                                                 */

    virtual void adjustVolume    (Volume &volume);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in SkeletonJointBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    SkeletonJoint(void);
    SkeletonJoint(const SkeletonJoint &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SkeletonJoint(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class SkeletonJointBase;

    friend class Skeleton;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const SkeletonJoint &source);
};

typedef SkeletonJoint *SkeletonJointP;

OSG_END_NAMESPACE

// include this here, so that it is available in the .inl
#include "OSGSkeleton.h"

#include "OSGSkeletonJointBase.inl"
#include "OSGSkeletonJoint.inl"

#endif /* _OSGSKELETONJOINT_H_ */

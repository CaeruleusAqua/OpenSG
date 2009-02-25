/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2003 by the OpenSG Forum                          *
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

#ifndef _OSGMATHMFIELDS_H_
#define _OSGMATHMFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGMField.h"
#include "OSGMathFieldTraits.h"

OSG_BEGIN_NAMESPACE

#ifndef DOXYGEN_SHOULD_SKIP_THIS


/*! \ingroup GrpBaseFieldMulti */
typedef MField<Matrix      > MFMatrix;


/*! \ingroup GrpBaseFieldMulti */
typedef MField<Matrix4d    > MFMatrix4d;


/*! \ingroup GrpBaseFieldMulti */
typedef MField<Matrix4fx   > MFMatrix4fx;


/*! \ingroup GrpBaseFieldMulti */
typedef MField<Quaternion  > MFQuaternion;


/*! \ingroup GrpBaseFieldMulti */
typedef MField<Quaternionfx> MFQuaternionfx;



#ifdef OSG_FLOAT_PROFILE
typedef MFMatrix       MFMatrixr;
typedef MFQuaternion   MFQuaternionr;
#else
typedef MFMatrix4fx    MFMatrixr;
typedef MFQuaternionfx MFQuaternionr;
#endif

#else // these are the doxygen hacks

/*! \ingroup GrpBaseFieldMulti */
struct MFMatrix : public MField<Matrix> {};
/*! \ingroup GrpBaseFieldMulti */
struct MFMatrix4d : public MField<Matrix4d> {};
/*! \ingroup GrpBaseFieldMulti */
struct MFMatrix4fx : public MField<Matrix4fx> {};
/*! \ingroup GrpBaseFieldMulti */
struct MFQuaternion : public MField<Quaternion> {};
/*! \ingroup GrpBaseFieldMulti */
struct MFQuaternionfx : MField<Quaternionfx> {};


#ifdef OSG_FLOAT_PROFILE
/*! \ingroup GrpBaseFieldMulti */
typedef MFMatrix       MFMatrixr;
/*! \ingroup GrpBaseFieldMulti */
typedef MFQuaternion   MFQuaternionr;
#else
/*! \ingroup GrpBaseFieldMulti */
typedef MFMatrix4fx    MFMatrixr;
/*! \ingroup GrpBaseFieldMulti */
typedef MFQuaternionfx MFQuaternionr;
#endif

#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGMATHMFIELDS_H_ */

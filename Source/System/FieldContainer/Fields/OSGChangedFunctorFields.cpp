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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include<OSGSystemDef.h>
#include<OSGFieldDescriptionBase.h>
#include<OSGChangedFunctorSFields.h>
#include<OSGChangedFunctorMFields.h>

OSG_BEGIN_NAMESPACE
#if 1
template<> 
OSG_DLL_EXPORT
void FieldDescription<FieldTraits<ChangedFunctorCallback>, 
                      SingleField                        >::cloneValues(
    const Field                     *pSrc,
          ConstFieldMaskArg          whichField,
    const StringVector              &share,
          FieldContainerPtrConstArg  pDst      ) const
{
    FWARNING(("clone values ni called for sf changed functors\n"));
}


template<> 
OSG_DLL_EXPORT
void FieldDescription<FieldTraits<ChangedFunctorCallback>, 
                      SingleField                        >::shareValues(
    const Field                     *pSrc,
          ConstFieldMaskArg          whichField,
          FieldContainerPtrConstArg  pDst      ) const
{
    FWARNING(("share values ni called for sf changed functors\n"));
}

template<> 
OSG_DLL_EXPORT
void FieldDescription<FieldTraits<ChangedFunctorCallback>, 
                      MultiField                          >::cloneValues(
    const Field                     *pSrc,
          ConstFieldMaskArg          whichField,
    const StringVector              &share,
          FieldContainerPtrConstArg  pDst      ) const
{
    FWARNING(("clone values ni called for mf changed functors\n"));
}

template<> 
OSG_DLL_EXPORT
void FieldDescription<FieldTraits<ChangedFunctorCallback>, 
                      MultiField                          >::shareValues(
    const Field                     *pSrc,
          ConstFieldMaskArg          whichField,
          FieldContainerPtrConstArg  pDst      ) const
{
    FWARNING(("share values ni called for mf changed functors\n"));
}
#endif

OSG_END_NAMESPACE

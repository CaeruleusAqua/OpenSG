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

OSG_BEGIN_NAMESPACE

inline
void FieldBundle::editSField(ConstFieldMaskArg OSG_CHECK_ARG(whichField))
{
#if 0
    if(_bvChanged == TypeTraits<BitVector>::BitsClear)
    {
        registerChangedContainer();
    }
    
    _bvChanged |= whichField;
#endif
}

template<class FieldT> inline
void FieldBundle::editMField(ConstFieldMaskArg  whichField,
                             FieldT            &          )
{
#if 0
    if(_bvChanged == TypeTraits<BitVector>::BitsClear)
    {
        registerChangedContainer();
    }
    
    _bvChanged |= whichField;
#endif
}

inline
void FieldBundle::changed(ConstFieldMaskArg, 
                          UInt32           )
{
}

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

inline
FieldBundle::FieldBundle(void) :
    Inherited()
{
}

inline
FieldBundle::FieldBundle(const FieldBundle &source) :
    Inherited(source)
{
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

inline
FieldBundle::~FieldBundle(void)
{
}

inline
const Char8 *FieldBundle::getClassname(void)
{
    return "FieldBundle";
}

template <class ObjectT> inline
void FieldBundle::newPtr(      typename ObjectT::ObjPtr &result, 
                         const          ObjectT         *prototypeP)
{
    result = new ObjectT(*prototypeP);

    result->onCreate(prototypeP);
}

template <class ObjectT> inline
void FieldBundle::newPtr(typename ObjectT::ObjPtr &result)
{
    result = new ObjectT();

    result->onCreate();
}


template <class ObjectT> inline
typename ObjectT::ObjPtr FieldBundle::constructPtr(ObjectT *pObj)
{
    return pObj;
}

template <class ObjectT> inline
typename ObjectT::ObjConstPtr FieldBundle::constructPtr(const ObjectT *pObj)
{
    return pObj;
}


OSG_END_NAMESPACE

#define OSGFIELDBUNDLE_INLINE_CVSID "@(#)$Id$"


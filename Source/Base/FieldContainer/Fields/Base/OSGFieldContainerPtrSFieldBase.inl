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
FieldContainerPtrSFieldBase::FieldContainerPtrSFieldBase(void) :
     Inherited (      ),
    _fieldValue(NullFC)
{
}

inline
FieldContainerPtrSFieldBase::~FieldContainerPtrSFieldBase(void)
{
}

inline
FieldContainerPtrSFieldBase::const_value 
    FieldContainerPtrSFieldBase::getValue(void) const
{
    return _fieldValue;
}

inline
UInt32 FieldContainerPtrSFieldBase::getBinSize(void) const
{
    return SFieldTraits::getBinSize(_fieldValue);
}


inline
void FieldContainerPtrSFieldBase::copyToBin(BinaryDataHandler &pMem) const
{
    SFieldTraits::copyToBin( pMem, 
                            _fieldValue);
}

inline
bool FieldContainerPtrSFieldBase::operator ==(const Self &source) const
{
    return _fieldValue == source._fieldValue;
}

OSG_END_NAMESPACE

/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     * 
 *                                                                           * 
 *                                                                           * 
 *           Copyright (C) 2000,2001,2002 by the OpenSG Forum                * 
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

#include "OSGConfig.h"
#include "OSGNFIOName.h"
#include "OSGNFIOFactory.h"
#include "OSGNFIOGeneric.h"

#include <vector>

#include "OSGLog.h"
#include "OSGImageFileHandler.h"
#include "OSGNameAttachment.h"
#include "OSGNFIOGeneric.h"


OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::NFIOName
           reads and writes a name attachment.
 */

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

NFIOName NFIOName::_the;

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*----------------------------- constructors  -----------------------------*/

NFIOName::NFIOName(void) :
    NFIOBase("Name")
{
    _version = 200;
}

/*------------------------------ destructor -------------------------------*/

NFIOName::~NFIOName(void)
{
}

/*-------------------------------------------------------------------------*\
 -  protected                                                              -
\*-------------------------------------------------------------------------*/

FieldContainerPtr NFIOName::readFC(const std::string &/*typeName*/)
{
    FDEBUG(("NFIOName::readFC\n"));

    NamePtr name = Name::create();

    UInt8 fcPtrType;
    _in->getValue(fcPtrType);

    UInt16 version;
    _in->getValue(version);

    if(version == 100)
    {
        std::string fieldName;
        std::string fieldType;
        UInt32 size = 0;
        
        // skip internal bool field
        _in->getValue(fieldName);
        _in->getValue(fieldType);
        _in->getValue(size);
        _in->skip(size);
        
        // read name field
        _in->getValue(fieldName);
        _in->getValue(fieldType);
        _in->getValue(size);

        SField<std::string> str;
        str.copyFromBin(*_in);
        
        name->editFieldPtr()->getValue().assign(str.getValue().c_str());
          
        readEndMarker();             
    }
    else
    {
        readFCFields(name);
    }

    return name;
}

void NFIOName::writeFC(const FieldContainerPtr &fc)
{
    if(fc == NullFC)
    {
        FWARNING(("NFIOName::writeFCPtr: fc == NullFC\n"));
        return;
    }

    FDEBUG(("NFIOName::witeFC\n"));

    // write field container header.
    _out->putValue(NFIOGeneric::getFCPtrType(fc));
    _out->putValue(_version);
    
    writeFCFields(fc);
}

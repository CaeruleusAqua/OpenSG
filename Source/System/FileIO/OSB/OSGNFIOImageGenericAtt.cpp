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

#include <OSGConfig.h>
#include <OSGNFIOImageGenericAtt.h>
#include <OSGNFIOFactory.h>
#include <OSGNFIOGeneric.h>

#include <OSGLog.h>
#include <OSGImageFileHandler.h>
#include <OSGNameAttachment.h>

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::NFIOImageGenericAtt
           reads and writes a image.
 */

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

NFIOImageGenericAtt NFIOImageGenericAtt::_the;

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*----------------------------- constructors  -----------------------------*/

NFIOImageGenericAtt::NFIOImageGenericAtt(void) :
    NFIOBase("ImageGenericAtt")
{
    _version = 200;
}

/*------------------------------ destructor -------------------------------*/

NFIOImageGenericAtt::~NFIOImageGenericAtt(void)
{
}

/*-------------------------------------------------------------------------*\
 -  protected                                                              -
\*-------------------------------------------------------------------------*/

FieldContainerPtr NFIOImageGenericAtt::readFC(const std::string &/*typeName*/)
{
    FDEBUG(("NFIOImageGenericAtt::readFC\n"));

    UInt8 fcPtrType;
    _in->getValue(fcPtrType);

    UInt16 version = 0;
    _in->getValue(version);
      
    skipFCFields();

    return NullFC;
}

void NFIOImageGenericAtt::writeFC(const FieldContainerPtr &/*fc*/)
{
    FDEBUG(("NFIOImageGenericAtt::witeFC\n"));

    // GenericAtt is not yet supported so just write a empty dummy out.
    _out->putValue(_version);

    writeEndMarker();
}

/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning(disable : 177)
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id$";
    static Char8 cvsid_hpp       [] = OSGNFIOIMAGEGENERICATT_HEADER_CVSID;
}

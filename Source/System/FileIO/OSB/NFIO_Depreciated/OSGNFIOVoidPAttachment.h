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

#ifndef _OSGNFIOVOIDPATTACHMENT_H_
#define _OSGNFIOVOIDPATTACHMENT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGNFIOBase.h"

OSG_BEGIN_NAMESPACE

/* \brief NFIOVoidPAttachment class.
          reads and writes a image.
*/

class NFIOVoidPAttachment : public NFIOBase
{
    /*==========================  PUBLIC  =================================*/
  public:

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructor                                 */
    /*! \{                                                                 */

    NFIOVoidPAttachment                     (void);
  
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Destructor                                */
    /*! \{                                                                 */

    virtual ~NFIOVoidPAttachment            (void);
  
    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
protected:

    /*---------------------------------------------------------------------*/
    /*! \name                    Read/Write                                */
    /*! \{                                                                 */

    virtual FieldContainerPtr   readFC  (const std::string &typeName);
    virtual void                writeFC (const FieldContainerPtr &fc);

    /*! \}                                                                 */ 
    /*==========================  PRIVATE  ================================*/
private:

    static NFIOVoidPAttachment _the;
};

OSG_END_NAMESPACE

#endif /* _OSGNFIOVOIDPATTACHMENT_H_ */

/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
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

#ifndef _OSGGEOMULTIPROPERTYDATA_H_
#define _OSGGEOMULTIPROPERTYDATA_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGGeoMultiPropertyDataBase.h"

OSG_BEGIN_NAMESPACE

class Window;

/*! \brief GeoMultiPropertyData class. See \ref 
           PageWindowGLUTGeoMultiPropertyData for a description.
*/

class OSG_DRAWABLE_DLLMAPPING GeoMultiPropertyData : public GeoMultiPropertyDataBase
{
  private:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef GeoMultiPropertyDataBase                             Inherited;

    /*---------------------------------------------------------------------*/
    /*! \name                      Access                                  */
    /*! \{                                                                 */

    inline const UInt8 *getData (void);
    inline       UInt8 *editData(void);

    inline UInt32 getSize(void);
    inline void setSize(UInt32 size);

    /*! \}                                                                 */

    /*---------------------------------------------------------------------*/
    /*! \name                 Chunk Class Access                           */
    /*! \{                                                                 */

    virtual const StateChunkClass * getClass         (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name              Static Chunk Class Access                       */
    /*! \{                                                                 */

    inline static        UInt32            getStaticClassId (void);
    inline static  const StateChunkClass * getStaticClass   (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    State Commands                            */
    /*! \{                                                                 */

    virtual void activate      (DrawEnv    *pEnv, 
                                UInt32      index = 0);

    virtual void changeFrom    (DrawEnv    *pEnv, 
                                StateChunk *old,
                                UInt32      index = 0);

    virtual void deactivate    (DrawEnv    *pEnv, 
                                UInt32      index = 0);

    virtual bool isTransparent (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Comparison                                 */
    /*! \{                                                                 */

    virtual Real32 switchCost  ( StateChunk * chunk );

    virtual bool   operator <  (const StateChunk &other) const;

    virtual bool   operator == (const StateChunk &other) const;
    virtual bool   operator != (const StateChunk &other) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField, 
                         UInt32            origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0, 
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in GeoMultiPropertyDataBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    GeoMultiPropertyData(void);
    GeoMultiPropertyData(const GeoMultiPropertyData &source);

    void onCreate(const GeoMultiPropertyData *p = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GeoMultiPropertyData(void); 

    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class GeoMultiPropertyDataBase;

    template<class ContainerFactoryT>
    friend struct CPtrConstructionFunctions;

    template<class ContainerFactoryT>
    friend struct PtrConstructionFunctions;

    static void initMethod(InitPhase ePhase);
    
    static StateChunkClass _class;

    /*---------------------------------------------------------------------*/
    /*! \name                         GL                                   */
    /*! \{                                                                 */

    void handleGL(DrawEnv *pEnv, UInt32 id);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name               OpenGL Extensions Used                         */
    /*! \{                                                                 */

    static UInt32 _extVertexBufferObject;
    static UInt32 _funcBindBuffer;
    static UInt32 _funcBufferData;
    static UInt32 _funcDeleteBuffers;
    /*! \}                                                                 */
  
    // prohibit default functions (move to 'public' if you need one)

    void operator =(const GeoMultiPropertyData &source);
};

typedef GeoMultiPropertyData *GeoMultiPropertyDataP;

OSG_END_NAMESPACE

#include "OSGGeoMultiPropertyDataBase.inl"
#include "OSGGeoMultiPropertyData.inl"

#define OSGGEOMULTIPROPERTYDATA_HEADER_CVSID "@(#)$Id: OSGGeoMultiPropertyData.h,v 1.1.2.3 2006/07/28 06:21:57 vossg Exp $"

#endif /* _OSGGEOMULTIPROPERTYDATA_H_ */

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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#include "OSGConfig.h"

#include "OSGGLEXT.h"
#include "OSGWindow.h"
#include "OSGGeoMultiProperty.h"
#include "OSGDrawEnv.h"

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::GeoMultiProperty
Class referencing data from a GeoMultiPropertyData. 
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void GeoMultiProperty::initMethod(InitPhase ePhase)
{
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

GeoMultiProperty::GeoMultiProperty(void) :
    Inherited()
{
}

GeoMultiProperty::GeoMultiProperty(const GeoMultiProperty &source) :
    Inherited(source)
{
}

GeoMultiProperty::~GeoMultiProperty(void)
{
}


/*----------------------------- Access ----------------------------*/

UInt32 GeoMultiProperty::getFormat    (void) const
{
    return getIFormat();
}

UInt32 GeoMultiProperty::getFormatSize(void) const
{
    return MapFormatToSize(getIFormat());
}

UInt32 GeoMultiProperty::getStride    (void) const
{
    return getIStride();
}

UInt32 GeoMultiProperty::getDimension (void) const
{
    return getIDimension();
}

UInt32 GeoMultiProperty::getSize      (void) const
{
    return size();
}

UInt32 GeoMultiProperty::size         (void) const
{
    return getISize();
}

bool GeoMultiProperty::getNormalize (void) const
{
    return getINormalize();
}

const UInt8 *GeoMultiProperty::getData(void) const
{
    return getContainer()->getData() + getOffset();
}

UInt8 *GeoMultiProperty::editData(void)
{
    return getContainer()->editData() + getOffset();
}


void GeoMultiProperty::getValue(MaxTypeT &eval, const UInt32 index ) const
{
    UInt16 dim = getDimension();
    bool norm = getNormalize();
    UInt32 stride = getStride() ? getStride() : getFormatSize() * dim;    
    const UInt8 *data = getData() + stride * index;

#define getValNormCase(vectype)                                 \
{                                                               \
vectype ival(vectype::Null);                                    \
for (UInt16 i = 0; i < dim; ++i)                                \
    ival[i] =                                                   \
        reinterpret_cast<const vectype::ValueType*>(data)[i];   \
                                                                \
if(norm)                                                        \
{                                                               \
    GeoConvertNormalize::convertOut(eval, ival,              \
        TypeTraits<vectype::ValueType>::getMax(), 0);           \
}                                                               \
else                                                            \
{                                                               \
    GeoConvert::convertOut(eval, ival);                      \
}                                                               \
}

#define getValCase(vectype)                                     \
{                                                               \
vectype ival(vectype::Null);                                    \
for (UInt16 i = 0; i < dim; ++i)                                \
    ival[i] =                                                   \
        reinterpret_cast<const vectype::ValueType*>(data)[i];   \
                                                                \
GeoConvert::convertOut(eval, ival);                          \
}
    switch(getFormat())
    {
    case GL_BYTE:                   getValNormCase(Vec4b );
                                    break;
    case GL_UNSIGNED_BYTE:          getValNormCase(Vec4ub);
                                    break;
    case GL_SHORT:                  getValNormCase(Vec4s );
                                    break;
    case GL_UNSIGNED_SHORT:         getValNormCase(Vec4us);
                                    break;
/*    case GL_INT:                    getValNormCase(Vec4i );
                                    break;
    case GL_UNSIGNED_INT:           getValNormCase(Vec4ui);
                                    break;
*/    case GL_FLOAT:                  getValCase    (Vec4f );
                                    break;
    case GL_DOUBLE:                 getValCase    (Vec4d );
                                    break;
    }
}



void GeoMultiProperty::clear(void)
{
    resize(0);
}

void GeoMultiProperty::resize(size_t newsize)
{
    UInt16 dim = getDimension();
    UInt32 stride = getStride() ? getStride() : getFormatSize() * dim;    
    
    if(stride * newsize + getOffset() >= getContainer()->getSize())
    {
        getContainer()->setSize(stride * newsize +  getFormatSize() * dim + 
                          getOffset());
    }

    setISize(newsize);
}

void GeoMultiProperty::setFormat(UInt32 val)
{
    setIFormat(val);
}
void GeoMultiProperty::setStride(UInt32 val)
{
    setIStride(val);
}

void GeoMultiProperty::setDimension(UInt32 val)
{
    setIDimension(val);
}

void GeoMultiProperty::setSize(UInt32 val)
{
    setISize(val);
}

void GeoMultiProperty::setNormalize(bool val)
{
    setINormalize(val);
}


void GeoMultiProperty::setValue(const MaxTypeT &eval, const UInt32 index )
{
    UInt16 dim = getDimension();
    bool norm = getNormalize();
    UInt32 stride = getStride() ? getStride() : getFormatSize() * dim;    
    UInt8 *data = editData() + stride * index;

#define setValNormCase(vectype)                                 \
{                                                               \
vectype ival;                                                   \
if(norm)                                                        \
{                                                               \
    GeoConvertNormalize::convertIn(ival, eval,               \
        TypeTraits<vectype::ValueType>::getMax(), 0);           \
}                                                               \
else                                                            \
{                                                               \
    GeoConvert::convertIn(ival, eval);                       \
}                                                               \
for (UInt16 i = 0; i < dim; ++i)                                \
    reinterpret_cast<vectype::ValueType*>(data)[i] =            \
        ival[i];                                                \
}

#define setValCase(vectype)                                     \
{                                                               \
vectype ival;                                                   \
GeoConvert::convertIn(ival, eval);                           \
for (UInt16 i = 0; i < dim; ++i)                                \
    reinterpret_cast<vectype::ValueType*>(data)[i] =            \
        ival[i];                                                \
}
    
    switch(getFormat())
    {
    case GL_BYTE:                   setValNormCase(Vec4b );
                                    break;
    case GL_UNSIGNED_BYTE:          setValNormCase(Vec4ub);
                                    break;
    case GL_SHORT:                  setValNormCase(Vec4s );
                                    break;
    case GL_UNSIGNED_SHORT:         setValNormCase(Vec4us);
                                    break;
/*    case GL_INT:                    setValNormCase(Vec4i );
                                    break;
    case GL_UNSIGNED_INT:           setValNormCase(Vec4ui);
                                    break;
*/    case GL_FLOAT:                  setValCase    (Vec4f );
                                    break;
    case GL_DOUBLE:                 setValCase    (Vec4d );
                                    break;
    }
}

/*! \}                                                                 */

/*---------------------------------------------------------------------*/
/*! \name                 Chunk Class Access                           */
/*! \{                                                                 */

const StateChunkClass *GeoMultiProperty::getClass(void) const
{
    return &GeoProperty::_class;
}

/*! \}                                                                 */
/*---------------------------------------------------------------------*/
/*! \name                    State Commands                            */
/*! \{                                                                 */

void GeoMultiProperty::activate(DrawEnv *pEnv, 
                                UInt32   slot )
{
    Window *win = pEnv->getWindow();
    bool isGeneric = (slot >= 16);  // !!!HACK. needs to be replaced for 2.0
    slot &= 15;
    
    if(!win->hasExtension(_extVertexBufferObject))
    {
        FWARNING(("GeoMultiProperty::activate: Window %d doesn't "
                  "support VBOs!\n", win));
                  return;
    }
    
    win->validateGLObject(getContainer()->getGLId(), pEnv);

     // get "glBindBufferARB" function pointer
    void (OSG_APIENTRY*_glBindBufferARB)
        (GLenum target, GLuint buffer) =
        (void (OSG_APIENTRY*)(GLenum target, GLuint buffer))
        pEnv->getWindow()->getFunction(_funcBindBuffer);
    
    _glBindBufferARB(GL_ARRAY_BUFFER_ARB, 
                     win->getGLObjectId(getContainer()->getGLId()));

#define BUFFER_OFFSET(i)     ((char *)NULL + (i))

    if(isGeneric)
    {
        void (OSG_APIENTRY*_glVertexAttribPointerARB) 
            (GLuint index, GLint size, GLenum type, GLboolean normalized,
             GLsizei stride, const GLvoid *pointer)=
        (void (OSG_APIENTRY*) (GLuint index, GLint size, GLenum type, 
             GLboolean normalized, GLsizei stride, const GLvoid *pointer))
            win->getFunction(_funcglVertexAttribPointerARB);

        _glVertexAttribPointerARB(slot, getDimension(), 
            getFormat(), 
            getNormalize(),
            getStride(), BUFFER_OFFSET(getOffset()));

        void (OSG_APIENTRY*_glEnableVertexAttribArrayARB) 
            (GLuint index)=
        (void (OSG_APIENTRY*) (GLuint index))
            win->getFunction(_funcglEnableVertexAttribArrayARB);

        _glEnableVertexAttribArrayARB(slot);
    }
    else
    {
        switch(slot)
        {
        case 0:     glVertexPointer(getDimension(), getFormat(),
                        getStride(), BUFFER_OFFSET(getOffset()));
                    glEnableClientState(GL_VERTEX_ARRAY);
                    break;
        case 2:     glNormalPointer(getFormat(),
                        getStride(), BUFFER_OFFSET(getOffset()));
                    glEnableClientState(GL_NORMAL_ARRAY);
                    break;
        case 3:     glColorPointer(getDimension(), getFormat(),
                        getStride(), BUFFER_OFFSET(getOffset()));
                    glEnableClientState(GL_COLOR_ARRAY);
                    break;
        case 4:     if (win->hasExtension(_extSecondaryColor))
                    {
                         void (OSG_APIENTRY*_glSecondaryColorPointerEXT)
                              (GLint size,GLenum type,GLsizei stride,
                               const GLvoid *pointer)=
                        (void (OSG_APIENTRY*)(GLint size,GLenum type,GLsizei stride,
                               const GLvoid *pointer))
                         win->getFunction(_funcglSecondaryColorPointer);

                        _glSecondaryColorPointerEXT(getDimension(),
                                                    getFormat(),
                                                    getStride(), BUFFER_OFFSET(getOffset()));
                        glEnableClientState(GL_SECONDARY_COLOR_ARRAY_EXT);
                    }
                    else
                    {
                        FWARNING(("GeoVectorProperty::activate: Window "
                                    "has no Secondary Color extension\n"));
                    }
                    break;
        case 8:  case 9: 
        case 10: case 11: 
        case 12: case 13: 
        case 14: case 15: 
                    {
                    void (OSG_APIENTRY*_glClientActiveTextureARB) 
                        (GLenum type)= (void (OSG_APIENTRY*) (GLenum type))
                        win->getFunction(_funcglClientActiveTextureARB);
                        
                    _glClientActiveTextureARB(GL_TEXTURE0_ARB + slot - 8);
                    glTexCoordPointer(getDimension(), getFormat(),
                                      getStride(), BUFFER_OFFSET(getOffset()));
                    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                    }
                    break;
        default:    FWARNING(("GeoVectorProperty::activate: Non-Generic"
                        " attribute nr. %d unknown!\n", slot));
                    break;
        }     
    } // isGeneric

    _glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
}

void GeoMultiProperty::changeFrom(DrawEnv    *pEnv, 
                                  StateChunk *old,
                                  UInt32      index)
{
    activate(pEnv, index);
}

void GeoMultiProperty::deactivate(DrawEnv *pEnv, 
                                  UInt32   index)
{
// Nothing to do here
}

bool GeoMultiProperty::isTransparent (void) const
{
    return false;
}

/*! \}                                                                 */
/*---------------------------------------------------------------------*/
/*! \name                   Comparison                                 */
/*! \{                                                                 */

Real32 GeoMultiProperty::switchCost(StateChunk *)
{
    return 0;
}

bool GeoMultiProperty::operator < (const StateChunk &other) const
{
    return this < &other;
}

bool GeoMultiProperty::operator == (const StateChunk &other) const
{
    GeoMultiProperty const *tother = dynamic_cast<GeoMultiProperty const*>(&other);

    if(!tother)
        return false;

    if(tother == this)
        return true;

    return false;
}

bool GeoMultiProperty::operator != (const StateChunk &other) const
{
    return ! (*this == other);
}

/*----------------------------- class specific ----------------------------*/

void GeoMultiProperty::changed(ConstFieldMaskArg whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

void GeoMultiProperty::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump GeoMultiProperty NI" << std::endl;
}


/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id$";
    static Char8 cvsid_hpp       [] = OSGGEOMULTIPROPERTY_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGGEOMULTIPROPERTY_INLINE_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif


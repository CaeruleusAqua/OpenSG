/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                     Copyright 2000-2002 by OpenSG Forum                   *
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

/*------------------------------- size ----------------------------------*/

/*! Set the width and height of the Window. Only use if you really know what
    you're doing. In most cases resize() is a better choice.
 */

inline 
void Window::setSize(UInt16 width, UInt16 height)
{
    setHeight(height);
    setWidth(width);
}

inline 
bool Window::isResizePending(void)
{
    return _sfResizePending.getValue();
}

/*! Check if the window has the indicated extension.
    \warning No error checks are done on the passed index!
 */

inline 
bool Window::hasExtension(UInt32 extId)
{
    return _availExtensions[extId];
}

/*! Check if the window has the indicated extension.
    \warning No error checks are done on the passed index!
 */
inline 
bool Window::hasCommonExtension(UInt32 extId)
{
    if(extId >= _commonExtensions.size())
        return false;

    return _commonExtensions[extId];
}

/*! Get the indicated extension function.
    The id and the returned functions are checked for sanity and a warning is
    issued if there are problems. Use getFunctionNoCheck if you're sure you
    don't need them.
 */

inline 
void *Window::getFunction(UInt32 funcId)
{
    if(funcId >= _extFunctions.size())
    {
        FINFO(("Window::getFunction: illegal id %d!\n", funcId));
        return NULL;
    }

    if(_extFunctions[funcId] == NULL)
    {
        FINFO(("Window::getFunction: function \"%s\" is NULL!\n",
                    _registeredFunctions[funcId].c_str()));
        return NULL;
    }

    return _extFunctions[funcId];
}

/*! Get the indicated extension function.
    \warning No error checks are done on the passed index nor on the returned
    function!
 */

inline 
void *Window::getFunctionNoCheck(UInt32 funcId)
{
    return _extFunctions[ funcId ];
}

/*! Return the value of the registered constant, Inf if not registered 
    or no value received yet.
*/

inline 
Real32 Window::getConstantValue(GLenum val)
{
    return getConstantValuev(val)[0];
}

/*! Set the library name where to find OpenGL extension functions. This has
    to be called before the first extension function is accessed, and it's
    safe to call it before osgInit().
 */

inline 
void Window::setGLLibraryName(const Char8 *s)
{
    _glLibraryName = s;
}

/*! Return the version of OpenGL running in the Window in the form
    0x<major><major><minor><minor>, e.g. 0x0201 for version 2.1.
 */

inline 
UInt32 Window::getGLVersion(void)
{
    return _glVersion;
}

/*! Find the id of a registered extension. Return -1 if extension not
    registered.
 */

inline 
Int32 Window::getExtensionId(const Char8  *s)
{
    std::vector<std::string>::iterator it;

    it = std::find(_registeredExtensions.begin(),
              _registeredExtensions.end(),
              s);

    if(it == _registeredExtensions.end())
        return -1;

    return Int32(it -_registeredExtensions.begin());
}

/*! Access the available extensions.
 */

inline 
const std::vector<std::string> &Window::getExtensions(void)
{
    return _extensions;
}

/*! Access the registered extensions.
 */

inline 
const std::vector<std::string> &Window::getRegisteredExtensions(void)
{
    return _registeredExtensions;
}

/*! Access the registered functions.
 */
inline 
const std::vector<std::string> &Window::getRegisteredFunctions(void)
{
    return _registeredFunctions;
}

/*! Access the ignored extensions.
*/
inline
const std::vector<std::string> &Window::getIgnoredExtensions(void)
{
    return _ignoredExtensions;
}

inline 
void Window::setGLObjectId(UInt32 osgId, UInt32 id2)
{
    if(osgId < _ids.size())
    {
        _ids[osgId] = id2;
    }
    else
    {
        _ids.resize(_glObjects.size());

        if(osgId < _ids.size())
        {
            _ids[osgId] = id2;
        }
        else
        {
            SWARNING << "Window::setGLObjectId: id (" 
                     << osgId 
                     << ") is not valid!" 
                     << std::endl;
        }
    }
}

inline
UInt32 Window::getGLObjectId(UInt32 osgId)
{
    if(osgId < _ids.size())
        return _ids[osgId];

    return 0;
}

inline 
UInt32 Window::getGLObjectsSize(void)
{
    return _glObjects.size();
}

/* GLObject helper class */

inline 
Window::GLObject::GLObject(GLObjectFunctor funct, GLObjectFunctor destroy) :
    _functor     (funct),
    _destroy     (destroy),
    _refCounter  (    0),
    _lastValidate(    0)
{
}

inline 
Window::GLObjectFunctor &Window::GLObject::getFunctor(void)
{
    return _functor;
}

inline 
void Window::GLObject::setFunctor(GLObjectFunctor funct)
{
    _functor = funct;
}

inline 
Window::GLObjectFunctor &Window::GLObject::getDestroyFunctor(void)
{
    return _destroy;
}

inline 
void Window::GLObject::setDestroyFunctor(GLObjectFunctor funct)
{
    _destroy = funct;
}

inline 
UInt32 Window::GLObject::getLastValidate(void)
{
    return _lastValidate;
}

inline 
void Window::GLObject::setLastValidate(UInt32 val)
{
    _lastValidate = val;
}

inline 
UInt32 Window::GLObject::getRefCounter(void)
{
    return _refCounter;
}

inline 
UInt32 Window::GLObject::incRefCounter(void)
{
    UInt32 val;

#ifndef OSG_WINCE
    if(! _GLObjectLock)
    {
        _GLObjectLock = ThreadManager::the()->getLock(NULL);
    }

    _GLObjectLock->acquire();
#endif

    val = _refCounter = _refCounter + 1;

#ifndef OSG_WINCE
    _GLObjectLock->release();
#endif

    return val;
}

inline 
UInt32 Window::GLObject::decRefCounter(void)
{
    UInt32 val;

#ifndef OSG_WINCE
    if(! _GLObjectLock)
    {
        _GLObjectLock = ThreadManager::the()->getLock(NULL);
    }

    _GLObjectLock->acquire();

#endif

    if(_refCounter)
    {
        val = _refCounter = _refCounter - 1;
    }
    else
    {
        val = 0;
    }

#ifndef OSG_WINCE
    _GLObjectLock->release();
#endif

    return val;
}    

inline
StageValidator *Window::getStageValidator(void)
{
    return _pStageValidator;
}


OSG_END_NAMESPACE

#define OSGWINDOW_INLINE_CVSID "@(#)$Id$"

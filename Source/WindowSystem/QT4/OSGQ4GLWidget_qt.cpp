/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

#include "OSGQ4GLWidget_qt.h"

#ifdef OSG_WITH_QT

#include <QtGui/qevent.h>

OSG_BEGIN_NAMESPACE

OSGQGLWidget::GLContext::GLContext(const QGLFormat & format) :
    QGLContext(format)
{
}
 
 // on makeCurrent() just do pretty nothing
void OSGQGLWidget::GLContext::makeCurrent(void)
{
    OSG_ASSERT(false);
}

/*! \class OSG::QTWindow

The class for QT-based windows. See \ref PageWindowQT for a description.

*/

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/

/*------------- constructors & destructors --------------------------------*/

/*! Constructor
*/


OSGQGLWidget::OSGQGLWidget(      QWidget    *parent,
                           const char       *name,
                           const QGLWidget  *shareWidget,
                                 Qt::WFlags  f           ) :
    QGLWidget(new GLContext(QGLFormat::defaultFormat()),
              parent, 
              shareWidget, 
              f                                        ) 
{
}

OSGQGLWidget::OSGQGLWidget(      GLContext       *context,
                                 QWidget         *parent ,
                           const QGLWidget       *shareWidget,
                                 Qt::WindowFlags  f           ) :
    QGLWidget(context, parent, shareWidget, f)
{
}

OSGQGLWidget::OSGQGLWidget(const QGLFormat  &format,
                                 QWidget    *parent,
                           const char       *name,
                           const QGLWidget  *shareWidget,
                                 Qt::WFlags  f           ) :
    QGLWidget(new GLContext(format), parent, shareWidget, f)
{
}


/*! Destructor
*/

OSGQGLWidget::~OSGQGLWidget( void )
{
}


/*------------------------------ access -----------------------------------*/

void OSGQGLWidget::initializeGL(void) 
{
}

void OSGQGLWidget::paintGL(void) 
{
}

void OSGQGLWidget::resizeGL(int, int) 
{
}

void OSGQGLWidget::makeCurrent(void)
{
}

void OSGQGLWidget::swapBuffers(void)
{
}

bool OSGQGLWidget::event(QEvent *pEvent)
{
#if defined(Q_WS_X11)
    if(pEvent->type() != QEvent::Hide &&
       pEvent->type() != QEvent::ParentChange) 
    {
        return Inherited::event(pEvent);
    }

    return true;
#else
    return Inherited::event(pEvent);
#endif
}

void OSGQGLWidget::resizeEvent(QResizeEvent *) 
{
    resizeGL(width(), height()); 
}

void OSGQGLWidget::paintEvent(QPaintEvent *) 
{ 
    paintGL(); 
};

OSG_END_NAMESPACE

#endif /* OSG_WITH_QT */

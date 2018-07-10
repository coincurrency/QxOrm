/****************************************************************************
**
** http://www.qxorm.com/
** http://sourceforge.net/projects/qxorm/
** Original file by Lionel Marty
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software.
**
** GNU Lesser General Public License Usage
** This file must be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file 'license.lgpl.txt' included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#if (QT_VERSION >= 0x040600)
#ifndef _QX_IS_QT_SCOPED_PTR_H_
#define _QX_IS_QT_SCOPED_PTR_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <QtCore/qscopedpointer.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>

namespace qx {
namespace trait {

template <typename T>
class is_qt_scoped_ptr
{

private:

   template <typename V> static char isSmartPtr(QScopedPointer<V>);
   static int isSmartPtr(...);
   static T t;

public:

   enum { value = (sizeof(qx::trait::is_qt_scoped_ptr<T>::isSmartPtr(t)) == sizeof(char)) };

   typedef typename boost::mpl::if_c<qx::trait::is_qt_scoped_ptr<T>::value, 
                                     boost::mpl::true_, 
                                     boost::mpl::false_>::type type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_QT_SCOPED_PTR_H_
#endif // (QT_VERSION >= 0x040600)

#if (QT_VERSION < 0x040600)
#ifndef _QX_IS_QT_SCOPED_PTR_H_
#define _QX_IS_QT_SCOPED_PTR_H_
namespace qx { namespace trait {
template <typename T>
class is_qt_scoped_ptr
{ public: enum { value = false }; typedef boost::mpl::false_ type; };
} } // namespace qx::trait
#endif // _QX_IS_QT_SCOPED_PTR_H_
#endif // (QT_VERSION < 0x040600)

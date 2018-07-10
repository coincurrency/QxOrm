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

#ifndef _QX_SQL_QUERY_H_
#define _QX_SQL_QUERY_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <QtSql/qsqlquery.h>

#include "../../include/QxCollection/QxCollection.h"

namespace qx {

class QX_DLL_EXPORT QxSqlQuery
{

protected:

   QString m_sQuery;                               // Query sql with place-holder
   QxCollection<QString, QVariant> m_lstValue;     // Bind value in this array

public:

   QxSqlQuery() { ; }
   QxSqlQuery(const QString & sQuery) : m_sQuery(sQuery) { ; }
   QxSqlQuery(const char * sQuery) : m_sQuery(sQuery) { ; }
   virtual ~QxSqlQuery() { ; }

   QString query() const   { return m_sQuery; }
   bool isEmpty() const    { return m_sQuery.isEmpty(); }

   QxSqlQuery & query(const QString & sQuery);

   QxSqlQuery & bind(const QVariant & vValue);
   QxSqlQuery & bind(const QString & sKey, const QVariant & vValue);

   void resolve(QSqlQuery & query) const;

};

} // namespace qx

#endif // _QX_SQL_QUERY_H_

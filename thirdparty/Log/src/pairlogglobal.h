#ifndef PAIRLOGGLOBAL_H
#define PAIRLOGGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(PAIRLOG_LIBRARY)
#define PAIRLOG_EXPORT Q_DECL_EXPORT
#else
#define PAIRLOG_EXPORT /*Q_DECL_IMPORT*/
#endif

#endif // PAIRLOGGLOBAL_H

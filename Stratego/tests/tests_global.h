#ifndef TESTS_GLOBAL_H
#define TESTS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTS_LIBRARY)
#  define TESTS_EXPORT Q_DECL_EXPORT
#else
#  define TESTS_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTS_GLOBAL_H

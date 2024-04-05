#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(STATICLIB_LIB)
#  define STATICLIB_EXPORT Q_DECL_EXPORT
# else
#  define STATICLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define STATICLIB_EXPORT
#endif

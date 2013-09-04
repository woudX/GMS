/************************************************************************/
/*	glimit.h
/*	Limits, basic types
/************************************************************************/

#ifndef _H_GLIMITS
#define _H_GLIMITS

#include <limits>

#include "gms.h"

/* chars used as small naturals */
typedef unsigned char gm_byte;

template<typename T1, typename T2>
T1 cast(T2 exp) {
	return static_cast<T1>(exp);
}


#endif // !_H_GLIMITS

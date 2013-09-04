#ifndef _H_GOBJECT
#define _H_GOBJECT

#include <stdarg.h>

#include "glimit.h"
#include "gms.h"

class TString {
public:
	gm_byte extra; /* reserved for short strings; "has hash" for longs */
	unsigned int hash;
	string str;
};


#endif // !_H_GOBJECT

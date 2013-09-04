#ifndef _H_GZIO
#define _H_GZIO

#include "gms.h"

const int EOZ = -1;		/* end of stream */

class Zio {
public:
	char next();
	void read(string fileName);
private:
	vector<char> m_buf;
	int m_pos;		/* current pos in buf*/
};


#endif // !_H_GZIO

#ifndef _LIVE_OBJECT
#define _LIVE_OBJECT

#include "liveConnection.h"

class liveSet;

class liveObject {
	
public:
	void setPath();
	string getAttr(string _property);
	void setAttr(string _property, string _value);
	int getLiveId();
	
	liveSet * parent_set;
	liveConnection * connection;
	int live_id;
	
};

#endif	
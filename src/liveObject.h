#ifndef _LIVE_OBJECT
#define _LIVE_OBJECT

#include "liveConnection.h"

class liveSet;

class liveObject {
	
public:
	void setPath();
	string getAttr(string _property);
	void setAttr(string _property, string _value);
	void callFunction(string _function);
	int getLiveId();
	int msleep(unsigned long milisec);
	
	liveSet* parent_set;
	int live_id;
	
};

#endif	
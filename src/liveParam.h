#ifndef _LIVE_PARAM
#define _LIVE_PARAM

#include "liveObject.h"

class liveParam: public liveObject {
	
public:
	liveParam(liveSet* _parent_set, int _track_order, int _device_order, int _order, float _val, string _name);
	string getName();
	int getTrackOrder();
	int getOrder();
	void setVal(float _val);
	
	int track_order;
	int device_order;
	int order;
	float val;
	string name;
	
};

#endif
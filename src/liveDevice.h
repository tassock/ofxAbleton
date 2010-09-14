#ifndef _LIVE_DEVICE
#define _LIVE_DEVICE

#include "liveObject.h"

class liveDevice: public liveObject {
	
public:
	liveDevice(liveSet* _parent_set, int _track_order, int _order, string name);
	string getName();
	int getTrackOrder();
	int getOrder();
	
	int track_order;
	int order;
	string name;
	
};

#endif
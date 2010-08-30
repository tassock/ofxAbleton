#ifndef _LIVE_CLIP
#define _LIVE_CLIP

#include "liveObject.h"

class liveClip: public liveObject {
	
public:
	liveClip(liveSet* _parent_set, int _track_order, int _order, string name);
	string getName();
	int getTrackOrder();
	int getOrder();
	void fire();
	
	int track_order;
	int order;
	string name;
	
};

#endif
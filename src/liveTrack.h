#ifndef _LIVE_TRACK
#define _LIVE_TRACK

#include "liveObject.h"
#include "liveClipSlot.h"

class liveTrack: public liveObject {
	
public:
	liveTrack(liveSet* _parent_set, int _order, string _name);
	
	int order;
	string name;
	
};

#endif
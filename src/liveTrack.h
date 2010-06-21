#ifndef _LIVE_TRACK
#define _LIVE_TRACK

#include "liveObject.h"
#include "liveClipSlot.h"

#define NUM_CLIP_SLOTS 10

class liveTrack: public liveObject {
	
public:
	liveTrack(liveSet* _parent_set, int _live_id, int _order, bool _is_master);
	string path();
	void getClipSlots();
	
	int order;
	bool is_master;
	
	liveClipSlot * clip_slots[NUM_CLIP_SLOTS];
	
};

#endif
#ifndef _LIVE_CLIP
#define _LIVE_CLIP

#include "liveObject.h"

class liveClip: public liveObject {
	
public:
	liveClip(liveSet* _parent_set, int _live_id, int _clip_slot_id);
	string getName();
	
	int clip_slot_id;
	string name;
	
};

#endif
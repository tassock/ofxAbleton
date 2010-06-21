#ifndef _LIVE_CLIP_SLOT
#define _LIVE_CLIP_SLOT

#include "liveObject.h"
#include "liveClip.h"

class liveClipSlot: public liveObject {
	
public:
	liveClipSlot(liveSet* _parent_set, int _live_id, int _track_id, int _order, int _track_order);
	void getClip();
	
	int track_id;
	int order;
	int track_order;
	bool has_clip;
	
	liveClip* clip;
	
};

#endif
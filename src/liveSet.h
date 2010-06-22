#ifndef _LIVE_SET
#define _LIVE_SET

#include "ofMain.h"
#include "liveConnection.h"
#include "liveTrack.h"
#include "liveClip.h"
#include "liveClipSlot.h"

#define NUM_TRACKS 5
#define MAX_CLIPS 200

class liveClip;

class liveSet {
	
public:
	liveSet();
	liveConnection * getConnection();
	void update();
	void getMasterTrack();
	void getTracks();
	void addClip(liveClip* clip);
	int getClipCount();
	liveClip * getClipByName(string name);
	
	liveConnection * connection;
	liveTrack *master_track;
	liveTrack *tracks[NUM_TRACKS + 1]; // +1 for master track
	liveClip * clips[MAX_CLIPS];

};

#endif	
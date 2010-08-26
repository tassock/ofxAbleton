#ifndef _LIVE_SET
#define _LIVE_SET

#include "ofMain.h"
#include "liveConnection.h"
#include "liveTrack.h"
#include "liveClip.h"
#include "liveClipSlot.h"
#include "liveObject.h"

#define NUM_TRACKS 5
#define MAX_CLIPS 200

// Forward declarations
class liveClip;
class liveObject;

//class liveSet {
class liveSet: public liveObject {
	
public:
	liveSet();
	liveConnection * getConnection();
	void update();
	void play();
	void stop();
	void getMasterTrack();
	void getTracks();
	void addClip(liveClip* clip);
	int getClipCount();
	liveClip * getClipByName(string name);
	int getBeat();
	int getStep();
	
	int beat;
	int step;
//	liveConnection * connection;
	liveTrack *master_track;
	liveTrack *tracks[NUM_TRACKS + 1]; // +1 for master track
	liveClip * clips[MAX_CLIPS];

};

#endif	
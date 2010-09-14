#ifndef _LIVE_SET
#define _LIVE_SET

#include "ofMain.h"
#include "liveTrack.h"
#include "liveClip.h"
#include "liveDevice.h"
#include "liveClipSlot.h"
#include "liveObject.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SEND_PORT 9000
#define RECIEVE_PORT 9001
#define NUM_STEPS 32
#define FRAME_RATE 60

// Forward declarations
class liveClip;
class liveObject;
class liveDevice;

class liveSet {
//class liveSet: public liveObject {
	
public:
	liveSet();
	void update();
	void recieveData();
	void play();
	void stop();
	void getInfo();
	void getTracks();
	void getClips();
	void getDevices();
	liveClip * getClipByName(string name, int track_order);
	int getBeat();
	int getStep();
	void sendMessage(ofxOscMessage message);
	
	ofxOscSender sender;
	ofxOscReceiver receiver;
	bool playing;
	float tempo;
	int beat;
	int step;
	vector<liveTrack*> tracks;
	vector<liveClip*> clips;
	vector<liveDevice*> devices;

};

#endif	
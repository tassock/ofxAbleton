#ifndef _LIVE_CONNECTION
#define _LIVE_CONNECTION

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
//#define SEND_PORT 7402
//#define RECIEVE_PORT 7403
#define NUM_STEPS 32
#define NUM_BEATS 4

class liveConnection {
	
public:
	
	liveConnection();
	void recieveData();
	void update();
	void play();
	void stop();
	void setMode(string _mode);
	void handleTransport(int _beat);
	int live_path(string arg);
	void sendMessage(string address, string arg);
	string sendMessageWithCallback(string address, string arg);
	string recieveStringData();
	int getBeat();
	int getStep();
	
	ofxOscSender sender;
	ofxOscReceiver receiver;
	int int_buffer;
	vector<ofxOscMessage> message_que;
	bool playing;
	string mode;
	int beat;
	int step;
	
};

#endif	
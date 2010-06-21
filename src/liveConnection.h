#ifndef _LIVE_CONNECTION
#define _LIVE_CONNECTION

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SEND_PORT 7402
#define RECIEVE_PORT 7403

class liveConnection {
	
public:
	
	liveConnection();
	int live_path(string arg);
	void sendMessage(string address, string arg);
	string sendMessageWithCallback(string address, string arg);
	void recieveData();
	string recieveStringData();
	
	ofxOscSender sender;
	ofxOscReceiver receiver;
	int int_buffer;
	
};

#endif	
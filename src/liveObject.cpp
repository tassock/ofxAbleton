/*
 *  liveObject.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveObject.h"
#include "liveSet.h"

void liveObject::setPath(){
//	connection->sendMessage("/set_live_object", "id " + ofToString(live_id));
}

string liveObject::getAttr(string _property){
//	setPath();
//	msleep(50);
//	//cout << "get_attr: " << _property << endl;
//	return connection->sendMessageWithCallback("/live_object", "get " + _property);
}

void liveObject::setAttr(string _property, string _value){
	cout << "set_attr" << endl;
}

void liveObject::callFunction(string _function) {
//	setPath();
//	msleep(50);
//	connection->sendMessage("/live_object", "call " + _function);
}

int liveObject::getLiveId(){
	return live_id;
}


// http://cc.byexamples.com/2007/05/25/nanosleep-is-better-than-sleep-and-usleep/
int liveObject::msleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
		continue;
    return 1;
}

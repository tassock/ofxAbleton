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
	connection->sendMessage("/set_live_object", "id " + ofToString(live_id));
}

string liveObject::getAttr(string _property){
	setPath();
	//cout << "get_attr: " << _property << endl;
	return connection->sendMessageWithCallback("/live_object", "get " + _property);
}

void liveObject::setAttr(string _property, string _value){
	cout << "set_attr" << endl;
}

int liveObject::getLiveId(){
	return live_id;
}
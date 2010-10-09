/*
 *  liveDevice.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveParam.h"
#include "liveSet.h"

//--------------------------------------------------------------
liveParam::liveParam(liveSet* _parent_set, int _track_order, int _device_order, int _order, float _val, string _name){
	parent_set = _parent_set;
	track_order = _track_order;
	device_order = _device_order;
	order = _order;
	val = _val;
	name = _name;
	
	//setVal(0.5);
	
	cout << "liveParam( track_order: " << track_order << ", device_order: " << device_order << ", order: " << order << ", val: " << val << ", name: " << name << ")" << endl;
}


//--------------------------------------------------------------
string liveParam::getName(){
	return name;
}


//--------------------------------------------------------------
int liveParam::getTrackOrder(){
	return track_order;
}


//--------------------------------------------------------------
int liveParam::getOrder(){
	return order;
}

void liveParam::setVal(float _val) {
	if (name == "GainLo") {
		val = _val * 0.85;
	} else {
		val = _val;
	}

	ofxOscMessage m;
	m.setAddress( "/live/device" );
	m.addIntArg(track_order);
	m.addIntArg(device_order);
	m.addIntArg(order);
	m.addFloatArg(val);
	parent_set->sendMessage( m );
}
/*
 *  liveDevice.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveDevice.h"
#include "liveSet.h"

//--------------------------------------------------------------
liveDevice::liveDevice(liveSet* _parent_set, int _track_order, int _order, string _name){
	parent_set = _parent_set;
	track_order = _track_order;
	order = _order;
	name = _name;
	
	cout << "liveDevice( track_order: " << track_order << ", order: " << order << ", name: " << name << ")" << endl;
	
	// Get params
	ofxOscMessage m;
	m.setAddress( "/live/device" );
	m.addIntArg(track_order);
	m.addIntArg(order);
	parent_set->sendMessage( m );
}


//--------------------------------------------------------------
string liveDevice::getName(){
	return name;
}


//--------------------------------------------------------------
int liveDevice::getTrackOrder(){
	return track_order;
}


//--------------------------------------------------------------
int liveDevice::getOrder(){
	return order;
}
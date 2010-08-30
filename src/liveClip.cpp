/*
 *  liveClip.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveClip.h"
#include "liveSet.h"

//--------------------------------------------------------------
liveClip::liveClip(liveSet* _parent_set, int _track_order, int _order, string _name){
	parent_set = _parent_set;
	track_order = _track_order;
	order = _order;
	name = _name;
	
	cout << "liveClip( track_order: " << track_order << ", order: " << order << ", name: " << name << ")" << endl;
}


//--------------------------------------------------------------
string liveClip::getName(){
	return name;
}


//--------------------------------------------------------------
int liveClip::getTrackOrder(){
	return track_order;
}


//--------------------------------------------------------------
int liveClip::getOrder(){
	return order;
}


//--------------------------------------------------------------
void liveClip::fire() {
	// /live/play/clip         (int track, int clip)
	ofxOscMessage m;
	m.setAddress( "/live/play/clip" );
	m.addIntArg(track_order);
	m.addIntArg(order);
	parent_set->sendMessage( m );
}
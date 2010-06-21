/*
 *  liveSet.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveSet.h"

//--------------------------------------------------------
liveSet::liveSet(){
	
	// Clear object arrays
	for ( int i=0; i<MAX_CLIPS; i++ ) {
		clips[i] = NULL;
	}
	
	connection = new liveConnection();
	getMasterTrack();
	getTracks();
	
	cout << "!!!clip_count: " << getClipCount() << endl;
	
}

liveConnection * liveSet::getConnection() {
	return connection;
}
	

//--------------------------------------------------------
void liveSet::update(){
	connection->recieveData();
}


//--------------------------------------------------------
void liveSet::getMasterTrack(){
	int live_id = connection->live_path("goto live_set master_track");
	int order = 0;
	master_track = new liveTrack(this, live_id, order, true);
}


//--------------------------------------------------------
void liveSet::getTracks(){
	for ( int i=0; i<NUM_TRACKS; i++ ) {
		int live_id = connection->live_path("goto live_set tracks " + ofToString(i));
		tracks[i] = new liveTrack(this, live_id, i, false);
	}
}


//--------------------------------------------------------
void liveSet::addClip(liveClip* clip) {
	int clip_id = clip->getLiveId();
	clips[clip_id] = clip;
}


//--------------------------------------------------------
int liveSet::getClipCount() {
	int clip_count = 0;
	for ( int i=0; i<MAX_CLIPS; i++ ) {
		if (clips[i]) {
			clip_count += 1;
		}
	}
	return clip_count;
}
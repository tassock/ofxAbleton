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
	
	// Set live_id
	live_id = connection->live_path("goto live_set");
	
//	cout << "!!!clip_count: " << getClipCount() << endl;
//	cout << "!!!clip_name:  " << getClipByName("1_3")->getName() << endl;
//	getClipByName("1_3")->callFunction("fire");
	
}

liveConnection * liveSet::getConnection() {
	return connection;
}
	

//--------------------------------------------------------
void liveSet::update(){
	connection->update();
	beat = connection->getBeat();
	step = connection->getStep();
}


//--------------------------------------------------------
void liveSet::play(){
	callFunction("play_selection");
	connection->play();
}


//--------------------------------------------------------
void liveSet::stop(){
	cout << "STOP()" << endl;
	callFunction("stop_all_clips");
	connection->stop();
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
			cout << "CLIP: " << clips[i]->getName() << endl;
		}
	}
	return clip_count;
}


//--------------------------------------------------------
liveClip * liveSet::getClipByName(string name) {
	for ( int i=0; i<MAX_CLIPS; i++ ) {
		if (clips[i]) {
			if (clips[i]->getName() == name) {
				return clips[i];
			}
		}
	}
}

//--------------------------------------------------------------
int liveSet::getBeat() {
	return beat;
}


//--------------------------------------------------------------
int liveSet::getStep() {
	return step;
}
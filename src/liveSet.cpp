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
	
	cout << "@ " << endl;
	
	// open an outgoing connection to HOST:PORT
	sender.setup( HOST, SEND_PORT );
	
	// listen on the given port
	receiver.setup( RECIEVE_PORT );
	
	// Set defaults
	playing = false;
	beat = 0;
	step = 0;
	
	// Scan for tracks and clips
	getInfo();
	getTracks();
	getClips();
	getDevices();
	
	sleep(1);
	recieveData();
	
	cout << "!!initialized" << endl;
	
	//setCrossfader(0.8);
	
}
	

//--------------------------------------------------------
void liveSet::update(){
	
	// Increment step
	if (playing == true) {
		step ++; // Need to advance in proportion to tempo
		if (step == NUM_STEPS) {
			step = 0;
			beat ++;
		}
	}
	
	// get messages
	recieveData();
}


//--------------------------------------------------------
// Handle incoming OSC messages
void liveSet::recieveData() {
	while( receiver.hasWaitingMessages() ) {
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		
//		cout << "@: " << m.getAddress() << endl;
		
		// Create liveTrack
		if ( m.getAddress() == "/live/name/track" ) {
			int order = m.getArgAsInt32( 0 );
			string name = m.getArgAsString( 1 );
			tracks.push_back( new liveTrack(this, order, name) );
		}
		
		// Create liveClip
		if ( m.getAddress() == "/live/name/clip" ) {
			int track_order = m.getArgAsInt32( 0 );
			int order = m.getArgAsInt32( 1 );
			string name = m.getArgAsString( 2 );
			clips.push_back( new liveClip(this, track_order, order, name) );
		}
		
		// Create liveDevice
		if ( m.getAddress() == "/live/devicelist" ) {
			int track_order = m.getArgAsInt32( 0 );
			int order = m.getArgAsInt32( 1 );
			string name = m.getArgAsString( 2 );
			devices.push_back( new liveDevice(this, track_order, order, name) );
		}
		
		// Create liveParam
		if ( m.getAddress() == "/live/device/allparam" ) {
			int _track_o   = m.getArgAsInt32(  0 );
			int _device_o  = m.getArgAsInt32(  1 );
			for ( int i=0; i<10; i++ ) {
				int b = i * 3;
				int _parameter = m.getArgAsInt32(  b + 2 );
				float _val     = m.getArgAsFloat(  b + 3 );
				string _name   = m.getArgAsString( b + 4 );
				params.push_back( new liveParam(this, _track_o, _device_o, _parameter, _val, _name) );
			}
		}
		
		// Handle transport
		if ( m.getAddress() == "/bar_transport" ) {
			int _beat = m.getArgAsInt32( 0 );
			if ( _beat >= 0 and playing == true ) {
				beat = _beat;
				step = 0;
			}
		}
		
		// Recieve tempo
		if ( m.getAddress() == "/live/tempo" ) {
			float _tempo = m.getArgAsFloat( 0 );
			cout << "Tempo: " << _tempo << endl;
			tempo = tempo;
		}
		
	}
}


//--------------------------------------------------------
void liveSet::play(){
	// Set playing flag, reset beat
	playing = true;
	// Send message to live
	ofxOscMessage m;
	m.setAddress( "/live/play" );
	sender.sendMessage( m );
}


//--------------------------------------------------------
void liveSet::stop(){
	playing = false;
	beat = 0;
	step = 0;
	// Send message to live
//	ofxOscMessage m;
//	m.setAddress( "/live/stop" );
//	sender.sendMessage( m );
	// stop all tracks
	for ( int i=0; i<clips.size(); i++ ) {
		liveClip* s_clip = clips[i];
		ofxOscMessage m;
		m.setAddress( "/live/stop" );
		m.addIntArg( s_clip->getTrackOrder() );
		m.addIntArg( s_clip->getOrder() );
		sender.sendMessage( m );
	}
}


//--------------------------------------------------------
void liveSet::getInfo(){
	
	// Get tempo
	ofxOscMessage m;
	m.setAddress( "/live/tempo" );
	sender.sendMessage( m );
	
}


//--------------------------------------------------------
void liveSet::getTracks(){
	ofxOscMessage m;
	m.setAddress( "/live/name/track" );
	sender.sendMessage( m );
}


//--------------------------------------------------------
void liveSet::getClips(){
	ofxOscMessage m;
	m.setAddress( "/live/name/clip" );
	sender.sendMessage( m );
}


//--------------------------------------------------------
// Get devices for each track
void liveSet::getDevices(){
	
	for ( int i=0; i<2; i++ ) {
		
		cout << "PIONG" << endl;
	
		ofxOscMessage m;
		m.setAddress( "/live/devicelist" );
		m.addIntArg( i );
		sender.sendMessage( m );
	
	}
}


//--------------------------------------------------------
liveClip * liveSet::getClipByName(string name, int track_order) {
	for ( int i=0; i<clips.size(); i++ ) {
		
		if (clips[i]->getName() == name and clips[i]->getTrackOrder() == track_order) {
			return clips[i];
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


//--------------------------------------------------------------
void liveSet::sendMessage(ofxOscMessage message) {
	sender.sendMessage( message );
}


//--------------------------------------------------------------
void liveSet::setCrossfader(float val) {
	ofxOscMessage m;
	m.setAddress( "/live/master/crossfader" );
	m.addFloatArg( (val * 2) - 1 );
	sender.sendMessage( m );
}
/*
 *  liveConnection.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveConnection.h"

liveConnection::liveConnection() {
	
	// open an outgoing connection to HOST:PORT
	sender.setup( HOST, SEND_PORT );
	
	// listen on the given port
	receiver.setup( RECIEVE_PORT );
	
	// set defaults
	int_buffer = 0;
	playing = false;
	beat = 0;
	step = 0;
	mode = "scan"; // "scan", "live"
}


//--------------------------------------------------------
// Call once per frame (60 times/sec)
void liveConnection::update() {
	
	// Increment step
	if (playing == true) {
		step ++;
		if (step == NUM_STEPS) {
			step = 0;
		}
	}
	
	// send first message in que
	if (message_que.size() > 0) {
		for (int i=0; i<message_que.size(); i++) {
			ofxOscMessage m = message_que[i];
			cout << "PNEXT: " << m.getAddress() << " , " << m.getArgAsString( 0 ) << endl;
		}
		cout << "SENDING: " << message_que[0].getArgAsString( 0 ) << endl;
		sender.sendMessage( message_que[ 0 ] );
		message_que.erase( message_que.begin() );
		cout << "message_que.size(): " << message_que.size() << endl;
//		cout << "NEXT: " << message_que[0].getArgAsString( 0 ) << endl;
		for (int i=0; i<message_que.size(); i++) {
			ofxOscMessage m = message_que[i];
			cout << "NEXT: " << m.getAddress() << m.getArgAsString( 0 ) << endl;
		}
	}
	
	// get messages
	recieveData();
}


//--------------------------------------------------------
void liveConnection::play() {
	playing = true;
	beat = 0;
	step = 0;
}


//--------------------------------------------------------
void liveConnection::stop() {
	playing = false;
}


//--------------------------------------------------------
void liveConnection::setMode(string _mode) {
	mode = _mode;
}


//--------------------------------------------------------
// Handle incoming OSC messages
void liveConnection::recieveData() {
	while( receiver.hasWaitingMessages() ) {
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		if ( m.getAddress() == "/slot1" ) {
			int_buffer = m.getArgAsInt32( 1 );
		}
		else if ( m.getAddress() == "/bar_transport" ) {
			handleTransport( m.getArgAsInt32(0) - 1 ); // Ableton counts 0 as 1
		}
	}
}


//--------------------------------------------------------
// Set bar beat and step vars
void liveConnection::handleTransport(int _beat) {
	if ( _beat >= 0 and playing == true ) {
		beat = _beat;
		step = 0;
	}
}
	


//--------------------------------------------------------
int liveConnection::live_path(string arg){
	
	ofxOscMessage m;
	m.setAddress( "/live_path" );
	m.addStringArg(arg);
	sender.sendMessage( m );
	
	while (int_buffer == 0) {
		recieveData();
		sleep(0.1);
		//cout << "sleep..." << endl;
	}
	int return_int = int_buffer;
	int_buffer = 0;
	return return_int;
}


//--------------------------------------------------------
void liveConnection::sendMessage(string address, string arg) {
	ofxOscMessage m;
	m.setAddress( address );
	m.addStringArg(arg);
	
	// send or que depending on mode
	if (mode == "scan") {
		sender.sendMessage( m );
	} else if (mode == "live") {
		//message_que.insert( message_que.end(), m);
		message_que.push_back(m);
		//cout << "message_que.size(): " << message_que.size() << endl;
	}
}


//--------------------------------------------------------
string liveConnection::sendMessageWithCallback(string address, string arg) {
	ofxOscMessage m;
	m.setAddress( address );
	m.addStringArg(arg);
	sender.sendMessage( m );
	
	return recieveStringData();
}


//--------------------------------------------------------
// Used in callback
string liveConnection::recieveStringData() {
	string buffer = "test";
	while (buffer == "test") {
		while( receiver.hasWaitingMessages() ) {
			ofxOscMessage m;
			receiver.getNextMessage( &m );
			int i = 1;
			if ( m.getAddress() == "/slot1" ) {
				if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
					buffer = ofToString( m.getArgAsInt32( i ) );
				else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
					buffer = m.getArgAsString( i );
			}
		}
		sleep(0.1);
		//cout << "sleep..." << endl;
	}
	return buffer;
}


//--------------------------------------------------------------
int liveConnection::getBeat() {
	return beat;
}


//--------------------------------------------------------------
int liveConnection::getStep() {
	return step;
}
	
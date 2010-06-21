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
	
	// set buffers
	int_buffer = 0;
	
}


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


void liveConnection::sendMessage(string address, string arg) {
	ofxOscMessage m;
	m.setAddress( address );
	m.addStringArg(arg);
	sender.sendMessage( m );
}


string liveConnection::sendMessageWithCallback(string address, string arg) {
	ofxOscMessage m;
	m.setAddress( address );
	m.addStringArg(arg);
	sender.sendMessage( m );
	
	return recieveStringData();
}


void liveConnection::recieveData() {
	while( receiver.hasWaitingMessages() ) {
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		if ( m.getAddress() == "/slot1" ) {
			int_buffer = m.getArgAsInt32( 1 );
		}
	}
}


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
	
/*
 *  liveTrack.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveTrack.h"
#include "liveSet.h"

liveTrack::liveTrack(liveSet* _parent_set, int _live_id, int _order, bool _is_master){
	parent_set = _parent_set;
	connection = parent_set->getConnection();
	live_id = _live_id;
	order = _order;
	is_master = _is_master;
	
	cout << "liveTrack( live_id: " << live_id << ", order: " << order << ", is_master: " << is_master << ")" << endl;
	
	if (!is_master) {
		getClipSlots();
	}
}

string liveTrack::path() {
	if (is_master) {
		return "master_track";
	} else {
		return "tracks " + ofToString(order);
	}
}


void liveTrack::getClipSlots() {
	for ( int i=0; i<NUM_CLIP_SLOTS; i++ ) {
		string clip_slot_path = "goto live_set " + path() + " clip_slots " + ofToString(i);
		//cout << "-clip_slot_path: " << clip_slot_path << endl;
		int clip_slot_id = connection->live_path(clip_slot_path);
		clip_slots[i] = new liveClipSlot(parent_set, clip_slot_id, live_id, i, order);
	}
}
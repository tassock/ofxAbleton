/*
 *  liveClipSlot.cpp
 *  ofxAbleton
 *
 *  Created by Peter Marks on 6/20/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "liveClipSlot.h"
#include "liveSet.h"

liveClipSlot::liveClipSlot(liveSet* _parent_set, int _live_id, int _track_id, int _order, int _track_order){
	parent_set = _parent_set;
	live_id = _live_id;
	track_id = _track_id;
	order = _order;
	track_order = _track_order;
	has_clip = ofToInt( getAttr("has_clip") );
	
	cout << "liveClipSlot( live_id: " << live_id << ", has_clip: " << has_clip << ", track_id: " << track_id << ", order: " << order << ")" << endl;
	
	getClip();
}


// get the clip if it exists.
void liveClipSlot::getClip(){
	
//	// Weird hackish bs
//	int new_order = order -1;
//	if (new_order == -1) {
//		new_order = 0;
//	}
//	
//	if (has_clip) {
//		string clip_path = "goto live_set tracks " + ofToString(track_order) + " clip_slots " + ofToString(new_order) + " clip";
//		//cout << "-clip_path: " << clip_path << endl;
//		int clip_id = connection->live_path(clip_path);
//		clip = new liveClip(parent_set, clip_id, live_id);
//	}
}
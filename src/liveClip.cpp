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

liveClip::liveClip(liveSet* _parent_set, int _live_id, int _clip_slot_id){
	parent_set = _parent_set;
	connection = parent_set->getConnection();
	live_id = _live_id;
	clip_slot_id = _clip_slot_id;
	
	cout << "liveClip( live_id: " << live_id << ", clip_slot_id: " << clip_slot_id << ")" << endl;
	parent_set->addClip(this);
}

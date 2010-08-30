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

liveTrack::liveTrack(liveSet* _parent_set, int _order, string _name) {
	parent_set = _parent_set;
	order = _order;
	name = _name;
	
	cout << "liveTrack( order: " << _order << ", name: " << name << endl;
}
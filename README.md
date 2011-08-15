# ofxAbleton #

An Open Frameworks / C++ wrapper for communicating with Ableton Live via OSC. 

  
## Author ##

Peter Marks (petertmarks [at] gmail [dot] com)


## Status ##

This is an immature library that's not being actively developed by the original author. I'm not currently using Open Frameworks, but have been asked to provide further documentation for this code. Hopefully it will be of use to someone who wants to integrate Open Frameworks with Ableton, but its by no means a complete solution. 


## Dependancies ##

+ [Live OSC](http://liine.net/livecontrol/ableton-liveapi/liveosc/)


## Usage ##

  > new liveSet;
  => Scans current live set, copies set info, track info, clip info, device info and device param info into C++ objects of type liveSet, liveTrack, liveClip, liveDevice and liveParam. 
  
  > liveSet->play();
  => Plays current live set
  
  > liveSet->clips;
  => Returns vector containing liveClip objects
  
  > liveClip->fire();
  => fires selected clip object
  
  > liveParam->setVal(0.5)
  => Set the vale of a param object. 
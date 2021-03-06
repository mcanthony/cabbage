/*
  Copyright (C) 2015 Rory Walsh

  Cabbage is free software; you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Cabbage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
  02111-1307 USA

*/
#ifndef MIXERSTRIP_H
#define MIXERSTRIP_H

#include "../../JuceLibraryCode/JuceHeader.h"

class InternalMixerStrip :  public Component, 
							public ChangeListener,
							public ChangeBroadcaster
{
public:
	InternalMixerStrip(String name, int numChannels);
	~InternalMixerStrip();
	ScopedPointer<Slider> gainSlider;
	
	void changeListenerCallback (ChangeBroadcaster*);
	float currentGainLevel;
	void paint(Graphics& g);
	void resized();
	void drawLevelMeter (Graphics& g, float x, float y, int width, int height, float level);
	Array<float, CriticalSection> channelRMS;
	StringArray rmsValues;
	void mouseDown(const MouseEvent &e);
	void mouseDrag(const MouseEvent &e);
	
	bool isInput()
	{
		return mixerName=="Inputs" ? true : false;
	}
	
private:
	ScopedPointer<DrawableRectangle> currentGainMarker;
	String mixerName;
	int numberOfChannels;
	NormalisableRange<float> range;
};

#endif
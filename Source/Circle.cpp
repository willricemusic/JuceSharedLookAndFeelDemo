/*
  ==============================================================================

    Circle.cpp
    Created: 12 Aug 2016 11:00:43pm
    Author:  Will Rice

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Circle.h"
#include "LookAndFeel.h"

//==============================================================================
Circle::Circle()
{
    setSize (100, 100);
}

void Circle::paint (Graphics& g)
{
    getLookAndFeel().drawCircle (g, *this);
}

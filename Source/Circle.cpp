/*
  ==============================================================================

    Circle.cpp
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

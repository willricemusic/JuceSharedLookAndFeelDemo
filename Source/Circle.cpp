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
    (**sharedLookAndFeel).registerComponent (static_cast<Component*>(this));
    setSize (100, 100);
}

Circle::~Circle()
{
    (**sharedLookAndFeel).deregisterComponent (static_cast<Component*>(this));
}

void Circle::paint (Graphics& g)
{
    //lf->drawCircle (g, *this);
    (**sharedLookAndFeel).getCurrentLookAndFeel()->drawCircle (g, *this);
}

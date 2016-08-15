/*
  ==============================================================================

    Triangle.cpp
    Created: 12 Aug 2016 11:00:58pm
    Author:  Will Rice

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Triangle.h"
#include "LookAndFeel.h"

//==============================================================================
Triangle::Triangle()
{
    setLookAndFeel (lf);
    setSize (100, 100);
}

Triangle::~Triangle()
{
}

void Triangle::paint (Graphics& g)
{
    lf->drawTriangle (g, *this);
}

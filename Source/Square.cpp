/*
  ==============================================================================

    Square.cpp
    Created: 12 Aug 2016 11:00:51pm
    Author:  Will Rice

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Square.h"
#include "LookAndFeel.h"

//==============================================================================
Square::Square()
{
    setLookAndFeel (lf);
    setSize (100, 100);
}

Square::~Square()
{
}

void Square::paint (Graphics& g)
{
    lf->drawSquare (g, *this);
}

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
    setSize (100, 100);
}

void Square::paint (Graphics& g)
{
    getLookAndFeel().drawSquare (g, *this);
}

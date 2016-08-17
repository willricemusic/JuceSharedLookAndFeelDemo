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
    (**sharedLookAndFeel).registerComponent (static_cast<Component*>(this));
    setSize (100, 100);
}

Square::~Square()
{
    (**sharedLookAndFeel).deregisterComponent (static_cast<Component*>(this));
}

void Square::paint (Graphics& g)
{
    //lf->drawSquare (g, *this);
    (**sharedLookAndFeel).getCurrentLookAndFeel()->drawSquare (g, *this);
}

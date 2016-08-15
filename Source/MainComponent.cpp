/*
  ==============================================================================

    MainComponent.cpp
    Created: 15 Aug 2016 5:03:26pm
    Author:  Will Rice

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "LookAndFeel.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setLookAndFeel (lf);
    setSize (600, 400);
    addAndMakeVisible (circle);
    addAndMakeVisible (triangle);
    addAndMakeVisible (square);
}

MainContentComponent::~MainContentComponent()
{    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::grey);
}

void MainContentComponent::resized()
{
    int oneThird = getWidth() / 3;
    
    Rectangle<int> r = getLocalBounds();
    
    circle.setBounds (r.removeFromLeft (oneThird));
    triangle.setBounds (r.removeFromLeft (oneThird));
    square.setBounds (r);
}
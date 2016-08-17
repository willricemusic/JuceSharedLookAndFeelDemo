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
    (**sharedLookAndFeel).registerComponent (static_cast<Component*>(this));
    setSize (600, 400);
    addAndMakeVisible (circle);
    addAndMakeVisible (triangle);
    addAndMakeVisible (square);
    
    lafBox.addItemList ((**sharedLookAndFeel).getLookAndFeelNames(), 1);
    lafBox.setSelectedItemIndex ((**sharedLookAndFeel).getCurrentLookAndFeelIndex());
    lafBox.addListener (this);
    addAndMakeVisible (lafBox);
}

MainContentComponent::~MainContentComponent()
{
    (**sharedLookAndFeel).deregisterComponent (static_cast<Component*>(this));
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
    
    r = getLocalBounds().removeFromBottom (70).withSizeKeepingCentre (130, 30);
    lafBox.setBounds (r);
}

void MainContentComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == &lafBox)
        (**sharedLookAndFeel).setAllLookAndFeels (lafBox.getSelectedItemIndex());
}
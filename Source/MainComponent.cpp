/*
  ==============================================================================

    MainComponent.cpp
    Author:  Will Rice

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "LookAndFeel.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    addAndMakeVisible (circle);
    addAndMakeVisible (triangle);
    addAndMakeVisible (square);
    
    lafBox.addItemList (getSharedLookAndFeel().getLookAndFeelNames(), 1);
    lafBox.setSelectedItemIndex (getSharedLookAndFeel().getCurrentLookAndFeelIndex());
    lafBox.addListener (this);
    addAndMakeVisible (lafBox);
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
    
    r = getLocalBounds().removeFromBottom (70).withSizeKeepingCentre (130, 30);
    lafBox.setBounds (r);
}

void MainContentComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == &lafBox)
        getSharedLookAndFeel().setAllLookAndFeels (lafBox.getSelectedItemIndex());
}
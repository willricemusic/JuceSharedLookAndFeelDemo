/*
  ==============================================================================

    MainComponent.h
    Created: 15 Aug 2016 5:03:26pm
    Author:  Will Rice

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SharedLookAndFeelComponent.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"


class MainContentComponent   : public SharedLookAndFeelComponent<Component>,
                               private ComboBox::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    Circle circle;
    Triangle triangle;
    Square square;
    
    ComboBox lafBox;
    
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED

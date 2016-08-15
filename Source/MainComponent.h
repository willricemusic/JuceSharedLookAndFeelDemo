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
#include "SharedLookAndFeel.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"


class MainContentComponent   : public Component,
                               public SharedLookAndFeel
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED

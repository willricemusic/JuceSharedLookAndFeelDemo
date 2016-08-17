/*
  ==============================================================================

    Triangle.h
    Created: 12 Aug 2016 11:00:58pm
    Author:  Will Rice

  ==============================================================================
*/

#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SharedLookAndFeel.h"

//==============================================================================
class Triangle    : public Component,
                    public SharedLookAndFeelSetup
{
public:
    Triangle();
    ~Triangle();
    
    enum ColourIds
    {
        fillColourId        = 0x2001000,
        strokeColourId      = 0x2001010
    };
    
    struct LookAndFeelMethods
    {
        virtual ~LookAndFeelMethods() {}
        virtual void drawTriangle (Graphics&, Triangle&) = 0;
    };

    void paint (Graphics& g);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Triangle)
};


#endif  // TRIANGLE_H_INCLUDED

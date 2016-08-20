/*
  ==============================================================================

    Circle.h
    Author:  Will Rice

  ==============================================================================
*/

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../WithSharedLookAndFeel.h"

//==============================================================================
class Circle      : public WithSharedLookAndFeel<Component>
{
public:
    Circle();
    ~Circle() {}
    
    enum ColourIds
    {
        fillColourId        = 0x2000000,
        strokeColourId      = 0x2000010
    };
    
    struct LookAndFeelMethods
    {
        virtual ~LookAndFeelMethods() {}
        virtual void drawCircle (Graphics&, Circle&) = 0;
    };

    void paint (Graphics& g);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Circle)
};


#endif  // CIRCLE_H_INCLUDED

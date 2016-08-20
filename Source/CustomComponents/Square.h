/*
  ==============================================================================

    Square.h
    Author:  Will Rice

  ==============================================================================
*/

#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../WithSharedLookAndFeel.h"

//==============================================================================
class Square      : public WithSharedLookAndFeel<Component>
{
public:
    Square();
    ~Square() {}
    
    enum ColourIds
    {
        fillColourId        = 0x2002000,
        strokeColourId      = 0x2002010
    };
    
    struct LookAndFeelMethods
    {
        virtual ~LookAndFeelMethods() {}
        virtual void drawSquare (Graphics&, Square&) = 0;
    };

    void paint (Graphics& g);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Square)
};


#endif  // SQUARE_H_INCLUDED

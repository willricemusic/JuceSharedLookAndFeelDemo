/*
  ==============================================================================

    SharedLookAndFeel.h
    Created: 15 Aug 2016 5:03:26pm
    Author:  Will Rice

  ==============================================================================
*/

#ifndef SHAREDLOOKANDFEEL_H_INCLUDED
#define SHAREDLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//========================== forward declarations ==============================

struct CustomLookAndFeel_Shared;
struct CustomLookAndFeel;

//==============================================================================
/** 
*/
class SharedLookAndFeel
{
public:
    SharedLookAndFeel();

protected:
    ScopedPointer<SharedResourcePointer<CustomLookAndFeel_Shared>> sharedLookAndFeel;
    CustomLookAndFeel* lf;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SharedLookAndFeel)
};

#endif  // SHAREDLOOKANDFEEL_H_INCLUDED

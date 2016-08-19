/*
  ==============================================================================

    SharedLookAndFeelComponent.h
    Created: 19 Aug 2016 4:12:43pm
    Author:  Will Rice

  ==============================================================================
*/

#ifndef SHAREDLOOKANDFEELCOMPONENT_H_INCLUDED
#define SHAREDLOOKANDFEELCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//========================== forward declarations ==============================

struct CustomLookAndFeel;
struct SharedLookAndFeel;

//==============================================================================
/** 
*/
class SharedLookAndFeelComponent  : public Component
{
public:
    SharedLookAndFeelComponent();
    ~SharedLookAndFeelComponent();
    
    CustomLookAndFeel& getLookAndFeel() const;
    SharedLookAndFeel& getSharedLookAndFeel() const;
    
private:
    ScopedPointer<SharedResourcePointer<SharedLookAndFeel>> sharedLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SharedLookAndFeelComponent)
};



#endif  // SHAREDLOOKANDFEELCOMPONENT_H_INCLUDED

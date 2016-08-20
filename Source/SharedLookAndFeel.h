/*
  ==============================================================================

    SharedLookAndFeel.h
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
template <typename ComponentType>
class WithSharedLookAndFeel  : public ComponentType
{
public:
    WithSharedLookAndFeel (const String& componentName = String::empty);
    ~WithSharedLookAndFeel();
    
    CustomLookAndFeel& getLookAndFeel() const;
    SharedLookAndFeel& getSharedLookAndFeel() const;
    
private:
    ScopedPointer<SharedResourcePointer<SharedLookAndFeel>> sharedLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WithSharedLookAndFeel<ComponentType>)
};



#endif  // SHAREDLOOKANDFEELCOMPONENT_H_INCLUDED

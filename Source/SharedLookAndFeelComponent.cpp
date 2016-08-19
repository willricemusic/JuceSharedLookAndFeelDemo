/*
  ==============================================================================

    SharedLookAndFeelComponent.cpp
    Created: 19 Aug 2016 4:12:43pm
    Author:  Will Rice

  ==============================================================================
*/

#include "SharedLookAndFeelComponent.h"
#include "LookAndFeel.h"

SharedLookAndFeelComponent::SharedLookAndFeelComponent()
  : sharedLookAndFeel (new SharedResourcePointer<SharedLookAndFeel>)
{
    (**sharedLookAndFeel).registerComponent (this);
}
    
SharedLookAndFeelComponent::~SharedLookAndFeelComponent()
{
    (**sharedLookAndFeel).deregisterComponent (this);
}
    
CustomLookAndFeel& SharedLookAndFeelComponent::getLookAndFeel() const
{
    return *((**sharedLookAndFeel).getCurrentLookAndFeel());
}

SharedLookAndFeel& SharedLookAndFeelComponent::getSharedLookAndFeel() const
{
    return (**sharedLookAndFeel);
}
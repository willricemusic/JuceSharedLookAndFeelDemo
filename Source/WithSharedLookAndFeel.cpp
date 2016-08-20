/*
  ==============================================================================

    SharedLookAndFeel.cpp
    Author:  Will Rice

  ==============================================================================
*/

#include "WithSharedLookAndFeel.h"
#include "LookAndFeel.h"

template <typename ComponentType>
WithSharedLookAndFeel<ComponentType>::WithSharedLookAndFeel (const String& componentName)
  : ComponentType (componentName),
    sharedLookAndFeel (new SharedResourcePointer<SharedLookAndFeel>)
{
    (**sharedLookAndFeel).registerComponent (this);
}

template <typename ComponentType>
WithSharedLookAndFeel<ComponentType>::~WithSharedLookAndFeel()
{
    (**sharedLookAndFeel).deregisterComponent (this);
}

template <typename ComponentType>
CustomLookAndFeel& WithSharedLookAndFeel<ComponentType>::getLookAndFeel() const
{
    return *((**sharedLookAndFeel).getCurrentLookAndFeel());
}

template <typename ComponentType>
SharedLookAndFeel& WithSharedLookAndFeel<ComponentType>::getSharedLookAndFeel() const
{
    return (**sharedLookAndFeel);
}

template class WithSharedLookAndFeel<Component>;

/** Add to the list below any classes derived from Component which you want
    to use with a SharedLookAndFeel inside the Projucer.

    NOTE: The child class MUST have a default constructor. Without a default
    constructor it is impossible for the Projucer to instantiate the component
    in isolation.
*/

template class WithSharedLookAndFeel<Button>;
template class WithSharedLookAndFeel<ImageButton>;
template class WithSharedLookAndFeel<Slider>;
template class WithSharedLookAndFeel<ToggleButton>;

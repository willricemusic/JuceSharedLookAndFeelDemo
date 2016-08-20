/*
  ==============================================================================

    SharedLookAndFeel.cpp
    Author:  Will Rice

  ==============================================================================
*/

#include "SharedLookAndFeel.h"
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

/** List Component sub-types here */
template class WithSharedLookAndFeel<Button>;
//template class WithSharedLookAndFeel<ArrowButton>;
//template class WithSharedLookAndFeel<DrawableButton>;
//template class WithSharedLookAndFeel<HyperlinkButton>;
template class WithSharedLookAndFeel<ImageButton>;
//template class WithSharedLookAndFeel<ShapeButton>;
template class WithSharedLookAndFeel<ToggleButton>;

template class WithSharedLookAndFeel<Slider>;


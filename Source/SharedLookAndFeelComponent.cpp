/*
  ==============================================================================

    SharedLookAndFeelComponent.cpp
    Created: 19 Aug 2016 4:12:43pm
    Author:  Will Rice

  ==============================================================================
*/

#include "SharedLookAndFeelComponent.h"
#include "LookAndFeel.h"

template <typename ComponentType>
SharedLookAndFeelComponent<ComponentType>::SharedLookAndFeelComponent()
  : sharedLookAndFeel (new SharedResourcePointer<SharedLookAndFeel>)
{
    (**sharedLookAndFeel).registerComponent (this);
}

template <typename ComponentType>
SharedLookAndFeelComponent<ComponentType>::~SharedLookAndFeelComponent()
{
    (**sharedLookAndFeel).deregisterComponent (this);
}

template <typename ComponentType>
CustomLookAndFeel& SharedLookAndFeelComponent<ComponentType>::getLookAndFeel() const
{
    return *((**sharedLookAndFeel).getCurrentLookAndFeel());
}

template <typename ComponentType>
SharedLookAndFeel& SharedLookAndFeelComponent<ComponentType>::getSharedLookAndFeel() const
{
    return (**sharedLookAndFeel);
}

template class SharedLookAndFeelComponent<Component>;
/** List Component sub-types here? */

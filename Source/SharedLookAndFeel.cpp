/*
  ==============================================================================

    SharedLookAndFeel.cpp
    Created: 15 Aug 2016 5:03:26pm
    Author:  Will Rice

  ==============================================================================
*/

#include "SharedLookAndFeel.h"
#include "LookAndFeel.h"

SharedLookAndFeel::SharedLookAndFeel()
  : sharedLookAndFeel (new SharedResourcePointer<CustomLookAndFeel_Shared>),
    lf (&(**sharedLookAndFeel).laf)
{
    
}
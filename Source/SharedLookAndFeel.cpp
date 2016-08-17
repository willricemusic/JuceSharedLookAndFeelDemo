/*
  ==============================================================================

    SharedLookAndFeel.cpp
    Created: 15 Aug 2016 5:03:26pm
    Author:  Will Rice

  ==============================================================================
*/

#include "SharedLookAndFeel.h"
#include "LookAndFeel.h"

SharedLookAndFeelSetup::SharedLookAndFeelSetup ()
  : sharedLookAndFeel (new SharedResourcePointer<SharedLookAndFeel>),
    lf ((**sharedLookAndFeel).getCurrentLookAndFeel())
{
}

SharedLookAndFeelSetup::~SharedLookAndFeelSetup()
{
}
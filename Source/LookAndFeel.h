/*
  ==============================================================================

    LookAndFeel.h
    Author:  Will Rice

  ==============================================================================
*/

#ifndef LOOKANDFEEL_H_INCLUDED
#define LOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

//==============================================================================
/** An abstract base class from which the app's LookAndFeels will inherit
*/
struct CustomLookAndFeel          : public LookAndFeel_V3,
                                    public Circle::LookAndFeelMethods,
                                    public Triangle::LookAndFeelMethods,
                                    public Square::LookAndFeelMethods
{
};

//==============================================================================
/** A LookAndFeel with components drawn as outlines
*/
struct CustomLookAndFeel_Outline  : public CustomLookAndFeel
{
    CustomLookAndFeel_Outline()
    {
        setColour (Circle::strokeColourId,                      Colours::teal);
        setColour (Triangle::strokeColourId,                    Colours::green);
        setColour (Square::strokeColourId,                      Colours::blue);
        
        setColour (ComboBox::outlineColourId,                   Colours::white);
        setColour (ComboBox::arrowColourId,                     Colours::white);
        setColour (ComboBox::textColourId,                      Colours::white);
        
        setColour (PopupMenu::backgroundColourId,               Colours::grey);
        setColour (PopupMenu::highlightedBackgroundColourId,    Colours::white);
        setColour (PopupMenu::highlightedTextColourId,          Colours::black);
    }
    
    void drawCircle (Graphics& g, Circle& circle) override
    {
        int shortEdge = jmin (circle.getWidth(), circle.getHeight());
        
        Rectangle<int> r = circle.getLocalBounds()
                           .withSizeKeepingCentre (shortEdge, shortEdge)
                           .reduced (25);
        
        g.setColour (circle.findColour (Circle::strokeColourId));
        g.drawEllipse (r.toFloat(), 5);
    }
    
    void drawTriangle (Graphics& g, Triangle& triangle) override
    {
        Rectangle<int> r = triangle.getLocalBounds().reduced (25);
                           
        Path p;
        p.addTriangle (0.0f, 0.0f, 0.0f, 1.0f, 0.866f, 0.5f);
        p.applyTransform (p.getTransformToScaleToFit (r.toFloat(), true, Justification::centred));
        
        g.setColour (triangle.findColour (Triangle::strokeColourId));
        g.strokePath (p, PathStrokeType (5));
    }
    
    void drawSquare (Graphics& g, Square& square) override
    {
        int shortEdge = jmin (square.getWidth(), square.getHeight());
        
        Rectangle<int> r = square.getLocalBounds()
                           .withSizeKeepingCentre (shortEdge, shortEdge)
                           .reduced (25);
                           
        g.setColour (square.findColour (Square::strokeColourId));
        g.drawRect (r, 5);
    }
    
    void drawComboBox (Graphics& g, int width, int height, const bool /*isButtonDown*/,
                       int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box) override
    {
        g.setColour (box.findColour (ComboBox::outlineColourId));
        g.drawRect (0, 0, width, height, 1);

        const float arrowX = 0.3f;
        const float arrowH = 0.2f;

        Path p;
        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.45f - arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.45f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.45f);

        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.55f + arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.55f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.55f);

        g.setColour (box.findColour (ComboBox::arrowColourId).withMultipliedAlpha (box.isEnabled() ? 1.0f : 0.3f));
        g.strokePath (p, PathStrokeType (1));
    }
};

//==============================================================================
/** A LookAndFeel with components drawn as solid fills
*/
struct CustomLookAndFeel_Flat     : public CustomLookAndFeel
{
    CustomLookAndFeel_Flat()
    {
        setColour (Circle::fillColourId,    Colours::purple);
        setColour (Triangle::fillColourId,  Colours::turquoise);
        setColour (Square::fillColourId,    Colours::orange);
    }
    
    void drawCircle (Graphics& g, Circle& circle) override
    {
        int shortEdge = jmin (circle.getWidth(), circle.getHeight());
        
        Rectangle<int> r = circle.getLocalBounds()
                           .withSizeKeepingCentre (shortEdge, shortEdge)
                           .reduced (25);
        
        g.setColour (circle.findColour (Circle::fillColourId));
        g.fillEllipse (r.toFloat());
    }
    
    void drawTriangle (Graphics& g, Triangle& triangle) override
    {
        Rectangle<int> r = triangle.getLocalBounds().reduced (25);
                           
        Path p;
        p.addTriangle (0.0f, 0.0f, 0.0f, 1.0f, 0.866f, 0.5f);
        p.applyTransform (p.getTransformToScaleToFit (r.toFloat(), true, Justification::centred));
        
        g.setColour (triangle.findColour (Triangle::fillColourId));
        g.fillPath (p);
    }
    
    void drawSquare (Graphics& g, Square& square) override
    {
        int shortEdge = jmin (square.getWidth(), square.getHeight());
        
        Rectangle<int> r = square.getLocalBounds()
                           .withSizeKeepingCentre (shortEdge, shortEdge)
                           .reduced (25);
                           
        g.setColour (square.findColour (Square::fillColourId));
        g.fillRect (r);
    }
    
    void drawComboBox (Graphics& g, int width, int height, const bool /*isButtonDown*/,
                       int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box) override
    {
        g.fillAll (box.findColour (ComboBox::backgroundColourId));

        const float arrowX = 0.3f;
        const float arrowH = 0.2f;

        Path p;
        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.45f - arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.45f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.45f);

        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.55f + arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.55f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.55f);

        g.setColour (box.findColour (ComboBox::arrowColourId).withMultipliedAlpha (box.isEnabled() ? 1.0f : 0.3f));
        g.fillPath (p);
    }
};

//==============================================================================
/** The shared look and feel object
*/
class SharedLookAndFeel
{
public:
    SharedLookAndFeel()
    {
        /** Add your CustomLookAndFeel instances here.
            Use the 'isDefault' flag to set a default LAF
        */
        addLookAndFeel (new CustomLookAndFeel_Flat(), "Flat");
        addLookAndFeel (new CustomLookAndFeel_Outline(), "Outlines", true);
    }

    void registerComponent (Component* component)
    {
        components.add (component);
        component->setLookAndFeel (getCurrentLookAndFeel());
    }
    
    void deregisterComponent (Component* component)
    {
        components.remove (components.indexOf (component));
    }
    
    CustomLookAndFeel* getCurrentLookAndFeel()
    {
        return lookAndFeels[currentLookAndFeelIndex];
    }
    
    int getCurrentLookAndFeelIndex() const noexcept
    {
        return currentLookAndFeelIndex;
    }
    
    void setAllLookAndFeels (const int lookAndFeelIndex)
    {
        jassert (lookAndFeelIndex >= 0 && lookAndFeelIndex < lookAndFeels.size());
        
        currentLookAndFeelIndex = lookAndFeelIndex;
        
        for (int i = 0; i < components.size(); i++)
        {
            components[i]->setLookAndFeel (getCurrentLookAndFeel());
        }
    }
    
    const StringArray& getLookAndFeelNames() const noexcept
    {
        return lookAndFeelNames;
    }
    
private:
    OwnedArray<CustomLookAndFeel> lookAndFeels;
    StringArray lookAndFeelNames;
    Array<Component*> components;
    int currentLookAndFeelIndex;
    
    void addLookAndFeel (CustomLookAndFeel* laf, const String& name, bool isDefault = false)
    {
        if (lookAndFeels.size() == 0)
                currentLookAndFeelIndex = 0;
        
        lookAndFeels.add (laf);
        lookAndFeelNames.add (name);
        
        if (isDefault)
            currentLookAndFeelIndex = lookAndFeels.size() - 1;
    }
};

#endif  // LOOKANDFEEL_H_INCLUDED

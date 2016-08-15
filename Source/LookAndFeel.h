/*
  ==============================================================================

    LookAndFeel.h
    Created: 15 Aug 2016 5:03:26pm
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
        setColour (Circle::strokeColourId,  Colours::teal);
        setColour (Triangle::strokeColourId, Colours::green);
        setColour (Square::strokeColourId,  Colours::blue);
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
};

//==============================================================================
/** A LookAndFeel with components drawn as solid fills
*/
struct CustomLookAndFeel_Flat     : public CustomLookAndFeel
{
    CustomLookAndFeel_Flat()
    {
        setColour (Circle::fillColourId,  Colours::purple);
        setColour (Triangle::fillColourId, Colours::turquoise);
        setColour (Square::fillColourId,  Colours::orange);
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
};

//==============================================================================
/** The shared look and feel object
*/
struct CustomLookAndFeel_Shared
{
    CustomLookAndFeel_Flat laf;
};

#endif  // LOOKANDFEEL_H_INCLUDED

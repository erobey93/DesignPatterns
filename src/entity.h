//Emily Robey
//Lab 2 - CST 276 - WI 23
//Entity Class

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "rand.h"

class Entity
{
public:
    Entity() : x(0), y(0) {};
    virtual ~Entity() {};

    //updates entities - virtual so can be re-defined/overidden by subclass
    virtual void update(float dt, const float wWidth) = 0;  //actual updating happens in subclasses
    virtual void move(float dt)
    {
	  //FIXME 
	  //x = 10.f * dt;
	  //y = 10.f * dt; 
    } 
    virtual void render(sf::RenderTarget& target, sf::RenderStates state) const
    {
        sf::CircleShape shape(20.0f); //don't make a data member to keep abstraction high - cleaner seperation of concerns, which makes it easier to change the entities appearence w/out affecting the rest of the code
	shape.setFillColor(sf::Color::Green); 
	target.draw(shape); 
    }
    //updates x and y positions 

    protected: 
    //TODO --> could make this a struct
    float x = 0.f;
    float y = 0.f;
};

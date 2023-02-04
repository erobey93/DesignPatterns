//Emily Robey
//CST 276 - WI 23 - Lab 2
//Enemy class

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"
using std::string;
using std::cout;
using std::endl;

class Enemy : public Entity
{
public:

    Enemy() {};
    virtual void update(float dt, const float wWidth) override = 0;

    virtual void render(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        sf::CircleShape shape(200.f);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x, y);
        target.draw(shape);

    }
    virtual void updateVelocity(float uVX, float uVY)
    {
        vX = vX + uVX;
        vY = vY + uVY;
    }

protected:

    float vX = 0.f;
    float vY = 0.f;

};

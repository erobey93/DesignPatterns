//Emily Robey
//CST 276 - WI 23 - Lab 2
//Ship class

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"

using std::endl;
using std::cout;

class Ship : public Entity
{
public:

    Ship(int delay, float x, float y) : frame(0), delay(delay) {
        setPosition(x, y);
    }
    virtual void update(float dt, const float wWidth) override
    {
        if(++frame == delay)
        {
            shoot();
            //reset timer
            frame = 0;
        }
        //x + 50 * dt, y + 50 * dt;

    }

    void render(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::RectangleShape shape(sf::Vector2f(50,50));//set initial position(which should change for ships
        shape.setFillColor(sf::Color::Red); //set color
        shape.setPosition(x, y);//set position
        target.draw(shape); //draw ship
    }
    void setPosition(float uX, float uY)
    {
        x = uX;
        y = uY;

    }//TODO --> add in velocity and eventListener for right and left keys

    void shoot()
    {
        cout << "SHOOT FIXME" << endl;
    }

private:
    int frame;
    int delay;
};

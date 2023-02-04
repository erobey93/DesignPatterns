//Emily Robey
//CST 276 - WI 23 - Lab 2
//FastEnemy class

#pragma once

#include <iostream>
#include "enemy.h"

class FastEnemy : public Enemy
{
public:
    FastEnemy() : patrollingLeft(false) {
    }

    virtual void update(float dt, const float wWidth) override
    {
        if(patrollingLeft)
        {
            vX = -10.0f; //move left
            x = x + vX;
            if(x == 0)
            {
                patrollingLeft = false;
            }
        }
        else
        {
            vX = 10.0f;//move right
            x = x + vX;
            if(x == wWidth)
            {
                patrollingLeft = true;
            }
        }
    }
    virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        sf::CircleShape shape(22.f);
        shape.setFillColor(sf::Color::Yellow);
        shape.move(x, y);
        target.draw(shape);
    }

private:
    bool patrollingLeft;
};

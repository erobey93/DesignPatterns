//Emily Robey
//CST 276 - WI 23 - Lab 2
//Slow Enemy class

#pragma once

#include <iostream>
#include "enemy.h"

class SlowEnemy : public Enemy
{
public:

    SlowEnemy() : patrollingLeft(false) {

    }

    virtual void update(float dt, const float wWidth) override
    {
        cout << "Slow Enemy updated " << endl;
        if(patrollingLeft)
        {
            vX = -5.f;//move left
            x = x + vX;
            if(x == 0)
            {
                patrollingLeft = false;
            }
        }
        else
        {
            vX = 5.f; //move right
            x = x + vX;
            if(x > wWidth)
            {
                patrollingLeft = true;
            }
        }
    }

    virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        sf::CircleShape shape(22.f);
        shape.setFillColor(sf::Color::Green);
        shape.move(x,y);
        target.draw(shape);
    }

private:
    bool patrollingLeft;
};


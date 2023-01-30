//Emily Robey
//
//Enemy class
//

#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"

class Enemy : public Entity
{
public:
    
    Enemy() {};
    ~Enemy(){}; 
    virtual void update()
    {
        float s = dt.asSeconds();

        //so just move one "entity"  now, since our list of entities is in world?
        shape.move(getX() * s, getY() * s);//need to set x and y though...

    }
    void render(sf::RenderWindow &window) //not sure if I should be taking in the window from main still?
    {
        // always clear!
        window.clear();

        // drawing happens here (off-screen)
        window.draw(shape);

        // swap the display buffer (double-buffering)
        window.display();

    }

private:
    sf::CircleShape shape;// change to triangle shape
    sf::Time dt;



};

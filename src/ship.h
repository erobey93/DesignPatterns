//Emily Robey
//
//Ship class
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"

class Ship : public Entity
{
public:

    Ship();
    ~Ship(); 
    void update()
    {
        float s = dt.asSeconds();

        //so just move one "entity"  now, since our list of entities is in world?
        shape.move(getX() * s, getY() * s);

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
    //I'm confused why the subclasses would have their own updates and renders? I'm generally confused about how all of this is working...
private:
    sf::CircleShape shape;// change to triangle shape 
    sf::Time dt;
};

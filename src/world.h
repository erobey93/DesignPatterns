//Emily Robey
//CST 276 - WI 23 - Lab 2
//World Class

#pragma once

#include <iostream>
#include "entity.h"
#include "enemyFactory.h"
#include "enemy.h"
#include "ship.h"
#include "string"

using std::string;

class World
{
public:
    World() : numEntities(0) {}
    ~World() {};

    void addEntity(Entity *entity)
    {
        entities.push_back(entity);
        numEntities++;
    }
    void collision(sf::Shape &shape1, sf::Shape &shape2)
    {
        sf::FloatRect bounds1 = shape1.getGlobalBounds();
        sf::FloatRect bounds2 = shape2.getGlobalBounds();

        if(bounds1.intersects(bounds2))
        {
            cout << "intersection" << endl;
        }
        //get centers and radii of the two shapes
        //determine the distance between the centers
        //check if the shapes are intersecting
        //calc collision response
        //update velocities of two shapes
        //so I need an update velocity function probably
    }
    void update(float dt, const float wWidth)
    {
        for(auto& entity : entities)
        {
            //collision(entities(i), entities(i + 1)); //not exactly but lets see FIXME
            entity -> update( dt, wWidth);

        }
//if(play.getGlobalBounds().intersects(shape.getGlobalBounds()))//check for an intersection

    }
    //RenderTarget = abstract base class that represents a target to draw graphics to
    //could be RenderWindow, RenderTexture, etc
    //RenderStates defines how the object should be drawn (position, rotation, scale)
    //often use sf::RenderStates::Default, but can set by creating a RenderStates object and doing .blendMode = sf::BlendAdd, or a number of other state specsin SFML library
    void render(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(const auto& entity : entities)
        {
            entity->render(target,states);
        }

    }

    int getNumEntities()
    {
        return numEntities;
    }
    Entity *getElement(int index)
    {
        return entities.at(index);
    }

private:
    int numEntities;
    std::vector<Entity*> entities; //switched to vector

};

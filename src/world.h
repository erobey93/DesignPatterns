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
    
    bool collision(sf::Shape &shape1, sf::Shape &shape2)
    {
	//get bounds for shapes
        sf::FloatRect bounds1 = shape1.getGlobalBounds();
        sf::FloatRect bounds2 = shape2.getGlobalBounds();
	//check for collision
        if(bounds1.intersects(bounds2))
        {
		return true;
        }
	else
	{
		return false; 
	}
    }
    void update(float dt, const float wWidth)
    {
        for(auto& entity : entities)
        {
            entity -> update( dt, wWidth);

        }
/* FIXME not sure how to handle collision since an Entitiy isn't a shape..
 * I could just adjust each new shape's position since they're only moving along the x-axis, but I don't know if that's the best way to go about it. 
	for(int i = 0; i < entities.size(); i++)
	{
		for(int j = (i + 1); j < entities.size(); ++j)
		{
			if(collision(entities[i], entities[j]))
			{
				//handle collision
			}

		}
		}*/

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

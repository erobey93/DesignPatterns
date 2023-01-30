//Emily Robey
//Lab 2 - CST 276 - WI 23
//World Class

#pragma once

#include <iostream>
#include "entity.h"
#include "enemyFactory.h"
#include "ship.h" 

class World
{
public:
    World() : numEntities(0) {}
    void createEnemies() 
    {
        entities[numEntities] = randEnemy -> makeEnemy(); //set appropriate Entity element to randEnemy which creates a new enemy in the list/array
        //if we do this though, what will "ship" or any non-enemy entities do with this function? I'm confused about this...
	numEntities ++;
    }
    void createShip()
    {
	entities[numEntities] = aShip; 
	numEntities++; 
    }
    void gameLoop()
    {
	    while (true)
	    {
		    //handle user input
		    
		    //update each entity
		    for(int i = 0; i < numEntities; i++)
		    {
			    entities[i] -> update(); 
		    }
	    }
    }
    //should this be in here? maybe not? 
    void processEvents(sf::RenderWindow & window, std::vector<sf::CircleShape> & shapes) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

private:
    const int MAX_ENTITITES = 100; //FIXME change this just to compile for now 
    Entity *entities[100];//list of entities in game 
    int numEntities;
    //or should EnemyFactor be down here?
    EnemyFactory *randEnemy;
    Ship *aShip; 

};

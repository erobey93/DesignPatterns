//Emily Robey
//Lab 2 - CST 276 - WI 23
//World Class

#include <iostream>
#include "entity.h"

class World
{
public:
    World() : numEntities(0) {}
    void setEntities()
    {
        EnemyFactory randEnemy; //make Enemy should randomly pick one of the enemy types and return
        entities[numEntities] = randEnemy.makeEnemy(); //set appropriate Entity element to randEnemy which creates a new enemy in the list/array
    }
    void gameLoop();

private:
    Entity *entities[MAX_ENTITIES];
    int numEntities;
    //or should EnemyFactor be down here?
    EnemyFactory randEnemy;

}

//Emily Robey
//
//EnemyFactory class

#pragma once

#include <iostream>
#include "enemy.h"
#include "slowEnemy.h"
#include "fastEnemy.h"

using std::endl;
using std::cout;

class EnemyFactory
{
public:
    static Enemy *makeEnemy()
    {
        //randomly choose
        int random = rand() % 2;
        if(random == 1)
        {
            return new SlowEnemy(); //make new space in memory and return a slowEnemy
        }
        else
        {
            return new FastEnemy(); //make new space in memory and return a fastEnemy
        }
    }
private:
};

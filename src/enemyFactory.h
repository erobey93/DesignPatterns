//Emily Robey 
//
//EnemyFactory class

#pragma once

#include <iostream>
#include "enemy.h"
#include "slowEnemy.h"
#include "fastEnemy.h"

class EnemyFactory
{
	public:
		EnemyFactory(){}; 
		~EnemyFactory(){}; 

		Enemy *makeEnemy()
		{
			SlowEnemy *slow;
			FastEnemy *fast; 
			//randomly choose 
			int random = rand() % 2 + 1; 
			if(random == 1)
			{
				randEnemy = slow; 
			}
			else
			{
				randEnemy = fast; 
			}

			return randEnemy; 
		}
	private:
		Enemy *randEnemy; 
};

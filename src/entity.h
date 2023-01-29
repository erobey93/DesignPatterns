//Emily Robey
//Lab 2 - CST 276 - WI 23
//Entity Class

#pragma once

#include <iostream>
#include "enemy.h"
#include "ship.h" //ToDo --> do I need to include these actually? 

class Entity
{
public:
	Entity() : x(0), y(0) {};
	virtual ~Entity(){};
	virtual void update() = 0; 

	double x() const 
	{ 
		return x; 
	}
	double y() const
	{
		return y; 
	}

	void setX(double u_x) 
	{
		x = u_x;
	}
	void setY(double u_y)
	{
		y = u_y;
	}

private:
	double x;
	double y; 
}

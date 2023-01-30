//Emily Robey
//Lab 2 - CST 276 - WI 23
//Entity Class

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "rand.h"

class Entity
{
public:
    Entity() : x(0), y(0) {};
    virtual ~Entity() {};
    //updates entities - virtual so can be re-defined/overidden by subclass
    virtual void update() = 0; //actual updating happens in subclasses
    virtual void render() = 0; //actual rendering happens in subclasses 

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }

    void setX(double u_x) //subclasses use to set their x coordinate 
    {
        x = u_x;
    }
    void setY(double u_y) //subclasses use to set their y coordinats 
    {
        y = u_y;
    }

private:
    double x;
    double y;
};

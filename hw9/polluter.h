// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/18/2016
// File: polluter.h
/*Description:
  The polluter class. Similar to activist.
*/
#ifndef POLLUTER_H
#define POLLUTER_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
using namespace std;

class polluter
{
  struct position //represents postion
   {
     int x;
     int y;
   };
  private:
    string name;
    position tile;
    char appearance;
  public:
    polluter(string n);
    /*Description: Constructs polluter class
    Pre: valid n string. 
    Post:sets n to name,appearance to 'P'
    tile to (-1,1)*/

    void place_me(town & t);
    /*Description: Randomly places polluter in the town
    Pre: Town has to have mapSize, walls and exits. 
    Build() has to be called essentially.
    Post:Randomly places on a valid tile(Not wall,exit or 
    polluter or anything that can collide).*/

    void randMove(town & t);
    /*Description: Moves the character to a valid position or stays put.
    Pre: Same as place_me
    Post:randomly moves in cardinal directions, if something is in the way.
    Diginity should be reduced. TODO fix diginity collision*/
};

#endif
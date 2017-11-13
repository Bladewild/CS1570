// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: town.h
/*Description:
 The class for town. It is a rectangular grid that holds and can
 display what's inside it.
*/

#ifndef TOWN_H
#define TOWN_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
static const short MAX=25;

//------------------------------------------------------------------------------

class town
{
  short mapSize;
  public:
    char tile[25][25];	
  
    friend ostream& operator << (ostream& out, town & t );
    /*Description: Outputs the image of the town
      Pre: tile has to be cleared at least and mapSize has to be set
      Post: Outputs from (0,0) to mapSize bounds (Up to the wall edges)*/

    town(short gridSize=MAX);
    /*Description: Constructor
      Pre: Takes in size of map as int (includes walls)
      Post: sets actual map size to gridSize (defaults  MAX if none).
      Build's map with walls and exits. and clears the area.*/

    void clear();
    /*Description: Clears whole array. (not \0)
      Pre: a town object with a 2d tile array not exceeding MAX. Don't call
      if board is not to be fully cleared.
      Post: Sets all elements to ' '*/
    void build();
    /*Description: Sets up town area.
      Pre: Has to follow up clear(). Pre same as clear()
      Post: Sets up walls and 4 exits depending on mapSize*/

    void setmapSize(short size);
    /*Description: Set's map size
      Pre: size cannot be smaller than 4 or bigger than MAX
      Post:sets map size*/
    short getmapSize();
    /*Description: Returns map size
      Pre:None
      Post: Returns mapSize*/
};

#endif

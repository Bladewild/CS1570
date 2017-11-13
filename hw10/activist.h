// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: activist.h
/*Description:
  Activist Class. A character that moves around valid town
  and can collide. 
*/
#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
#include "polluter.h"
#include "root.h"
using namespace std;

class root;
class activist
{
   struct position //represents postion
    {
      int x;
      int y;
    };
  private:
    float toxicity; //Must renge between 0.0-3.0
    int dignity;  //Range between 0-100
    
    char appearance;
    string name;
    string status;//normal,cool,gone

  public:
    int digLossBump,digLossCop;// values loss for dignity.
    bool onRoot;
    bool onCop;
    bool bumpingintoWall;
    position tile;

    activist(string name="Not Lisa",char c='A');
    /*Description: Constructs activist object
      Pre: String name has to be valid. 
      Post: Set's the default states for all the variables excluding name
      and appearance (c) if given*/
      
    friend ostream& operator << (ostream& out, activist a );
    /*Description: Outputs the appearance of activist
      Pre: a valid activist object that has appearance set.
      Post:Spits out 'A' or whatever appearance is set*/

    void place_me(town & t);
    /*Description: Randomly places activist in the town
      Pre: Town has to have mapSize, walls and exits. 
      Build() has to be called essentially.
      Post:Randomly places on a valid tile(Not wall,exit or 
      polluter or anything that can collide).*/

    void placeMeInMiddle(town & t);
    /*Description: Same as place_me but places in middle
      Pre: a valid built town. Same as place_me. Tries to place in middle
      Post:Places position in the middle of the town (+1/-1)
      Defaults to place_me if cannot be placed.*/

    void move(town & t,polluter & p);
    /*Description: Decides whether to move semi-itelligent or random
      Pre: Same as place_me and the polluter object to chase.
      Post: If toxicity is above a certain value, move will choose
      randMove. If not, smartMove will be called.*/

    void randMove(town & t);
    /*Description: Moves the character to a valid position or stays put.
      Pre: Same as place_me
      Post:randomly moves in cardinal directions.*/

    void smartMove(town & t,int y,int x);
    /*Description:
      Pre: same as place_me but with a valid position on the town map
      Post: Moves cardinals directions. Moves to y-axix of target first. If
      same y-axis, moves x-axis. Will not bump into walls unless the target
      is outside the walls in a valid space.*/

    void checkTriggers(town & t,position & newTile);
    /*Description: Does logic for collisions and triggers
      Pre: the newTile being investigated by the move function.
      Has to be called from one of the move functions.
      Post: Checks part of the game logic pertaining to the activist's
      next location. Also completes part of the moving process of
      replacing last location to specified character.*/

    void setDignityLosses(int bump,int cop);
    /*Description: Changes values of dignity loss
      Pre: parameters cannot be negative.
      Post:sets dignity losses*/

    void setToxicity(float t);
    /*Description: Set toxicity
      Pre:a valid range 0.0->3.0
      Post: Sets toxicity to t*/

    void setDignity(int d);
    /*Description: set diginity
      Pre: valid range 0-->100
      Post: sets diginity*/

    void setPostion(int x,int y);
    /*Description: sets position
      Pre: valid x and y coordinates on map
      Post: sets position*/

    void setAppearance(char a);
    /*Description: changes what the character looks like
      Pre: a valid character than be displayed
      Post: changes appearance*/

    void setStatus(string s);
    /*Description: Changes status
      Pre: string s can only be "normal","cool","gone"
      Post:sets status*/
    
    //Self-explanatory
    float getToxicity();
    int getDignity();
    char getAppearance();
    string getStatus();

};

#endif

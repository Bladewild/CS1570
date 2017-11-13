// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: header.h
/*   Description:
   header file of the simulation 
   */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "root.h"
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include <fstream>
//#include <windows.h> //For sleep
using namespace std;

const int MAX_ROOTS=20;   
const int DAYS_TO_SHOW=1;

void simulation(const int gridSize,const int numRoots,const int nmCops,
                int digLossBump,int digLossCop, float & perExit,
                float & perWacked,float & perSuccess,float & perDeath, 
                float & avgTox,int day) ;     
/*Description: Simulates one day of the chase
      Pre: Config data values, percent values to be calcaluted on, the
      current day that is being simulated.
      Post: Displays the simulation of the chase until activist is
      inactive. Shows only X days from DAYS_TO_SHOW. The rest only displays
      major events that activist did.*/

char checkActive(bool & active,polluter & p,activist & a,town & t,int day); 
/*Description: Checks if the activist has triggered a state where the day
	  immediately ends.
      Pre: The active bool variable that shows if the activist can still
      perform her tasks. The activist object in question. The polluter being
      chased by the same activist object. The town that these objects
      are moving about. The current day the simulation is on. 
      Post: Checks if inactive state is triggered. Outputs nothing if
      still active. Outputs message if inactive state is triggered and
      active variable is set to true. Also returns the cause of inactivity
      by character*/

void checkDignity(activist & a,int day);
/*Description: Checks if diginity decreasing triggers are triggered. Runs
      appropriate game logic.
      Pre: The activist object in chasing the polluter. The current day
      being simulated.
      Post: Decreases diginity and outputs appropriate message if trigger
      variables trip. Any extra game logic applies if need be.*/

void checkRoot(activist & a,root listofRoots [],
               int & currentRootStock,int day);
/*Description: Adds the toxicity of the last element 
      in listofRoots to activist.
      if activist has stepped on a root.
      Pre: the activist being moved. The array of roots. The currentRootStock 
      that can be accessed. The day being simulated.
      Post: If the activist is onRoot, the currentRootStock-th place will be
      selected from listofRoots. The currrentRootStock will then decrease and
      toxicity of selected root is added to activist.*/

void placeCharacters(char c,int numChar,town & t);
/*Description: Randomly places X number of char c in the town
      Pre: Town has to have mapSize, walls and exits. A valid
      character that can be outputted. the number of characters
      that will be displayed (numChar).
      Build() has to be called essentially.
      Post: Randomly places on a valid empty tile(Not wall,
      exit or anything that has a symbol on it).*/
                            

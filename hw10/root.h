// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: root.h
/*Description:
 
*/
#ifndef ROOT_H
#define ROOT_H


#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "activist.h"
using namespace std;

class activist;
class root
{
  public:
    string type;//either truffle or square
    float effect; //neg is square,pos is truffle, cannot be zero
    root();
    /*Description: Creates a root that is either truffle or square
    Pre: NONE
    Post: Randomly selectes either truffle or square with
    a random effect value within the root type's range.
    Effect cannot be zero*/

    friend activist operator + (const root r, activist & a);
    friend activist operator + (activist & a, const root r);
    /*Description: Adds effect of root to activist toxicity
      Pre: A valid activist and a valid root.
      Post: The effect value of root is added into the activist's
      toxicity.*/
};

#endif

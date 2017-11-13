// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 10/26/2016
// File: header.h
/*Description:
	This is where all the prototypes are located and descriptions
	of what they do.
	All the global delcaration are located.
*/
#ifndef HEADER_H
#define HEADER_H

using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
//------------------------------------------------------------------------------
const int SIZE=15;
const float percentXtolerance=0.55; //Must be above 50%;
const string arrayName[]= {"Homer","Maggie","Bart","Moe","Barney","Marge",
                           "Cletus","Snake","Mr. Burns","Dr. Nick",
                           "Krusty the Clown","Chief Wiggum","Ralph Wiggum",
                           "Skinner","Lenny"};
struct lisa
{
	string name;
	int guilt;
};

struct wiggum
{
	int sector;
	int weight;//of pile trash
};

//------------------------------------------------------------------------------
bool operator < (const lisa lhs,const lisa rhs);
bool operator > (const lisa lhs,const lisa rhs);
//These compare the guilt values and returns a bool

ostream& operator << (ostream& out, const lisa l );
//This outputs name and guilt

bool operator < (const wiggum lhs,const wiggum rhs);
bool operator > (const wiggum lhs,const wiggum rhs);
//These compare the weight values and returns a bool

ostream& operator << (ostream& out, const wiggum w );
//This outputs the sector and weight
//------------------------------------------------------------------------------
template <typename T>
void sortDescending(T t [])
{
  T temp;
  for(int i=0;i<SIZE;i++)
  {
    for(int j=i;j<SIZE;j++)
    {
      if(t[i]<t[j])//This compares largest and switches if true
      {
        temp=t[i];
        t[i]=t[j];
		    t[j]=temp; //eventually the largest should be in front
	    }
    }
  }
}
template <typename T>
void displayArray(T t [])
{
  for(int i=0;i<SIZE;i++)
    cout<<t[i]<<endl;
}
/*Description: Displays a greeting msg
  Pre: An array of T type (in this case wiggum or lisa).
  Has to be filled to work properly.
  Post: Displays the cout of */
//------------------------------------------------------------------------------
void greetings();
/*Description: Displays a greeting msg
  Pre: None
  Post: Displays a msg to console*/
void signOff();
/*Description: Display a sign off msg
  Pre: None
  Post: Dispays a sign off msg*/
int RNG(int min,int max);
/*Description: Creates a random number from min-max
  Pre: Two ints that are positive values.
  Post: Returns a random positive integer from min-max*/
//------------------------------------------------------------------------------
void sortBySector(wiggum filledWiggum []);
/*Description: Sorts the array wiggum into sectors
  Pre: a wiggum array that is filled
  Post:the wiggum array is now sorted by sector*/
//------------------------------------------------------------------------------
void generateWiggum(wiggum emptyWiggum []);
/*Description: Fills the empty wiggum array
  Pre: an empty wiggum array
  Post: empty wiggum array is now filled with random data*/

void generateLisa(lisa emptyLisa []);
/*Description:
  Pre:
  Post:*/
//------------------------------------------------------------------------------
void assignNames(lisa arrayLisa []);
/*Description: Fills random names in empty lisa array
  Pre: an empty lisa array
  Post: the empty lisa array has random names*/
void assignGuilt(lisa arrayLisa []);
/*Description: Fills random Guilt in empty lisa array
  Pre: an empty lisa array
  Post:the empty lisa array has random Guilt values*/
void assignSector(wiggum arrayWiggum []);
/*Description: Fills random sectors in empty wiggum array
  Pre: an empty wiggum array
  Post: the empty wiggum array has random sectors*/
void assignWeight(wiggum arrayWiggum []);
/*Description: Fills random weight in empty wiggum array
  Pre: an empty wiggum array
  Post: the empty wiggum array has random weight*/
//------------------------------------------------------------------------------
void findGuiltiest(lisa filledLisa [],int x, int include []);
/*Description: Outputs the offenders that are identified by the include array
  Pre: A sorted lisa array, the size of include array, the include array
  that has the indexes of the offenders.
  Post: Displays the offenders listed by indexes in include*/
void findXGuiltiest(lisa filledLisa [],int x);
/*Description: Outputs the top x guiltiest in lisa array.
  Pre: A sorted lisa array and x guiltiest asked.
  Post: Displays the top x guiltiest in the array*/
void findXthGuiltiest(lisa filledLisa [],int xth);
/*Description: Outputs xth guiltiest in lisa array.
  Pre: A descending sorted lisa array and xth guiltiest asked.
  xth guiltiest must not be 0.
  Post: Displays the xth guiltiest in the array*/
int findTotalTrash(wiggum filledWiggum []);
/*Description: Finds total weight in filledWiggum array
  Pre: a wiggum array that is filled
  Post:Returns the total weight in wiggum array as an int*/
int findTotalTrash(wiggum filledWiggum [],int sector);
/*Description: Finds total weight in filledWiggum array for a
  SPECIFIC SECTOR.
  Pre: a wiggum array that is filled
  Post:Returns the total weight of a SPECIFIC SECTOR
  in wiggum array as an int*/
void findAllSectorTrash(wiggum filledWiggum [],int sector);
/*Description: Displays individual weight of trash for that sector
  Pre: a wiggum array filled, the sector identified as int
  Post: Outputs list of individual weights for that sector*/
int findPileByWeightandSector(wiggum filledWiggum [],int weight,int sector);
/*Description: finds the index of a pile by its weight and sector
  Pre: a wiggum array filled, int weight 25-500, int sector 1-7
  Post: returns index equal to weight and sector.
        If cannot be found, a -1 is returned*/

void findLeast50Offenders(wiggum filledWiggum [],lisa arrayLisa []);
/*Description: finds offenders (mostly top) who fill at least 50%-52%
               of the trash in springfield
  Pre: a wiggum array filled, lisa array filled.
  Post:Displays the offenders who contribute 50-52%*/
//------------------------------------------------------------------------------
void identifyPile(wiggum filledWiggum [],lisa arrayLisa []);
/*Description: finds pile asked by user. Connects to the function below
  Pre: a wiggum array filled, lisa array filled.
  Post:the pile searched by user is outputed. Asks if user wants to 
       restart*/
void identifyPileByWeight(wiggum filledWiggum [],lisa filledLisa [],int sector);
/*Description: This is the actual function that finds the pile
  Pre: a wiggum array filled, lisa array filled.
  Post: Asks for weight. Finds pile index by weight and sector
        using another function. Once index is found,
        outputs the offender*/
//------------------------------------------------------------------------------
void listSectors(wiggum filledWiggum []);
/*Description: Lists sectors of the filled wiggum array
  Pre: a wiggum array filled
  Post: Outputs the sectors with the individual weight of
        trash below them*/
//------------------------------------------------------------------------------
void segfault();
//Don't ask
#endif

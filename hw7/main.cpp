// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 10/26/2016
// File: main.cpp
/*Description:
   Zeroeth Task: Outputs the two databases
   First Task: Displays top two offenders in springfield
   Second Task: Displays the offenders who contributed at least 50% of trash 
   but not going over 55%. 
   Third Task: Asks user to identify a trash pile by sector and weight.
*/

//------------------------------------------------------------------------------
#include "header.h"

int main()
{
  srand(time(NULL));
  wiggum W [SIZE];
  lisa L [SIZE];
  
  greetings();
  //Zeroeth Task
  generateWiggum(W);
  generateLisa(L);
  cout<<endl;
  sortDescending(W);
  sortDescending(L);

  displayArray(W);
  cout<<endl;
  displayArray(L);
  cout<<endl;

  //First Task
  findXGuiltiest(L,2);
  cout<<endl;

  //Second Task
  findLeast50Offenders(W,L);
  cout<<endl;
  
  //Third Task
  sortBySector(W);
  listSectors(W);
  sortDescending(W);
  identifyPile(W,L);

  signOff();
  return 0;
}

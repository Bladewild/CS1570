// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 10/26/2016
// File: functions.cpp
/*Description:
  These are where the functions are located. No overloaded operators here.
*/

#include "header.h"
//------------------------------------------------------------------------------
void greetings()
{
  cout<<"Welcome Trash Offender Database!"<<endl;
}
void signOff()
{
  cout<<endl<<"Have a nice day !"<<endl;
}

int RNG(int min,int max)
{
  return min + rand()% (max-min+1);
}
//------------------------------------------------------------------------------
//SORT

//Im just keeping it here because no reason to delete. This used to have a
// real intended function other than making the sector list look organized.
void sortBySector(wiggum filledWiggum []) //This is bubble sort
{
  int tempSector=0,tempWeight=0;
  for(int i=0;i<SIZE;i++)
  {
    for(int j=i;j<SIZE;j++)
    {
      if(filledWiggum[i].sector>filledWiggum[j].sector)
      {
        tempSector=filledWiggum[i].sector;
        filledWiggum[i].sector=filledWiggum[j].sector;
        filledWiggum[j].sector=tempSector;

        tempWeight=filledWiggum[i].weight;
        filledWiggum[i].weight=filledWiggum[j].weight;
        filledWiggum[j].weight=tempWeight;
      }
    }
  }
}
//------------------------------------------------------------------------------
//GENERATE
void generateWiggum(wiggum emptyWiggum []) //Makes an array filled with wiggum
{
  assignSector(emptyWiggum);
  assignWeight(emptyWiggum);
}

void generateLisa(lisa emptyLisa []) //Makes an array filled with lisa
{
  assignNames(emptyLisa);
  assignGuilt(emptyLisa);
}
//------------------------------------------------------------------------------
//ASSIGN- These are self-explanitory
//The ones with numbers are capped appropriately.
void assignNames(lisa arrayLisa [])
{
  for(int i=0;i<SIZE;i++)
    arrayLisa[i].name=arrayName[i];
}
void assignGuilt(lisa arrayLisa [])
{
  for(int i=0;i<SIZE;i++)
    arrayLisa[i].guilt=RNG(100,10000);
}
void assignSector(wiggum arrayWiggum [])
{
  for(int i=0;i<SIZE;i++)
    arrayWiggum[i].sector=RNG(1,7);
}
void assignWeight(wiggum arrayWiggum [])
{
  for(int i=0;i<SIZE;i++)
    arrayWiggum[i].weight=RNG(25,500);
}
//------------------------------------------------------------------------------
//FIND
///finds the guilty that is in the include array.
void findGuiltiest(lisa filledLisa [],int x, int include [])
{
  for(int i=0;i<x;i++)
  {
    if(include[i]==i)//Runs only if not -1.
      cout<<filledLisa[i]<<endl;
  }
}
void findXGuiltiest(lisa filledLisa [],int x)
{
  cout<<"These are the top "<<x<<" guiltiest in springfield in order."<<endl;
  cout<<"--------------------------------"<<endl;
  for(int i=0;i<x;i++)
      cout<<filledLisa[i]<<endl;
}
void findXthGuiltiest(lisa filledLisa [],int xth) //outputs the xth guiltiest
{ //Assuming filledLisa is in descending order.  (NO 0 for xth)
  cout<<filledLisa[xth-1].name<<" is the perpetrator."<<endl;
}
int findTotalTrash(wiggum filledWiggum []) //This will find all the weight
{
  int total=0;
  for(int i=0;i<SIZE;i++)
    total+=filledWiggum[i].weight;
  //cout<<"[Debug] Total: "<<total<<endl;
  return total;
}
int findTotalTrash(wiggum filledWiggum [],int sector) //Weight for that sector
{
  int total=0;
  for(int i=0;i<SIZE;i++)
  {
    if(filledWiggum[i].sector==sector)//Runs if sector is found
    {
      total+=filledWiggum[i].weight;
      //cout<<"[Debug] Sector: "<<filledWiggum[i].sector<<endl;
    }
  }
  //cout<<"[Debug] Total: "<<total<<endl;
  return total;
}
//Displays all trash in that sector.
//**-filledWiggum has to be sorted sector first!!!!
//**-After user finishes choosing piles, sector must be sorted DESCENDING again.
void findAllSectorTrash(wiggum filledWiggum [],int sector)
{
  int numPile=1;
  for(int i=0;i<SIZE;i++)
  {
    if(filledWiggum[i].sector==sector)
    {
      cout<<"["<<numPile<<"] "<<filledWiggum[i].weight<<endl;
      numPile++;
    }
  }
}
//returns the index number. This accepts approximations. Rounds essentially
int findPileByWeightandSector(wiggum filledWiggum [],int weight,int sector)
{
  for(int i=0;i<SIZE;i++)
  {
    if(weight==filledWiggum[i].weight && sector==filledWiggum[i].sector)
      return i;
  }
  cout<<"Failed to find match"<<endl;
  return -1;
}
void findLeast50Offenders(wiggum filledWiggum [],lisa filledLisa [])
{
  int percent50Trash=0; int xGuilty=0;
  int totalTrash=findTotalTrash(filledWiggum);
  int offenders [SIZE];

  cout<<"The total trash is "<<totalTrash<<" lbs."<<endl;
  //keep going until pile is at least 50%.
  do
  {
    percent50Trash+=filledWiggum[xGuilty].weight;
    if(percent50Trash>(totalTrash*percentXtolerance))//Checks if above 55%
    {
      //cout<<"DUCKY! "; DEBUG
      percent50Trash-=filledWiggum[xGuilty].weight;//Removes weight from total
      offenders[xGuilty]=-1; //This disallows from reading later on.
    }
    else
    {
      offenders[xGuilty]=xGuilty;//stores the index of offenders
    }
    xGuilty++;
    //cout<<xGuilty<<" Current Trash: "<<percent50Trash<<endl; DEBUG
  }while(percent50Trash <= totalTrash/2);
  cout.precision(4);
  cout<<"These offenders"
      <<" are the ones responsible for "<<endl
      <<((percent50Trash*100.0)/totalTrash)<<"% of trash in springfield"
      <<" in order of guilt."<<endl;
  cout<<"--------------------------------"<<endl;
  findGuiltiest(filledLisa,xGuilty,offenders);
}
//------------------------------------------------------------------------------
//IDENTIFY

void identifyPile(wiggum filledWiggum [],lisa filledLisa [])
{
  int userChoiceINT=0;
  string userChoiceSTR;
  do
  {
    cout<<"Which sector would you like to search: ";
    cin>> userChoiceINT;
    if(userChoiceINT<1 || 7<userChoiceINT)
    {
      cout<<"The sector you entered is out of range."
          <<"\nPlease enter a new value"<<endl;
      continue;
    }
    else //Valid Choice
    {
      cout<<endl;
      identifyPileByWeight(filledWiggum,filledLisa,userChoiceINT);
    }
    cout<<"Do you want to quit?(yes or no or segfault) ";cin>>userChoiceSTR;
    if(userChoiceSTR=="segfault")//segfaults....This caused me great pain
      segfault();
  }while(userChoiceSTR!="yes" && userChoiceSTR!="y");

}
//wiggum must be sorted descending during initialization.
void identifyPileByWeight(wiggum filledWiggum [],lisa filledLisa [],int sector)
{
  int index; int userChoiceINT=0;
  do
  {
    findAllSectorTrash(filledWiggum,sector);
    cout<<"Enter the weight of the pile you would like to identify: ";
    cin>> userChoiceINT;
    if(userChoiceINT<25 || 500<userChoiceINT)
    {
      cout<<"The weight you entered is out of range."
          <<"\nPlease enter a new value"<<endl;
      continue; //resets loop if invalid input
    }
    index= findPileByWeightandSector(filledWiggum,userChoiceINT,sector);
    if(index==-1) //resets loop if a pile isn't found
    {
      cout<<"The weight you entered cannot be found."
          <<"\nPlease enter a new value"<<endl;
      continue;
    }
    findXthGuiltiest(filledLisa,index+1);//Had to have +1 bc how function works
    break; //Because I can't use recursive methods.
  }while(true); //This is only used for 'continue' to work.
}
//------------------------------------------------------------------------------
//LIST
void listSectors(wiggum filledWiggum [])
{
  int sectorTrash=0;
  for(int i=1;i<=7;i++)
  {
    sectorTrash=findTotalTrash(filledWiggum,i);
    cout<<"Sector "<< i
    <<" total trash: "<<sectorTrash<<" lbs"<<endl;
    findAllSectorTrash(filledWiggum,i);
  }
}
//------------------------------------------------------------------------------
//SEGFAULTS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void segfault()
{
  cout<<endl;
  cout<<"In computing, a segmentation fault (often shortened to segfault) or"
      <<" access violation is a fault raised by hardware with memory "
      <<"protection, notifying an operating system (OS) about a memory access"
      <<" violation; on x86 computers this is a form of general protection"
      <<" fault. The OS kernel will, in response, usually perform some "
      <<"corrective action, generally passing the fault on to the offending "
      <<"process by sending the process a signal. Processes can in some cases "
      <<"install a custom signal handler, allowing them to recover on their"
      <<" own,[1] but otherwise the OS default signal handler is used, "
      <<"generally causing abnormal termination of the process (a program"
      <<" crash), and sometimes a core dump."<<endl<<endl;

  cout<<"Poem from http://www.poppyfields.net/filks/00216.html"<<endl;
  cout<<"I\'ve looked in kernel memory,"<<endl;
  cout<<"I\'ve looked in the tables."<<endl;
  cout<<"I try to find some core"<<endl;
  cout<<"For fifty million pages."<<endl;
  cout<<"They call me the swapper."<<endl;
  cout<<"I\'ve been searching low and high."<<endl;
  cout<<"Unix won\'t run out of memory"<<endl;
  cout<<"Till the day I die."<<endl<<endl;

  cout<<"I asked Dennis Ritchie,"<<endl;
  cout<<"I asked Ken Thompson."<<endl;
  cout<<"I asked comp.unix.wizards,"<<endl;
  cout<<"But they couldn\'t help me either."<<endl;
  cout<<"They call me the swapper."<<endl;
  cout<<"I\'ve been searching low and high."<<endl;
  cout<<"Unix won\'t run out of memory"<<endl;
  cout<<"Till the day I die."<<endl<<endl;

  cout<<"People tend to hate me,"<<endl;
  cout<<"Cause I swap too slow."<<endl;
  cout<<"As I page out their jobs"<<endl;
  cout<<"They want to shake my hand."<<endl;
  cout<<"Focusing on swap space,"<<endl;
  cout<<"Investigating pagefaults,"<<endl;
  cout<<"I\'m a pagedaemon,"<<endl;
  cout<<"I\'m a very desperate hack."<<endl<<endl;

  cout<<"Unix won\'t run out of memory"<<endl;
  cout<<"Till the day I die."<<endl<<endl;

  cout<<"I learned how to raise resident set size."<<endl;
  cout<<"Yeah, but look at this process it\'s mem\'ry bound!"<<endl;
  cout<<"I\'m happy when you segfault,"<<endl;
  cout<<"and when you run thrash.c I crash."<<endl;
  cout<<"I get values but I"<<endl;
  cout<<"Don\'t know how or why!"<<endl<<endl;

  cout<<"I\'m looking for core,"<<endl;
  cout<<"You\'re looking for CPU,"<<endl;
  cout<<"We\'re running on the same box,"<<endl;
  cout<<"And we don\'t know what to do!"<<endl;
  cout<<"They call me the swapper."<<endl;
  cout<<"I\'ve been searching low and high."<<endl;
  cout<<"Unix won\'t run out of memory"<<endl;
  cout<<"Till the day I die."<<endl<<endl;
  string A="Segmentation fault (core dumped)";
  int lots=1;
  string segfault [1]={A};
  for(int i=0;0<lots;i++)
    cout<<A<<" "<<segfault[i];
  }

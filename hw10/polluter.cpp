// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: polluter.cpp
/*Description:
  contains member functions of polluter class
*/
#include "polluter.h"
polluter::polluter(string n,char c)
{
  name=n;
  appearance=c;
  tile.x=-1;
  tile.y=1;
}

void polluter::place_me(town & t)
{
  //srand(time(NULL));
  int newX,newY;
  const int MIN=1,MAX=2;
  //Places randomly inside the map,within walls. Nothing on top
  do
  {
    //This spawns within walls
    newX=rand()%(t.getmapSize()-MAX)+MIN;
    newY=rand()%(t.getmapSize()-MAX)+MIN;
    //Cannot spawn on acivist or root
  }while(t.tile[newX][newY]!=' ');
  tile.x=newX;
  tile.y=newY;

  //row=y//Coloumn=y**** [y][x]   
  //Place character onto tile
  t.tile[tile.y][tile.x]=appearance;
}
void polluter::randMove(town & t)
{
  static bool caughtbyCop=false;
  if(caughtbyCop==false)
  {
    //row=y//Coloumn=y**** [y][x]   
    //set newTile to currentTile activist tile
    position newTile={tile.x,tile.y};
    static bool onRoot=false;
    int direction=rand()%4;
    //Change either x or y tile depending on direction
    switch(direction)
    {
      case 0://Up
        newTile.y=tile.y-1;
        break;
      case 1://Left
        newTile.x=tile.x-1;
        break;
      case 2://Down
        newTile.y=tile.y+1;
        break;
      case 3://Right
        newTile.x=tile.x+1;
        break;
    }
    //cout<<endl<<"Tx: "<<newTile.x<<"| Ty: "<<newTile.y<<endl<<endl;
    //Check Collision
    char chosenTile=t.tile[newTile.y][newTile.x];
    if(chosenTile=='C')//cannot move if caught by cop
    {
      caughtbyCop=true;
    }   
    if(chosenTile=='W' || chosenTile=='E' || chosenTile=='A')
    {
      //Reverts back to original tile
      newTile.x=tile.x;
      newTile.y=tile.y;
      chosenTile=t.tile[newTile.y][newTile.x];
    }
    if(onRoot==true && chosenTile!=appearance)
    { //leaving root and into valid space
      //Put root back
      t.tile[tile.y][tile.x]='R';  
      onRoot=false;
    }
    else
    { //Erase previous location
      t.tile[tile.y][tile.x]=' ';  
    }  
    //Relocate polluter
    tile.x=newTile.x;
    tile.y=newTile.y;
    //Move appearance to new location
    t.tile[tile.y][tile.x]=appearance;
    if(chosenTile=='R')//on the root
    {
      onRoot=true;
    }
    //CORRECTLY MOVES FROM A ROOT TO ANOTHER ROOT!! 
    // PRR // PR // RP // RRP
  }
}

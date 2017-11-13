// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/18/2016
// File: polluter.cpp
/*Description:
  contains member functions of polluter class
*/
#include "polluter.h"
polluter::polluter(string n)
{
  name=n;
  appearance='P';
  tile.x=-1;
  tile.y=1;
}

void polluter::place_me(town & t)
{
  srand(time(NULL));
  int newX,newY;
  //Places randomly inside the map,within walls. Nothing on top
  do
  {
    //This spawns within walls
    newX=rand()%(t.getmapSize()-2)+1;
    newY=rand()%(t.getmapSize()-2)+1;
    //Cannot spawn on acivist or root
  } while(t.tile[newX][newY]=='A' || t.tile[newX][newY]=='R');
  tile.x=newX;
  tile.y=newY;

  //row=y//Coloumn=y**** [y][x]   
  //Place character onto tile
  t.tile[tile.y][tile.x]=appearance;
}
void polluter::randMove(town & t)
{
  //row=y//Coloumn=y**** [y][x]   
  //set newTile to currentTile activist tile
  position newTile={tile.x,tile.y};

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
  if(chosenTile=='W')
  {
    //cout<<"Bumped into wall"<<endl;
    //Reverts back to original tile
    newTile.x=tile.x;
    newTile.y=tile.y;
  }
  else if(chosenTile=='A')
  {
    //Reverts back to original tile
    //cout<<"Bumped into activist"<<endl;
    newTile.x=tile.x;
    newTile.y=tile.y;
  }
  else if(chosenTile=='R')//TODO character for ROOTS
  {
    //Nothing happens
  }
  //row=y//Coloumn=y**** [y][x]   
  //Erase previouse location
  t.tile[tile.y][tile.x]=' ';
  //Relocate polluter
  tile.x=newTile.x;
  tile.y=newTile.y;
  //Move appearance to new location
  t.tile[tile.y][tile.x]=appearance;

}

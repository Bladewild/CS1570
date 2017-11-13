// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/18/2016
// File: activist.cpp
/*Description:
  member functions of activist class
*/
#include "activist.h"

activist::activist(string n)
{
  appearance='A';
  toxicity=0.5;
  dignity=100;
  status="normal";
  tile.x=-1;
  tile.y=1;
  name=n;
}

void activist::place_me(town & t)
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
  } while(t.tile[newX][newY]=='P' || t.tile[newX][newY]=='R');
  tile.x=newX;
  tile.y=newY;

  //Place character onto tile
  t.tile[tile.x][tile.y]=appearance;
}
void activist::placeMeInMiddle(town & t)
{
  //TODO Check if something is on top
  tile.x=t.getmapSize()/2;
  tile.y=t.getmapSize()/2;
  char chosenTile=t.tile[tile.y][tile.x];
  if(chosenTile!=' ') //Defaults to random if not clear
  {
    randMove(t);
  }
  else
    t.tile[tile.y][tile.x]=appearance;
  //row=y//Coloumn=y**** [y][x]   
  //Place character onto tile
}

void activist::randMove(town & t)
{
  int DECREASEDIGNITY=10; //Will change
  //row=y//Coloumn=y**** [y][x]
  //set newTile to currentTile activist tile
  position newTile={tile.x,tile.y};

  int direction=rand()%4;
  //Change either x or y tile depending on direction
  switch(direction)
  {
    case 0://Up
      newTile.y=tile.y-1;
      //cout<<"Moved Up"<<endl;
      break;
    case 1://Left
      newTile.x=tile.x-1;
      //cout<<"Moved Left"<<endl;
      break;
    case 2://Down
      newTile.y=tile.y+1;
      //cout<<"Moved Down"<<endl;
      break;
    case 3://Right
      newTile.x=tile.x+1;
      //cout<<"Moved Right"<<endl;
      break;
  }
  //cout<<endl<<"Tx: "<<newTile.x<<"| Ty: "<<newTile.y<<endl<<endl;
  //**Note: Bumping can occur so the activist will not move
  //for that turn. Please do not take points off just because
  //the character has to move that turn.

  //"An activist will also have a dignity value that starts
  // at 100 and diminishes as he/she BUMPS into walls
  //and experiences other "indignities" (to come)"
  //Check Collision
  char chosenTile=t.tile[newTile.y][newTile.x];
  if(chosenTile=='W')
  {
    dignity-=DECREASEDIGNITY;
    if(dignity==0)
    {
      //TODO FILL THIS IN FOR 0 DIGINITY
    }
    //Reverts back to original tile
    newTile.x=tile.x;
    newTile.y=tile.y;
    //cout<<"Bumped into wall"<<endl;
  }
  else if(chosenTile=='P')
  {
    //Reverts back to original tile
    newTile.x=tile.x;
    newTile.y=tile.y;
  }
  else if(chosenTile=='R')//TODO character for ROOTS
  {
    //Whatever root thingy happens.
    //toxicity+=
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

ostream& operator << (ostream& out, activist a )
{
  out<<a.getAppearance();
  return out;
}

void activist::setToxicity(float t)
{
  toxicity=t;
}
void activist::setDignity(int d)
{
  dignity=d;
}
void activist::setPostion(int x,int y)
{
  tile.x=x;
  tile.y=y;
}
void activist::setAppearance(char a)
{
  appearance=a;
}
void activist::setStatus(string s)
{
  status=s;
}

float activist::getToxicity()
{
  return toxicity;
}
int activist::getDignity()
{
  return dignity;
}

char activist::getAppearance()
{
  return appearance;
}
string activist::getStatus()
{
  return status;
}

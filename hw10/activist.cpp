// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: activist.cpp
/*Description:
  member functions of activist class
*/
#include "activist.h"

activist::activist(string n,char c)
{
  appearance=c;
  toxicity=0.05; //0.08-cool,0.25-gone (quits and ends)
  dignity=100;
  status="normal";
  tile.x=-1;
  tile.y=1;
  name=n;
  setDignityLosses(5,5);
  onCop=false;
  onRoot=false;
  onCop=false;
  bumpingintoWall=false;
}

void activist::place_me(town & t)
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
    place_me(t);
  }
  else
    t.tile[tile.y][tile.x]=appearance;
  //row=y//Coloumn=y**** [y][x]   
  //Place character onto tile
}
void activist::move(town & t,polluter & p)
{
  const float threshold=0.08;
  if(toxicity<threshold)
    smartMove(t,p.tile.y,p.tile.x);
  else
    randMove(t);
}
void activist::randMove(town & t)
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

  checkTriggers(t,newTile); 
  //Relocate activist
  tile.x=newTile.x;
  tile.y=newTile.y;
  //Move appearance to new location
  t.tile[tile.y][tile.x]=appearance;
}

void activist::smartMove(town & t,int y,int x)
{

  position newTile={tile.x,tile.y};
  int diffPosX=tile.x-x; //if given pos is negative, bottom right
  int diffPosY=tile.y-y; //if given pos is positive, top left
  //cout<<"diffPosX: "<<diffPosX<<" diffPosY:"<<diffPosY<<endl;
  //cout<<"X:"<<x<<" Y:"<<y<<endl;
  //Moves vertically first always. If cannot, goes horizontally
  //No reason to check for wall collision
  //because polluter does not go out of bounds
  if(0<diffPosY)//go up
  {
    newTile.y=tile.y-1;
  }
  else if(diffPosY<0)//go down
  {
    newTile.y=tile.y+1;
  }
  else if(0<diffPosX)//go left
  {
    newTile.x=tile.x-1;
  }
  else if(diffPosX<0)//go right
  {
    newTile.x=tile.x+1;       
  }    
  checkTriggers(t,newTile); 
  //Relocate activist
  tile.x=newTile.x;
  tile.y=newTile.y;
  //Move appearance to new location
  t.tile[tile.y][tile.x]=appearance;
 }

void activist::checkTriggers(town & t,position & newTile)
{
  char chosenTile=t.tile[newTile.y][newTile.x];
  if(chosenTile=='W')//take out root later on.
  {
    bumpingintoWall=true;
    //dignity decrease is calculated elsewhere.

    //Reverts back to original tile
    newTile.x=tile.x;
    newTile.y=tile.y;
    chosenTile=t.tile[newTile.y][newTile.x];
  }  
  else if(chosenTile=='R')//character for ROOTS
  {
    onRoot=true;
  }
  if(onCop==true && chosenTile!=appearance)
  { //leaving cop and into valid space
    //Put Cop back
    t.tile[tile.y][tile.x]='C';  
    onCop=false;
  }
  else
  { //Erase previous location
    t.tile[tile.y][tile.x]=' ';  
  } 
  if(chosenTile=='C')//New tile is a cop
  {
    onCop=true;
  } 
}

ostream& operator << (ostream& out, activist a )
{
  out<<a.getAppearance();
  return out;
}

void activist::setDignityLosses(int bump,int cop)
{
  digLossBump=bump;
  digLossCop=cop;
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

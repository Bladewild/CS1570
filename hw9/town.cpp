// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/18/2016
// File: town.cpp
/*Description:
 member functions of town class
*/
#include "town.h"

town::town(short gridSize)
{
	//clear grid*
  setmapSize(gridSize);
  clear();
  build();
}

//ROOTS!! REMEMVER ROOTS

void town::build()
{
	//build walls
	for(int i=0;i<mapSize;i++)//row
	{
		for(int j=0;j<mapSize;j++)
		{
			if(i==0 || j==0 || i==mapSize-1 || j==mapSize-1)
			  tile[i][j]='W';
			else
			{
				tile[i][j]=' ';
			}
		}
	}
	//build exits
	tile[0][mapSize/2]='E';
	tile[mapSize/2][0]='E';
	tile[mapSize-1][mapSize/2]='E';
	tile[mapSize/2][mapSize-1]='E';
}
void town::clear()
{
	for(int i=0;i<MAX;i++)//row
	{
		for(int j=0;j<MAX;j++)
		{
				tile[i][j]=' ';
		}
	}
}

void town::setmapSize(short size)
{
  mapSize=size;
}

short town::getmapSize()
{
  return mapSize;
}

ostream& operator << (ostream& out, town & t )
{
  for(int i=0;i<t.mapSize;i++)//row
	{
		for(int j=0;j<t.mapSize;j++)
		{
			out<<t.tile[i][j];
		}
		out<<endl;
	}
  return out;
}

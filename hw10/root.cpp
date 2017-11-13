// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 12/6/2016
// File: root.cpp
/*Description:
  contains member functions of polluter class
*/
#include "root.h"
root::root()
{	
  //srand(time(NULL));
  const float sMAX=0.010,sMIN=0.001; //neg
  const float sDIVMULT=1000;//this is used because % only works for ints.
  const float tMAX=0.10,tMIN=0.05; //pos
  const float tDIVMULT=100;
  //numElements++;
  //Assign effect value and type
  float effectValue;
  string rootType;
  int sign=rand()%2;
  //0 is neg,1 is pos
  if(sign)//is pos, TRUFFLE
  {//                   10-1=9  1 (1-10)
  
    effectValue=(rand()%(static_cast<int>((tMAX-tMIN)*tDIVMULT+1))
                 +tMIN*tDIVMULT)/tDIVMULT;
    rootType="truffle";
  }
  else //SQUARE
  {
    effectValue=(rand()%(static_cast<int>((sMAX-sMIN)*sDIVMULT+1))
                 +sMIN*sDIVMULT)/sDIVMULT;
    effectValue*=-1;//turns into negative
    rootType="square";
  }
  effect=effectValue;
  type=rootType;

}

activist operator + (const root r, activist & a)
{
  float newToxicity=a.getToxicity()+r.effect;
  a.setToxicity(newToxicity);
  return a;
}
activist operator + (activist & a, const root r)
{
	return r+a;
}
//the root has to be removed from the array made 
//previously or not accesible.


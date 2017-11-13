// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 10/26/2016
// File: overloadOperators.cpp
/*Description:
	This includes only the overloaded operators
*/
#include "header.h"

//Lisa
bool operator < (const lisa lhs,const lisa  rhs)
{
  if(lhs.guilt < rhs.guilt)
  {
    return true;
  }
  return false;
}
bool operator > (const lisa lhs,const lisa rhs)
{
  if(lhs.guilt > rhs.guilt)
  {
    return true;
  }
  return false;
}

ostream& operator << (ostream& out, const lisa l )
{
  out <<"Name: "<<l.name<<", Guilt: "<<l.guilt;
  return out;
}
//Wiggum
bool operator < (const wiggum lhs,const wiggum rhs)
{
  if(lhs.weight < rhs.weight)
  {
    return true;
  }
  return false;
}

bool operator > (const wiggum lhs,const wiggum rhs)
{
  if(lhs.weight > rhs.weight)
  {
    return true;
  }
  return false;
}

ostream& operator << (ostream& out, const wiggum w )
{
  out <<"Sector: "<<w.sector<<", Weight: "<<w.weight
      <<" lbs";
  return out;
}

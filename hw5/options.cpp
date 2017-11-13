// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 10/2/2016
// File: options.cpp 
//------------------------------------------------------------------------------
/*Description:
	Contains the functions of hw5
*/
#include "hw5_header.h"

float option1()
{
  float user_input;
  //Range Between 0-100
  do
  {
  	cout<<endl<<"Enter number of pounds food wasted: ";
  	cin>>user_input;
  }while(!(0<=user_input && user_input<=100));
  return user_input;
}



int option2()
{
  //If they do not use public trasnport, returns 0,
  //If they do, inputs between 1-250 inclusive.
  int user_input;
  char char_input;
  cout<<"Do you use public transport? (y/n)";cin>>char_input;
  if(char_input=='n')
  {
    return 0;
  }
  else if(char_input=='y')
  {
  	do
	{
	  cout<<endl<<"How many miles have you traveled: "; cin>>user_input;
	}while(!(1<=user_input && user_input<=250));
  }
}

int option3()
{
  const int BURNSCONSTANT=570;
  
  //If Mr.Burns, returns BURNSCONSTANT
  //If not, asks if relative. If so, returns half of BURNSCONSTANT.
  //If not, asks age and returns that. Must be equal or greater than 0;
  char user_input;
  int age;
  cout<<endl<<"Are you Mr. Burns (y/n):";cin>>user_input;
  if(user_input=='y')
  	return BURNSCONSTANT;
  else if(user_input=='n')
  {
  	cout<<endl<<"Are you related to Mr.Burns (y/n):";
	cin>>user_input;
  	if(user_input=='y')
  	  return BURNSCONSTANT/2;
  	else
    {
      do
      {
  	    cout<<endl<<"What is your age in years? ";cin>>age;
      }while(!(0<=age));
      return age;
	}
  }
}  

float option4(float waste)
{
 
  int user_input;
  cout<<endl;
  //Range must be between 0-3
  do
  {
    cout<<"How many whole pigs did your father eat this week: ";
	cin>>user_input;
  }while( !(0<=user_input && user_input<=3));
  
  //Returns value calculated by Lisa's equation.
  return waste*user_input*user_input+3*user_input+5;
}

float option5(float value,float mult,float add)
{
  return value*mult +add;
}

void greeting()
{
  cout<<"Welcome! "<<endl;
}
void goodbye()
{
  cout<<"Goodbye! "<<endl;
}

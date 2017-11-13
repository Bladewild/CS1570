// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 10/2/2016
// File: hw5.cpp 
//------------------------------------------------------------------------------
/*Description:
	Computes your carbon footprint by asking random
	questions which calculates a values. The values
	are added up together for the GUILT value.
*/

#include "hw5_header.h"
 
int main()
{
  //Delcarations
  float frmp=NULL;
  int user_input=NULL;
  float numFoodWasted=NULL;
  int numMiles=NULL,age=NULL;
  //Constants for modyfing transitmiles and waste values
  const float WASTEMULT=1.5, WASTEADD=6;
  const float TRANSMULT=-2,TRANSADD=1;
  //Trigger variables to prevent choosing more than once
  bool trg1=false,trg2=false,trg3=false,trg4=false;
  float GUILT;

  greeting();
  
  while(true)
  {
  
  //Menu
  //For debugging
  //cout<<numFoodWasted<<":"<<numMiles<<":"
  //<<age<<":"<<frmp<<endl;  
  cout<<"\n    Carbon Footprint Survey"<<endl;
  cout<<"   ---------------------------"<<endl;
  cout<<"1.  Wasteful (food) Consumption"<<endl;
  cout<<"2.  Public Transit Usage"<<endl;
  cout<<"3.  Industrial Complicity"<<endl;
  cout<<"4.  Farm-related Methane Production"<<endl;
  cout<<"5.  Compute GUILT value"<<endl;
  cin>>user_input;
  
  //Select appropriate option given by user_input.
  //Can only choose an option once. 
  //Prevents further requests. 
  //Option 4 requires completion of option 1.
  //Option 5 requires previous options to be completed.
  switch(user_input)
  {
    case 1:
    if(trg1==false)
    {
      numFoodWasted= option1(); trg1=true;
	}
     else
	  cout<<"Unable to choose this option."<<endl;
    break;
    case 2:
    if(trg2==false)
    {
      numMiles= option2(); trg2=true;
	}
	 
	else
	  cout<<"Unable to choose this option."<<endl;
    break;
    case 3:
    if(trg3==false)
    {
	  age= option3(); trg3=true;
	}
	 else
	  cout<<"Unable to choose this option."<<endl;
    break;
    case 4:
    if(trg1==false)
      cout<<endl<<"Please choose #1 first."<<endl;
    else if(trg4==false)
    {
      frmp= option4(numFoodWasted); trg4=true;
    }
    else
      cout<<"Unable to choose this option."<<endl;
    break;
    case 5:
    if (trg1!=false && trg2!=false && trg4!=false)
    {
    	numFoodWasted=option5(numFoodWasted,WASTEMULT,WASTEADD);
    	numMiles=option5(numMiles,TRANSMULT,TRANSADD);
    	/* For debugging
    	cout<<"Wasted: "<<numFoodWasted<<endl;
    	cout<<"Miles: "<<numMiles<<endl;
    	cout<<"Age: "<<age<<endl;
    	cout<<"frmp: "<<frmp<<endl;
    	*/
    	//GUILT EQUATION: Adds up all the values and outputs
    	//their value of guilt.
    	GUILT=numFoodWasted+numMiles+age+frmp;
    	cout<<endl<<"Your guilt is "<<GUILT<<endl;
    	goodbye();
    	return 0;
    }
    else
      cout<<"Please complete the previous listing.";
    break;
    default:
    cout<<"Wrong Input"<<endl;
    }
  }
  return 0;
}



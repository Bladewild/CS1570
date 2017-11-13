// Programmer: Marky Santos-Tankia // Student ID:12454208
// instructor Name: Dileep // Section: // Date: 09/7/2016
// File: hw2.cpp 

/* Description:
	Asks for length and freakfish from user.
	Calculates the Tank Dimensions given.
	Outputs the results. 
*/
#include <iostream>
using namespace std;
int main()
{
  //Declare Varibles
  int length,width,height;
  bool extraEYES;
  const int LIFE=11;
  
  //Input from user
  cout << "Input Length: ";
  cin>>length;  
  cout << "Any fish are there with at least two "
  <<"eyes (yes=1,no=0): ";
  cin >>extraEYES;
  
  //Calculations
  width= length/4, height=length*2/3;
  float tankVol= 7.48*width*length*height;
  float waterVol= tankVol-2*static_cast<float>(extraEYES);
  float waste= static_cast<float>(LIFE)/(height*12.0);
  int fishnum=waterVol/25;
  
  //Display
  cout<<"\nTank Dimensions \n----------------";
  cout<<"\nLength    "  << length << " ft";
  cout<<"\nWidth     "<< width <<  " ft";
  cout<<"\nHeight    " << height << " ft";
  cout<<"\nTank Cap  " << tankVol << " gals";
  cout<<"\nWater     " << waterVol << " gals";
  cout<<"\nWaste     " << waste << " rads";
  
 
    cout<<"\n   _///_ \n";
    cout<<"  /o    \\/ \n";
    cout<<"  > ))_./\\ \n";
    cout<<"     <  \n";
     cout<<"Your tank will hold "<< fishnum <<" fishes.";
   
  return 0;
}  



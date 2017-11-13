// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 09/14/2016
// File: hw3.cpp 

/* Description:
	Asks for inspiration number
	Number is used to make notes.
	Each number corresponds to each animal and note.
	Each note will increase snack for speciic animal
	Manipulate until number is 1 where it will stop.
	Display snack count at the end.
*/
  #include <iostream>
  using namespace std;
int main()
{
  //Declarations
  int elchuc=0,buck=0,ffish=0,threeleg=0,tbears=0,hans=0,cletus=0;
  const string NT_A="wah",NT_Bb="bleep",NT_Cplusplus="do-wah",NT_Dminus="ding",NT_Esharp="honk",NT_Fb="wapp",NT_H="DOH!";
  const int THREE=3,TWO=2,ONE=1;
  int inspirationNum;
  
  cout<<"Hello Lisa!"<<endl;
  //Intakes a valid inspiration number from user.
  //Has to be in between 10 and 100 inclusive. 
  do
  {
    cout<<"What is your inspiration Number? ";
    cin>>inspirationNum;    
    if(inspirationNum<10)
      cout<<"\nThis number is too Ralph Wiggumian. Try Again.\n";       
    else if(inspirationNum>100)
      cout<<"\nThis number is too Jon Coltranian. Try Again.\n";
    else
      break;
  }
   while(true);
   
  //Plays notes while adding snacks to each associated animal
  while(inspirationNum!= 1)  
  {
    if(inspirationNum%7==0)
      {
        cout<<NT_A<<" ";
        elchuc++;
      }
    else if(inspirationNum%7==1)
      {
        cout<<NT_Bb<<" ";
        buck++;
      }
    else if(inspirationNum%7==2)
      {
        cout<<NT_Cplusplus<<" ";
        ffish++;
      }
    else if(inspirationNum%7==3)
      {
        cout<<NT_Dminus<<" ";
        threeleg++;
      }
    else if(inspirationNum%7==4)
      {
        cout<<NT_Esharp<<" ";
        tbears++;
      }
    else if(inspirationNum%7==5)
      {
        cout<<NT_Fb<<" ";
        hans++;
      }
    else if(inspirationNum%7==6)
      {
        cout<<NT_H<<" ";
        cletus++;
      }
    //Manipulates inspiration number.
    if(inspirationNum%TWO ==0)
      inspirationNum/=TWO;
    else
      inspirationNum= (THREE*inspirationNum+ONE);
  }
  
  
  //Displays snack count for each animal.;
  cout<<"\n\nWhat beautiful music!";
  cout<<"\nHere's the snacks for each animal.";
  cout<<"\n\nEl Chupacabra   "<<elchuc  <<endl;
  cout<<"BuckToothedSlug "<<buck     <<endl;
  cout<<"Freaky Fish     "<<ffish    <<endl;
  cout<<"3-legged Snake  "<<threeleg <<endl;
  cout<<"Trash Bears     "<<tbears   <<endl;
  cout<<"Hans            "<<hans     <<endl;
  cout<<"Cletus          "<<cletus   <<endl;
  cout<< "\nProgram will now exit.";
  cout<<"\nGoodbye!";
  cout<<"\nx_x";
  return 0;
}



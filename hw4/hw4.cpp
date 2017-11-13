// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 09/16/2016
// File: hw4.cpp 
/*Description:

	Asks for user's name that will be used throughout program
	Displays menu which the user will ask item number and 
	how many of that item they want. Error trappings are included.
	Price Total is calculated during this process.

	After user exits the menu, they will be shown their balance
	and be asked to insert money. Their change will be displayed.

*/

//I wish I was allowed to use functions.... There's wouldn't
//be a lot of if statements otherwise.

using namespace std;
#include <iostream>

int main()
{
  //Declarations
  string user_name;
  int numGinko=5,numMandrake=4,numGinseng=9,numSquare=11,numVitR=8;
  const float priceGinko=4.50,priceMandrake=1.23,
  			  priceGinseng=2.39,priceSquare=99.98,priceVitR=0.78;
  float priceTotal,priceFinal,taxRate=0.16,change;
  int tax_on_total;
  int user_input;
  int numBuy;

  //Asks Username
  cout<<"Enter your name: "; cin>>user_name;

  do
  {
  	//Outputs a menu for the user.
  	cout<<endl;
    cout<<"Roots n' Stuff'"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1. Ginko Root ($4.50)     "<< (numGinko?    "": " NO LONGER AVAILABLE.") <<endl;
    cout<<"2. Mandrake Root ($1.23)  "<< (numMandrake? "": " NO LONGER AVAILABLE.")<<endl;
    cout<<"3. Ginseng Root ($2.39)   "<< (numGinseng?  "": " NO LONGER AVAILABLE.")<<endl;
    cout<<"4. Square Root ($99.98)   "<< (numSquare?   "": " NO LONGER AVAILABLE.")<<endl;
    cout<<"5. Vitamin R Root ($0.78) "<< (numVitR?     "": " NO LONGER AVAILABLE.")<<endl;
    cout<<"6. Quit"<<endl;
    cin>>user_input;
    cout<<endl;

    /*
    	Selects item requested by user through the use of an integer.
    	Will output snarky comment if the input is invalid.
    	This occurs for when value is not 1-6 for the menu, the user tries
    	to buy an item that is out of stock, the user enters a negative number for
    	how much they are buying.
    	A partial buy will occur if user tries to buy more than stock. It will give
    	what is available.
    	The price of the item multiplied by how much the ask for and added to the priceTotal.
    	The item stock will decrease by how much they bought. It will not go down below 0.
    */
    switch(user_input)
    {
  	  case 1:
	  if(numGinko)
	    {
	      cout<<"How many do you wish to buy "<<user_name<<"? ";cin>>numBuy;
	      if(numBuy<0)
	       {
	         cout<<"Stop Lowering your IQ "<< user_name<<"! INVALID NUMBER!"<<endl<<endl;
	         break;
	       }
	       else
	       {
	       	 if(numBuy>numGinko)
	       	 {
	       	   cout<<endl<<"You requested more than in stock "<< user_name<<". You will recieve what is available.";
	       	   cout<<endl;
	       	    numBuy=numGinko;
	       	 }
	         numGinko-=numBuy;
	         priceTotal+=priceGinko*numBuy;
	       }
	    }
		else
	  	{
	  		cout<<"Your IQ is lower than current stock of the item which is 0"<< user_name<<". To raise IQ, please try again\n"
	  			<<endl; 
	  	}
		break;
		case 2:
		if(numMandrake)
	    {
	      cout<<"How many do you wish to buy "<<user_name<<"? ";cin>>numBuy;
	      if(numBuy<0)
	       {
	         cout<<"Stop Lowering your IQ "<< user_name<<"! INVALID NUMBER!"<<endl<<endl;
	         break;
	       }
	       else
	       {	       	
	       	 if(numBuy>numMandrake)
	       	 {
	       	   cout<<endl<<"You requested more than in stock "<< user_name<<". You will recieve what is available.";
	       	   cout<<endl;
	       	   numBuy=numMandrake;
	       	 }
	         numMandrake-=numBuy;
	         priceTotal+=priceMandrake*numBuy;
	       }
	    }
		else
	  	{
	  		cout<<"Your IQ is lower than current stock of the item which is 0 "<< user_name<<". To raise IQ, please try again\n"
	  			<<endl; 
	  	}
		break;
		case 3:
		if(numGinseng)
	    {
	      cout<<"How many do you wish to buy "<<user_name<<"? ";cin>>numBuy;
	      if(numBuy<0)
	       {
	         cout<<"Stop Lowering your IQ "<< user_name<<"! INVALID NUMBER!"<<endl<<endl;
	         break;
	       }
	       else
	       {
	       	 if(numBuy>numGinseng)
	       	 {
	       	   cout<<endl<<"You requested more than in stock "<< user_name<<". You will recieve what is available.";
	       	   cout<<endl;
	       	    numBuy=numGinseng;
	       	 }
	         numGinseng-=numBuy;
	         priceTotal+=priceGinseng*numBuy;
	       }
	    }
		else
	  	{
	  		cout<<"Your IQ is lower than current stock of the item which is 0 "<< user_name<<". To raise IQ, please try again\n"
	  			<<endl; 
	  	}
		break;
		case 4:
		if(numSquare)
	    {
	      cout<<"How many do you wish to buy "<<user_name<<"? ";cin>>numBuy;
	      if(numBuy<0)
	       {
	         cout<<"Stop Lowering your IQ "<< user_name<<"! INVALID NUMBER!"<<endl<<endl;
	         break;
	       }
	       else
	       {
	       	 if(numBuy>numSquare)
	       	 {
	       	   cout<<endl<<"You requested more than in stock "<< user_name<<". You will recieve what is available.";
	       	   cout<<endl;
	       	    numBuy=numSquare;
	       	 }
	         numSquare-=numBuy;
	         priceTotal+=priceSquare*numBuy;
	       }
	    }
		else
	  	{
	  		cout<<"Your IQ is lower than current stock of the item which is 0 "<< user_name<<". To raise IQ, please try again\n"
	  			<<endl; 
	  	}
		break;
		case 5:
		if(numVitR)
	    {
	      cout<<"How many do you wish to buy "<<user_name<<"? ";cin>>numBuy;
	      if(numBuy<0)
	       {
	         cout<<"Stop Lowering your IQ"<< user_name<<"! INVALID NUMBER!"<<endl<<endl;
	         break;
	       }
	       else
	       {
	       	 if(numBuy>numVitR)
	       	 {
	       	   cout<<endl<<"You requested more than in stock "<< user_name<<". You will recieve what is available.";
	       	   cout<<endl;
	       	    numBuy=numVitR;
	       	 }
	         numVitR-=numBuy;
	         priceTotal+=priceVitR*numBuy;
	       }
	    }
		else
	  	{
	  		cout<<"Your IQ is lower than current stock of the item which is 0 "<< user_name<<". To raise IQ, please try again\n"
	  			<<endl; 
	  	}
		break;
		case 6:
		  //Nothing Happens here.
	  	break;
		default:
		cout<<"The item does not exist. Please enter a valid number."<<endl;
	}
  }while(user_input!=6);

  //Formats Correctly on Screen
  cout.setf(ios::fixed);cout.setf(ios::showpoint);cout.precision(2);

  //Calculates Amount of Tax and Final Amount
  //Tax is rounded up and stored as an int
  tax_on_total= (priceTotal*taxRate) + 0.5;
  priceFinal= tax_on_total+priceTotal;

  //Outputs price of the order. Asks user to input money.
  do
  {
  	cout<<endl<<"Customer: "<<user_name;
  	cout<<endl<<"Price Total  : $"<<priceTotal;
  	cout<<endl<<"Tax Rate[16%]: $"<<tax_on_total;
  	cout<<endl<<"Final Balance: $"<<priceFinal;
    cout<<endl<<"Insert Money : ";cin>>user_input;
    if(user_input<priceFinal) {cout<<endl<<"Please Enter an appropriate amount "<<user_name<<"."<<endl;}
  }while(user_input<priceFinal);

  //Change Calculation
  change=user_input-priceFinal;

  //Displays Change
  cout<<endl<<"Your change is $"<<change;
  cout<<endl<<"Have a nice day "<<user_name<<"!"<<endl;
  return 0;
}



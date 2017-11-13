// Programmer: Marky Santos-Tankia 
// Instructor Name: Dileep // Section:E // Date: 10/5/2016
// File: hw5_header.h 
//------------------------------------------------------------------------------
/*Description:
	Header file of hw5
*/
#ifndef HW5_HEADER_H
#define HW5_HEADER_H

using namespace std;
#include <iostream>


void greeting();
//Description: Greets user 
//Pre: None
//Post: Outputs message greeting user

void goodbye();
//Description: Signs off user
//Pre: None
//Post: Outputs message signing off user

float option1();
//Description: Asks user how much food 
//             in lb they wasted.
//Pre: None
//Post: Outputs messages and user inputs what is asked.
//		Returns food wasted by float

int option2();
//Description: Asks user if they use transport
//			   If so, asks how many miles. 
//Pre: None
//Post: Outputs messages and user inputs what is asked.
//		Returns transit miles by int

int option3();

//Description: Ask if Mr. Burns or relative.
//			   If not, age is asked.
//Pre: None
//Post: Outputs messages and user inputs what is asked.
//		Returns Age as an integer 

float option4(float waste);
//Description: Asks how many pigs they ate that week
//			   and uses an equation that uses the
//			   waste value and pig eaten value.
//Pre: The float variable waste from option1;
//Post: Outputs messages and user inputs what is asked.
//		Returns Farm-related Methane Production
//      value as an integer


float option5(float value,float mult,float add);
//Description: Modifies value with mult and add.
//Pre: All floats. All options must be completed
//	   at this point. 
//Post: Returns a modified value by multiplying
// 		with mult and adds with add.

#endif

// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/9/2016
// File: main.cpp
/*Description:

  Holds the debate. Ask questions. Candidates responds.
  Declares winner.
  
  **note on cstring, it is a struct i made in order to make an array
  of cstrings. This makes it easier to organize and use the lines from
  the files.
*/

//------------------------------------------------------------------------------
//note there are 15lines in the prefixes.
#include "header.h"

int main()
{
  //Initialize the cstring struct arrays
  cstring cand1sentences [MAXLINES];
  cstring cand1interjections [MAXLINES];
  cstring cand2sentences [MAXLINES];
  cstring cand2interjections [MAXLINES];
  cstring prefixes [MAXLINES];

  srand(time(NULL));
  greetings();

  //Stores all the lines into cstring arrays.
  insertLines(cand1sentences,"candidate1_sentences.dat");
  insertLines(cand1interjections,"candidate1_interjections.dat");
  insertLines(cand2sentences,"candidate2_sentences.dat");
  insertLines(cand2interjections,"candidate2_interjections.dat");
  insertLines(prefixes,"prefix_expressions.dat");

  //This the main part
  debate(cand1sentences,cand1interjections,cand2sentences,
        cand2interjections,prefixes);

  signOff();
  return 0;
}


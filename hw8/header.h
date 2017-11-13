// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 10/26/2016
// File: header.h
/*Description:
  header file of debate. Contains structs, constants and
  prototypes.
*/
#ifndef HEADER_H
#define HEADER_H

using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

const int MAXLINES=17+1;//Last one is null
const string NUMPREFIXLINES="15";
struct cstring
{
  char ntca[1000];
  bool isNull;
  int numWords;//num of words in array;
  int sizeofArray; //This is only for the first element of the array***
  //If true, the the last character is Null and marks end of cstring.
};
//------------------------------------------------------------------------------
//MISC
void greetings();
/*Description: Greets User 
  Pre: None
  Post:Ouputs greeting msg*/

void signOff();
/*Description: Signs Off User 
  Pre: None
  Post:Ouputs exit msg*/

int myRand(int min,int max);
/*Description: Generates a random number from min to max;
  Pre: Min and Max have to be positive. Max has to be greater
  than min.
  Post:Function will return a random integer from min to max inclusive.*/

//------------------------------------------------------------------------------

void debate(cstring cand1sentences [],cstring cand1interjections [],
            cstring cand2sentences [],cstring cand2interjections [],
            cstring prefixes []);
/*Description: Holds the debate. Ask questions. Candidates responds.
  Declares winner.
  Pre: All the arrays of cstring structs initialized earlier. insertLines must
  function properly or else the rest of the logic doesn't work.
  Post:Asks how many pairs of questions. Cycles through the question and 
  answer by how many pairs were given. Displays answers after each question
  by user and the candidates current score. After all questions are asked, 
  displays final scores and displays who won.*/

void insertLines(cstring response [], const string file);
/*Description: Fills response with cstring structs from data in file.dat
  Pre:response must be +1 greater than the number of lines in the file.dat.
  file has to have a valid .dat name and must be in the same directory as this
  functions.cpp
  Post:fills in the response array with the lines from file.dat. Sets every
  structvariable isNull to false except last one which contains no line
  from file.dat.*/

void clearPhrase(char answer[]);
/*Description: Clears the ntca up to \0. Still works if the phrase is empty.
  Pre: The ntca answer. 
  Post: Fills the ntca with \0 up until \0 (Essentially the length*/

void buildAnswer(char answer [], cstring sentences [],
  const cstring interjections [],const cstring prefixLines []);
/*Description: Builds the answer for the candidate returned by char answer []. 
  Pre: A cleared answer array. Cannot be full. Sentences have to be
  initialized before hand. Same as interjections and cstrings.
  Post: Randomly chooses number of sentences from 2-4. Builds an ntca around 
  this. A posssible prefix in the beginning and possible interjections between 
  each line. Each phrase is tacked on to the answer array. Spaces are 
  appropriately added.*/

void displayAnswer(char answer []);
/*Description: Displays the answer [].
  Pre: the answer []. It has to be filled or nothing will be outputted. No weird
  characters that might crash the program. Has to be an ntca.
  Post:Outputs character by character, what's inside answer [] up until '\0'*/

void selectPhrase(char phrase [],int parts,cstring line,int iteration);
/*Description: char array phrase is modified to have a sectioned off phrase
  from line determined by parts and the current iteration.
  Pre:an empty phrase character cleared by clearPhrase. parts has to be the 
  same as the number of sentences to be outputted (excluding prefix and 
  interjections). line has to be the random line selected from the candidates
  file. iteration is the current iteration or current phrase being made. 
  So the first phrase is the first iteration, second phrase second iteration,
  etc. parts range 2-4, iteration 1-4.
  Post:Selects an apporiate phrase from ctstring line. Calculates the number
  of words in equal parts. Rounds up always. Depending on iteration, caculates
  which word to start on and end at. Final iteration has special case.
  Calcalates min and max index from ntcaRange. From ntcaRange, characters
  from index min to max in line.ntca are stored into phrase array.*/

void ntcaRange(int & min,int & max,char ntca [],
               int numwordStart,int numwordEnd,
               bool lastIteration);
/*Description: Finds min and max index to be sectioned off.
  Pre: min and max are integers, presumably 0. ntca from the cstring line
  in selectPhrase (cannot be empty). numwordStart/End has to be within 0 to
  maxwords-1. Will crash if goes to max words. bool lastIteration is used
  to include the final word if it is true. 
  Post: finds min index depending on the first word to start at and max 
  index depending on numwordEnd to stop.(basically the min/max equals
  the character index before or after the designated nth word)
  lastIteration, if true, makes numwordEnd equals the last index of ntca*/

int findNumWords(const char sentence []);
/*Description: Returns total words in the ntca.
  Pre: an ntca from the the cstring being initialized array or any ntca that
  has at least one word. Cannot be empty.
  Post: returns the number of words in the ntca sentence*/

//------------------------------------------------------------------------------

void appendPrefix(const cstring prefixLines [], char answer []);
/*Description: 50% chance of adding a random prefix to answer
  Pre: the cstring array of prefixlines, an empty answer char array.
  Post: 50% chance of adding a prefix line into the answer char array*/

void appendInterjection(const cstring interjectionLines [], char answer []);
/*Description: 25% chance of adding a random interjection to answer
  Pre: the cstring array of interjection from that specific candidates answer
  being built. An answer with a phrase before it (not an interjection or
  another interjection). 
  Post: 25% chance of adding an interjection line into the answer char array*/

void replaceEndingPunctuation(char answer [], int length);
/*Description: Replaces ending punctuation with '!','?',or'.'
  Pre: a completed answer char array before replacing last punctuation. the 
  number of characters in answer char array.
  Post: Replacing the last character of answer aray with 
  -40% period,30% question mark,30% exclamation point.*/

//------------------------------------------------------------------------------
//For the score part.

float calculateScore(char fullAnswer[]);
/*Description: Calculates score word by word
  Pre: a full answer must be used.
  Post: returns the score calculated by the words and characters */

void getToken(char word[],const char fullAnswer[],int & index);
/*Description: modifies word to contain token.
  Pre: word can be empty or full. fullAnswer has to be the
  final answer. int index has to be 0 for the first word and
  increasing for every next word.
  Post: word is modified to contain from one space to another.
  So ",example! " is ",example!". Stops if a space is found.*/

int assignWordScore(char a []);
/*Description: returns score calculated from assigning score to char a
  and multipliers are possibly activated.
  Pre: a char array that contains no spaces
  Post: returns the score calculated by*/

int assignCharScore(char a);
/*Description: returns score from the character passed. Multipliers
  are possibly activated.
  Pre: any character that is not an escape character. Will only work
  if it's alphabet.
  Post: returns the assigned score of the character plus a possible
  multiplier*/

void concat(char target [],const char source []);
/*Description: adds from source to target
  Pre: a source that is not empty. target can be initially.
  Post:adds source to target and a space*/
  
#endif


// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // Date: 11/9/2016
// File: functions.cpp
/*Description:
   contains the functions of the debate
*/

#include "header.h"
//------------------------------------------------------------------------------
void greetings()
{
  cout<<"Welcome to Presidential Debates!"<<endl<<endl;
}

void signOff()
{
  cout<<endl<<endl<<"Have a nice day!"<<endl;
}

int myRand(int min,int max)
{
  return min + rand()%(max-min+1);
}

//------------------------------------------------------------------------------

void debate(cstring cand1sentences [],cstring cand1interjections [],
            cstring cand2sentences [],cstring cand2interjections [],
            cstring prefixes [])
{
  cout.precision(3); 
  char answer[1000];
  int numQuestions;
  float score1=0,score2=0;
  string random;
  bool invalidAnswer=false;
  do 
  {
  cout<<"How many pair of questions would you like to ask?(1=1question/candidate): ";
  cin>>numQuestions;

  if(numQuestions>0) //error checks range
   invalidAnswer=false;
  else
  {
    cout<<"Please input valid number."<<endl;
    invalidAnswer=true;
  }

}while (invalidAnswer==true);
  cout<<endl;
  cin.ignore();
  for(int i=0;i<numQuestions;i++)
  {
    //for candidate 1
    cout<<"Candidate 1--------------\n\n";
    cout<<"Question: ";
	  getline(cin,random);
    cout<<endl;
    clearPhrase(answer);//Get's rid of weird character in the beginning
    buildAnswer(answer,cand1sentences,cand1interjections,prefixes);
    displayAnswer(answer);
    cout<<endl;
    score1+=calculateScore(answer);
    cout<<endl<<"SCORE: "<< score1;
    clearPhrase(answer);
    //for candidate 2
    cout<<endl<<endl;
    cout<<"Candidate 2--------------\n\n";
    cout<<"Question: ";
    getline(cin,random);
    cout<<endl;
    buildAnswer(answer,cand2sentences,cand2interjections,prefixes);
    displayAnswer(answer);
    cout<<endl;
    score2+=calculateScore(answer);
    cout<<"SCORE: "<< score2;
    clearPhrase(answer);
    cout<<endl<<endl;
  }
  cout<<endl<<"FINAL SCORES:"<<endl;
  cout<<"Candidate 1: "<<score1<<endl;
  cout<<"Candidate 2: "<<score2<<endl<<endl;
  if(score1<score2)
    cout<<"Candidate 1 wins!";
  else if(score2<score1)
    cout<<"Candidate 2 wins!";
  else
    cout<<"It's a tie!";
}

void insertLines(cstring response [], const string file)
{
  ifstream fin;
  fin.open(file.c_str());
  //cout<<"Reading "<<file<<endl;
  string sentence;
  char numberofLines [3];
  if(file=="prefix_expressions.dat") //Special case for prefix file
    strcpy(numberofLines,NUMPREFIXLINES.c_str());
  else
    fin.getline(numberofLines,3); //Reads number of lines in the file

  //cout<<"There are "<<numberofLines<<" lines"<<endl;
  int numLines= atoi(numberofLines); //Converts to an int.
  int i;
  for(i=0;i<numLines;i++)
  {
    getline(fin,sentence);
    strcpy(response[i].ntca,sentence.c_str());
    
    response[i].numWords= findNumWords(sentence.c_str());//inputs numWords
    response[i].isNull=false;
  }
  response[i].isNull=true;//Last one is NULL to know that the array ends there.
  response[0].sizeofArray=numLines; //Self Explanatory.
              // Used to know sizeofArray. No reason to do it for all elements.

  fin.close();
}

void clearPhrase(char answer[])//Clears the ntca to be filled again.
{
  int length=strlen(answer);
  for(int i=0;i<length;i++)
    answer[i]='\0';
}
void buildAnswer(char answer [], cstring sentences [],
  const cstring interjections [],const cstring prefixLines [])
{
  char phrase[200];
  int numSentences= myRand(2,4);
  
  int RNG= myRand(0,sentences[0].sizeofArray-1);
  appendPrefix(prefixLines,answer);

  selectPhrase(phrase,numSentences,sentences[RNG],1);//first phrase
  concat(answer,phrase);
  clearPhrase(phrase);

  //the index is kinda wonky here but makes sense logically
  for(int i=2;i<=numSentences;i++) 
  {
    RNG= myRand(0,sentences[0].sizeofArray-1);
    appendInterjection(interjections,answer);

    selectPhrase(phrase,numSentences,sentences[RNG],i);
    concat(answer,phrase);
    clearPhrase(phrase);
  }
  //For ending punctuation
  int answerLength=strlen(answer);
  replaceEndingPunctuation(answer,answerLength);
  //add '\0' at the end
  answer[answerLength-1]='\0';
}

void displayAnswer(char answer [])
{
  int length=strlen(answer);
  for(int i=0;i<length;i++)
  {
    cout<<answer[i];
  }
}

//Parts is how many to divide the phrase by
void selectPhrase(char phrase [],int parts,cstring line,int iteration)
{
  int min=0,max=0;

  //rounds up
  int wordsineachSection= (static_cast<float>(line.numWords)/parts)+0.99;

  //Calculate the position of wordmin and wordmax in terms of word
  int numwordStart,numwordEnd;
  bool lastIteration=false;
  if(iteration==1)//if first iteration
  {
    numwordStart=0; //Start from first word, which is index 0
    numwordEnd=wordsineachSection;//Stop at the xth word.
  }
  else if (iteration==parts)//if this is the final iteration
  {
    numwordStart=wordsineachSection*(iteration-1);
    numwordEnd=(line.numWords-1); //go until '\n' essentially
    lastIteration=true;
  }
  else //These are in between iterations
  {
    numwordStart=wordsineachSection*(iteration-1);
    numwordEnd=wordsineachSection*(iteration);
    //So lets say 24 words,3 parts. Therefore, wordsineachSection=8
    //Iteration is 2.
    //numwordStart should equal 8. numwordEnd=16;
  }
  //cout<<"ITERATION: "<<iteration<<endl<<endl;
  ntcaRange(min,max,line.ntca,numwordStart,numwordEnd,lastIteration); //Find the min,max indexes.

  //modify phrase;
  int j=0;//this for the phrase;
  for(int i=min;i<=max;i++)
  {
    phrase[j]=line.ntca[i];
    j++;
  }
  if(!(iteration==parts))//if not last iteration
    j--;
  phrase[j]='\0'; //Makes ntca
  
}

void ntcaRange(int & min,int & max,char ntca [],
               int numwordStart,int numwordEnd,
               bool lastIteration)
{
  int i=0, wordCount=0;

  //find the min index
  while(wordCount!=numwordStart)
  {
    if(ntca[i]==' ')
    {
      wordCount++;
      //cout<<"Min Word Count: "<<wordCount<<endl;
    }
    i++;
  }
  min=i;
  //cout<<"FIRST CHARACTER: ["<<ntca[i]<<"]"<<endl;
  //cout<<"FINAL Min Word Count: "<<wordCount<<endl;
  //cout<<"FINAL Min Word Index: "<<min<<endl<<endl;
  //find the max index
  while(wordCount!=numwordEnd)
  {
    if(ntca[i]==' ')
    {
      wordCount++;
      //cout<<"Max Word Count: "<<wordCount<<endl;
    }
    i++;
  }
  i--;
  if(lastIteration==true)
    i=strlen(ntca);
  max=i;

  //cout<<"\n["<<ntca[i-3]<<ntca[i-2]<<ntca[i-1]<<ntca[i]<<ntca[i+1]<<"]"
  //    <<endl;
  //cout<<"LAST CHARACTER: ["<<ntca[i]<<"]"<<endl;
  //cout<<"FINAL Max Word Count: "<<wordCount<<endl;
  //cout<<"FINAL Max index:"<<max<<endl<<endl;
}

int findNumWords(const char sentence [])//This works
{
  int word=0, length=strlen(sentence);
  for(int i=0;i<length;i++)
  {
    if(sentence[i]==' ')
      word++;
  }
  word++;//This is for the last word in the sentence or if there is only
        //One word in the line.
  //cout<<"There are "<<word<<" words in the sentence"<<endl;
  return word;
}
//------------------------------------------------------------------------------

//requires the prefix cstring array
void appendPrefix(const cstring prefixLines [], char answer [])
{
  //50% chance of appending
  int RNG= myRand(1,100);
  if(RNG>50)
  {
    RNG=myRand(0,14);//these are 15lines
    concat(answer,prefixLines[RNG].ntca);
  }
}

void appendInterjection(const cstring interjectionLines [], char answer [])
{
  //25% chance of appending
  int RNG= myRand(1,100);
  if(RNG<=25)
  {
    RNG=myRand(0,interjectionLines[0].sizeofArray-1);
    concat(answer,interjectionLines[RNG].ntca);
  }
}

void replaceEndingPunctuation(char answer [], int length)
{
  int RNG= myRand(1,100);
  if(RNG>60)//Period 40% Chance
    answer[length-2]='.';
  else if(RNG>30)//Question Mark 30% Chance
    answer[length-2]='?';
  else if(RNG>0)//Exclamation Point 30% Chance
    answer[length-2]='!';
}

//------------------------------------------------------------------------------
//Score calculating section
float calculateScore(char fullAnswer[])
{
  float score=0;
  int i=0,length=strlen(fullAnswer);
  char word[20]; //has to be +1 greater than biggest word in the speech
  do
  {
    getToken(word,fullAnswer,i);
    score+=assignWordScore(word);
    i++;
    //cout<<"CURRENT SCORE-----: " <<score<<endl;
  }while(i<length && fullAnswer[i]!='\0');
  cout<<endl;
  cout<<"Score before dividing: "<<score<<endl;
  cout<<"Number of Characters: "<<length<<endl;
  score/=strlen(fullAnswer);
  //Divides score by how many characters are in the array
  return score;
}
void getToken(char word[],const char fullAnswer[],int & index)
{
  int i=0;
  while(fullAnswer[index]!=' ' && fullAnswer[index]!='\0')
  {
  	//cout<<fullAnswer[index]<<"-";
    word[i]=fullAnswer[index];
    i++;
    index++;
    //cout<<"Current Index "<<index<<endl;
  }
  word[i]='\0';
}

int assignWordScore(char a [])
{
  int score=0, length=strlen(a);
  for(int i=0;i<length;i++)
  {
    if(isalpha(a[i])) //Alphabet only
      score+=assignCharScore(a[i]);
  }
  int RNG=myRand(1,100);
  if(RNG<=5)//5%
   score*=2;
  else if(RNG<=7)//2%
   score*=3;
  //cout<<"WORD SCORE: "<<score<<endl;
  return score;
}
int assignCharScore(char a)
{
  int score=0;
  char lower=tolower(a);
  switch(lower)
  {
    case 'e':
    case 'a':
    case 'i':
    case 'o':
    case 'n':
    case 'r':
    case 't':
    case 'l':
    case 's':
    case 'u':
      score=1;
      break;
    case 'd':
    case 'g':
      score=2;
      break;
    case 'b':
    case 'c':
    case 'm':
    case 'p':
      score=3;
      break;
    case 'f':
    case 'h':
    case 'v':
    case 'w':
    case 'y':
      score=4;
      break;
    case 'k':
      score=5;
      break;
    case 'j':
      score=8;
      break;
  }
  int RNG=myRand(1,100); //Cannot have both modifiers. Only one.
  if(RNG<=2)//2%
    score*=3;
  else if(RNG<=5)//3%
    score*=2;
  //cout<<"CURRENT LETTER: "<<a<<" SCORE: "<<score<<endl;
  return score;
}


void concat(char target [],const char source [])
{
  strncat(target,source,strlen(source));
  strcat(target," ");
}

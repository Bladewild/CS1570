// Programmer: Marky Santos-Tankia
// Instructor Name: Dileep // Section:E // 12/6/2016
// File: main.cpp
/*   Description:
   Simulates an activist in a town that chases a polluter. Cops and roots
   are on the ground. Activist will pursue polluter until inactive triggers
   occur. Will move randomy if toxicity reaches a certain level. Outputs
   the map, dignity and toxicity for only DAYS_TO_SHOW. Major events to 
   activist will always be outputted. After x number of simulation of days
   have occured, the data is outputed by percentages.
*/
                                                   
#include "header.h"

int main()
{
	    
  srand(time(NULL));
  ifstream fin;
  fin.open("config.dat");
  int gridSize,numRoots,numCops,numDays,digLossBump,digLossCop;
  fin>>gridSize>>numRoots>>numCops>>numDays>>digLossBump>>digLossCop;
  int days=1;
  float perExit=0,perWacked=0,perSuccess=0,perDeath=0,avgTox=0; 
  fin.close(); //These are the stats
  cout<<"----------POLLUTER CHASE------------\n\n";
  do 
  {
    cout<<"Simulating Day ["<<days<<"]"<<endl
        <<"--------------------"<<endl;
    simulation(gridSize,numRoots,numCops,digLossBump,digLossCop,
              perExit,perWacked,perSuccess,perDeath,avgTox,days);
    days++;
  	//cout<<days/static_cast<float>(numDays)*100.0<<"% Done";
  	//system("cls");
  }while(days<=numDays);
  const float per=100;
  //Report Results
  //Sleep(1000);
  //system("cls");
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout<<"----------------------------------\n\n";
  cout<<"Percentages for "<<numDays<<" days"<<endl;
  cout<<"----------------"<<endl;
  cout<<"Exits:        "<<perExit/numDays*per<<"%"<<endl;
  cout<<"Wacked Out:   "<<perWacked/numDays*per<<"%"<<endl;
  cout<<"Success:      "<<perSuccess/numDays*per<<"%"<<endl;
  cout<<"Death:        "<<perDeath/numDays*per<<"%"<<endl;
  cout.precision(4);
  cout<<"Avg Toxicity: "<<avgTox/numDays<<endl;

  cout<<"\nPROGRAM EXITING--------------------"<<endl;
                                                                                                          
  return 0;
}

// represents one day/run/chase/whatever...and hopefully many many truffles
void simulation(const int gridSize,const int numRoots,const int nmCops,
                int digLossBump,int digLossCop, float & perExit,
                float & perWacked,float & perSuccess,float & perDeath, 
                float & avgTox,int day) 
{
  const int numCops=nmCops;
  int currentRootStock=numRoots; //This is used to decrease availabe roots.
  int iteration=1;
  bool active=true;
  char cause=' ';

  town springfield(gridSize);
  activist lisa("Lisa",'L'); 
  lisa.setDignityLosses(digLossBump,digLossCop);
  polluter homer("Homer",'H');
  root listofRoots [MAX_ROOTS];

  for(int i=0;i<numRoots;i++)
  {
    listofRoots[i]= root();
    //cout<<listofRoots[i].type<<": "<<listofRoots[i].effect<<endl;
  }

  lisa.placeMeInMiddle(springfield);
  homer.place_me(springfield);
  placeCharacters('R',numRoots,springfield); //Places Roots
  placeCharacters('C',numCops,springfield); //Places Roots

  //cout<<"diffPosX:  "<<" diffPosY:"<<endl;
  //cout<<"X: "<<" Y:"<<endl;
  do
  {
    if(day<=DAYS_TO_SHOW)
    {
      cout<<endl<<"Day "<<day<<endl;
      cout << springfield << endl;
      cout<<"Turn: "<<iteration<<endl;   
      iteration++;
    } 
    checkRoot(lisa,listofRoots,currentRootStock,day);
    checkDignity(lisa,day);
    cause=checkActive(active,homer,lisa,springfield,day);
    if(day<=DAYS_TO_SHOW)
    {
      cout<<"Current Dignity: "<<lisa.getDignity()<<endl;
      cout<<"Current Toxicity: "<<lisa.getToxicity()<<endl;
      //Sleep(200);
      //system("cls");
    }
    if(active==true)
    {
      homer.randMove(springfield);   
      lisa.move(springfield,homer);
    }
  } while (active); //continue if active true 
    //system("cls");
    switch(cause)
    {
      case 'e'://exits
        perExit++;
        break;
      case 'c'://catches polluter
        perSuccess++;
        break;
      case 'd'://dies
        perDeath++;
        break;
      case 'i'://gone
        perWacked++;
        break;
    }
    avgTox+=lisa.getToxicity();
    cout<<endl;
    cout<<"Final Dignity: "<<lisa.getDignity()<<endl;
    cout<<"Final Toxicity: "<<lisa.getToxicity()<<endl<<endl;
}


void checkDignity(activist & a,int day) 
{
  if(a.bumpingintoWall==true)
  {
    a.setDignity(a.getDignity()-a.digLossBump); //Death by dignity is 
    cout<<"Activist is bumping into a wall.";   //checked somewhere else
    if(day>DAYS_TO_SHOW)
      cout<<endl;
    a.bumpingintoWall=false;
  }
  if(a.onCop==true) 
  {//This is detached because possibility of activist staying on tile 
    a.setDignity(a.getDignity()-a.digLossCop);
    cout<<"Activist is talking to a cop.";
    if(day>DAYS_TO_SHOW)
      cout<<endl;
  }
}

char checkActive(bool & active,polluter & p,activist & a,town & t,int day) 
{
  string causeofInactive=" ";
  char cause;
  //the activist exits the town 
  if( (t.tile[a.tile.y][a.tile.x-1] =='W' 
    && t.tile[a.tile.y][a.tile.x+1]=='W') ||  //Horizontal exits WEW
     (t.tile[a.tile.y-1][a.tile.x] =='W'                     //W
    && t.tile[a.tile.y+1][a.tile.x]=='W') )  //Vertical exits  E
                                                           //W
  {
    active=false;
    causeofInactive="Activist has exited.";
    cause='e';
  }
  else if(p.tile.y==a.tile.y && p.tile.x==a.tile.x)  //catches the polluter
  {
    active=false;   
    causeofInactive="Activist has caught the polluter.";
    cause='c';
  }
  else if(a.getDignity()<=0) //dies of supreme indignity
  {
    active=false;
    causeofInactive="Activist has died of Supreme Indignity.";
    cause='d';
  }
  else if(a.getToxicity()>=0.25)
  {
    active=false;
    if(day<=DAYS_TO_SHOW)
      causeofInactive="\nActivist is gone.";
    else
      causeofInactive="Activist is gone.";
    cause='i';
  }

  if(day<=DAYS_TO_SHOW && causeofInactive!=" ")
  {
    cout<<causeofInactive<<endl;
    //Sleep(1500);
  }
  else if(day>DAYS_TO_SHOW && causeofInactive!=" ")
  {
    cout<<causeofInactive<<endl;
  }
  else if(day<=DAYS_TO_SHOW)
    cout<<endl;
    
  return cause;
  //becomes over-intoxicated by roots
}

void checkRoot(activist & a,root listofRoots [],
               int & currentRootStock,int day)
{
  if(a.onRoot==true && currentRootStock!=0)
  {
    root selectedRoot=listofRoots[currentRootStock-1];
    a=a+selectedRoot;
    a.onRoot=false;
      cout<<"Activist has eaten a "<<selectedRoot.type<<" with "
          <<selectedRoot.effect<< " toxicity.";
    if(day<=DAYS_TO_SHOW)
    {
      //Sleep(750);
    }
    else if(day>DAYS_TO_SHOW)
    {
      cout<<endl;
    }
    currentRootStock--;

    if(a.getToxicity()<=0.0) //cannot have negative toxicity
      a.setToxicity(0.0);
  }
}


void placeCharacters(char c,int numChar,town & t)
{
  const int MIN=1,MAX=2;
  for(int i=0;i<numChar;i++)
  {
    int newX,newY;
    //Places randomly inside the map,within walls. Nothing on top
    do
    {
      //This spawns within walls
      newX=rand()%(t.getmapSize()-MAX)+MIN;
      newY=rand()%(t.getmapSize()-MAX)+MIN;
      //Cannot spawn on acivist or root
    }while(t.tile[newX][newY]!=' ');
    t.tile[newX][newY]=c;
  }
}

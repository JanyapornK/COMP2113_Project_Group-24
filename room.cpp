#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "room.h"
using namespace std;

struct Room{
  string name;
  bool win;
  bool key;
  bool arrived; //t=user already got in before
};

void printChoices(vector <Room> places){
  cout<<"I wonder where the keys are..."<<endl;
  cout<<"Where should I go? (Enter the place)";
  int count=0; //no of room not yet arrived
  for (int i=0;i<places.size();i++){
    if (places[i].arrived==false){
      count+=1;}
  }
  int counter=0;
  //print places that not yet arrived
  for (int i=0;i<places.size();i++){
    if (places[i].arrived==false){
      counter+=1;
      if (counter != count){
        cout<<places[i].name<<"/ ";
      }else if (counter == count){
      cout<<places[i].name<<endl;
      }
    }
  }
}

int main(){
  string name[]={"Canteen","Library","Classroom","Common room"};
  vector <Room> places; 

  srand((unsigned)time(NULL));
  int random=(rand()%4); //random generate one room having key

  for (int i=0;i<sizeof(name) / sizeof(name[0]);i++){ //initialise rooms
    Room r;
    r.name=name[i];
    r.win=false;
    r.arrived=false;
    if (i==random){
      r.key=true;}
    else{
      r.key=false;}
    places.push_back(r);
  }

bool gameover = false;
while (true){
  printChoices(places); //print rooms that is unarrived by user
  string input;
  cin>>input;
  transform(input.begin(), input.end(), input.begin(), tolower); 
  if (input=="canteen" && places[0].arrived==false){
    /*battle
    if (win = true && place[0].key == true){
      break;}
    else if (win = true && key == false){ 
      place[0].arrived = true;
      continue;}
    else if (win = false){ 
      gameover=true;
      cout<<"Ouch!! I was caught! (GAME OVER)"<<endl;
      break;}
      */
  } else if (input=="library" && places[1].arrived==false){
    //battle
  }else if (input=="classroom" && places[2].arrived==false){
    //battle
  }else if (input=="common room" && places[3].arrived==false){
    //battle
  }else {
    cout<<"Maybe I should choose another place to go... (Re-enter a place)"<<endl; //re-choose
  }

  return gameover ? 1 : 0;
}
    
return 0;
}

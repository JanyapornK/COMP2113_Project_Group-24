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

bool checkValidInput(string input, vector <Room> places){
  string roomname;
  for (Room r:places){
    roomname=r.name;
    transform(roomname.begin(), roomname.end(), roomname.begin(), tolower); 
    if (roomname==input && r.arrived==false){
      return true;
    }

  }
  return false;
}

int Rmain(){
  string name[]={"Canteen","Library","Classroom","Common room"};
  vector <Room> places; 

  srand((unsigned)time(NULL));
  int random=(rand()%4); //random generate one room having key

  for (int i=0;i<4;i++){ //initialise rooms
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
while (gameover==false){
  printChoices(places); //print rooms that is unarrived by user
  string input;
  cin>>input;
  transform(input.begin(), input.end(), input.begin(), tolower); 
  
  if (checkValidInput(input,places)==false){
    cout<<"The place is invalid. Maybe I should choose another place to go... (Re-enter a place)" <<endl; //rechoose
  }else{
 
    if (input=="canteen"){
      /*battle
      if (win = true && places[0].key == true){
        break;}
      else if (win = true && places[0].key == false){ 
        places[0].arrived = true;
        continue;}
      else if (win = false){ 
        gameover=true;
        cout<<"Ouch!! I was caught! (GAME OVER)"<<endl;
        break;}
        */
    } else if (input=="library"){
      //battle
    }else if (input=="classroom"){
      //battle
    }else if (input=="common room"){
      //battle
    }

}
    
return gameover ? 1 : 0; // Return 1 if gameover
}

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "room.h"
#include "battle.h"
using namespace std;

struct Room{
  string name;
  bool key;
  bool arrived; //t=user already got in before
};

void printChoices(vector <Room> places){
  cout<<"Where are the keys...?"<<endl;
  cout<<"Where would you go? (Enter the place)";
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

int Rmain(character *playerCharacter, character opponent){
  string name[]={"Canteen","Library","Classroom","Common room"};
  vector <Room> places; 

  srand((unsigned)time(NULL));
  int random=(rand()%4); //random generate one room having key

  for (int i=0;i<4;i++){ //initialise rooms
    Room r;
    r.name=name[i];
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
    cout<<"The place is invalid. Choose another place to go... (Re-enter a place)" <<endl; //rechoose
  }else{
 
    if (input=="canteen"){
      bool result = BATTLE_RESULT(*playerCharacter, opponent);
      if (result = true && places[0].key == true){
        cout<<"You defeated the opponent, and the key is here!"<<endl;
        break;}
      else if (result = true && places[0].key == false){ 
        places[0].arrived = true;
        cout<<"You defeated the opponent, but the key is not here. Maybe it is in the other room."<<endl;
        continue;}
      else if (result = false){ 
        gameover=true;
        cout<<"You were defeated! (GAME OVER)"<<endl;
        break;}
    } else if (input=="library"){
      bool result = BATTLE_RESULT(*playerCharacter, opponent);
      if (result = true && places[1].key == true){
        cout<<"You defeated the opponent, and the key is here!"<<endl;
        break;}
      else if (result = true && places[1].key == false){ 
        places[0].arrived = true;
        cout<<"You defeated the opponent, but the key is not here. Maybe it is in the other room."<<endl;
        continue;}
      else if (result = false){ 
        gameover=true;
        cout<<"You were defeated! (GAME OVER)"<<endl;
        break;}
    }else if (input=="classroom"){
      bool result = BATTLE_RESULT(*playerCharacter, opponent);
      if (result = true && places[2].key == true){
        cout<<"You defeated the opponent, and the key is here!"<<endl;
        break;}
      else if (result = true && places[2].key == false){ 
        places[0].arrived = true;
        cout<<"You defeated the opponent, but the key is not here. Maybe it is in the other room."<<endl;
        continue;}
      else if (result = false){ 
        gameover=true;
        cout<<"You were defeated! (GAME OVER)"<<endl;
        break;}
    }else if (input=="common room"){
      bool result = BATTLE_RESULT(*playerCharacter, opponent);
      if (result = true && places[3].key == true){
        cout<<"You defeated the opponent, and the key is here!"<<endl;
        break;}
      else if (result = true && places[3].key == false){ 
        places[0].arrived = true;
        cout<<"You defeated the opponent, but the key is not here. Maybe it is in the other room."<<endl;
        continue;}
      else if (result = false){ 
        gameover=true;
        cout<<"You were defeated! (GAME OVER)"<<endl;
        break;}
    }

}
    
return gameover ? 1 : 0; // Return 1 if gameover
}

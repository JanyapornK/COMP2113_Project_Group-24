#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "room.h"
#include "battle.h"
#include "character.h"

using namespace std;

//change the all character of the word to lower case
string upperToLower(string &word){
  for (int i=0;i<word.length();i++){
    if (word[i]>=65 && word[i]<=90){
      word[i]=word[i]+32;
    }
  }
    return word;
}

//print out all choices that can be chosen by user
void printChoices(const vector <Room> &places){
  cout<<"Where are the keys...?"<<endl;
  cout<<"Where would you go? (Enter the place) ";
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
        cout<<places[i].name<<" / ";
      }else if (counter == count){
      cout<<places[i].name<<endl;
      }
    }
  }
}
  
    

//check if the input of the user is valid  
bool checkValidInput(const string& input, const vector<Room>& places)
{
  string roomname;
  for (Room r : places)
  {
    roomname = r.name;
    //transform(roomname.begin(), roomname.end(), roomname.begin(), tolower); 
    roomname=upperToLower(roomname);

    if (roomname == input && r.arrived == false)
    {
      return true;
    }
  }
  return false;
}

int Rmain(character *playerCharacter){
  vector<string> name = { "Canteen", "Library", "Classroom", "Common room" };
  vector<Room> places; 

  srand((unsigned)time(NULL));
  int random = rand() % 4; // Random generate one room having key

  for (int i = 0; i < 4; i++)
  { 
    // Initialise rooms
    Room r;
    r.name = name[i];
    r.arrived = false;
    r.key = (i == random);

    // Initialising rooms' opponents
    int oppHealth = 25;
    int oppAttack = rand() % 10 + 1;
    int oppDefence = rand() % 10 + 1;
    int oppIntelligence = rand() % 10 + 1;
    // Ensuring that room minibosses have only one stat above 5
    int statsAboveFive = 0;
    if (oppAttack > 5) statsAboveFive++;
    if (oppDefence > 5) statsAboveFive++;
    if (oppIntelligence > 5) statsAboveFive++;
    // Adjusting stats to meet the above requirement
    while (statsAboveFive > 1)
      {
        if (oppAttack > 5)
        {
          oppAttack = rand() % 5 + 1;
          statsAboveFive--;
        }
        if (statsAboveFive <= 1) break;
        if (oppDefence > 5)
        {
          oppDefence = rand() % 5 + 1;
          statsAboveFive--;
        }
        if (statsAboveFive <= 1) break;
        if (oppIntelligence > 5)
        {
          oppIntelligence = rand() % 5 + 1;
          statsAboveFive--;
        }
      }
    r.opponent = character("Guard", oppHealth, oppAttack, oppDefence, oppIntelligence);
    
    places.push_back(r);
  }

  bool gameover = false;
  while (!gameover)
  {
    printChoices(places); // Print unvisited rooms
    string input;
    getline(cin >> ws, input);
    //transform(input.begin(), input.end(), input.begin(), tolower); 
    input=upperToLower(input);
    if (!checkValidInput(input, places))
    {
      cout << "The place is invalid or already visited, Choose another place to go... (Re-enter a place)" << endl; 
    }
    else
    {
      int roomIndex = -1;
      for (int i = 0; i < places.size(); i++)
      {
        string roomname = places[i].name;
        //transform(roomname.begin(), roomname.end(), roomname.begin(), tolower());
        roomname=upperToLower(roomname);
        if (roomname == input)
        {
          roomIndex = i;
          break;
        }
      }
  
      if (roomIndex == -1)
      {
        cout << "An error occured. Please try again." << endl;
        continue;
      }
      Room& currentRoom = places[roomIndex];
  
      // Start battle with the opponent in the room
      bool result = BATTLE_RESULT(playerCharacter, currentRoom.opponent);
    
      if (result) // Player won the battle
      {
        currentRoom.arrived = true;
        if (currentRoom.key) // Key is in current room
        {
          cout << "You defeated the opponent, and the key is here!" << endl;
          break;
        }
        else
        {
          cout << "You defeated the opponent, but the key is not here. Maybe it is in the other room." << endl;
        }
      }
      else // Player lost the battle
      {
        gameover = true;
        cout << "You were defeated! (GAME OVER)" << endl;
        break;
      }
    }
  }
  
  return gameover ? 1 : 0; // Return 1 if gameover, 0 if key is found
}

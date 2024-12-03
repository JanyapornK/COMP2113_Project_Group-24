#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "character.h"

using namespace std;

struct Room
{
  string name;
  bool key;
  bool arrived;
  character opponent;
};

void printChoices(const vector<Room>& places);
bool checkValidInput(const string& input, const vector<Room>& places);
int Rmain(character* playerCharacter);

#endif

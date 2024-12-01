#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
struct Room{
  string name;
  bool win;
  bool key;
  bool arrived; }

void printChoices(vector <Room> places);

#endif

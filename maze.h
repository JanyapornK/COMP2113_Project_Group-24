#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
using namespace std;

class Maze {
public:
  Maze(const vector<string>& layout);           // Constructor to load a fixed maze
  void play();                                  // Maze gameplay                             
  void displayMaze() const;                     // Display the current maze
  bool move(char direction);              // Move the player (w, a, s, d)
  bool isExitReached() const;                   // Check if the player has reached the exit

private:
  vector<string> mazeLayout;          // 2D representation of the maze
  int playerR, playerC;               // Player's current position
};

#endif

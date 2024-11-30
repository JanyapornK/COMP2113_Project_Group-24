#include "Maze.h"
#include <iostream>
#include <vector>
using namespace std;

Maze::Maze(int scenario){
  // Define two fixed mazes for different parts of the game
  if(scenario = 1){
    mazeLayout = {
      "###########",
      "#     # # #",
      "###   # # #",
      "S   #   # #",
      "######  # #",
      "#       # #",
      "# ####### #",
      "#    #    #",
      "# ##      E",
      "##########F"
    };
  } else if (scenario = 2) {
    mazeLayout = {
      "############",
      "S          #",
      "# # #####  #",
      "# #     #  #",
      "# # ### #  #",
      "# # #   #  #",
      "# # # ###  #",
      "### #   ####",
      "#   ##     #",
      "# ###  #####",
      "#      #   #",
      "# ###### # #",
      "#          #",
      "#########  #",
      "#          E",
      "############",
    };
  }
  
  for (size_t i = 0; i < mazeLayout.size(); ++i) {
    for (size_t j = 0; j < mazeLayout[i].size(); ++j) {
      if (mazeLayout[i][j] == 'P') {
        playerX = i;
        playerY = j;
      }
    }
  }
  return;
}

void Maze::displayMaze() const {
  for (const auto& row : mazeLayout) {
    cout << row << endl;
  }
}

bool Maze::move(char direction) {
  return false;
}

bool Maze::isExitReached() const {
  return false;
}

void Maze::play() {
  return;
}

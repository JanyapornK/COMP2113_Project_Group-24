#include "maze.h"
#include <iostream>
#include <vector>
using namespace std;

Maze::Maze(int scenario){
  // Define two fixed mazes for different parts of the game
  if(scenario == 1){
    mazeLayout = {
      "###########",
      "#     # # #",
      "###   # # #",
      "P   #   # #",
      "######  # #",
      "#       # #",
      "# ####### #",
      "#    #    #",
      "# ##      E",
      "###########"
    };
    // Set the player's starting position ('P')
    playerR = 3;
    playerC = 0;
    return;
  } else if (scenario == 2) {
    mazeLayout = {
      "############",
      "P          #",
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
    // Set the player's starting position ('P')
    playerR = 1;
    playerC = 0;
    return;
  }
}

void Maze::displayMaze() const {
  for (const auto& row : mazeLayout) {
    cout << row << endl;
  }
}

bool Maze::move(char direction) {
  int newR = playerR, newC = playerC;
  // Calculate new position based on direction
  switch (direction) {
    case 'w': newR--; break;  // Move up
    case 'a': newC--; break;  // Move left
    case 's': newR++; break;  // Move down
    case 'd': newC++; break;  // Move right
    default: return false;    // Invalid input
  }
  if (newR >= 0 && newR < mazeLayout.size() && newC >= 0 && newC < mazeLayout[newR].size()) {
    char targetCell = mazeLayout[newR][newC];
    if (targetCell == ' ' || targetCell == 'E') {
      // Update player's position
      mazeLayout[playerR][playerC] = ' ';  // Clear old position
      playerR = newR;
      playerC = newC;
      mazeLayout[playerR][playerC] = 'P';  // Mark new position
      return true;
    }
  }
  return false; // Invalid move
}

bool Maze::isExitReached() const {
  return mazeLayout[playerR][playerC] == 'E';
}

void Maze::play() {
  cout << "Welcome to the Maze! Use w (up), a (left), s (down), d (right) to move." << endl;
  while (!isExitReached()) {
    displayMaze();  // Show the maze
    cout << "Enter your move: ";
    char moveChar;
    cin >> moveChar;
    if (!move(moveChar)) {
      cout << "Invalid move! Try again." << endl;
    }
  }
  cout << "Congratulations! You have reached the exit!" << endl;
  return;
}

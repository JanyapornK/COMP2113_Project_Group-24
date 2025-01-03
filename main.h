#ifndef MAIN_H
#define MAIN_H

#include "character.h"
#include "room.h"
#include "maze.h"
#include "battle.h"
#include <string>
#include <vector>

char menu(); // Displays the main menu and gets user choice
void backgroundStory(); // Displays the game's background story
void startNewGame(); // Starts a new game session
void loadGame(); // Loads a previously saved game
void saveGame(); // Saves the game state

#endif

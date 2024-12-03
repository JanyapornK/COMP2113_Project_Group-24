#include <iostream>
#include "character.h"
#include "room.h"
#include "maze.h"
#include "battle.h"

using namespace std;

char menu() 
{
    char choice;
    // Print the selection menu;
    cout << "**********************************" << endl;
    cout << "Welcome to HKU mission impossible!" << endl;
    cout << "**********************************" << endl;
    cout << "1. New game." << endl;
    cout << "2. Load game." << endl;
    cout << "3. Exit." << endl;

    cin >> choice;
    cout << endl;

    return choice;
}

void startNewGame() {
    // Choose the character
    character* playerCharacter = character::selectCharacter();

    if (playerCharacter) {
        cout << "You have selected the following character: " << endl;
        playerCharacter->displayStats();

        //go to room.cpp to find key
        Rmain();
        // Scenario 1: Solve the maze to enter the professor's office
        cout << "You must solve the maze to enter the professor's office!" << endl;
        Maze mazeEnter(1);
        mazeEnter.play();

        // Scenario 2: Solve the maze to escape after stealing the exam paper
        cout << "You must solve the maze to escape the building!" << endl;
        Maze mazeOut(2);
        mazeOut.play();

        character opponent();
        if (BATTLE_RESULT(*playerCharacter, opponent)) {
            cout << "You defeated the opponent!" << endl;
        }
        else {
            cout << "You were defeated!" << endl;
        }

        delete playerCharacter; // Clean up dynamically allocated memory
    }
    else {
        cout << "Error selecting character." << endl;
    }
}

void loadGame() {

}
                    
                
int main() 
{
    char choice = menu();
    while (choice != '3') 
    {
        switch (choice)
        {
            case '1':
                startNewGame(); // Start a new game
                break;
            
            case '2':
                loadGame(); //load the previous saved game progress
                break;
            
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
        }
        choice = menu();
    }
    cout << "Hope you enjoyed the game!" << endl;

    return 0;
}


#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
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

int backgroundStory() {
    cout << "A rumor spreads through the campus about the professor losing his office key." << endl;
    this_thread::sleep_for(chromo::seconds(1)); // Delay for 1 second
    cout << "Whispers suggest that finding the key grants access to exam papers for better results." << endl;
    this_thread::sleep_for(chromo::seconds(1)); // Delay for 1 second
    cout << "Students are tempted by the opportunity and embark on a clandestine quest to locate the missing key." << endl;
    this_thread::sleep_for(chromo::seconds(1)); // Delay for 1 second
    cout << "Now hurry up and be the first person to find the key!!!" << endl;
    
    return 0;
}

void startNewGame() {
    backgroundStory();
    
    // Choose the character
    character* playerCharacter = character::selectCharacter();

    if (playerCharacter) {
        cout << "You have selected the following character: " << endl;
        playerCharacter->displayStats();

        // Go to room.cpp to find the key
        Rmain();
        
        // Scenario 1: Solve the maze to enter the professor's office
        cout << "You must solve the maze to enter the professor's office!" << endl;
        Maze mazeEnter(1);
        mazeEnter.play();

        // Scenario 2: Solve the maze to escape after stealing the exam paper
        cout << "You must solve the maze to escape the building!" << endl;
        Maze mazeOut(2);
        mazeOut.play();

        // Battle system
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
    ifstream infile("savegame.txt");
    
    if (!infile) {
        cout << "No saved game found." << endl;
        return;
    }

    string name;
    int health, maxHealth, attack, defence, intelligence;
    int currentScenario;

    // Read the character data from the file
    infile >> name >> health >> maxHealth >> attack >> defence >> intelligence >> currentScenario;

    // Load game state (e.g., current scenario)
    Maze maze(currentScenario);
    maze.play(); // Enter the maze gameplay

    // Clean up
    delete playerCharacter;
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
                loadGame(); // Load the previous saved game progress
                break;
            
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
        }
        
        choice = menu(); // Show the menu again
    }
    
    cout << "Hope you enjoyed the game!" << endl;

    return 0;
}

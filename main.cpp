#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "character.h"
#include "room.h"
#include "maze.h"
#include "battle.h"

using namespace std;

// Print the selection menu
char menu() {
    char choice;
    cout << "**********************************" << endl;
    cout << "Welcome to HKU mission impossible!" << endl;
    cout << "**********************************" << endl;
    cout << "1. New game." << endl;
    cout << "2. Save game." << endl;
    cout << "3. Load game." << endl;
    cout << "4. Exit." << endl;

    cin >> choice;
    cout << endl;

    return choice;
}

void backgroundStory() {
    cout << "A rumor spreads through the campus about the professor losing his office key..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Whispers suggest that finding the key grants access to exam papers for better results..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Students are tempted by the opportunity and embark on a clandestine quest to locate the missing key..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Now hurry up and be the first person to find the key!!!" << endl;
}

void startNewGame() {
    backgroundStory();
    
    // Choose the character
    character* playerCharacter = character::selectCharacter();
    int currentScenario = 1; // Set initial scenario

    if (playerCharacter) {
        cout << "You have selected the following character: " << endl;
        playerCharacter->displayStats();

        // Start the gameplay loop
        bool playing = true;
        while (playing) {
            cout << "You are in a new scenario. What would you like to do?" << endl;
            cout << "1. Exlopre the maze." << endl;
            cout << "2. Save game." << endl;
            cout << "3. Exit to the main menu." << endl;

            char choice;
            cin >> choice;

            switch (choice) {
                case '1':
                    cout << "You must solve the maze to enter the professor's office!" << endl;
                    Maze mazeEnter(currentScenario);
                    mazeEnter.play();
                    break;

                case '2':
                    saveGame(playerCharacter, currentScenario);
                    break;

                case '3':
                    playing = false; // Exit the gameplay loop
                    break;

                default:
                    cout << "Invalid input! Please select 1, 2, or 3." << endl;
                    break;
            }
        }
        delete playerCharacter; // Clean up dynamically allocated memory
    }        
    else {
        cout << "Error selecting character." << endl;
    }
}
        // Go to room.cpp to find the key <if character not rebel>
        //character opponent();
        //if (playerCharacter != nullptr && playerCharacter->getType() != "Rebel") {
        // Rmain(*playerCharacter, opponent);}

        // Scenario 1: Solve the maze to enter the professor's office
        //cout << "You must solve the maze to enter the professor's office!" << endl;
        //Maze mazeEnter(1);
        //mazeEnter.play();

        // Scenario 2: Solve the maze to escape after stealing the exam paper
        //cout << "You must solve the maze to escape the building!" << endl;
        //Maze mazeOut(2);
        //mazeOut.play();

        // Battle system
        //character opponent();

void loadGame() {
    ifstream infile("savegame.txt");  
    if (!infile) {
        cout << "No saved game found." << endl;
        return;
    }

    string name;
    int health, maxHealth, attack, defence, intelligence;
    int currentScenario;

    // Read the character data from savegame.txt
    infile >> name >> health >> attack >> defence >> intelligence >> currentScenario;

    // Initialize the character based on loaded data
    character* playerCharacter = new character(name, health, attack, defence, intelligence);
    cout << "Loaded character: " << playerCharacter->getName() << endl;
    playerCharacter->displayStats();
    
    // Load game state (e.g., current scenario)
    Maze maze(currentScenario);
    maze.play(); // Enter the maze gameplay

    delete playerCharacter; // Clean up dynamically allocated memory
}       
        
void saveGame(character* playerCharacter, int currentScenario) {
    ofstream outfile("savegame.txt");
    if (outfile) {
        outfile << playerCharacter->getName() << " "
                << playerCharacter->getHealth() << " "
                << playerCharacter->getAttack() << " "
                << playerCharacter->getDefence() << " "
                << playerCharacter->getIntelligence() << " "
                << currentScenario << endl;
        cout << "Game saved successfully!" << endl;
    }
    else {
        cout << "Error saving the game." << endl;
    }
}
                             
int main() {
    character* playerCharacter = nullptr; // Declare playerCharacter globally accessible
    int currentScenario = 1; // Declare currentScenario globally accessible
    char choice = menu();
    
    while (choice != '4') {
        switch (choice) {
            case '1':
                startNewGame(); // Start a new game
                break;
            
            case '2':
                // Ensure a character is selected before saving
                if (playerCharacter) {
                    saveGame(playerCharacter, currentScenario); // Save progress
                }
                else {
                    cout << "No game in progress to save." << endl;
                }
                break;

            case '3':
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

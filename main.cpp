#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "room.h"
#include "maze.h"
#include "battle.h"

using namespace std;

character* playerCharacter = nullptr;
int currentScenario = 0;

// Print the selection menu
char menu() 
{
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

void backgroundStory() 
{
    cout << "A rumor spreads through the campus about the professor losing his office key..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Whispers suggest that finding the key grants access to exam papers for better results..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Students are tempted by the opportunity and embark on a clandestine quest to locate the missing key..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for 1 second
    cout << "Now hurry up and be the first person to find the key!!!" << endl;
}

void saveGame()
{
    if (playerCharacter == nullptr)
    {
        cout << "No game in progress to save." << endl;
        return;
    }

    ofstream outfile("savegame.txt");
    if (outfile)
    {
        outfile << playerCharacter->getName() << " "
                << playerCharacter->getHealth() << " "
                << playerCharacter->getAttack() << " "
                << playerCharacter->getDefence() << " "
                << playerCharacter->getIntelligence() << " "
                << currentScenario << endl;

        // Save specialAbility and abilityInfo
        outfile << playerCharacter->getSpecialAbility() << endl;
        outfile << playerCharacter->getAbilityInfo() << endl;

        cout << "Game saved successfully!" << endl;
    }
    else
    {
        cout << "Error saving the game." << endl;
    }
}

void startNewGame() 
{
    backgroundStory();

    // Initialize the rooms
    vector<Room> places = {
    {"Canteen", false, false, false},
    {"Canteen", false, false, false},
    {"Canteen", false, false, false},
    {"Canteen", false, false, false},
    };
    
    // Choose the character
    playerCharacter = character::selectCharacter(); // Use the global variable
    currentScenario = 0; // Set initial scenario

    if (playerCharacter)
    {
        cout << "You have selected the following character:" << endl;
        playerCharacter->displayStats();

        bool gameInProgress = true;
        while (gameInProgress)
        {
            // Present options to the player based on current scenario
            cout << "\nWhat would you like to do next?" << endl;
            if (currentScenario == 0)
            {
                cout << "1. Search for the key." << endl;
                cout << "2. Save game." << endl;
                cout << "3. Exit to main menu." << endl;
                char choice;
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    // Wrap code in braces
                    // Check if the character is a rebel
                    if (dynamic_cast<rebel*>(playerCharacter) == nullptr)
                    {
                        // If not a rebel, search for the key
                        int roomResult = Rmain(playerCharacter);
                        if (roomResult == 1)
                        {
                            // Game over
                            cout << "Game over. You failed to find the key or were defeated." << endl;
                            delete playerCharacter;
                            playerCharacter = nullptr;
                            gameInProgress = false;
                        }
                        else
                        {
                            cout << "You found the key!" << endl;
                            currentScenario = 1;
                        }
                    }
                    else
                    {
                        cout << "As a rebel, you can pick locks and skip finding the key." << endl;
                        currentScenario = 1;
                    }
                    break;
                }
                case '2':
                    saveGame();
                    break;
                case '3':
                    // Exit to main menu
                    delete playerCharacter;
                    playerCharacter = nullptr;
                    gameInProgress = false;
                    break;
                default:
                    cout << "Invalid input! Please select 1, 2, or 3." << endl;
                    break;
                }
            }
            else if (currentScenario == 1)
            {
                cout << "1. Enter the maze to reach the professor's office." << endl;
                cout << "2. Save game." << endl;
                cout << "3. Exit to main menu." << endl;
                char choice;
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    // Wrap code in braces
                    // Proceed to Scenario 1: Maze to enter the professor's office
                    cout << "You must solve the maze to enter the professor's office!" << endl;
                    Maze mazeEnter(1);
                    mazeEnter.play();
                    currentScenario = 2;
                    break;
                }
                case '2':
                    saveGame();
                    break;
                case '3':
                    // Exit to main menu
                    delete playerCharacter;
                    playerCharacter = nullptr;
                    gameInProgress = false;
                    break;
                default:
                    cout << "Invalid input! Please select 1, 2, or 3." << endl;
                    break;
                }
            }
            else if (currentScenario == 2)
            {
                cout << "1. Confront the professor." << endl;
                cout << "2. Save game." << endl;
                cout << "3. Exit to main menu." << endl;
                char choice;
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    // Wrap code in braces
                    // Battle with the professor
                    character professor("Professor", 50, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);

                    // Ensure the professor has at least two stats above 5
                    int statsAboveFive = 0;
                    if (professor.getAttack() > 5) statsAboveFive++;
                    if (professor.getDefence() > 5) statsAboveFive++;
                    if (professor.getIntelligence() > 5) statsAboveFive++;
                    while (statsAboveFive < 2)
                    {
                        int statToIncrease = rand() % 3;
                        switch (statToIncrease)
                        {
                        case 0:
                            professor.setAttack(rand() % 5 + 6);
                            break;
                        case 1:
                            professor.setDefence(rand() % 5 + 6);
                            break;
                        case 2:
                            professor.setIntelligence(rand() % 5 + 6);
                            break;
                        }
                        statsAboveFive = 0;
                        if (professor.getAttack() > 5) statsAboveFive++;
                        if (professor.getDefence() > 5) statsAboveFive++;
                        if (professor.getIntelligence() > 5) statsAboveFive++;
                    }

                    cout << "You have encountered the professor!" << endl;

                    bool battleResult = BATTLE_RESULT(playerCharacter, professor);
                    if (!battleResult)
                    {
                        cout << "You were defeated by the professor. Game over." << endl;
                        delete playerCharacter;
                        playerCharacter = nullptr;
                        gameInProgress = false;
                    }
                    else
                    {
                        cout << "You defeated the professor and got the exam papers!" << endl;
                        currentScenario = 3;
                    }
                    break;
                }
                case '2':
                    saveGame();
                    break;
                case '3':
                    // Exit to main menu
                    delete playerCharacter;
                    playerCharacter = nullptr;
                    gameInProgress = false;
                    break;
                default:
                    cout << "Invalid input! Please select 1, 2, or 3." << endl;
                    break;
                }
            }
            else if (currentScenario == 3)
            {
                cout << "1. Escape through the maze." << endl;
                cout << "2. Save game." << endl;
                cout << "3. Exit to main menu." << endl;
                char choice;
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    // Wrap code in braces
                    // Proceed to Scenario 2: Maze to escape the building
                    cout << "You must solve the maze to escape the building!" << endl;
                    Maze mazeOut(2);
                    mazeOut.play();
                    currentScenario = 4;
                    break;
                }
                case '2':
                    saveGame();
                    break;
                case '3':
                    // Exit to main menu
                    delete playerCharacter;
                    playerCharacter = nullptr;
                    gameInProgress = false;
                    break;
                default:
                    cout << "Invalid input! Please select 1, 2, or 3." << endl;
                    break;
                }
            }
            else if (currentScenario == 4)
            {
                // Game completed
                cout << "Congratulations! You have successfully completed the game!" << endl;
                delete playerCharacter;
                playerCharacter = nullptr;
                gameInProgress = false;
            }
        }
    }
    else
    {
        cout << "Error selecting character." << endl;
    }
}

void loadGame()
{
    ifstream infile("savegame.txt");
    if (!infile)
    {
        cout << "No saved game found." << endl;
        return;
    }

    string charType;
    int health, attack, defence, intelligence;
    int loadedScenario;
    string specialAbility;
    string abilityInfo;

    // Read the character data from savegame.txt
    infile >> charType >> health >> attack >> defence >> intelligence >> loadedScenario;
    infile.ignore(); // Ignore the newline after the last integer

    getline(infile, specialAbility);
    getline(infile, abilityInfo);

    // Initialize the character based on loaded data
    if (charType == "Athlete")
    {
        playerCharacter = new athlete();
    }
    else if (charType == "Hacker")
    {
        playerCharacter = new hacker();
    }
    else if (charType == "Rebel")
    {
        playerCharacter = new rebel();
    }
    else
    {
        cout << "Unknown character type in save file." << endl;
        return;
    }

    playerCharacter->setHealth(health);
    playerCharacter->setAttack(attack);
    playerCharacter->setDefence(defence);
    playerCharacter->setIntelligence(intelligence);
    playerCharacter->setSpecialAbility(specialAbility);
    playerCharacter->setAbilityInfo(abilityInfo);

    currentScenario = loadedScenario;

    cout << "Loaded character: " << playerCharacter->getName() << endl;
    playerCharacter->displayStats();

    // Continue the game from the saved scenario
    bool gameInProgress = true;
    while (gameInProgress)
    {
        // Present options to the player based on current scenario
        cout << "\nWhat would you like to do next?" << endl;
        if (currentScenario == 0)
        {
            cout << "1. Search for the key." << endl;
            cout << "2. Save game." << endl;
            cout << "3. Exit to main menu." << endl;
            char choice;
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                // Wrap code in braces
                // Check if the character is a rebel
                if (dynamic_cast<rebel*>(playerCharacter) == nullptr)
                {
                    // If not a rebel, search for the key
                    int roomResult = Rmain(playerCharacter);
                    if (roomResult == 1)
                    {
                        // Game over
                        cout << "Game over. You failed to find the key or were defeated." << endl;
                        delete playerCharacter;
                        playerCharacter = nullptr;
                        gameInProgress = false;
                    }
                    else
                    {
                        cout << "You found the key!" << endl;
                        currentScenario = 1;
                    }
                }
                else
                {
                    cout << "As a rebel, you can pick locks and skip finding the key." << endl;
                    currentScenario = 1;
                }
                break;
            }
            case '2':
                saveGame();
                break;
            case '3':
                // Exit to main menu
                delete playerCharacter;
                playerCharacter = nullptr;
                gameInProgress = false;
                break;
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
            }
        }
        else if (currentScenario == 1)
        {
            cout << "1. Enter the maze to reach the professor's office." << endl;
            cout << "2. Save game." << endl;
            cout << "3. Exit to main menu." << endl;
            char choice;
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                // Wrap code in braces
                // Proceed to Scenario 1: Maze to enter the professor's office
                cout << "You must solve the maze to enter the professor's office!" << endl;
                Maze mazeEnter(1);
                mazeEnter.play();
                currentScenario = 2;
                break;
            }
            case '2':
                saveGame();
                break;
            case '3':
                // Exit to main menu
                delete playerCharacter;
                playerCharacter = nullptr;
                gameInProgress = false;
                break;
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
            }
        }
        else if (currentScenario == 2)
        {
            cout << "1. Confront the professor." << endl;
            cout << "2. Save game." << endl;
            cout << "3. Exit to main menu." << endl;
            char choice;
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                // Wrap code in braces
                // Battle with the professor
                character professor("Professor", 50, rand() % 10 + 1,
                    rand() % 10 + 1, rand() % 10 + 1);

                // Ensure the professor has at least two stats above 5
                int statsAboveFive = 0;
                if (professor.getAttack() > 5) statsAboveFive++;
                if (professor.getDefence() > 5) statsAboveFive++;
                if (professor.getIntelligence() > 5) statsAboveFive++;
                while (statsAboveFive < 2)
                {
                    int statToIncrease = rand() % 3;
                    switch (statToIncrease)
                    {
                    case 0:
                        professor.setAttack(rand() % 5 + 6);
                        break;
                    case 1:
                        professor.setDefence(rand() % 5 + 6);
                        break;
                    case 2:
                        professor.setIntelligence(rand() % 5 + 6);
                        break;
                    }
                    statsAboveFive = 0;
                    if (professor.getAttack() > 5) statsAboveFive++;
                    if (professor.getDefence() > 5) statsAboveFive++;
                    if (professor.getIntelligence() > 5) statsAboveFive++;
                }

                cout << "You have encountered the professor!" << endl;

                bool battleResult = BATTLE_RESULT(playerCharacter, professor);
                if (!battleResult)
                {
                    cout << "You were defeated by the professor. Game over." << endl;
                    delete playerCharacter;
                    playerCharacter = nullptr;
                    gameInProgress = false;
                }
                else
                {
                    cout << "You defeated the professor and got the exam papers!" << endl;
                    currentScenario = 3;
                }
                break;
            }
            case '2':
                saveGame();
                break;
            case '3':
                // Exit to main menu
                delete playerCharacter;
                playerCharacter = nullptr;
                gameInProgress = false;
                break;
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
            }
        }
        else if (currentScenario == 3)
        {
            cout << "1. Escape through the maze." << endl;
            cout << "2. Save game." << endl;
            cout << "3. Exit to main menu." << endl;
            char choice;
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                // Wrap code in braces
                // Proceed to Scenario 2: Maze to escape the building
                cout << "You must solve the maze to escape the building!" << endl;
                Maze mazeOut(2);
                mazeOut.play();
                currentScenario = 4;
                break;
            }
            case '2':
                saveGame();
                break;
            case '3':
                // Exit to main menu
                delete playerCharacter;
                playerCharacter = nullptr;
                gameInProgress = false;
                break;
            default:
                cout << "Invalid input! Please select 1, 2, or 3." << endl;
                break;
            }
        }
        else if (currentScenario == 4)
        {
            // Game completed
            cout << "Congratulations! You have successfully completed the game!" << endl;
            delete playerCharacter;
            playerCharacter = nullptr;
            gameInProgress = false;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char choice = menu();

    while (choice != '4') {
        switch (choice)
        {
        case '1':
            startNewGame(); // Start a new game
            break;
        case '2':
            saveGame(); // Save the game
            break;
        case '3':
            loadGame(); // Load the previous saved game progress
            break;
        case '4':
            exit(0);
        default:
            cout << "Invalid input! Please select 1, 2, 3 or 4." << endl;
            break;
        }
        choice = menu(); // Show the menu again
    }
    cout << "Hope you enjoyed the game!" << endl;

    return 0;
}

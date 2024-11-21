#include <iostream>
#include "character.h"
#include "room.h"
#include "maze.h"

using namespace std;

char menu() 
{
    char choice;
    //print the selection menu;
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

int main() 
{
    char choice = menu();
    while (choice != '3') 
    {
        switch (choice)
        {
            case '1':
                //choose the character
            case '2':
                //load the previous saved game progress
            default:
                cout << "Invalid input!" << endl;
        }
        choice = meue();
    }
    cout << "Hope you enjoyed the game!" << endl;

    return 0;
}
        
    
    

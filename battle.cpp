/* For this to work, the program is expected to receive 4 types of data from a struct (the character stuff).
e.g.
struct Character {
  int HP/Stamina;
  int ATT;
  int DEF;
  int INT;
}
ATT, DEF, and INT will range from 1 to 10 (randomly generated for opponents, with minibosses having only 1 of them above five and the prof having 2 of them above 5. )
HP/Stamina will be 25 for the mini-bosses and 50 for the professor.No regeneration of HP, based on items and stuff after 
The idea is as follows: suppose the player has the following stats: HP = 50, ATT = 6, DEF = 5, INT = 7, the prof has HP = 50, Att = 7, Def = 7, Int = 9
(The intelligence of the players determines the possibility of avoiding battle at all, while the Intelligence of the bosses determine playstyle)
The battle mech is a turned-based attack. Both the bosses and the player have 2 choices: attack or heal/intimidate.
Attack:
1. Damage = dice throw (1-12) + (ATT - DEF)
- If ends up less than 0, damage failed,
- regardless it is the opponents turn, same process

Heal/Intimidate:
if player Int > opponent:
  -> roll dice (1-12)
  -> (SPECIAL) -> if = = 12 sth special will happen
  Number rolled += player's HP
if player Int < = opponent:
  Number rolled += player's HP
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "battle.h"
#include "character.h"
using namespace std;

int DICE_ROLLING()
{ 
    //standard die rolling,
    srand(time(NULL));           //random seed
    int die = rand() % 12 + 1;    // rand 1-12
    return die;
}

void ATTACK(character* player, character& opponent)
{ 
    //takes in ATT stats of player, def of opponent, and the Health Points of Opponent
    int Damage, Dice;
    Dice = DICE_ROLLING();
    Damage = Dice + player->getAttack() - opponent.getDefence(); //damage calculation
    if (Dice == 12)
        cout << "BONUS DAMAGE" << endl;
        Damage += Dice;
    
// Athlete's special ability: 50% chance to deal double damage
    if (dynamic_cast<athlete*>(player))
    {
        int chance = DICE_ROLLING();
        if (chance <= 6)
        {
            cout << "Special Ability Activated: Double Damage!" << endl;
            Damage *= 2;
        }
    }

// damage update to health points
    if (Damage > 0)
    {
        opponent.setHealth(opponent.getHealth() - Damage);
        cout << "Success! Damage dealt: " << Damage << endl;
        cout << "Opponent's HP = " << opponent.getHealth() << endl;
    }
    else
    {
        cout << "Attack failed, zero damage dealt." << endl;
        cout << "Opponent's HP = " << opponent.getHealth() << endl;
    }
}


void ATTACK_O(character& opponent, character* player)
{ 
    //Same as above but reversing the roles
    int Damage, Dice;
    Dice = DICE_ROLLING();
    Damage = Dice + opponent.getAttack() - player->getDefence();
    if (Dice == 12)
    {
        cout << "BONUS DAMAGE" << endl;
        Damage += Dice;
    }
    if (Damage > 0)
    {
        player->setHealth(player->getHealth() - Damage);
        cout << "You have suffered damage! Damage received: " << Damage << endl;
        cout << "Your HP = " << player->getHealth() << endl;
    }
    else
    {
        cout << "Opponent's attack failed, zero damage received." << endl;
        cout << "Your HP = " << player->getHealth() << endl;
    }
}

void INT(character* player, character& opponent)
{ 
    //Second battle mechanism, intimidating, basically heals and possibly deals damage)
    // (takes in Intelligence of both Player and Opponent, and their Healths, 
    int Rolled_No = DICE_ROLLING();
    if (Rolled_No == 12){
            opponent.setHealth(opponent.getHealth() - Rolled_No / 2);
            cout << "Congrats, bonus action. Damage done to Opponent!" << endl;
            cout << "Opponent's HP = " << opponent.getHealth() << endl;
            player->setHealth(player->getHealth() + Rolled_No);
            cout << "Healed, Your HP = " << player->getHealth() << endl;
    }
    else
    {
        int originalHP = player->getHealth();
        int healthChange = player->getIntelligence() + Rolled_No - opponent.getIntelligence();
        player->setHealth(originalHP + healthChange);
        
        if (player->getHealth() > originalHP)
        {
            cout << "Healed, Your HP = " << player->getHealth() << endl;
        }
        else if (player->getHealth() == originalHP)
        {
            cout << "Healing failed, Your HP = " << player->getHealth() << endl;
        }
        else
        {
            cout << "Failed to intimidate and got intimidated back, Your HP = " << player->getHealth() << endl;
        }
    }
}

void INT_O(character& opponent, character* player)
{ 
    //same as above, different perspective, reversal of roles
    int Rolled_No = DICE_ROLLING();
    
    if (Rolled_No == 12)
    {
        player->setHealth(player->getHealth() - Rolled_No / 2);
        cout << "Oh no, bonus action, damage received!" << endl;
        cout << " Your HP = " << player->getHealth() << endl;
        opponent.setHealth(opponent.getHealth() + Rolled_No);
        cout << "Opponent has healed, HP = " << opponent.getHealth() << endl;
    }
    else
    {
        int originalHP = opponent.getHealth();
        int healthChange = opponent.getIntelligence() + Rolled_No - player->getIntelligence();
        opponent.setHealth(originalHP + healthChange);
        
        if (opponent.getHealth() > originalHP)
        {
            cout << "Opponent healed, HP = " << opponent.getHealth() << endl;
        }
        else if (opponent.getHealth() == originalHP)
        {
            cout << "Opponent's healing failed, HP = " << opponent.getHealth() << endl;
        }
        else
        {
            cout << "Opponent failed to intimidate and got intimidated back, HP = " << opponent.getHealth() << endl;
        }
    }
}

bool BATTLE_RESULT(character* player, character& opponent)
{ 
    // Hacker's special ability: 50% chance to skip battle
    if (dynamic_cast<hacker*>(player))
    {
        int chance = DICE_ROLLING();
        if (chance <= 6)
        {
            cout << "\nSpecial Ability Activated: You hacked the security system and skipped the battle!" << endl;
            return true;
        }
    }
    
    //implements the battle mechanism, gets the player and the opponent details, and returns true if the player wins)
    cout << "\nOpponent stats:" << endl;
    cout << "Health = " << opponent.getHealth() << endl;
    cout << "Attack = " << opponent.getAttack() << endl;
    cout << "Defence = " << opponent.getDefence() << endl;
    cout << "Intelligence = " << opponent.getIntelligence() << endl;

    cout << "\nWhat will you do?" << endl;
    cout << "Enter \"Attack \" to attack" << endl;
    cout << "Enter \"Intimidate \" to Heal" << endl;
    cout << "Chance that \"Intimidate \" will cause drastic damage as well, provided you have high enough intelligence." << endl;
    cout << "Note that the enemy also has the same moveset as you, they can also deal damage after they are defeated." << endl;

    string command;
    while (player->getHealth() > 0 && opponent.getHealth() > 0)
    {
        // Player's actions
        cout << "\nYour turn: " << endl;
        cin >> command;
        if (command == "Attack" || command == "attack")
        {
            ATTACK(player, opponent);
            if (opponent.getHealth() <= 0) break;
            cout << "\nOpponent's turn: "<< endl;
        }
        else if (command == "Intimidate" || command == "intimidate")
        {
            INT(player, opponent);
            if (opponent.getHealth() <= 0) break;
            cout << "\nOpponent's turn: " << endl;
        }
        else
        {
            cout << "Invalid command, you wasted your turn!!!" << endl;
            cout << "\nOpponent's turn: " << endl;
        }
        
        // Opponent's actions
        int Action = DICE_ROLLING();
        if (Action > 2 && opponent.getHealth() >= 20){
            cout << "Opponent Attacks." << endl;
            ATTACK_O(opponent, player);
        }
        else 
        {
            cout << "Opponent intimidates." << endl;
            INT_O(opponent, player);
        } 
    }

    if (player->getHealth() <= 0)
    {
        cout << "You have been defeated!" << endl;
        return false;
    }
    else
    {
        cout << "You won the battle!" << endl;
        return true;
}

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
1. Damage = dice throw (1-6) + (ATT - DEF)
- If ends up less than 0, damage failed,
- regardless it is the opponents turn, same process

Heal/Intimidate:
if player Int > opponent:
  -> roll dice (1-12)
  -> (SPECIAL) -> if = = 6 win autonomatically
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

int DICE_ROLLING(){
    srand(time(NULL));
    int die = rand() %12 + 1;
    return die;
}

void ATTACK (const int P_ATT, const int O_DEF, int& O_HP){
    int Damage, Dice;
    Dice = DICE_ROLLING();
    Damage = Dice + P_ATT - O_DEF;
    if (Dice == 12)
        cout <<"BONUS DAMAGE"<<endl;
        Damage += Dice;

    if (Damage > 0){
        O_HP-= Damage;
        cout<<"Success! Damage dealt: "<< Damage <<endl;
        cout<<"Opponent's HP = "<< O_HP <<endl;
    }
    else{
        cout << "Attack failed, zero damage dealt: "<<endl;
        cout<<"Opponent's HP = "<< O_HP <<endl;
    }
}

void ATTACK_O (const int O_ATT, const int P_DEF, int& P_HP){
    int Damage, Dice;
    Dice = DICE_ROLLING();
    Damage = Dice + O_ATT - P_DEF;
    if (Dice == 12)
        cout <<"BONUS DAMAGE"<<endl;
        Damage += Dice;
    if (Damage > 0){
        P_HP-= Damage;
        cout<<"You have suffered damage! Damage received: "<< Damage <<endl;
        cout<<"Your HP = "<< P_HP <<endl;
    }
    else{
        cout << "Opponent's attack failed, zero damage received: "<<endl;
        cout<<"Your HP = "<< P_HP <<endl;
    }
}

void INT (const int P_INT, const int O_INT, int& P_HP, int& O_HP){
    int Rolled_No = DICE_ROLLING();
    if (Rolled_No == 12){
            O_HP-= Rolled_No/2;
            cout << "Congrats, bonus action. Damage done to Opponent!"<<endl;
            cout << " Opponent's HP = " << O_HP << endl;
            P_HP += Rolled_No ;
            cout << "Healed, HP = " << P_HP << endl;
    }
    else{
        int original = P_HP;
        P_HP = P_HP + P_INT + Rolled_No - O_INT;
        if (P_HP > original)
            cout << "Healed, HP = " << P_HP << endl;
        else if (P_HP == original)
            cout << "Healing failed, HP = " << P_HP << endl;
        else
            cout <<"Failed to intimidate and got intimidated back, HP = " << P_HP <<endl;
    }

}

void INT_O (const int O_INT, const int P_INT, int& O_HP, int& P_HP){
    int Rolled_No = DICE_ROLLING();
    
    if (Rolled_No == 12){
        P_HP-= Rolled_No/2;
        cout << "Oh no, bonus action, damage received!"<<endl;
        cout << " Your HP = " << P_HP << endl;
        O_HP += Rolled_No;
        cout << "Opponent has healed, HP = " << O_HP << endl;
        }
    else{
        int original = O_HP;
        O_HP = O_HP + O_INT + Rolled_No - P_INT;
        if (O_HP > original)
            cout << "Healed, HP = " << O_HP << endl;
        else if (O_HP == original)
            cout << "Healing failed, HP = " << O_HP << endl;
        else
            cout <<"Failed to intimidate and got intimidated back, HP = " << O_HP <<endl;
    }
}

bool BATTLE_RESULT (character& Player, character& Opponent){
    cout << "What will you do?"<<endl;
    cout << "Enter \"Attack \" to attack"<<endl;
    cout << "Enter \"Intimidate \"to Heal"<<endl;
    cout << "Chance that \"Intimidate \" will cause drastic damage as well, provided you have high enough INT"<<endl;
    cout << "Note that the enemy also has the same moveset as you, they can also deal damage after they are defeated."<< endl;
    cout << "Opp stats:"<<endl;
    cout << "Health = "<< Opponent.health <<endl;
    cout << "Attack = " << Opponent.attack << endl;
    cout << "Defence = " << Opponent.defence << endl;
    cout << "Intelligence = " << Opponent.intelligence << endl;
    string command;
    while (Player.health > 0 && Opponent.health > 0){
        cout <<"Your turn: " <<endl;
        cin >> command;
        if (command == "Attack"){
            ATTACK(Player.attack, Opponent.defence, Opponent.health);
            cout <<"Opponent's turn: "<< endl;
        }
        else if (command == "Intimidate"){
            INT(Player.intelligence, Opponent.intelligence, Player.health, Opponent.health);
            cout <<"Opponent's turn: " <<endl;
        }
        else{
            cout<<"Invalid command, you wasted your turn!!! \n" << "Opponent's turn: "<< endl;
        }
        int Action = DICE_ROLLING();
        if (Action > 2 && Opponent.HP >= 20){
            cout << "Opponent Attacks."<<endl;
            ATTACK_O(Opponent.ATT, Player.DEF, Player.HP);
        }
        else {
            cout << "Opponent intimidates." <<endl;
            INT_O(Opponent.INT, Player.INT, Opponent.HP, Player.HP);
    
        } 

    }

    if (Player.health <= 0)
        return false;
    else
        return true;

}

//battle.h
#ifndef BATTLE_H
#define BATTLE_H

int DICE_ROLLING();
bool BATTLE_RESULT (Character& Player, Character& Opponent);
void ATTACK (const int P_ATT, const int O_DEF, int& O_HP);
void INT (const int P_INT, const int O_INT, int& P_HP, int& O_HP);
void ATTACK_O (const int O_ATT, const int P_DEF, int& P_HP);
void INT_O (const int O_INT, const int P_INT, int& O_HP, int& P_HP);


#endif

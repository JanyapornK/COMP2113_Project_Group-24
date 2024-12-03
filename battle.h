//battle.h
#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"

int DICE_ROLLING();
void ATTACK(character* player, character& opponent);
void ATTACK_O(character& opponent, character* player);
void INT(character* player, character& opponent);
void INT_O(character& opponent, character* player);
bool BATTLE_RESULT (character* player, character& opponent);

#endif

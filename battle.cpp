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
  -> roll dice (1-6)
  -> (SPECIAL) -> if = = 6 win autonomatically
  Number rolled += player's HP
if player Int < = opponent:
  Number rolled += player's HP
*/



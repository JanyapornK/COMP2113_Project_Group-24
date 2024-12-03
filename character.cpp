#include "character.h"
#include <iostream>
#include <string>

// Constructor
character::character() : name(""), health(100), attack(10), defence(5), intelligence(0) {}

character::character(std::string name, int health, int attack, int defence, int intelligence) : name(name), health(health), attack(attack), defence(defence), intelligence(intelligence) {}
// Destructor
character::~character() {}

// Stat getting methods
std::string character::getName() const { return name; }
int character::getHealth() const { return health; }
int character::getMaxHealth() const { return maxHealth; }
int character::getDefence() const { return defence; }
int character::getIntelligence() const { return intelligence; }
// string getSpecialAbility() const { return specialAbility; } (TBD)

// Stat setting method
void character::setHealth(int h)
{
	health = (h > maxHealth) ? maxHealth : h;
}

/*
// virtual method for speical ability
void character::useSpecialAbility()
{
	cout << name << " uses " << specialAbility << "!" << endl;
	// ability effect in battle classes
}
*/

// Stat displaying method
void character::displayStats() const
{
	std::cout << "Character: " << name << std::endl;
	std::cout << "Health: " << health << "/" << maxHealth << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defence: " << defence << std::endl;
	std::cout << "Intelligence: " << intelligence << std::endl;
	// cout << "Special Ability: " << specialAbility << endl; (TBD)
}

// Character selection method
character* character::selectCharacter()
{
	int choice;
	std::cout << "Choose your character: " << std::endl;
	std::cout << "1: ???" << std::endl; // characters making still in progress
	std::cout << "2: ???" << std::endl;
	std::cout << "3: ???" << std::endl;
	std::cout << "4: ???" << std::endl;
	std::cout << "Enter the number of your choice: ";
	std::cin >> choice;

	character* player = nullptr;
	
	switch (choice)
	{
	case 1:
		player = new character("???", 150, 20, 15, 5);
		break;
	case 2:
		player = new character("???", 100, 10, 5, 25);
		break;
	case 3:
		player = new character("???", 120, 15, 10, 10);
		break;
	case 4:
		player = new character("???", 110, 18, 8, 8);
		break;
	default:
		std::cout << "Invalid choice. Defaulting to ???." << std::endl; // by default choosing the 1st character
		player = new character("???", 150, 20, 15, 5);
		break;
	}

	player->displayStats();
	return player;
}

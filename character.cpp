#include "character.h"
#include <iostream>
#include <string>

// Base class constructor
character::character() : name(""), health(100), attack(10), defence(5), intelligence(0) {}
character::character(std::string name, int health, int attack, int defence, int intelligence, std::string specialAbility) : name(name), health(health), attack(attack), defence(defence), intelligence(intelligence), specialAbility(specialAbility) {}
// Base class destructor
character::~character() {}

// Stat getting methods
std::string character::getName() const { return name; }
int character::getHealth() const { return health; }
int character::getDefence() const { return defence; }
int character::getIntelligence() const { return intelligence; }
std::string character::getSpecialAbility() const { return specialAbility; }

// Stat setting method
void character::setHealth(int h)
{
	health = h;
}

/*
// Virtual method for speical ability
void character::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// ability effect in battle classes
}
*/

// Stat displaying method
void character::displayStats() const
{
	std::cout << "\nCharacter: " << name << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defence: " << defence << std::endl;
	std::cout << "Intelligence: " << intelligence << std::endl;
	std::cout << "Special Ability: " << specialAbility << std::endl;
}

// Character selection method
character* character::selectCharacter()
{
	int choice;
	std::cout << "Choose your character: " << std::endl;
	std::cout << "1: Athlete" << std::endl; // characters making still in progress
	std::cout << "2: Hacker" << std::endl;
	std::cout << "3: Rebel" << std::endl;
	std::cout << "Enter the number of your choice: ";
	std::cin >> choice;

	character* player = nullptr;
	
	switch (choice)
	{
	case 1:
		player = new athlete();
		break;
	case 2:
		player = new hacker();
		break;
	case 3:
		player = new rebel();
		break;
	default:
		std::cout << "Invalid choice. Defaulting to Athlete." << std::endl; // by default choosing the 1st character
		player = new athlete();
		break;
	}

	player->displayStats();
	return player;
}

// ===============
// Derived classes
// ===============

// Athlete class
athlete::athlete()
	: character("Athelete", 150, 25, 20, 5, "Smash") {}
void athlete::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: have a chance to deal double damage
}

// Hacker class
hacker::hacker()
	: character("Hacker", 100, 15, 15, 10, "Override") {}
void hacker::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: have a chance to skip battle in rooms
}

// Rebel class
rebel::rebel()
	: character("Rebel", 75, 10, 10, 5, "Pick Lock") {}
void rebel::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: entering office without the need of a key
}

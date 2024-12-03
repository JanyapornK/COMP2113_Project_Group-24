#include "character.h"
#include <iostream>
#include <string>

// Base class constructor
character::character() : name(""), health(100), attack(10), defence(5), intelligence(0), specialAbility(""), abilityInfo("") {}
character::character(std::string name, int health, int attack, int defence, int intelligence) : name(name), health(health), attack(attack), defence(defence), intelligence(intelligence) {}
character::character(std::string name, int health, int attack, int defence, int intelligence, std::string specialAbility, std::string abilityInfo) : name(name), health(health), attack(attack), defence(defence), intelligence(intelligence), specialAbility(specialAbility), abilityInfo(abilityInfo) {}
// Base class destructor
character::~character() {}

// Stat getting methods
std::string character::getName() const { return name; }
int character::getHealth() const { return health; }
int character::getDefence() const { return defence; }
int character::getIntelligence() const { return intelligence; }
std::string character::getSpecialAbility() const { return specialAbility; }
std::string character::getAbilityInfo() const { return abilityInfo; }

// Stat setting method
void character::setHealth(int h) { health = h; }
void character::setAttack(int a) { attack = a; }
void character::setDefence(int d) { defence = d; }
void character::setIntelligence(int i) { intelligence = i; }


// Virtual method for speical ability
void character::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// ability effect in battle classes
}

// Stat displaying method
void character::displayStats() const
{
	std::cout << "\nCharacter: " << name << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defence: " << defence << std::endl;
	std::cout << "Intelligence: " << intelligence << std::endl;
	std::cout << "\nSpecial Ability: " << specialAbility << std::endl;
	std::cout << abilityInfo << std::endl;
}

// Character selection method
character* character::selectCharacter()
{
	int choice;
	bool confirmed = false;
	character* player = nullptr;
	
	while (!confirmed)
	{
		std::cout << "\nChoose your character: " << std::endl;
		std::cout << "1: Athlete" << std::endl; // characters making still in progress
		std::cout << "2: Hacker" << std::endl;
		std::cout << "3: Rebel" << std::endl;
		std::cout << "Enter the number of your choice: ";
		std::cin >> choice;
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
			std::cout << "Invalid choice, please enter 1,2 or 3." << std::endl;
			continue;
		}

		// Display stats for confirmation
		player->displayStats();

		// Confirmation input
		char confirm;
		std::cout << "Do you want to select this character? (y/n)";
		std::cin >> confirm;

		if (confirm == 'y' || confirm == 'Y')
		{
			confirmed = true;
		}
		else
		{
			delete player; // Clean up and loop again
			player = nullptr;
		}
	}
	
	return player;
}

// ===============
// Derived classes
// ===============

// Athlete class
athlete::athlete()
	: character("Athelete", 150, 25, 20, 5, "Smash", "Attacks have a 50% chance on dealing double damage.") {}
void athlete::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: have a chance to deal double damage
}

// Hacker class
hacker::hacker()
	: character("Hacker", 100, 15, 15, 10, "Override", "Attempts to override security cameras and alarms, 50% chance on skipping battle completely.") {}
void hacker::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: have a chance to skip battle in rooms
}

// Rebel class
rebel::rebel()
	: character("Rebel", 75, 10, 10, 5, "Pick Lock", "The ability to pick locks, removing the need to locate the key.") {}
void rebel::useSpecialAbility()
{
	std::cout << name << " uses " << specialAbility << "!" << std::endl;
	// Implement effect: entering office without the need of a key
}

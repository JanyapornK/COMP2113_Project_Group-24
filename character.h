#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class character
{
protected:
	std::string name;
	int health;
	int maxHealth;
	int attack;
	int defence;
	int intelligence;
	// string specialAbility; (TBD)

public:
	character();
	character(std::string name, int health, int attack, int defence, int intelligence);
	virtual ~character();

	std::string getName() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getDefence() const;
	int getIntelligence() const;
	// string getSpecialAbility() const; (TBD)

	void setHealth(int health);

	// virtual void useSpecialAbility();

	void displayStats() const;

	static character* selectCharacter();

};

#endif

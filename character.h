//character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

// Base character class
class character
{
protected:
	std::string name;
	int health;
	int attack;
	int defence;
	int intelligence;
	std::string specialAbility;
	std::string abilityInfo;

public:
	// Constructors
	character();
	character(std::string name, int health, int attack, int defence, int intelligence);
	character(std::string name, int health, int attack, int defence, int intelligence, std::string specialAbility, std::string abilityInfo);
	// Destructor
	virtual ~character();

	// Items getting methods
	std::string getName() const;
	int getHealth() const;
	int getDefence() const;
	int getIntelligence() const;
	std::string getSpecialAbility() const;
	std::string getAbilityInfo() const;

	// Stat setting method
	void setHealth(int health);
	void setAttack(int attack);
	void setDefence(int defence);
	void setIntelligence(int intelligence);

	// Virtual method for special ability
	virtual void useSpecialAbility();

	// Stat displaying method
	void displayStats() const;

	// Character selection method
	static character* selectCharacter();
};

// Derived character classes
class athlete : public character
{
public:
	athlete();
	void useSpecialAbility() override;
};

class hacker : public character
{
public:
	hacker();
	void useSpecialAbility() override;
};

class rebel : public character
{
public:
	rebel();
	void useSpecialAbility() override;
};

#endif 

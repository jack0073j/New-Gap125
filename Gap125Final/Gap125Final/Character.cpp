#include <iostream>
#include <string>
#include "Character.h"

Character::Character()
{
	health = 100;
	maxHealth = 100;
	attackStr = 10;
	defense = 5;
	isDead = false;
}

Character::Character(int HP, int ATK, int DEF, std::string NA)
{
	name = NA;
	health = HP;
	maxHealth = HP;
	attackStr = ATK;
	defense = DEF;
	isDead = false;
}
Character::~Character()
{
}
void Character::Attack(Character& target)
{
	std::cout << name << " attack " << target.name << "\n";
	target.AddDamage(attackStr);
}

void Character::HealHealth(int i)
{
	health += i;
	std::cout << name << " heals " << i << " health.\n";
	if (health>maxHealth)
	{
		health = maxHealth;
	}
}
void Character::AddDamage(int i)
{
	health -= i;
	std::cout << name << " takes " << i << " damage.\n";
	if (health <= 0)
	{
		Dead();
	}
	//checkHealth();
}
void Character::Check()
{
	std::cout << name << " HP: " << health << "/" << maxHealth << " ,ATK:" << attackStr << " DEF:" << defense << "\n";
}
void Character::Dead()
{
	std::cout << name << "dead.\n";
	isDead = true;
}
int  Character::GetAttackStr()
{
	return attackStr;
}
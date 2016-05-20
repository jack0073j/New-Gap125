#include <string>
#include <iostream>
#include "Weapon.h"

Weapon::Weapon()
{
}
Weapon::Weapon(std::string  NA, int Val, int ATK, int DUR)
{
	name = NA;
	value = Val;
	attack = ATK;
	durability = DUR;
}
Weapon::~Weapon()
{
}
int Weapon::getAttack() {
	return attack;
}

void Weapon::Broken()
{
}
void Weapon::loseDurability()
{
	durability -= 1;
	if (durability <= 0)
	{
		Broken();
	}
}
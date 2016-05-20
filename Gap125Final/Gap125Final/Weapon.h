#pragma once
#include "Item.h"
class Weapon :
	public Item
{
public:
	Weapon();
	Weapon(std::string NA, int Val, int ATK, int DUR);
	~Weapon();
	void Broken();
	int getAttack();
	void loseDurability();


protected:
	int  attack;
	int durability;
};


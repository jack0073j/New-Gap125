#include <string>
#include <iostream>
#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Player::Player(int HP, int ATK, int DEF, std::string NA, int STA, int MEN)
{
	name = NA;
	health = HP;
	maxHealth = HP;
	attackStr = ATK;
	defense = DEF;
	maxStamina = STA;
	stamina = STA;
	maxMental = MEN;
	mental = MEN;
	isDead = false;
}

void Player::EquipWeapon(Weapon* w)
{
	equippedWeapon = w;
}


void Player::DiscardWeapon()
{
	equippedWeapon = nullptr;
}
void Player::Attack(Character& target)
{
	int damageToApply = attackStr;
	if (equippedWeapon)
	{
		damageToApply += equippedWeapon->getAttack();
		equippedWeapon->loseDurability();
	}

	std::cout << "You deal " << damageToApply << " damage\n";
	std::cout << name << " attack " << target.name << "\n";
	target.AddDamage(damageToApply);
}






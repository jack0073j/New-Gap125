#include <string>
#include <iostream>
#include "TeamMember.h"

TeamMember::TeamMember()
{
}

TeamMember::TeamMember(int HP, int ATK, int DEF, std::string NA, int STA, int MEN)
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

TeamMember::~TeamMember()
{
}
void TeamMember::AdjustMaxStamina(int i)
{
	maxStamina += i;

	if (i>0)
	{
		std::cout << name << " heal " << i << " max stamina\n";
		stamina += i;
	}
	else if (i<0)
	{
		std::cout << name << " lose " << i << " max stamina\n";
		if (stamina > maxStamina)
			stamina = maxStamina;
	}

	if (maxStamina <= 0)
	{
		maxStamina = 0;
		std::cout << name << " starved to death.\n";
		Dead();
	}
}
void TeamMember::AdjustStamina(int i)
{
	stamina += i;

	if (i>0)
	{
		std::cout << name << " heal " << i << " stamina\n";
		if (stamina > maxStamina)
			stamina = maxStamina;
	}
	else if (i<0)
	{
		std::cout << name << " lose " << i << "  stamina\n";
		if (stamina <= 0)
		{
			stamina = 0;
			std::cout << name << " starved to death.\n";
			Dead();
		}
	}
}
void TeamMember::AdjustMaxMental(int i)
{
	maxMental += i;

	if (i>0)
	{
		std::cout << name << " get " << i << " max mental\n";
		mental += i;
	}
	else if (i<0)
	{
		std::cout << name << " lose " << i << " max mental\n";
		if (mental > maxMental)
			mental = maxMental;
	}

	if (maxMental <= 0)
	{
		maxMental = 0;
		std::cout << name << " killed himself.\n";
		Dead();
	}
}
void TeamMember::AdjustMental(int i)
{
	mental += i;

	if (i>0)
	{
		std::cout << name << " get " << i << " mental\n";
		if (mental >  maxMental)
			mental = maxMental;
	}
	else if (i<0)
	{
		std::cout << name << " lose " << i << "  mental\n";
		if (mental <= 0)
		{
			mental = 0;
			std::cout << name << " killed himself.\n";
			Dead();
		}
	}
}
void TeamMember::EquipWeapon(Weapon* w)
{
	equippedWeapon = w;
}


void TeamMember::DiscardWeapon()
{
	equippedWeapon = nullptr;
}
void TeamMember::Attack(Character& target)
{
	int damageToApply = attackStr;
	if (equippedWeapon)
	{
		damageToApply += equippedWeapon->getAttack();
		equippedWeapon->loseDurability();
	}

	std::cout << name << " attack " << target.name << "\n";
	std::cout << "You deal " << damageToApply << " damage\n";
	target.AddDamage(damageToApply);
}
void TeamMember::Check()
{ 
	std::cout << name << ", health:" << health << "/" << maxHealth << ", Stamina:" << stamina << "/" << maxStamina << ", Mental:" << mental << "/" << maxMental << "\n";
	int damageToApply = attackStr;
	if (equippedWeapon)
	{
		damageToApply += equippedWeapon->getAttack();
		equippedWeapon->loseDurability();
	}
	std::cout << "ATK:" << damageToApply << " DEF:" << defense<<"\n";
}

int TeamMember::GetATK() 
{
	int damageToApply = attackStr;
	if (equippedWeapon)
	{
		damageToApply += equippedWeapon->getAttack();
		
	}
	return damageToApply;
}
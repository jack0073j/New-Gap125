#pragma once
#include "Weapon.h"
#include "TeamMember.h"
class Player :
	public TeamMember
{
public:
	Player();
	~Player();
	Player(int HP, int ATK, int DEF, std::string NA, int STA, int MEN);
	void EquipWeapon(Weapon* WP);
	void DiscardWeapon();
	void Attack(Character& target) override;
	//void Check()override;
private:
	Weapon* equippedWeapon;
};

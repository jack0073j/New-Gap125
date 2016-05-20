#pragma once
#include "Weapon.h"
#include "Character.h"
class TeamMember :
	public Character
{
public:
	TeamMember();
	TeamMember(int HP, int ATK, int DEF, std::string NA, int STA, int MEN);
	~TeamMember();
	void AdjustMaxStamina(int i);
	void AdjustStamina(int i);
	void AdjustMaxMental(int i);
	void AdjustMental(int i);
	void EquipWeapon(Weapon* WP);
	void DiscardWeapon();
	void Attack(Character& target) override;
	void Check()  override;
	int GetATK();
protected:
	int maxStamina;
	int stamina;
	int maxMental;
	int mental;
	Weapon* equippedWeapon;
};
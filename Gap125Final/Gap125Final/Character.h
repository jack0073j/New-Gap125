#pragma once
class Character
{
public:
	Character(int HP, int ATK, int DEF, std::string NA);
	Character();
	~Character();
	std::string name;
	virtual void Attack(Character& target);
	void HealHealth(int);
	void AddDamage(int);
	virtual void Check();
	virtual void Dead();
	bool isDead;
	int GetAttackStr();
protected:
	int maxHealth;
	int health;

	int attackStr;
	int defense;
};


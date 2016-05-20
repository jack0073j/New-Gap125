#pragma once
class MotherBase
{
public:
	MotherBase();
	MotherBase(int f, int j);
	~MotherBase();
	int theBedCanUse=0;
	int GetFoodInt();
	int GetJunkInt();
	int GetBedInt();
	int GetTranquilizersInt();
	int GetFirstAidKitInt();
	float GetDefensePercentage();
	void AdjustFood(int i);
	void AdjustJunk(int i);
	void AdjustBed(int i);
	void AdjustTranquilizers(int i);
	void AdjustFirstAidKit(int i);
	void AdjustMaxDefense(int i);
	void AdjustDefense(int i);
	void MakeBed();
	void Check();
	bool garden= false;
	bool heater = false;
	bool kitchen = false;


private:
	int food=0;
	int junk=0;
	int tranquilizers=0;
	int firstAidKit = 0;
	int bed=0;
	int maxDefense=100;
	int defense=40;
};


#include <iostream>
#include <string>
#include <vector>
#include "MotherBase.h"
#include "TeamMember.h"
MotherBase::MotherBase()
{
}
MotherBase::MotherBase(int f, int j)
{
	food = f;
	junk = j;
	tranquilizers = 1;
	firstAidKit = 1;
	bed = 0;
	maxDefense = 100;
	defense = 45;
	theBedCanUse = 0;
}

MotherBase::~MotherBase()
{
}
int MotherBase::GetFoodInt() 
{
	return food;
}
int MotherBase::GetJunkInt()
{
	return junk;
}
int MotherBase::GetBedInt()
{
	return bed;
}
int MotherBase::GetFirstAidKitInt()
{
	return firstAidKit;
}
int  MotherBase::GetTranquilizersInt()
{
	return tranquilizers;
}
float MotherBase::GetDefensePercentage()
{
	float pe;
	pe = (float)defense / (float)maxDefense;
	return pe;
}

void MotherBase::AdjustFood(int i)
{
	food += i;
	if(food<=0)
	{
		food = 0;
	}
}
void MotherBase::AdjustJunk(int i)
{
	junk += i;
	if (i>0)
	{
		std::cout << "The house get " << i << " junk\n";

	}
	else if (i<0)
	{
		std::cout << "The house lose " << i << " junk\n";
		
	}
	if(junk<=0)
	{
		junk = 0;
	}
}
void MotherBase::AdjustBed(int i)
{
	bed += i;
	if (bed <= 0)
	{
		bed = 0;
	}
}
void MotherBase::AdjustFirstAidKit(int i) 
{
	firstAidKit += i;
	if (i>0)
	{
		std::cout << "You get " << i << " first aid kit\n";

	}
	else if (i<0)
	{
		std::cout << "You use " << i << " first aid kit\n";

	}
	if (firstAidKit <= 0)
	{
		firstAidKit = 0;
	}
}
void MotherBase::AdjustTranquilizers(int i)
{
	tranquilizers += i;
	if (i>0)
	{
		std::cout << "You get " << i << " Tranquilizer\n";

	}
	else if (i<0)
	{
		std::cout << "You use " << i << " Tranquilizer\n";

	}
	if (tranquilizers <= 0)
	{
		tranquilizers = 0;
	}
}
void MotherBase::AdjustMaxDefense(int i)
{
	maxDefense += i;
	if (i>0)
	{
		std::cout << "you strengthen the defenses of the house. now it has" << maxDefense << " max defense!\n";
		defense += i;
	}
	else if (i<0)
	{
		std::cout << "the house lose " << i << " max defense!\n";
		if (maxDefense = 10)
		{
			maxDefense = 10;
			
		}
	}
	
	
}
void MotherBase::AdjustDefense(int i)
{
	defense += i;

	if (i>0)
	{
		std::cout <<"The house heal " << i << " defense\n";
		
	}
	else if (i<0)
	{
		std::cout << "The house lose " << i << " defense\n";
		if (defense <= 0)
		{
			defense = 0;
		}
	}

	
}
void MotherBase::Check() 
{
	std::cout << "Defenses of the house:" << defense << "/" << maxDefense << " food:" << food << " junk:" << junk <<" tranquilizers:"<< tranquilizers<<" first Aid Kit:" << firstAidKit <<"\n";

}
void MotherBase::MakeBed()
{
	bed += 1;
	std::cout << "you build a new bed!";
}
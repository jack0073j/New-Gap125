#include <iostream>
#include <string>
#include <vector>
#include "MotherBase.h"
#include "TeamMember.h"
#include "DaytimeEvents.h"



DaytimeEvents::DaytimeEvents()
{
}


DaytimeEvents::~DaytimeEvents()
{
}

void DaytimeEvents::SetMB(MotherBase &MB)
{
	*motherBase = MB;
}

void DaytimeEvents::SetTM(TeamMember &TM)
{
	*teamMember = TM;
}

void DaytimeEvents::SetVTM(std::vector<TeamMember> &Vtm) 
{
	*teamMembers = Vtm;
}
int DaytimeEvents::ComputeTheHeaterPoint(int i, MotherBase m)
{
	int	addmantal = i;
	if (m.heater == true) {
		std:: cout << "The heater is working.\n";
		addmantal += 15;
	}
	return addmantal;

}


void DaytimeEvents::ShowDayTimeBasic(){}
void DaytimeEvents::ShowDayTimeUseItems() {}
void DaytimeEvents::ShowDayTimeBuild() {}

int DaytimeEvents::SleepOnFloor(TeamMember &tm, MotherBase &mb) 
{
	std::cout << tm.name << " go to sleep on the floor.\n";
	tm.AdjustMental(ComputeTheHeaterPoint(20, mb));
	return 2;

}
int DaytimeEvents::SleepOnBed(TeamMember &tm, MotherBase &mb) 
{
	if (mb.theBedCanUse >= 1) {
		std::cout << tm.name << " go to sleep on the bed.\n";

		tm.AdjustMental(ComputeTheHeaterPoint(45, mb));
		mb.theBedCanUse -= 1;
		return 2;
	}
	else
	{
		std::cout << "you don't have the enough bed to sleep";
		return 0;
	}
}


int DaytimeEvents::EatFood(TeamMember &tm, MotherBase &mb)
{
	if (mb.GetFoodInt() >= 1)
	{
		std::cout << tm.name << " eat a food.\n";
		mb.AdjustFood(-1);
		tm.AdjustStamina(50);
	}
	else
		std::cout << "you don't have enough food.\n";

	return 0;
}
int DaytimeEvents::EatTranquilizer(TeamMember &tm, MotherBase &mb)
{
	if (mb.GetTranquilizersInt() >= 1)
	{
		std::cout << tm.name << "eat a tranquilizers.\n";
		mb.AdjustTranquilizers(-1);
		tm.AdjustStamina(50);
	}
	else
		std::cout << "you don't have enough food.\n";
	return 0;
}
int DaytimeEvents::UseGarden(TeamMember &tm, MotherBase &mb)
{
	if (mb.garden == true) {

		std::cout << "you find 3 food.\n";
		mb.AdjustFood(3);
		tm.AdjustStamina(-20);
		return 2;
	}
	else
	{
		std::cout << "Unrecogn\n";
		return 0;
	}
	

}
int DaytimeEvents::UseKitchen(TeamMember &tm, MotherBase &mb, std::vector<TeamMember*> &allTm)
{
	if (mb.kitchen == true) {
		if (mb.GetFoodInt() >= allTm.size())
		{
			std::cout << tm.name << " use some food.\n";
			mb.AdjustFood((allTm.size()*-1));
			for (int i = 0; i < allTm.size(); i++)
			{
				allTm[i]->AdjustStamina(60);
			}
			tm.AdjustStamina(-20);
			
			return 2;
		}
		else
		{
			std::cout << "you do not have enough  food to do is. ";
			return 0;
		}

	}
	else
	{
		std::cout << "Unrecogn\n";
		return 0;
	}


}




int DaytimeEvents::FixHouse(TeamMember &tm, MotherBase &mb)
{
	if (mb.GetJunkInt() >= 10)
	{
		mb.AdjustJunk(-10);
		mb.AdjustDefense(10);
		tm.AdjustStamina(-20);
		return 2;
	}
	else
	{
		std::cout << "you don't have enough junk.";
		return 0;
	}
}
int DaytimeEvents::StrengthenHouse(TeamMember &tm, MotherBase &mb) 
{
	if (mb.GetJunkInt() >= 30)
	{
		mb.AdjustJunk(-30);

		tm.AdjustStamina(-20);
		return 2;
	}
	else
	{
		std:: cout << "you don't have enough junk.";
		return 0;
	}
}
int DaytimeEvents::BuildBed(TeamMember &tm, MotherBase &mb) 
{
	if (mb.GetJunkInt() >= 30)
	{
		mb.AdjustJunk(-30);
		mb.MakeBed();
		tm.AdjustStamina(-20);
		return 2;
	}
	else
	{
		std::cout << "you don't have enough junk.\n";
		return 0;
	}
}
int DaytimeEvents::BuildGarden(TeamMember &tm, MotherBase &mb)
{
	if (mb.garden == false) {
		if (mb.GetJunkInt() >= 60)
		{
			mb.AdjustJunk(-60);
			mb.garden = true;
			std:: cout << "you build a garden.!\n";
			tm.AdjustStamina(-20);
			return 2;
		}
		else
		{
			std::cout << "you don't have enough junk.\n";
			return 0;
		}
	}
	else
	{
		std::cout << "Unrecogn\n";
		return 0;
	}
}
int DaytimeEvents::BuildHeater(TeamMember &tm, MotherBase &mb)
{
	if (mb.heater == false) {
		if (mb.GetJunkInt() >= 100)
		{
			mb.AdjustJunk(-100);
			mb.heater = true;
			std::cout << "you build a heater.!\n";
			tm.AdjustStamina(-20);
			return 2;
		}
		else
		{
			std::cout << "you don't have enough junk.\n";
			return 0;
		}
	}
	else
	{
		std::cout << "Unrecogn\n";
		return 0;
	}
}
int DaytimeEvents::BuildKitchen(TeamMember &tm, MotherBase &mb) 
{
	if (mb.kitchen == false) {
		if (mb.GetJunkInt() >= 80)
		{
			mb.AdjustJunk(-80);
			mb.heater = true;
			std::cout << "you build a kitchen.!\n";
			tm.AdjustStamina(-20);
			return 2;
		}
		else
		{
			std::cout << "you don't have enough junk.\n";
			return 0;
		}
	}
	else
	{
		std::cout << "Unrecogn\n";
		return 0;
	}
}
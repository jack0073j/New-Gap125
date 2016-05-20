#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "MotherBase.h"
#include "TeamMember.h"
#include "NighttimeEvents.h"

NighttimeEvents::NighttimeEvents()
{
	srand(time(NULL));
	nightWatchAttack = 0;
}

NighttimeEvents::~NighttimeEvents()
{
}
int NighttimeEvents::ComputeTheHeaterPoint(int i, MotherBase m)
{
	int	addmantal = i;
	if (m.heater == true) {
		std::cout << "The heater is working.\n";
		addmantal += 15;
	}
	return addmantal;

}
int NighttimeEvents::FindSupplies(TeamMember &tm, MotherBase &mb) 
{ 
	int  findFood=0;
	int  findJunk=0;
	int  findTranquilizers=0;
	int  findFirstAidKit=0;
	srand(time(NULL));
	int targetNam;
	targetNam = rand() % 100 + 1;

	if (targetNam <= 20)
	{
		std::cout << tm.name << " find some supplies.";
		findFood+= rand() % 3 + 1;
		findJunk+= rand() % 18 + 1;
		findTranquilizers += rand() % 3 + 1;
		findFirstAidKit += rand() % 3 + 1;

		mb.AdjustFood(findFood);
		mb.AdjustJunk(findJunk);
		mb.AdjustTranquilizers(findTranquilizers);
		mb.AdjustFirstAidKit(findFirstAidKit);
	}
	else if (targetNam <= 80)
	{
		std::cout << tm.name << " can not find any supplies tonight.\n";
	}
	else
	{
		std::cout << tm.name << " make Too much noise! Zombies attack " << tm.name << ".\n";
		int Damage = rand() % 20 + 1;
		tm.AddDamage(Damage);
	}
	return 2; 
}



int NighttimeEvents::FindSurvivor(TeamMember &tm, MotherBase &mb, std::vector<TeamMember*> &allTm) 
{
	srand(time(NULL));
	int targetNam;
	targetNam = rand() % 100 + 1;
	//int stage = 0;

	if (targetNam <= 20)
	{
		std::cout << tm.name<<" find a new survivor! what is his name?";
		std::string newName;
		std::cin >> newName;
		int rHP = rand() % 200 + 1;
		int rATK = rand() % 50 + 1;
		int rDEF = rand() % 50 + 1;
		int rSTA = rand() % 200 + 1;
		int rMEN = rand() % 200 + 1;
		allTm.push_back(new TeamMember(rHP, rATK, rDEF, newName, rSTA, rMEN));
			
	}
	else if (targetNam<=80)
	{
		std::cout << tm.name<<" can not find any people tonight.\n";
	}
	else
	{
		std::cout <<tm.name<< " make Too much noise! Zombies attack "<<tm.name <<".\n";
		int Damage = rand() % 20 + 1;
		tm.AddDamage(Damage);
	}
	return 2;
}


int NighttimeEvents::NightWatch(TeamMember &tm, MotherBase &mb)
{ 
	std::cout << tm.name << " will be the Night Watch tonight.\n";
	tm.AdjustMental(-20);
	if (tm.isDead == false) {
		//nightWatchTM.push_back(tm);
		int i = tm.GetATK();
		nightWatchAttack += i;

	}
	else
	{
		std::cout << tm.name << " is dead he can not be the Night Watch.\n";
	}
	return 2; 
}

int NighttimeEvents::SleepOnFloor(TeamMember &tm, MotherBase &mb) 
{
	std::cout << tm.name << " go to sleep on the floor.\n";
	tm.AdjustMental(ComputeTheHeaterPoint(20, mb));
	return 2;
}

int NighttimeEvents::SleepOnBed(TeamMember &tm, MotherBase &mb) 
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
void NighttimeEvents::NightAttack(MotherBase &mb)
{
	srand(time(NULL));
	int targetNam;
	targetNam = rand() % 100 + 1;
	if (targetNam <= 50)
	{
		if (mb.GetDefensePercentage() >= 0.5) 
		{
			std::cout << "someone tryed to broke into the house last night. but they did not succeed.\n";
			mb.AdjustDefense(-10);
		}
		else
		{
			std::cout << "someone  brokeed into the house last night.\n";
			mb.AdjustDefense(-10);
			int randAttack;
			randAttack= rand() % 25 + 1;
			//if (nightWatchTM.size() > 0) {
			if(nightWatchAttack>0){
				if (nightWatchAttack >= randAttack)
				{
					std::cout << "the night watch successful protect the house";
				}
				else
				{

					std::cout << "the night watch did not succeed for protect the house";
					std::cout << "they stoled something .";
					/*
					std::cout << "they stoled something and attack our people.";
					for (int i = 0; i < nightWatchTM.size(); i++)
					{
						nightWatchTM[i].AddDamage(randAttack);
						
					}*/

					mb.AdjustFood(-5);
					mb.AdjustJunk(-10);
				}
			}
			else
			{
				std::cout << "there was no one watch the house so they stoled something .\n";
				mb.AdjustFood(-5);
				mb.AdjustJunk(-10);
			}
		}
	}
	else
	{
		
	}

}


void Fighting(TeamMember &tm)
{
	int PInput = 0;
	bool isFighting=true;
	while (isFighting)
	{
		std::cout <<"What does "<< tm.name << "want to do?\n";
		std::cout << "(1) Attack.\n";
		std::cout << "(2) Escape.\n";
		std::cout << "(3) Use First Aid Kit";
		std::cin >> PInput;
		switch (PInput)
		{
		case 1:
		{
			
			break;
		}
		case 2:
		{
		
			break;
		}
		case 3:
		{
			
			break;
		}
		
		default:
		{
			std::cout << "Unrecogn\n";
			break;
		}
		}
	}

}
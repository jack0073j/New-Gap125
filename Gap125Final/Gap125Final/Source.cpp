#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>

#include "Character.h"
#include "TeamMember.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "MotherBase.h"
#include "DaytimeEvents.h"
#include "NighttimeEvents.h"

using namespace std;

void showInfo(int Day)
{
	cout << "Day:"<<Day<<"\n";
}
void ShowAllTeamMemberInfo(vector<TeamMember*> &teamMember)
{
	for (int i = 0; i < teamMember.size(); i++)
	{
		teamMember[i]->Check();
	}
}


void theDay(TeamMember &tm, MotherBase &mb, vector<TeamMember*> &allTm, DaytimeEvents &day)
{
	int PlayerInput = 0;
	//string characterName = tm.name;
	

	tm.Check();
	bool isCompleteThisPerson;
	isCompleteThisPerson = false;
	while (!isCompleteThisPerson)
	{
		int stage = 0;
		mb.Check();
		if (0 == stage) {
			cout << "What does " << tm.name << "  want to do at day time?\n";
			cout << "(1).Eat food or Use Items.\n";
			cout << "(2).Build something.\n";
			cout << "(3).Go to sleep on the floor.\n";
			cout << "(4).Go to sleep on the bed.(" << mb.theBedCanUse << "bed eft over)\n";
			cin >> PlayerInput;
			stage += 1;
		}

		switch (PlayerInput)
		{
		case 1:
		{
			cout << "What does " << tm.name << "want to use?\n";
			cout << "(1).eat food.\n";
			cout << "(2).use tranquilizer.\n";
			if (mb.garden == true)
				cout << "(3) go to garden and make find some food.\n";
			if (mb.kitchen == true)
				cout << "(4) go to kitchen and make food for everyone.\n";
			cout << "(0).cancel.\n";
			cin >> PlayerInput;

			switch (PlayerInput)
			{
			case 1:
			{
				stage = day.EatFood(tm, mb);
				break;
			}
			case 2:
			{
				stage = day.EatTranquilizer(tm, mb);
				break;
			}
			case 3:
			{
				stage = day.UseGarden(tm, mb);
				break;
			}
			case 4:
			{
				stage = day.UseKitchen(tm, mb, allTm);
				break;
			}
			
			default:
			{
				cout << "Unrecogn\n";
				stage = 0;
				break;
			}
			}
			break;
		}
		case 2://(2).Search for Junk.\n
		{
			cout << "(1).Fix the house.(10 Junk)\n";
			cout << "(2).Strengthen the defenses of the house.(30 Junk)";
			cout << "(3).Build a bed.(30 Junk)\n";
			if (mb.garden == false)
				cout << "(4).Build a garden.(60 Junk)\n";
			if (mb.heater == false)
				cout << "(5)Fix the heater.(100 Junk)\n";
			if (mb.kitchen == false)
				cout << "(6)Build the kitchen.(80 Junk)\n";
			cin >> PlayerInput;

			switch (PlayerInput)
			{
			case 1:
			{	
				stage = day.FixHouse(tm, mb);
				break;
			}
			case 2:
			{
				stage = day.StrengthenHouse(tm, mb);
				break;
			}
			case 3:
			{
				stage = day.BuildBed(tm, mb);
				break;
			}
			case 4:
			{
				stage = day.BuildGarden(tm, mb);
				break;
			}
			case 5:
			{
				stage = day.BuildHeater(tm, mb);
				break;
			}
			case 6:
			{
				stage = day.BuildKitchen(tm, mb);
				break;
			}
			default:
			{
				cout << "Unrecogn\n";
				stage = 0;
				break;
			}
			}

			break;
		}
		case 3:
		{
			stage = day.SleepOnFloor(tm, mb);
			break;
		}
		case 4:
		{
			stage= day.SleepOnBed(tm, mb);
			break;

		}
		default:
		{
			cout << "Unrecogn\n";
			stage = 0;
			break;
		}
		}

		if (stage == 2)
		{
			isCompleteThisPerson = true;
		}

	}
}

void theNight(TeamMember &tm, MotherBase &mb, vector<TeamMember*> &allTm, NighttimeEvents &night) 
{
	int PlayerInput = 0;
	//string characterName = tm.name;


	tm.Check();
	bool isCompleteThisPerson;
	isCompleteThisPerson = false;
	while (!isCompleteThisPerson)
	{
		int stage = 0;
		mb.Check();
		if (0 == stage) {
			cout << "What does " << tm.name << "  want to do at day time?\n";
			cout << "(1).Go out and find Supplies.\n";
			cout << "(2).Go out and find survivor.\n";
			cout << "(3) Be the Night Watch.\n";
			cout << "(4).Go to sleep on the floor.\n";
			cout << "(5).Go to sleep on the bed.(" << mb.theBedCanUse << " bed eft over)\n";
			cin >> PlayerInput;
			isCompleteThisPerson = true;
			stage += 1;
		}


		switch (PlayerInput)
		{
		case 1:
		{
			stage = night.FindSupplies(tm, mb);
			break;
		}
		case 2:
		{
			stage = night.FindSurvivor(tm, mb, allTm);
			break;
		}
		case 3:
		{
			stage = night.NightWatch(tm, mb);
			break;
		}
		case 4:
		{
			stage = night.SleepOnFloor(tm, mb);
			break;
		}
		case 5:
		{
			stage = night.SleepOnBed(tm, mb);
			break;
		}
		default:
		{
			cout << "Unrecogn\n";
			stage = 0;
			break;
		}
		}
		if (stage == 2)
		{
			isCompleteThisPerson = true;
		}
	}
}
//void EatFood(){}
int main()
{
	bool isActive = true;
	int state = 0;
	int day = 0;
	DaytimeEvents Day;
	NighttimeEvents Night;
	
	string inputString = "";
	int inputInt = 0;
	
	MotherBase motherBase(20, 20);
	vector<TeamMember*> teamMember;

//	srand(time(NULL));
	while (isActive)
	{
		//-------------------
		//Introduction
		//-------------------
		if (state == 0)
		{
			day = 1;
			cout << "Some Introduction.\n";
			//Player.ResetResources();
			cout << "Enter your first team member name.\n";
			cin >> inputString;
			teamMember.push_back(new TeamMember(100, 10, 10, inputString, 100, 100));
			//Player player(100, 10, 10, inputString, 100, 100);

			cout << "Enter your second team member name.\n";
			cin >> inputString;
			teamMember.push_back(new TeamMember(80, 10,6, inputString, 100, 120));

			cout << "Enter your third team member name.\n";
			cin >> inputString;
			teamMember.push_back(new TeamMember(100, 10, 10, inputString, 100, 50));


			state += 1;
			cout << "Enter anything to continue.\n";
			cin >> inputString;
		}
		//-------------------
		//Game Play-day
		//-------------------
		else if (state == 1)
		{
			cout << "______________________________________________\n";
			showInfo(day);
			motherBase.Check();
			ShowAllTeamMemberInfo(teamMember);
			cout << "______________________________________________\n";
			//std::fill(teamMember.begin(), teamMember.end(), 0);
			cout << "Enter anything to continue.\n";
			cin >> inputString;
			
			//-------------------
			//Game Play-EACH DAY
			//-------------------
			
			motherBase.theBedCanUse= motherBase.GetBedInt();
			for (int i = 0; i < teamMember.size(); i++)
			{
				theDay(*teamMember[i], motherBase, teamMember,Day);
				cout << "______________________________________________\n";
			}
			for (int i = 0; i < teamMember.size(); i++)
			{
				if (teamMember[i]->isDead == true)
					teamMember.erase(teamMember.begin() + (i));
			}
			if (teamMember.size() <= 0) {
				cout << "Everyone is dead.Game over.\n";
				cout << "Enter anything to continue.\n";
				cin >> inputString;
				isActive = false;
			}
			
			//-------------------
			//Game Play-Night
			//-------------------
			cout << "the night is comeing!\n";
			motherBase.theBedCanUse = motherBase.GetBedInt();
			Night.nightWatchAttack = 0;
			//Night.nightWatchTM.erase(Night.nightWatchTM.begin(), Night.nightWatchTM.end());
			for (int i = 0; i < teamMember.size(); i++)
			{
				theNight(*teamMember[i], motherBase, teamMember,Night);
				cout << "______________________________________________\n";
			}
			Night.NightAttack(motherBase);
			for (int i = 0; i < teamMember.size(); i++)
			{
				if (teamMember[i]->isDead == true)
					teamMember.erase(teamMember.begin() + (i));
			}
			if (teamMember.size() <= 0) {
				cout << "Everyone is dead.Game over.\n";
				cout << "Enter anything to continue.\n";
				cin >> inputString;
				isActive = false;
			}
			day += 1;
		}
	}
}
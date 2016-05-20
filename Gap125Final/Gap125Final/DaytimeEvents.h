#pragma once
#include "MotherBase.h"
#include "TeamMember.h"
class DaytimeEvents
{
public:
	DaytimeEvents();
	//DaytimeEvents();
	~DaytimeEvents();
	void SetMB(MotherBase &MB);
	void SetTM(TeamMember &TM);
	void SetVTM(std::vector<TeamMember> &Vtm);
	int ComputeTheHeaterPoint(int i, MotherBase m);
	void ShowDayTimeBasic();
	void ShowDayTimeUseItems();
	void ShowDayTimeBuild();

	int SleepOnFloor(TeamMember &tm, MotherBase &mb);
	int SleepOnBed(TeamMember &tm, MotherBase &mb);

	int EatFood(TeamMember &tm, MotherBase &mb);
	int EatTranquilizer(TeamMember &tm, MotherBase &mb);
	int UseGarden(TeamMember &tm, MotherBase &mb);
	int UseKitchen(TeamMember &tm, MotherBase &mb, std::vector<TeamMember*> &allTm);

	int FixHouse(TeamMember &tm, MotherBase &mb);
	int StrengthenHouse(TeamMember &tm, MotherBase &mb);
	int BuildBed(TeamMember &tm, MotherBase &mb);
	int BuildGarden(TeamMember &tm, MotherBase &mb);
	int BuildHeater(TeamMember &tm, MotherBase &mb);
	int BuildKitchen(TeamMember &tm, MotherBase &mb);


protected:
	MotherBase *motherBase;
	TeamMember *teamMember;
	std::vector<TeamMember> *teamMembers;
};


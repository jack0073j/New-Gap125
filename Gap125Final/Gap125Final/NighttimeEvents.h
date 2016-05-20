#pragma once
#include "MotherBase.h"
#include "TeamMember.h"
class NighttimeEvents
{
public:
	NighttimeEvents();
	~NighttimeEvents();
	int ComputeTheHeaterPoint(int i, MotherBase m);
	//std::vector<TeamMember> &nightWatchTM;
	int nightWatchAttack;
	int FindSupplies(TeamMember &tm, MotherBase &mb);
	int FindSurvivor(TeamMember &tm, MotherBase &mb, std::vector<TeamMember*> &allTm);
	int NightWatch(TeamMember &tm, MotherBase &mb);
	int SleepOnFloor(TeamMember &tm, MotherBase &mb);
	int SleepOnBed(TeamMember &tm, MotherBase &mb);

	void NightAttack(MotherBase &mb);
//private:


};


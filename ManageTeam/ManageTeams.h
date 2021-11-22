#pragma once
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Team/Team.h"
#include <QSql>
#include "../Db/Database/DbManager.h"
#include "Graph.h"
#include "../orderedMap/orderedMap.h"

class ManageTeams
{
public:
    ManageTeams();
    void ReadData();
    void AddTeam(Team& newTeam);
    void RemoveTeam(Team& toRemove);
    void ShortestPath();
    mapADT<Team> &GetTravelPlan();
    deque<Team*>& GetShortTravelPlan();
    void setStartingTeam(const string& initial);
    [[nodiscard]] const mapADT<Team>& GetTeams() const;
    void graphPrep();

protected:
    DbManager teamManager;
public:
    static mapADT<Team> TeamMap;
    static deque<Team*> shortTravelPlan;
    static mapADT<Team> travelPlan;
    Graph g;
    Team startingTeam;
};

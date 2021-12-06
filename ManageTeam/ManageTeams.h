#pragma once
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Team/Team.h"
#include <QSql>
#include "../DB/Database/DbManager.h"
#include "ManageTeam/Graph/Graph.h"
#include "../orderedMap/orderedMap.h"

class ManageTeams
{
public:
    ManageTeams();
    void ReadData();
    void AddTeam(Team& newTeam);
    void RemoveTeam(Team& toRemove);
    mapADT<Team> &GetTravelPlan();
    void setStartingTeam(const string& initial);
    [[nodiscard]] const mapADT<Team>& GetTeams() const;
    void graphPrep();

protected:
    DbManager teamManager;

public:
    static mapADT<Team> TeamMap;
    static mapADT<Team> travelPlan;
    int totalSeatCap = 0;
    vector<string> teamsToTravelTo;
    Graph g;
    Team startingTeam;
};

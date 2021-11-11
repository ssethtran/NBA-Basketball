#pragma once
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Team/Team.h"
#include "../Db/Database/DbManager.h"
#include "../orderedMap/orderedMap.h"

class ManageTeams
{
public:
    ManageTeams();
    void ReadData();
    void AddTeam(Team& newTeam);
    void RemoveTeam(Team& toRemove);
    [[nodiscard]] const mapADT<Team>& GetTeams() const;

protected:
    DbManager teamManager;
private:
    mapADT<Team> TeamMap;
};

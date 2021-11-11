#include "ManageTeams.h"
#include "Team/Team.h"
#include <iterator>
#include "../orderedMap/orderedMap.h"

bool operator == (Team& t1, Team& t2){
    if (t1.team_name == t2.team_name)
        return true;
    return false;
}

ManageTeams::ManageTeams() {

}

void ManageTeams::ReadData() {
    //euroCities.clear();
//    dataManager.printTeams();

    QSqlQuery query("SELECT * FROM teamsInfo");
    while (query.next())
    {
        Team* testTeam = new Team(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(),
                                  query.value(3).toString().toStdString(), query.value(4).toString().toStdString(), query.value(5).toInt(),
                                  query.value(6).toInt(), query.value(7).toString().toStdString());
        TeamMap.insert(*testTeam);
        if ((TeamMap.search(*testTeam)))
        {
            TeamMap.search(*testTeam)->printTeamInfo();
        }
        else
            cout << "null\n";

    }
}

void ManageTeams::AddTeam(Team& newTeam){
    TeamMap.insert(newTeam);
}

void ManageTeams::RemoveTeam(Team &toRemove) {
    TeamMap.del(toRemove);
}

const mapADT<Team>& ManageTeams::GetTeams() const {
    return TeamMap;
}


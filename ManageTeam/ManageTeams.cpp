#include "ManageTeams.h"
#include "Team/Team.h"
#include <iterator>
#include "../orderedMap/orderedMap.h"

mapADT<Team> ManageTeams::TeamMap;
mapADT<Team> ManageTeams::travelPlan;

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
        totalSeatCap += testTeam->stadCap;
        cout << "Inserting team into TeamMap...\nTEAM INSERTED:\n";
        if ((TeamMap.search(*testTeam)))
        {
            TeamMap.search(*testTeam)->printTeamInfo();
        }
        else
            cout << "null\n";

    }
    cout << "PRINTING OUT SOUVENIRS...\n";
    QSqlQuery souvenirsQuery1("SELECT * FROM teamsInfo");
    while (souvenirsQuery1.next())
    {
        QSqlQuery souvenirsQuery2("SELECT * FROM souvenirs WHERE team_name IS '" + souvenirsQuery1.value(2).toString() + "';");
        while (souvenirsQuery2.next())
        {
            Souvenir souvenir;
            souvenir.souvenirName = souvenirsQuery2.value(1).toString().toStdString();
            souvenir.cost = souvenirsQuery2.value(2).toDouble();
            cout << "Team: " << souvenirsQuery2.value(0).toString().toStdString() << endl;
            souvenir.printSouvenir();

            // Searching for team in the TeamMap
            Team* toSearch = new Team("", "", souvenirsQuery2.value(0).toString().toStdString(), "", "", 0, 0, "");
            TeamMap.search(*toSearch)->souvenirList.push_back(souvenir);
        }
    }
    graphPrep();



}

void ManageTeams::AddTeam(Team& newTeam){
    TeamMap.insert(newTeam);
}

void ManageTeams::RemoveTeam(Team &toRemove) {
    TeamMap.del(toRemove);
}

void ManageTeams::graphPrep() {
    vector<string> iN(0, "");
    for (auto & team : ManageTeams::TeamMap.GetTree())
    {
        if (team != NULL)
            iN.push_back(team->team_name);
    }
    g = Graph(iN);
    QSqlQuery distancesQuery("SELECT * from distances");
    while (distancesQuery.next())
    {
        g.addEdge(distancesQuery.value(0).toString().toStdString(), distancesQuery.value(2).toString().toStdString(),
                  distancesQuery.value(3).toDouble());
    }

}

mapADT<Team> &ManageTeams::GetTravelPlan(){
    return travelPlan;
}

void ManageTeams::setStartingTeam(const string &initial) {
    this->startingTeam.setTeamName(initial);
}

const mapADT<Team>& ManageTeams::GetTeams() const {
    return TeamMap;
}


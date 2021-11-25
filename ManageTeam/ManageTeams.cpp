#include "ManageTeams.h"
#include "Team/Team.h"
#include <iterator>
#include "../orderedMap/orderedMap.h"

mapADT<Team> ManageTeams::TeamMap;
deque<Team*> ManageTeams::shortTravelPlan;
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
        if ((TeamMap.search(*testTeam)))
        {
            TeamMap.search(*testTeam)->printTeamInfo();
        }
        else
            cout << "null\n";

    }
    QSqlQuery souvenirsQuery1("SELECT * FROM teamsInfo");
    while (souvenirsQuery1.next())
    {
        QSqlQuery souvenirsQuery2("SELECT * FROM souvenirs WHERE team_name IS '" + souvenirsQuery1.value(2).toString() + "';");
        while (souvenirsQuery2.next())
        {
            Souvenir thisSouvenir;
            thisSouvenir.souvenirName = souvenirsQuery2.value(1).toString().toStdString();
            thisSouvenir.cost = souvenirsQuery2.value(2).toDouble();
            cout << souvenirsQuery2.value(0).toString().toStdString() << "      " << thisSouvenir.souvenirName << "        " << thisSouvenir.cost << endl;
            Team* toSearch = new Team("", "", souvenirsQuery2.value(0).toString().toStdString(), "", "", 0, 0, "");
            TeamMap.search(*toSearch)->souvenirList.push_back(thisSouvenir);
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

//void ManageTeams::ShortestPath() {
//    bool found;
//
//    travelPlan.search(startingTeam)->distance = 0;
//    shortTravelPlan.push_back(travelPlan.search(startingTeam));
//    travelPlan.del(*(travelPlan.search(startingTeam)));
//
//    QSqlQuery distanceList("SELECT ending_team_name, distance from distances WHERE beginning_team_name IS '"
//        + QString::fromStdString(startingTeam.team_name) + "' ORDER BY distance");
//
//    distanceList.next();
//    auto group = distanceList.value(0);
//    while (!travelPlan.GetTree().empty()) {
//        found = false;
//        group = distanceList.begin();
//        while (!found && group != distanceList.end()) {
//            auto target = travelPlan.find(group->at(0));
//            if (target != travelPlan.end()) {
//                found = true;
//                target->second->distance = stoi(group->at(1));
//                shortTravelPlan.push_back(target->second);
//                sql = "SELECT ending_city,kilometers from distance WHERE starting_city IS '" +
//                      group->at(0) + "' ORDER BY kilometers;";
//                distanceList = cityDatabase.select_stmt(sql.c_str());
//                travelPlan.erase(target);
//            }
//            group++;
//        }
//    }
//}

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

deque<Team *> &ManageTeams::GetShortTravelPlan() {
    return shortTravelPlan;
}

void ManageTeams::setStartingTeam(const string &initial) {
    this->startingTeam.setTeamName(initial);
}

const mapADT<Team>& ManageTeams::GetTeams() const {
    return TeamMap;
}


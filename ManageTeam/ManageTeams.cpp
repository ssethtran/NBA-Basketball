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
    //Clearing data of the tree===================================
    //Clearing souvenirList vector of each team
    for (int i = 0; i < TeamMap.GetTree().size(); i++) {
        if (TeamMap.GetTree()[i] != nullptr)
            TeamMap.GetTree()[i]->souvenirList.clear();
    }
    TeamMap.clearTree(); //clearing out each team

    g.dist.clear(); //clearing out dist vector of the g (the Graph)
    //===============================================================

    //Inputting data from databases===================================
    cout << "INSERTING TEAMS INTO TeamMap...\n\n";
    stack<int> stadCaps;
    QSqlQuery query("SELECT * FROM teamsInfo");
    while (query.next()) {
        //Creating a new team based off each entry in the database
        Team* team = new Team(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(),
                              query.value(3).toString().toStdString(), query.value(4).toString().toStdString(), query.value(5).toInt(),
                              query.value(6).toInt(), query.value(7).toString().toStdString());
        stadCaps.push(query.value(5).toInt());
        TeamMap.insert(*team); //inserting Team into the TeamMap
        cout << "TEAM INSERTED:\n";
        //Searching for the inserted Team in the TeamMap
        if ((TeamMap.search(*team)))
            TeamMap.search(*team)->printTeamInfo(); //if it's found, it would print the team's information out
        else
            cout << "NULL\n\n"; //if it's not found, it would print out NULL
    }

    // popping stack to determine total seating capacity
    while (!stadCaps.empty()) {
        totalSeatCap += stadCaps.top();
        stadCaps.pop();
    }

    cout << "PRINTING OUT SOUVENIRS...\n\n";
    QSqlQuery souvenirsQuery1("SELECT * FROM teamsInfo");
    while (souvenirsQuery1.next()) {
        QSqlQuery souvenirsQuery2("SELECT * FROM souvenirs WHERE team_name IS '" + souvenirsQuery1.value(2).toString() + "';");
        while (souvenirsQuery2.next()) {
            //Assigning information to the souvenir
            Souvenir souvenir;
            souvenir.souvenirName = souvenirsQuery2.value(1).toString().toStdString();
            souvenir.cost = souvenirsQuery2.value(2).toDouble();
            //Printing souvenir information
            cout << "Team: " << souvenirsQuery2.value(0).toString().toStdString() << endl;
            souvenir.printSouvenir();

            //Searching for team in the TeamMap
            Team* toSearch = new Team("", "", souvenirsQuery2.value(0).toString().toStdString(), "", "", 0, 0, "");
            TeamMap.search(*toSearch)->souvenirList.push_back(souvenir);
        }
    }
    //===============================================================

    graphPrep(); //preparing the graph
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
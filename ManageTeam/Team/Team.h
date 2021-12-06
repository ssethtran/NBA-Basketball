#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <QPoint>
using namespace std;

class Souvenir {
public:
    string souvenirName;
    double cost;
    int amountBought;
    double amountSpent;

    Souvenir(){
        souvenirName = "";
        cost = 0;
        amountBought = 0;
        amountSpent = 0;
    }

    Souvenir(string souvenirName, double cost):
        souvenirName{souvenirName}, cost{cost}
    {
        amountBought = 0;
        amountSpent = 0;
    }

    void purchase(int amt)
    {
        amountBought = amt;
        amountSpent = amountBought * cost;
    };

    void printSouvenir() const {
        cout << "Souvenir: " << souvenirName << "\nCost: $" << cost << "\n\n";
    }
};

class Team{
public:
    string conference;
    string division;
    string team_name;
    string location;
    string arena_name;
    int stadCap;
    int joinedLeague;
    string coach;
    double distance;
    vector<Souvenir> souvenirList;

    Team(){
        conference = "";
        division = "";
        team_name = "";
        location = "";
        arena_name = "";
        stadCap = 0;
        joinedLeague = 0;
        coach = "";
        distance = 0.0;
    }
    Team(string conference, string division, string team_name, string location, string arena_name, int stadCap,
         int joinedLeague, string coach) :
            conference{conference}, division{division}, team_name{team_name}, location{location}, arena_name{arena_name},
            stadCap{stadCap}, joinedLeague{joinedLeague}, coach{coach} {
        distance = 0;
    };
    void printTeamInfo()
    {
        cout << team_name << "    " << arena_name << endl;
    }

    void setTeamName(string team_name)
    {
        this->team_name = team_name;
    }

    void addSouvenir(Souvenir toAdd)
    {
        souvenirList.push_back(toAdd);
    }

    void deleteSouvenir(int indexToDelete)
    {
        souvenirList.erase(souvenirList.begin() + indexToDelete, souvenirList.begin() + indexToDelete + 1);
    }

    friend bool operator == (Team& t1, Team& t2);

    bool operator > (const Team& team2){
        if(team_name > team2.team_name){
            return true;
        }
        return false;
    }

    bool operator < (const Team& team2){
        if(team_name < team2.team_name){
            return true;
        }
        return false;
    }

};

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

    Souvenir() {
        souvenirName = "";
        cost = 0;
        amountBought = 0;
        amountSpent = 0;
    }

    Souvenir(string souvenirName, double cost):
        souvenirName{std::move(souvenirName)}, cost{cost}
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
        cout << "Souvenir: " << souvenirName << "\nCost: " << cost << "\n\n";
    }
};

class Team{
public:
    string conference;
    string division;
    string team_name;
    string location;
    string arena_name;
    int stadiumCap;
    int joinedLeague;
    string coach;
    vector<Souvenir> souvenirList;

    Team(){
        conference = "";
        division = "";
        team_name = "";
        location = "";
        arena_name = "";
        stadiumCap = 0;
        joinedLeague = 0;
        coach = "";
    }

    Team(string conference, string division, string team_name, string location, string arena_name, int stadiumCap,
         int joinedLeague, string coach) :
            conference{std::move(conference)}, division{std::move(division)}, team_name{std::move(team_name)},
            location{std::move(location)}, arena_name{std::move(arena_name)}, stadiumCap{stadiumCap},
            joinedLeague{joinedLeague}, coach{std::move(coach)} {};

    void printTeamInfo() const {
        cout << "Team: " << team_name << "\nArena: " << arena_name << "\n\n";
    }

    void setTeamName(string teamName) {
        team_name = std::move(teamName);
    }

    void addSouvenir(const Souvenir& toAdd) {
        souvenirList.push_back(toAdd);
    }

    void deleteSouvenir(int indexToDelete) {
        souvenirList.erase(souvenirList.begin() + indexToDelete, souvenirList.begin() + indexToDelete + 1);
    }

    friend bool operator == (Team& t1, Team& t2);

    bool operator > (const Team& team2) const{
        if(team_name > team2.team_name){
            return true;
        }
        return false;
    }

    bool operator < (const Team& team2) const{
        if(team_name < team2.team_name){
            return true;
        }
        return false;
    }
};

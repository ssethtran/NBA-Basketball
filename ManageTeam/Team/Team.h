#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <QPoint>
using namespace std;

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

    Team(){
        conference = "";
        division = "";
        team_name = "";
        location = "";
        arena_name = "";
        stadCap = 0;
        joinedLeague = 0;
        coach = "";
    }
    Team(string conference, string division, string team_name, string location, string arena_name, int stadCap,
         int joinedLeague, string coach) :
            conference{conference}, division{division}, team_name{team_name}, location{location}, arena_name{arena_name},
            stadCap{stadCap}, joinedLeague{joinedLeague}, coach{coach} {};
    void printTeamInfo()
    {
        cout << team_name << "    " << arena_name << endl;
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

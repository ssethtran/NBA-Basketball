//
// Created by 4ktra on 12/2/2021.
//

#ifndef NBA_BASKETBALL_ADMIN_H
#define NBA_BASKETBALL_ADMIN_H

#endif //NBA_BASKETBALL_ADMIN_H

#include "../ManageTeam/ManageTeams.h"
#include "../DB/Database/DbManager.h"

class Admin : public ManageTeams {
public:
    void addNewTeam();
    void changePrice(const string& teamName, const string& souvenir, const string& cost);
    void addNewSouvenir(const string& teamName, const string& souvenir, const string& cost);
    void removeSouvenir(const string& teamName, const string& souvenir);
    void changeArena(const string& teamName, const string& arena);
    void changeCapacity(const string& teamName, const string& capacity);
    vector<string> readingAvailableTeams();
    vector<string> readingNewTeams();
    vector<string> readingSouvenirs(const string& teamName);

private:
    vector<string> readNewTeams;
    vector<string> readAvailableTeams;
    vector<string> readSouvenirs;
    QSqlDatabase m_db;
};
//
// Created by 4ktra on 12/2/2021.
//

#include "Admin.h"

void Admin::addNewTeam() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query("SELECT * FROM expansion");
    while (query.next()) {
        //Inserting new team information into the teamsInfo database
        QSqlQuery query1;
        query1.prepare("INSERT INTO teamsInfo (conference, division, team_name, location, arena_name,"
                       "stadium_capacity, joined_league, coach) VALUES (:conference, :division, :team_name,"
                       ":location, :arena_name, :stadium_capacity, :joined_league, :coach)");
        query1.bindValue(":conference", query.value(0).toString());
        query1.bindValue(":division", query.value(1).toString());
        query1.bindValue(":team_name", query.value(2).toString());
        query1.bindValue(":location", query.value(3).toString());
        query1.bindValue(":arena_name", query.value(4).toString());
        query1.bindValue(":stadium_capacity", query.value(5).toString());
        query1.bindValue(":joined_league", query.value(6).toString());
        query1.bindValue(":coach", query.value(7).toString());
        query1.exec();
    }

    QSqlQuery query2("SELECT * FROM seattleSouvenirs");
    while (query2.next()) {
        //Inserting new team souvenirs into the souvenirs database
        QSqlQuery query3;
        query3.exec("INSERT INTO souvenirs (team_name, item_name, cost) VALUES ('" + query2.value(0).toString()
                    + "', '" + query2.value(1).toString() + "', '" + query2.value(2).toString() + "')");
    }

    QSqlQuery query4("SELECT * FROM seattleDistances");
    while (query4.next()) {
        //Inserting new team distances into the distances database
        QSqlQuery query5;
        query5.exec("INSERT INTO distances (beginning_team_name, beginning_arena, ending_team_name, distance)"
                    "VALUES ('" + query4.value(0).toString() + "', '" + query4.value(1).toString() + "', '" +
                    query4.value(2).toString() + "', '" + query4.value(3).toString() + "')");
    }

    cerr << "Added to team to Database\n";
}

void Admin::changePrice(const string& teamName, const string& souvenir, const string& cost) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("UPDATE souvenirs SET cost = " + QString::fromStdString(cost) +
               " WHERE team_name IS '" + QString::fromStdString(teamName) + "' AND item_name IS '" +
               QString::fromStdString(souvenir) + "'");

    cerr << "Changed price of " << souvenir << ", from team " << teamName << ", to $" << cost << endl;

}

void Admin::addNewSouvenir(const string& teamName, const string& souvenir, const string& cost) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare("INSERT INTO souvenirs (team_name, item_name, cost) VALUES (:teamName, :souvenir, :cost)");
    query.bindValue(":teamName", QString::fromStdString(teamName));
    query.bindValue(":souvenir", QString::fromStdString(souvenir));
    query.bindValue(":cost", QString::fromStdString(cost));
    query.exec();

    cerr << "Added the souvenir, " << souvenir << ", to team, " << teamName << ", at the price of $" << cost << endl;
}

void Admin::removeSouvenir(const string& teamName, const string& souvenir) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("DELETE FROM souvenirs WHERE team_name IS '" + QString::fromStdString(teamName) + "' AND item_name IS '" + QString::fromStdString(souvenir) + "'");

    cerr << "Removed the souvenir, " << souvenir << ", from team, " << teamName << endl;
}

void Admin::changeArena(const string& teamName, const string& arena) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("UPDATE teamsInfo SET arena_name = '" + QString::fromStdString(arena) +
               "' WHERE team_name IS '" + QString::fromStdString(teamName) + "'");

    cerr << "Changed arena of team, " << teamName << ", to the arena, " << arena << endl;
}

void Admin::changeCapacity(const string& teamName, const string& capacity) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("UPDATE teamsInfo SET stadium_capacity = " + QString::fromStdString(capacity) +
               " WHERE team_name IS '" + QString::fromStdString(teamName) + "'");

    cerr << "Changed arena of team, " << teamName << ", to the capacity, " << capacity << endl;
}

vector<string> Admin::readingAvailableTeams() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    readAvailableTeams.clear();
    QSqlQuery query("SELECT * FROM teamsInfo");
    while (query.next())
        readAvailableTeams.push_back(query.value(2).toString().toStdString());
    return readAvailableTeams;
}

vector<string> Admin::readingNewTeams() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    readNewTeams.clear();
    QSqlQuery query("SELECT * FROM expansion");
    while (query.next())
        readNewTeams.push_back(query.value(2).toString().toStdString());
    return readNewTeams;
}

vector<string> Admin::readingSouvenirs(const string& teamName) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\Hiep\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    readSouvenirs.clear();
    QSqlQuery query("SELECT * FROM souvenirs WHERE team_name IS '" + QString::fromStdString(teamName) + "'");
    while (query.next())
        readSouvenirs.push_back(query.value(1).toString().toStdString());
    return readSouvenirs;
}
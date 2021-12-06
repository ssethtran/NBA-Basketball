//
// Created by Hiep on 11/9/2021.
//

#include "DbManager.h"

DbManager::DbManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Users\\4ktra\\OneDrive\\Desktop\\College Work\\CS 1D Homework\\CS 1D Project 2\\NBA Basketball Project\\NBA-Basketball\\NBA-Basketball\\DB\\nba-database.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

bool DbManager::addTeam(const QString& name)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;
    query.prepare("INSERT INTO teamsInfo VALUES (\"Western\", \"Southwest\", \"testers\", \"Irvine, CA\", \"test\", 69, 1983, \"Hiep Ton\")");
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addTeam error:" << query.lastError();
    }

    return success;
}

bool DbManager::teamExists(const QString& name) {
    QSqlQuery query;
    query.prepare("SELECT team_name FROM teamsInfo WHERE name = (:name)");
    query.bindValue(":name", name);

    while (query.next()) {
        if (query.value(2) == name) {
            return true;
        }
    }
    return false;
}

void DbManager::printTeams(){
    QSqlQuery query("SELECT * FROM teamsInfo");
    int idName = query.record().indexOf("team_name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << name;
    }
}

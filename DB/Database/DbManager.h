//
// Created by Hiep on 11/9/2021.
//

#pragma once
#include <QtSql>
#include "sqlite3/sqlite3.h"
#include <QDebug>
#include <QString>

class DbManager
{
public:
    DbManager();
    bool addTeam(const QString& name);
    bool teamExists(const QString& name);
    void printTeams();
private:
    QSqlDatabase m_db;
};

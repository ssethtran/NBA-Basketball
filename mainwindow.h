#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include <QLabel>
#include "DB/Database/DbManager.h"
#include "orderedMap/orderedMap.h"
#include "ManageTeam/ManageTeams.h"
#include "ManageTeam/Team/Team.h"
#include "UI/login/login.h"
#include "UI/ModdedLabel/ModdedLabel.h"
#include "UI/ModdedLineEdit/moddedlineedit.h"
#include "UI/Map/Map.h"
#include "Admin/Admin.h"
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AlphabeticalTeamAll();
    void AlphabeticalTeamEastern();
    void AlphabeticalTeamSoutheastEastern();
    void AlphabeticalCoach();
    void AlphabeticalArena();
    void SeatingCapSort();
    void JoinedLeagueSort();

public slots:
    void itemChanged(QTreeWidgetItem*, int);
    void updateSpent();
    void setPlan(QTreeWidgetItem*, int);
    void adminNewTeam();
    void adminChangePrice();
    void adminAddSouvenir();
    void updateChangePriceSCB();
    void adminDeleteSouvenir();
    void updateDelSCB();
    void adminChangeArena();

private slots:
    void on_actionLogin_triggered();
    void on_sortComboBox_currentTextChanged(const QString &sortMethod);
    void on_clearPlan_clicked();
    void on_submitPlan_clicked();

    void on_teamsTreeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_adminSubmit_clicked();
    void on_arenaSubmit_clicked();

private:
    Ui::MainWindow *ui;
    bool repurchase = false;
    ManageTeams teamManagement;
    vector<string> teamsToTravelTo;
    vector<string> travelOrder;
    Admin admin;
    string team;
    string souvenir;
    string price;
};
#endif // MAINWINDOW_H

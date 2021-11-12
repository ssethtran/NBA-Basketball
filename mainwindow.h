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
#include "UI/login/login.h"
#include "UI/ModdedLabel/ModdedLabel.h"
#include <string>

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

private slots:
    void on_actionLogin_triggered();
    void on_sortComboBox_currentTextChanged(const QString &sortMethod);

private:
    Ui::MainWindow *ui;
    ManageTeams teamManagement;
};
#endif // MAINWINDOW_H

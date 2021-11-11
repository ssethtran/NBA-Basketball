#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DB/Database/DbManager.h"
#include "orderedMap/orderedMap.h"
#include "ManageTeam/ManageTeams.h"
#include "UI/login/login.h"
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
    void AlphabeticalAll();

private slots:
    void on_actionLogin_triggered();

private:
    Ui::MainWindow *ui;
    ManageTeams teamManagement;
};
#endif // MAINWINDOW_H

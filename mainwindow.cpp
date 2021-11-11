#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    teamManagement.ReadData();
    AlphabeticalAll();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    login log;
//    ui->tabWidget->setTabEnabled(0, log.getCred());
//    ui->tabWidget->setTabEnabled(1, !log.getCred());
//    ui->tabWidget->setCurrentIndex(log.getCred());

    log.setModal(true);
    log.exec();
}

void MainWindow::AlphabeticalAll() {
    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Teams" << "Info on Teams");
    ui->teamsTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    for (auto & team : teamManagement.GetTeams().GetTree())
    {
        if (team != NULL) {
            auto *teams = new QTreeWidgetItem;
            teams->setText(0, QString::fromStdString(team->team_name));

            QLabel* conferenceVal = new QLabel;
            conferenceVal->setText(QString::fromStdString(team->conference));
            QTreeWidgetItem* conference = new QTreeWidgetItem;
            conference->setText(0,"Conference:");
            teams->addChild(conference);
            ui->teamsTreeWidget->setItemWidget(conference, 1, conferenceVal);

            QLabel* divisionVal = new QLabel;
            divisionVal->setText(QString::fromStdString(team->division));
            QTreeWidgetItem* division = new QTreeWidgetItem;
            division->setText(0,"Division:");
            teams->addChild(division);
            ui->teamsTreeWidget->setItemWidget(division, 1, divisionVal);

            QLabel* team_nameVal = new QLabel;
            team_nameVal->setText(QString::fromStdString(team->team_name));
            QTreeWidgetItem* team_name = new QTreeWidgetItem;
            team_name->setText(0,"Team Name:");
            teams->addChild(team_name);
            ui->teamsTreeWidget->setItemWidget(team_name, 1, team_nameVal);

            QLabel* locationVal = new QLabel;
            locationVal->setText(QString::fromStdString(team->location));
            QTreeWidgetItem* location = new QTreeWidgetItem;
            location->setText(0,"Location:");
            teams->addChild(location);
            ui->teamsTreeWidget->setItemWidget(location, 1, locationVal);

            QLabel* arena_nameVal = new QLabel;
            arena_nameVal->setText(QString::fromStdString(team->arena_name));
            QTreeWidgetItem* arena_name = new QTreeWidgetItem;
            arena_name->setText(0,"Arena Name:");
            teams->addChild(arena_name);
            ui->teamsTreeWidget->setItemWidget(arena_name, 1, arena_nameVal);

            QLabel* stadCapVal = new QLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            QTreeWidgetItem* stadCap = new QTreeWidgetItem;
            stadCap->setText(0,"Stadium Capacity:");
            teams->addChild(stadCap);
            ui->teamsTreeWidget->setItemWidget(stadCap, 1, stadCapVal);

            QLabel* joinedLeagueVal = new QLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            QTreeWidgetItem* joinedLeague = new QTreeWidgetItem;
            joinedLeague->setText(0,"Joined League:");
            teams->addChild(joinedLeague);
            ui->teamsTreeWidget->setItemWidget(joinedLeague, 1,joinedLeagueVal);

            QLabel* coachVal = new QLabel;
            coachVal->setText(QString::fromStdString(team->coach));
            QTreeWidgetItem* coach = new QTreeWidgetItem;
            coach->setText(0,"Coach:");
            teams->addChild(coach);
            ui->teamsTreeWidget->setItemWidget(coach, 1, coachVal);

            teams->setData(0, Qt::CheckStateRole, Qt::Unchecked);
            teams->setFlags(teams->flags() | Qt::ItemIsUserCheckable);
            ui->teamsTreeWidget->addTopLevelItem(teams);
        }
    }
    ui->teamsTreeWidget->sortItems(0, Qt::AscendingOrder);

    ui->teamsTreeWidget->setColumnWidth(0, 193);
    ui->teamsTreeWidget->setColumnWidth(1, 50);
}


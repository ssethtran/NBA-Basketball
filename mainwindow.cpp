#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    teamManagement.ReadData();
    AlphabeticalTeamAll();

    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Teams" << "Info on Teams");
    ui->teamsTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui->teamsTreeWidget->setColumnWidth(0, 193);
    ui->teamsTreeWidget->setColumnWidth(1, 50);
    connect(ui->clearPlan, SIGNAL(clicked()), this, SLOT(on_clearPlan_clicked()), Qt::UniqueConnection);

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

void MainWindow::AlphabeticalTeamAll() {
    ui->teamsTreeWidget->clear();

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
}

void MainWindow::AlphabeticalTeamEastern() {
    ui->teamsTreeWidget->clear();

    for (auto & team : teamManagement.GetTeams().GetTree())
    {
        if (team != NULL && team->conference == "Eastern") {
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
}

void MainWindow::AlphabeticalTeamSoutheastEastern() {
    ui->teamsTreeWidget->clear();

    for (auto & team : teamManagement.GetTeams().GetTree())
    {
        if (team != NULL && team->conference == "Eastern" && team->division == "Southeast") {
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
}

void MainWindow::AlphabeticalCoach() {
    ui->teamsTreeWidget->clear();
    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Coaches" << "Info on Teams");

    for (auto & team : teamManagement.GetTeams().GetTree())
    {
        if (team != NULL) {
            auto *coaches = new QTreeWidgetItem;
            coaches->setText(0, QString::fromStdString(team->coach));

            QLabel* team_nameVal = new QLabel;
            team_nameVal->setText(QString::fromStdString(team->team_name));
            QTreeWidgetItem* team_name = new QTreeWidgetItem;
            team_name->setText(0,"Team Name:");
            coaches->addChild(team_name);
            ui->teamsTreeWidget->setItemWidget(team_name, 1, team_nameVal);

            QLabel* conferenceVal = new QLabel;
            conferenceVal->setText(QString::fromStdString(team->conference));
            QTreeWidgetItem* conference = new QTreeWidgetItem;
            conference->setText(0,"Conference:");
            coaches->addChild(conference);
            ui->teamsTreeWidget->setItemWidget(conference, 1, conferenceVal);

            QLabel* divisionVal = new QLabel;
            divisionVal->setText(QString::fromStdString(team->division));
            QTreeWidgetItem* division = new QTreeWidgetItem;
            division->setText(0,"Division:");
            coaches->addChild(division);
            ui->teamsTreeWidget->setItemWidget(division, 1, divisionVal);

            QLabel* locationVal = new QLabel;
            locationVal->setText(QString::fromStdString(team->location));
            QTreeWidgetItem* location = new QTreeWidgetItem;
            location->setText(0,"Location:");
            coaches->addChild(location);
            ui->teamsTreeWidget->setItemWidget(location, 1, locationVal);

            QLabel* arena_nameVal = new QLabel;
            arena_nameVal->setText(QString::fromStdString(team->arena_name));
            QTreeWidgetItem* arena_name = new QTreeWidgetItem;
            arena_name->setText(0,"Arena Name:");
            coaches->addChild(arena_name);
            ui->teamsTreeWidget->setItemWidget(arena_name, 1, arena_nameVal);

            QLabel* stadCapVal = new QLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            QTreeWidgetItem* stadCap = new QTreeWidgetItem;
            stadCap->setText(0,"Stadium Capacity:");
            coaches->addChild(stadCap);
            ui->teamsTreeWidget->setItemWidget(stadCap, 1, stadCapVal);

            QLabel* joinedLeagueVal = new QLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            QTreeWidgetItem* joinedLeague = new QTreeWidgetItem;
            joinedLeague->setText(0,"Joined League:");
            coaches->addChild(joinedLeague);
            ui->teamsTreeWidget->setItemWidget(joinedLeague, 1,joinedLeagueVal);

            coaches->setData(0, Qt::CheckStateRole, Qt::Unchecked);
            coaches->setFlags(coaches->flags() | Qt::ItemIsUserCheckable);
            ui->teamsTreeWidget->addTopLevelItem(coaches);
        }
    }
    ui->teamsTreeWidget->sortItems(0, Qt::AscendingOrder);
}

void MainWindow::AlphabeticalArena() {
    ui->teamsTreeWidget->clear();
    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Arenas" << "Info on Teams");

    for (auto & team : teamManagement.GetTeams().GetTree())
    {
        if (team != NULL) {
            auto *arenas = new QTreeWidgetItem;
            arenas->setText(0, QString::fromStdString(team->arena_name));

            QLabel* team_nameVal = new QLabel;
            team_nameVal->setText(QString::fromStdString(team->team_name));
            QTreeWidgetItem* team_name = new QTreeWidgetItem;
            team_name->setText(0,"Team Name:");
            arenas->addChild(team_name);
            ui->teamsTreeWidget->setItemWidget(team_name, 1, team_nameVal);

            QLabel* conferenceVal = new QLabel;
            conferenceVal->setText(QString::fromStdString(team->conference));
            QTreeWidgetItem* conference = new QTreeWidgetItem;
            conference->setText(0,"Conference:");
            arenas->addChild(conference);
            ui->teamsTreeWidget->setItemWidget(conference, 1, conferenceVal);

            QLabel* divisionVal = new QLabel;
            divisionVal->setText(QString::fromStdString(team->division));
            QTreeWidgetItem* division = new QTreeWidgetItem;
            division->setText(0,"Division:");
            arenas->addChild(division);
            ui->teamsTreeWidget->setItemWidget(division, 1, divisionVal);

            QLabel* locationVal = new QLabel;
            locationVal->setText(QString::fromStdString(team->location));
            QTreeWidgetItem* location = new QTreeWidgetItem;
            location->setText(0,"Location:");
            arenas->addChild(location);
            ui->teamsTreeWidget->setItemWidget(location, 1, locationVal);

            QLabel* coachVal = new QLabel;
            coachVal->setText(QString::fromStdString(team->coach));
            QTreeWidgetItem* coach = new QTreeWidgetItem;
            coach->setText(0,"Coach:");
            arenas->addChild(coach);
            ui->teamsTreeWidget->setItemWidget(coach, 1, coachVal);

            QLabel* stadCapVal = new QLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            QTreeWidgetItem* stadCap = new QTreeWidgetItem;
            stadCap->setText(0,"Stadium Capacity:");
            arenas->addChild(stadCap);
            ui->teamsTreeWidget->setItemWidget(stadCap, 1, stadCapVal);

            QLabel* joinedLeagueVal = new QLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            QTreeWidgetItem* joinedLeague = new QTreeWidgetItem;
            joinedLeague->setText(0,"Joined League:");
            arenas->addChild(joinedLeague);
            ui->teamsTreeWidget->setItemWidget(joinedLeague, 1,joinedLeagueVal);

            arenas->setData(0, Qt::CheckStateRole, Qt::Unchecked);
            arenas->setFlags(arenas->flags() | Qt::ItemIsUserCheckable);
            ui->teamsTreeWidget->addTopLevelItem(arenas);
        }
    }
    ui->teamsTreeWidget->sortItems(0, Qt::AscendingOrder);
}

void MainWindow::SeatingCapSort() {
    ui->teamsTreeWidget->clear();

    bool flag = false;
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

            ModdedLabel* stadCapVal = new ModdedLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            stadCapVal->updateAccessibleName();
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

            int c = 0;
            QTreeWidgetItemIterator it(ui->teamsTreeWidget, QTreeWidgetItemIterator::NoChildren);
            while (*it) {
                if ((*it)->text(0) == "Stadium Capacity:")
                {
                    if (ui->teamsTreeWidget->itemWidget(*it, 1)->accessibleName().toInt() > team->stadCap)
                        c++;
                }
                it++;
            }
            if (flag == true)
                ui->teamsTreeWidget->insertTopLevelItem(c, teams);
            if (ui->teamsTreeWidget->topLevelItemCount() == 0 && flag == false) {
                ui->teamsTreeWidget->insertTopLevelItem(c, teams);
                flag = true;
            }
        }
    }
}

void MainWindow::JoinedLeagueSort() {
    ui->teamsTreeWidget->clear();

    bool flag = false;
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

            ModdedLabel* joinedLeagueVal = new ModdedLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            joinedLeagueVal->updateAccessibleName();
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

            int c = 0;
            QTreeWidgetItemIterator it(ui->teamsTreeWidget, QTreeWidgetItemIterator::NoChildren);
            while (*it) {
                if ((*it)->text(0) == "Joined League:")
                {
                    if (ui->teamsTreeWidget->itemWidget(*it, 1)->accessibleName().toInt() > team->joinedLeague)
                        c++;
                    if (ui->teamsTreeWidget->itemWidget(*it, 1)->accessibleName().toInt() == team->joinedLeague)
                        if ((*it)->parent()->text(0).toStdString() < team->team_name)
                            c++;
                }
                it++;
            }
            if (flag == true)
                ui->teamsTreeWidget->insertTopLevelItem(c, teams);
            if (ui->teamsTreeWidget->topLevelItemCount() == 0 && flag == false) {
                ui->teamsTreeWidget->insertTopLevelItem(c, teams);
                flag = true;
            }
        }
    }
}

void MainWindow::on_sortComboBox_currentTextChanged(const QString &sortMethod)
{
    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Teams" << "Info on Teams");
    if (sortMethod == "Team Name")
        AlphabeticalTeamAll();
    else if (sortMethod == "Team Name (Eastern)")
        AlphabeticalTeamEastern();
    else if (sortMethod == "Team Name (Southeast Eastern)")
        AlphabeticalTeamSoutheastEastern();
    else if (sortMethod == "Coach Name")
        AlphabeticalCoach();
    else if (sortMethod == "Arena Name")
        AlphabeticalArena();
    else if (sortMethod == "Arena Seating Capacity")
        SeatingCapSort();
    else if (sortMethod == "Year Joined League")
        JoinedLeagueSort();
}

void MainWindow::setPlan(QTreeWidgetItem* item, int col)
{
    if (item->checkState(0) == Qt::Checked) {
        if (teamManagement.GetTravelPlan().GetTree().empty())
            for (auto & dot: Map::teamMap) {
                if (dot->GetLocation() == item->text(0).toStdString()) {
                    dot->setPressed(true);
                    dot->QGraphicsItem::update();
                    teamManagement.setStartingTeam(dot->GetLocation());
                }
            }

        Team* tempTeam = new Team;
        tempTeam->setTeamName(item->text(0).toStdString());
        teamManagement.AddTeam(*tempTeam);
        for (auto & team: teamManagement.GetTravelPlan().GetTree()) cout << team->team_name << "[" << team->distance << "]" << " --> ";
        cout << endl;
        if (teamManagement.GetTravelPlan().GetTree().size() != 1) {
            for (auto &dot: Map::teamMap) {
                if (dot->GetLocation() == item->text(0).toStdString())
                    dot->setIsSelected(true);
            }
        }
    }
    else if (item->checkState(0) != Qt::Checked) {
        Team* tempTeam2 = new Team;
        tempTeam2->setTeamName(item->text(0).toStdString());
        teamManagement.RemoveTeam(*tempTeam2);
        for (auto & team: teamManagement.GetTravelPlan().GetTree()) cout << team->team_name << "[" << team->distance << "]" << " --> ";
        cout << endl;
        for (auto & dot: Map::teamMap) {
            if (dot->GetLocation() == item->text(0).toStdString()) {
                dot->setPressed(false);
                dot->setIsSelected(false);
            }
        }
    }
}

void MainWindow::on_submitPlan_clicked()
{
    ui->planTreeWidget->setHeaderLabels(QStringList() << "Teams & their Souvenirs" << "Cost ($)" << "Quantity to Buy");
    ui->planTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui->planTreeWidget->setColumnWidth(0, 193);
    ui->planTreeWidget->setColumnWidth(1, 50);
    ui->planTreeWidget->setColumnWidth(2, 100);

    QTreeWidgetItemIterator it(ui->teamsTreeWidget, QTreeWidgetItemIterator::HasChildren);
    while (*it)
    {
        if ((*it)->checkState(0) == Qt::Checked)
        {
            teamsToTravelTo.push_back((*it)->text(0).toStdString());
        }
        it++;
    }
    for (auto & team : teamsToTravelTo) {
        auto *teams = new QTreeWidgetItem;
        teams->setText(0, QString::fromStdString(team));

        Team* toSearch = new Team("", "", team, "", "", 0, 0, "");
        for (int i = 0; i < ManageTeams::TeamMap.search(*toSearch)->souvenirList.size(); i++) {
            auto* souvenir_costLineEdit = new moddedLineEdit;
            auto* quantity_souvenirLineEdit = new moddedLineEdit;

            QTreeWidgetItem* temp = new QTreeWidgetItem;
            temp->setText(0, QString(QString::fromStdString(ManageTeams::TeamMap.search(*toSearch)->souvenirList[i].souvenirName)));

            souvenir_costLineEdit->setText(QString::number(ManageTeams::TeamMap.search(*toSearch)->souvenirList[i].cost, 'f', 2));
            souvenir_costLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);

            //check for admin perms here
            souvenir_costLineEdit->setDisabled(true);
            souvenir_costLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            souvenir_costLineEdit->setStyleSheet("QLineEdit {color : black; }");
            souvenir_costLineEdit->setAlignment(Qt::AlignHCenter);

            quantity_souvenirLineEdit->setText(QString::number(0));
            quantity_souvenirLineEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
            quantity_souvenirLineEdit->setAlignment(Qt::AlignHCenter);
            quantity_souvenirLineEdit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");

            souvenir_costLineEdit->updateAccessibleName();
            quantity_souvenirLineEdit->updateAccessibleName();

            teams->addChild(temp);
            ui->planTreeWidget->setItemWidget(temp, 1, souvenir_costLineEdit);
            ui->planTreeWidget->setItemWidget(temp, 2, quantity_souvenirLineEdit);
            QMainWindow::connect(quantity_souvenirLineEdit, SIGNAL(textChanged(const QString &)), quantity_souvenirLineEdit, SLOT(updateAccessibleName()));
        }

        ui->planTreeWidget->addTopLevelItem(teams);
        //ui->teamsTreeWidget->setItemWidget(arena_name, 1, arena_nameVal);
    }
    connect(ui->updatepurchases_pushButton, SIGNAL(clicked()), this, SLOT(updateSpent()));
}

void MainWindow::itemChanged(QTreeWidgetItem *, int) {

}

void MainWindow::updateSpent() {
    QTreeWidgetItemIterator it(ui->planTreeWidget, QTreeWidgetItemIterator::NoChildren);
    double totalSpentOnTrip = 0;
    double totalSpentAtCity = 0;
    int totalBoughtAtCity = 0;
    int index = 0;
    while (*it) {
        if (ui->planTreeWidget->itemWidget(*it, 2))
        {
            totalSpentOnTrip += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            totalSpentAtCity += ui->planTreeWidget->itemWidget(*it, 1)->accessibleName().toDouble() * ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toDouble();
            totalBoughtAtCity += ui->planTreeWidget->itemWidget(*it, 2)->accessibleName().toInt();
            index++;

        }
        if (repurchase && index == (*it)->parent()->childCount() - 2)
        {
            (*it)->parent()->takeChild((*it)->parent()->childCount() - 1);
            (*it)->parent()->takeChild((*it)->parent()->childCount() - 1);
        }
        if (index == (*it)->parent()->childCount() && (*it)->parent()->childCount() > 0 /*&& repurchase == false*/)
        {
            QTreeWidgetItem* boughtAtCity = new QTreeWidgetItem();
            QLineEdit* boughtAtCity_lineedit = new QLineEdit();
            boughtAtCity_lineedit->setText(QString::number(totalBoughtAtCity));
            boughtAtCity_lineedit->setReadOnly(true);
            boughtAtCity_lineedit->setAlignment(Qt::AlignHCenter);
            boughtAtCity_lineedit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            boughtAtCity->setText(0, "# of Foods Bought:");
            (*it)->parent()->addChild(boughtAtCity);
            ui->planTreeWidget->setItemWidget(boughtAtCity, 1, boughtAtCity_lineedit);

            QTreeWidgetItem* spentAtCity = new QTreeWidgetItem();
            QLineEdit* spentAtCity_lineedit = new QLineEdit();
            spentAtCity_lineedit->setText(QString::number(totalSpentAtCity, 'f', 2));
            spentAtCity_lineedit->setReadOnly(true);
            spentAtCity_lineedit->setAlignment(Qt::AlignHCenter);
            spentAtCity_lineedit->setStyleSheet("QLineEdit {color : black; border: 1px solid black}");
            spentAtCity->setText(0, "Amount Spent (USD)");
            (*it)->parent()->addChild(spentAtCity);
            ui->planTreeWidget->setItemWidget(spentAtCity, 1, spentAtCity_lineedit);

            totalBoughtAtCity = 0;
            totalSpentAtCity = 0;
            index = 0;
            ++it;
        }
        ++it;
    }

    repurchase = true;
    ui->totalspent_LineEdit->setText(QString::number(totalSpentOnTrip, 'f', 2));
    ui->totalspent_LineEdit->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_clearPlan_clicked() {
    repurchase = false;
    teamsToTravelTo.clear();
    ui->totalDistanceTraveled_LineEdit->setText("");
    ui->totalspent_LineEdit->setText("");
    ui->planTreeWidget->clear();
}
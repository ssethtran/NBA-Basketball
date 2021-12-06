#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("NBA Basketball Application");
    ui->adminSubmit->setHidden(true);
    ui->arenaSubmit->setHidden(true);

    teamManagement.ReadData();

    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);

    ui->totalSeatCap_LineEdit->setText(QString::number(teamManagement.totalSeatCap));
    ui->totalSeatCap_LineEdit->setReadOnly(true);

    ui->teamsTreeWidget->setHeaderLabels(QStringList() << "Teams" << "Info on Teams");
    ui->teamsTreeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui->teamsTreeWidget->setColumnWidth(0, 193);
    ui->teamsTreeWidget->setColumnWidth(1, 50);
    AlphabeticalTeamAll();

    ui->submitPlan->setDisabled(true);
    ui->updatepurchases_pushButton->setDisabled(true);
    connect(ui->clearPlan, SIGNAL(clicked()), this, SLOT(on_clearPlan_clicked()), Qt::UniqueConnection);
    connect(ui->teamsTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));

    //ADMIN=========================================================================================================
    //ADMIN=========================================================================================================
    bool flag = true;
    string currTeam;
    for (const string& team: admin.readingNewTeams()) {
        currTeam = team;
        for (const string &teams: admin.readingAvailableTeams()) {
            if (team == teams) {
                flag = false;
                break;
            }
        }
        break;
    }
    if (flag) ui->addTeamCBox->addItem(QString::fromStdString(currTeam));

    //Setting "Add Team" button functionality
    connect(ui->addTeamButton, SIGNAL(clicked()), this, SLOT(adminNewTeam()));

    //=====================CHANGE TRADITIONAL SOUVENIR PRICE=====================
    //Setting the combo box for the available teams
    for (const string &team: admin.readingAvailableTeams())
        ui->changeSPriceTeamCB->addItem(QString::fromStdString(team));

    //Setting the combo box for the traditional souvenirs for the specified team
    for (const string &souvenirs: admin.readingSouvenirs(ui->changeSPriceTeamCB->currentText().toStdString()))
        ui->changeSPriceSCB->addItem(QString::fromStdString(souvenirs));

    //Connecting the "Teams" combo box to the "Souvenir" combo box
    connect(ui->changeSPriceTeamCB, SIGNAL(currentTextChanged(const QString)), this, SLOT(updateChangePriceSCB()));

    //Setting "Change Traditional Food Price" button functionality
    connect(ui->changeSPriceButton, SIGNAL(clicked()), this, SLOT(adminChangePrice()));

    //=====================ADD TRADITIONAL SOUVENIR=====================
    //Setting the combo box for the available teams
    for (const string &team: admin.readingAvailableTeams())
        ui->addSTeamCB->addItem(QString::fromStdString(team));

    //Setting "Add Traditional Souvenir" button functionality
    connect(ui->addSButton, SIGNAL(clicked()), this, SLOT(adminAddSouvenir()));

    //=====================DELETE TRADITIONAL SOUVENIR=====================
    //Setting the combo box for the available teams
    for (const string &team: admin.readingAvailableTeams())
        ui->delSTeamCB->addItem(QString::fromStdString(team));

    //Setting the combo box for the traditional souvenirs for the specified team
    for (const string &souvenir: admin.readingSouvenirs(ui->delSTeamCB->currentText().toStdString()))
        ui->delSSCB->addItem(QString::fromStdString(souvenir));

    //Setting "Delete Traditional Souvenir" button functionality
    connect(ui->deleteSButton, SIGNAL(clicked()), this, SLOT(adminDeleteSouvenir()));

    //Connecting the "Teams" combo box to the "Souvenir" combo box
    connect(ui->delSTeamCB, SIGNAL(currentTextChanged(const QString)), this, SLOT(updateDelSCB()));

    //=====================CHANGE ARENA=====================
    //Setting the combo box for the available teams
    for (const string &team: admin.readingAvailableTeams())
        ui->changeArenaTCB->addItem(QString::fromStdString(team));

    //Setting "Change Arena" button functionality
    connect(ui->changeArenaButton, SIGNAL(clicked()), this, SLOT(adminChangeArena()));

    //=====================CHANGE CAPACITY=====================
    //Setting the combo box for the available teams
    for (const string &team: admin.readingAvailableTeams())
        ui->changeCapacityTCB->addItem(QString::fromStdString(team));

    //Setting "Change Capacity" button functionality
    connect(ui->changeCapacityButton, SIGNAL(clicked()), this, SLOT(adminChangeCapacity()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adminNewTeam() {
    admin.addNewTeam();

    ui->addTeamCBox->clear();
    ui->changeSPriceTeamCB->clear();
    ui->addSTeamCB->clear();
    ui->delSTeamCB->clear();

    bool flag = true;
    string currTeam;
    for (const string& team : admin.readingNewTeams()) {
        currTeam = team;
        for (const string& teams : admin.readingAvailableTeams()) {
            if (team == teams) {
                flag = false;
                break;
            }
        }
        break;
    }
    if (flag) ui->addTeamCBox->addItem(QString::fromStdString(currTeam));

    for (auto& group : admin.readingAvailableTeams()) {
        ui->changeSPriceTeamCB->addItem(QString::fromStdString(group));
        ui->addSTeamCB->addItem(QString::fromStdString(group));
        ui->delSTeamCB->addItem(QString::fromStdString(group));
    }
}

void MainWindow::adminChangePrice() {
    team = ui->changeSPriceTeamCB->currentText().toStdString();
    souvenir = ui->changeSPriceSCB->currentText().toStdString();
    price = ui->changeSPricePLE->text().toStdString();

    admin.changePrice(team, souvenir, price);
}

void MainWindow::updateChangePriceSCB() {
    ui->changeSPriceSCB->clear();
    for (const string& souvenirs : admin.readingSouvenirs(ui->changeSPriceTeamCB->currentText().toStdString()))
        ui->changeSPriceSCB->addItem(QString::fromStdString(souvenirs));
}

void MainWindow::adminAddSouvenir() {
    team = ui->addSTeamCB->currentText().toStdString();
    souvenir = ui->addSLE->displayText().toStdString();
    price = ui->addSPriceLE->text().toStdString();

    if (!souvenir.empty() && !price.empty())
        admin.addNewSouvenir(team, souvenir, price);

    ui->delSSCB->clear();
    for (const string& souvenir : admin.readingSouvenirs(ui->delSTeamCB->currentText().toStdString()))
        ui->delSSCB->addItem(QString::fromStdString(souvenir));

    ui->changeSPriceSCB->clear();
    for (const string& souvenir : admin.readingSouvenirs(ui->changeSPriceTeamCB->currentText().toStdString()))
        ui->changeSPriceSCB->addItem(QString::fromStdString(souvenir));
}

void MainWindow::adminDeleteSouvenir() {
    team = ui->delSTeamCB->currentText().toStdString();
    souvenir = ui->delSSCB->currentText().toStdString();

    admin.removeSouvenir(team, souvenir);

    ui->delSSCB->clear();
    for (const string& souvenir : admin.readingSouvenirs(ui->delSTeamCB->currentText().toStdString()))
        ui->delSSCB->addItem(QString::fromStdString(souvenir));

    ui->changeSPriceSCB->clear();
    for (const string& souvenir : admin.readingSouvenirs(ui->changeSPriceTeamCB->currentText().toStdString()))
        ui->changeSPriceSCB->addItem(QString::fromStdString(souvenir));
}

void MainWindow::updateDelSCB() {
    ui->delSSCB->clear();
    for (const string& souvenir : admin.readingSouvenirs(ui->delSTeamCB->currentText().toStdString()))
        ui->delSSCB->addItem(QString::fromStdString(souvenir));
}

void MainWindow::adminChangeArena() {
    string arena = ui->changeArenaALE->text().toStdString();
    if (!arena.empty())
        admin.changeArena(ui->changeArenaTCB->currentText().toStdString(), arena);
}

void MainWindow::adminChangeCapacity() {
    string capacity = ui->changeCapacityCLE->text().toStdString();
    if (!capacity.empty())
        admin.changeCapacity(ui->changeCapacityTCB->currentText().toStdString(), capacity);
}

void MainWindow::on_adminSubmit_clicked() {
    teamManagement.ReadData();
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setCurrentIndex(false);
}

void MainWindow::on_arenaSubmit_clicked() {
    teamManagement.ReadData();
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setCurrentIndex(false);
}

void MainWindow::on_actionLogin_triggered() {
    login log;
    ui->tabWidget->setTabEnabled(0, log.getCred());
    ui->tabWidget->setTabEnabled(1, !log.getCred());
    ui->tabWidget->setTabEnabled(2, !log.getCred());
    ui->tabWidget->setCurrentIndex(log.getCred());

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

    bool flag = false;
    for (auto &team: teamManagement.GetTeams().GetTree()) {
        if (team != NULL) {
            auto *teams = new QTreeWidgetItem;
            teams->setText(0, QString::fromStdString(team->team_name));

            QLabel *conferenceVal = new QLabel;
            conferenceVal->setText(QString::fromStdString(team->conference));
            QTreeWidgetItem *conference = new QTreeWidgetItem;
            conference->setText(0, "Conference:");
            teams->addChild(conference);
            ui->teamsTreeWidget->setItemWidget(conference, 1, conferenceVal);

            QLabel *divisionVal = new QLabel;
            divisionVal->setText(QString::fromStdString(team->division));
            QTreeWidgetItem *division = new QTreeWidgetItem;
            division->setText(0, "Division:");
            teams->addChild(division);
            ui->teamsTreeWidget->setItemWidget(division, 1, divisionVal);

            QLabel *locationVal = new QLabel;
            locationVal->setText(QString::fromStdString(team->location));
            QTreeWidgetItem *location = new QTreeWidgetItem;
            location->setText(0, "Location:");
            teams->addChild(location);
            ui->teamsTreeWidget->setItemWidget(location, 1, locationVal);

            ModdedLabel* arena_nameVal = new ModdedLabel;
            arena_nameVal->setText(QString::fromStdString(team->arena_name));
            arena_nameVal->updateAccessibleName();
            QTreeWidgetItem* arena_name = new QTreeWidgetItem;
            arena_name->setText(0,"Arena Name:");
            teams->addChild(arena_name);
            ui->teamsTreeWidget->setItemWidget(arena_name, 1, arena_nameVal);

            QLabel *stadCapVal = new QLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            QTreeWidgetItem *stadCap = new QTreeWidgetItem;
            stadCap->setText(0, "Stadium Capacity:");
            teams->addChild(stadCap);
            ui->teamsTreeWidget->setItemWidget(stadCap, 1, stadCapVal);

            QLabel *joinedLeagueVal = new QLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            QTreeWidgetItem *joinedLeague = new QTreeWidgetItem;
            joinedLeague->setText(0, "Joined League:");
            teams->addChild(joinedLeague);
            ui->teamsTreeWidget->setItemWidget(joinedLeague, 1, joinedLeagueVal);

            ModdedLabel *coachVal = new ModdedLabel;
            coachVal->setText(QString::fromStdString(team->coach));
            coachVal->updateAccessibleName();
            QTreeWidgetItem *coach = new QTreeWidgetItem;
            coach->setText(0, "Coach:");
            teams->addChild(coach);
            ui->teamsTreeWidget->setItemWidget(coach, 1, coachVal);

            teams->setData(0, Qt::CheckStateRole, Qt::Unchecked);
            teams->setFlags(teams->flags() | Qt::ItemIsUserCheckable);

            int c = 0;
            QTreeWidgetItemIterator it(ui->teamsTreeWidget, QTreeWidgetItemIterator::NoChildren);
            while (*it) {
                if ((*it)->text(0) == "Coach:")
                {
                    if (ui->teamsTreeWidget->itemWidget(*it, 1)->accessibleName().toStdString() <= team->coach)
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

void MainWindow::AlphabeticalArena() {
    ui->teamsTreeWidget->clear();

    bool flag = false;
    for (auto &team: teamManagement.GetTeams().GetTree()) {
        if (team != NULL) {
            auto *teams = new QTreeWidgetItem;
            teams->setText(0, QString::fromStdString(team->team_name));

            QLabel *conferenceVal = new QLabel;
            conferenceVal->setText(QString::fromStdString(team->conference));
            QTreeWidgetItem *conference = new QTreeWidgetItem;
            conference->setText(0, "Conference:");
            teams->addChild(conference);
            ui->teamsTreeWidget->setItemWidget(conference, 1, conferenceVal);

            QLabel *divisionVal = new QLabel;
            divisionVal->setText(QString::fromStdString(team->division));
            QTreeWidgetItem *division = new QTreeWidgetItem;
            division->setText(0, "Division:");
            teams->addChild(division);
            ui->teamsTreeWidget->setItemWidget(division, 1, divisionVal);

            QLabel *locationVal = new QLabel;
            locationVal->setText(QString::fromStdString(team->location));
            QTreeWidgetItem *location = new QTreeWidgetItem;
            location->setText(0, "Location:");
            teams->addChild(location);
            ui->teamsTreeWidget->setItemWidget(location, 1, locationVal);

            ModdedLabel* arena_nameVal = new ModdedLabel;
            arena_nameVal->setText(QString::fromStdString(team->arena_name));
            arena_nameVal->updateAccessibleName();
            QTreeWidgetItem* arena_name = new QTreeWidgetItem;
            arena_name->setText(0,"Arena Name:");
            teams->addChild(arena_name);
            ui->teamsTreeWidget->setItemWidget(arena_name, 1, arena_nameVal);

            QLabel *stadCapVal = new QLabel;
            stadCapVal->setText(QString::number(team->stadCap));
            QTreeWidgetItem *stadCap = new QTreeWidgetItem;
            stadCap->setText(0, "Stadium Capacity:");
            teams->addChild(stadCap);
            ui->teamsTreeWidget->setItemWidget(stadCap, 1, stadCapVal);

            QLabel *joinedLeagueVal = new QLabel;
            joinedLeagueVal->setText(QString::number(team->joinedLeague));
            QTreeWidgetItem *joinedLeague = new QTreeWidgetItem;
            joinedLeague->setText(0, "Joined League:");
            teams->addChild(joinedLeague);
            ui->teamsTreeWidget->setItemWidget(joinedLeague, 1, joinedLeagueVal);

            QLabel *coachVal = new QLabel;
            coachVal->setText(QString::fromStdString(team->coach));
            QTreeWidgetItem *coach = new QTreeWidgetItem;
            coach->setText(0, "Coach:");
            teams->addChild(coach);
            ui->teamsTreeWidget->setItemWidget(coach, 1, coachVal);

            teams->setData(0, Qt::CheckStateRole, Qt::Unchecked);
            teams->setFlags(teams->flags() | Qt::ItemIsUserCheckable);

            int c = 0;
            QTreeWidgetItemIterator it(ui->teamsTreeWidget, QTreeWidgetItemIterator::NoChildren);

            string tempTeamArenaName = team->arena_name;
            for (int i = 0; i < tempTeamArenaName.size(); i++)
                tempTeamArenaName[i] = std::tolower(tempTeamArenaName[i]);
            while (*it) {
                if ((*it)->text(0) == "Arena Name:") {
                    string temp = ui->teamsTreeWidget->itemWidget(*it, 1)->accessibleName().toStdString();
                    for (int i = 0; i < temp.size(); i++)
                        temp[i] = std::tolower(temp[i]);
                    if (temp < tempTeamArenaName)
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
    ui->submitPlan->setDisabled(true);
    ui->submitPlan->setStyleSheet("");
    ui->updatepurchases_pushButton->setEnabled(true);
    ui->updatepurchases_pushButton->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))");

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
            teamManagement.teamsToTravelTo.push_back((*it)->text(0).toStdString());
        }
        it++;
    }
    for (auto & team : teamManagement.teamsToTravelTo) {
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

    // dijkstra's
    double dijkstraTotalDist = 0.0;
    double intermediateDistance = 0.0;
    for (int i = 0; i < travelOrder.size() - 1; i++) {
        teamManagement.g.dijkstra(travelOrder[i]);
        cout << endl << endl;
        for (int c = 0; c < teamManagement.g.dist.size(); c++)
        {
            // if last city to travel to == next in travel order
            if (teamManagement.g.dist[c]->cities.size() > 0 &&
                    teamManagement.g.dist[c]->cities[teamManagement.g.dist[c]->cities.size() - 1] == travelOrder[i + 1]) {
                dijkstraTotalDist += teamManagement.g.dist[c]->distance;
                intermediateDistance = teamManagement.g.dist[c]->distance;
                QTreeWidgetItem* newPath = new QTreeWidgetItem;
                newPath->setText(0, QString::fromStdString(teamManagement.g.dijkstraStart) + " to " + QString::fromStdString(teamManagement.g.dist[c]->cities[teamManagement.g.dist[c]->cities.size() - 1]));
                int numInPath = 1;
                for (int z = 0; z < teamManagement.g.dist[c]->cities.size(); z++)
                {
                    QTreeWidgetItem* nextInPath = new QTreeWidgetItem;
                    if (newPath->childCount() == 0)
                    {
                        nextInPath->setText(0, QString::number(numInPath) + ". " + QString::fromStdString(teamManagement.g.dijkstraStart));
                        z--;
                    }
                    else
                        nextInPath->setText(0, QString::number(numInPath) + ". " + QString::fromStdString(teamManagement.g.dist[c]->cities[z]));
                    numInPath++;
                    newPath->addChild(nextInPath);
                }
                QTreeWidgetItem* intermediateDistanceInWidget = new QTreeWidgetItem;
                intermediateDistanceInWidget->setText(0, "Distance: " + QString::number(intermediateDistance));
                newPath->addChild(intermediateDistanceInWidget);
                ui->djikstraWidget->addTopLevelItem(newPath);
            }
        }
        teamManagement.g.dist.clear();
    }
    ui->djikstraDistTraveled_LineEdit->setText(QString::number(dijkstraTotalDist));

    ShortestPath(travelOrder.at(0));
}

// recursive dijkstra's
void MainWindow::ShortestPath(string nextInPath) {
    double min = 1000000000;
    string from = nextInPath;
    int nextIndex = 0;
    if (teamManagement.teamsToTravelTo.size() != 1) {
        teamManagement.g.dijkstra(nextInPath);
        // left off here
    }
    else {
        ui->recursiveDistTraveled_LineEdit->setText(QString::number(recursiveTotalDist));
        recursiveTotalDist = 0.0;
        return;
    }
    for (int i = 0; i < teamManagement.g.dist.size(); i++) {
        if ( teamManagement.g.dist[i]->cities.size() > 0 && std::find(teamManagement.teamsToTravelTo.begin(), teamManagement.teamsToTravelTo.end(),
                      teamManagement.g.dist[i]->cities.back()) != teamManagement.teamsToTravelTo.end() && teamManagement.g.dist[i]->distance < min) {
            nextInPath = teamManagement.g.dist[i]->cities.back();
            nextIndex = i;
            min = teamManagement.g.dist[i]->distance;
        }
    }
    recursiveTotalDist += teamManagement.g.dist[nextIndex]->distance;
    double intermediateDistance = teamManagement.g.dist[nextIndex]->distance;
    QTreeWidgetItem *newPath = new QTreeWidgetItem;
    newPath->setText(0, QString::fromStdString(from) + " to " + QString::fromStdString(nextInPath));
    int numInPath = 1;
    for (int z = 0; z < teamManagement.g.dist[nextIndex]->cities.size(); z++)
    {
        QTreeWidgetItem* nextInPath = new QTreeWidgetItem;
        if (newPath->childCount() == 0)
        {
            nextInPath->setText(0, QString::number(numInPath) + ". " + QString::fromStdString(from));
            z--;
        }
        else
            nextInPath->setText(0, QString::number(numInPath) + ". " + QString::fromStdString(teamManagement.g.dist[nextIndex]->cities[z]));
        numInPath++;
        newPath->addChild(nextInPath);
    }
    QTreeWidgetItem* intermediateDistanceInWidget = new QTreeWidgetItem;
    intermediateDistanceInWidget->setText(0, "Distance: " + QString::number(intermediateDistance));
    //intermediateDistance = 0;
    newPath->addChild(intermediateDistanceInWidget);

    ui->recursiveWidget->addTopLevelItem(newPath);
    teamManagement.teamsToTravelTo.erase(std::find(teamManagement.teamsToTravelTo.begin(), teamManagement.teamsToTravelTo.end(), from));
    travelOrder.erase(std::find(travelOrder.begin(), travelOrder.end(), from));

    teamManagement.g.dist.clear();
    ShortestPath(nextInPath);
}

void MainWindow::itemChanged(QTreeWidgetItem * item, int col) {
    if (item->checkState(0) == Qt::Checked){
        travelOrder.push_back(item->text(0).toStdString());
    }
    else
    {
        for (int i = 0; i < travelOrder.size(); i++)
        {
            if (travelOrder[i] == item->text(0).toStdString()) {
                travelOrder.erase(travelOrder.begin() + i);
                if (travelOrder.size() < 2)
                {
                    ui->submitPlan->setDisabled(true);
                    ui->submitPlan->setStyleSheet("");
                }
                break;
            }
        }
    }
    if (travelOrder.size() >= 2) {
        ui->submitPlan->setEnabled(true);
        ui->submitPlan->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))");
    }
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
    teamManagement.teamsToTravelTo.clear();
    ui->djikstraWidget->clear();
    ui->recursiveWidget->clear();
    ui->djikstraDistTraveled_LineEdit->clear();
    ui->recursiveDistTraveled_LineEdit->clear();
    ui->totalspent_LineEdit->setText("");
    ui->updatepurchases_pushButton->setDisabled(true);
    ui->updatepurchases_pushButton->setStyleSheet("");

    for (int i = 0; ui->teamsTreeWidget->topLevelItem(i); i++)
        ui->teamsTreeWidget->topLevelItem(i)->setCheckState(0, Qt::Unchecked);

    ui->planTreeWidget->clear();
}

void MainWindow::on_teamsTreeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

    ui->recursiveWidget_2->clear();
    ui->recursiveWidget_3->clear();
    ui->recursiveWidget_4->clear();
    string selectedTeamName = item->text(0).toStdString();

    double MSTdistance = 0;
    double BFSdistance = 0;
    double DFSdistance = 0;

    vector<string> MSTcities(0, "");
    vector<string> BFScities(0, "");
    vector<string> DFScities(0, "");


    MSTdistance = teamManagement.g.MST(selectedTeamName, MSTcities);
    BFSdistance = teamManagement.g.BFS(selectedTeamName, BFScities);
    DFSdistance = teamManagement.g.DFS(selectedTeamName, DFScities);

    QTreeWidgetItem* tempString1 = new QTreeWidgetItem;
    tempString1->setText(0, "MST Distance starting with the " + QString::fromStdString(selectedTeamName) + " is: " + QString::number(MSTdistance, 'f', 2) + "\n");
    ui->recursiveWidget_2->addTopLevelItem(tempString1);
    for(int i = 1; i < MSTcities.size();i += 3){
        QTreeWidgetItem* temp = new QTreeWidgetItem;
        temp->setText(0, QString::fromStdString(MSTcities[i] + " -> " + MSTcities[i+1] + " : ") + QString::number(std::stod(MSTcities[i+2]), 'f', 2));
        ui->recursiveWidget_2->addTopLevelItem(temp);
    }


    QTreeWidgetItem* tempString2 = new QTreeWidgetItem;
    tempString2->setText(0, "BFS Distance starting with the " + QString::fromStdString(selectedTeamName) + " is: " + QString::number(BFSdistance, 'f', 2) + "\n");
    ui->recursiveWidget_4->addTopLevelItem(tempString2);
    for(int i = 0; i < BFScities.size();i ++){
        QTreeWidgetItem* temp = new QTreeWidgetItem;
        temp->setText(0, QString::fromStdString(BFScities[i]));
        ui->recursiveWidget_4->addTopLevelItem(temp);
    }

    QTreeWidgetItem* tempString3 = new QTreeWidgetItem;
    tempString3->setText(0, "DFS Distance starting with the " + QString::fromStdString(selectedTeamName) + " is: " + QString::number(DFSdistance, 'f', 2) + "\n");
    ui->recursiveWidget_3->addTopLevelItem(tempString3);
    for(int i = 0; i < DFScities.size();i ++){
        QTreeWidgetItem* temp = new QTreeWidgetItem;
        temp->setText(0, QString::fromStdString(DFScities[i]));
        ui->recursiveWidget_3->addTopLevelItem(temp);
    }
}


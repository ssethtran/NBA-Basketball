#include "dialog.h"
#include "ui_dialog.h"
#include "QPushButton.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPushButton* b2 = new QPushButton(this);
    ManageTeams* teams = new ManageTeams();
    int res =  teams->ReadTeamsCap();
    QString info = QString::number(res, 10);

    b2->setText(info);
    b2->show();
}


Dialog::~Dialog()
{
    delete ui;
}

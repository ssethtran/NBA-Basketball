#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Log In");

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/Hiep/NBA-Basketball/DB/user-info.sqlite");                                         // CHANGE PATH PER PROGRAMMER

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    isAdmin = false;
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM users");

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Account Information");

    query.exec() ? cout << "True\n" : cout << "False\n";

    if (query.exec()) {
        if (query.next()) {
            isAdmin = true;
        }
    }

//    for (auto& group: usernameList) {
//        if (QString::fromStdString(group.at(0)) == username && QString::fromStdString(group.at(1)) == password) {
//            isAdmin = true;
//            break;
//        }
//    }

    if (isAdmin) {
        QAbstractButton *close = msgBox.addButton(tr("OK"), QMessageBox::AcceptRole);
        msgBox.setText("<center>Account Connected</center>");
        msgBox.setInformativeText("<center>Click OK to continue</center>");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel{font-size: 12px;} QPushButton{width:72px; font-size: 12px;}");
        msgBox.exec();

        if (msgBox.clickedButton() == close) {
            QDialog::reject();
            std::cerr << "Login Dialog Closed\n";
        }
    }
    else {
        msgBox.setText("<center>Account Not Found</center>");
        msgBox.setInformativeText("<center>Please try again</center>");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet("QLabel{font-size: 12px;} QPushButton{width:72px; font-size: 12px;}");
        msgBox.exec();
    }
}

bool login::getCred() {
    return isAdmin;
}
#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>

using namespace std;

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool getCred();

private slots:
    void on_loginButton_clicked();

private:
    Ui::login *ui;
    bool isAdmin;
    QSqlQuery query;
};

#endif // LOGIN_H

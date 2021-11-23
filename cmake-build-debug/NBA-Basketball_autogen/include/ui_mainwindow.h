/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCircle;
    QAction *actionRectangle;
    QAction *actionLine;
    QAction *actionPolyLine;
    QAction *actionEllipse;
    QAction *actionSquare;
    QAction *actionText;
    QAction *actionPolygon;
    QAction *actionLogin;
    QAction *actionCreate_New_Account;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer;
    QLabel *label_15;
    QLineEdit *djikstraDistTraveled_LineEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_17;
    QLineEdit *bfsDistTraveled;
    QTabWidget *tabWidget;
    QWidget *traveller;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLineEdit *totalspent_LineEdit;
    QLabel *label_2;
    QPushButton *updatepurchases_pushButton;
    QPushButton *submitPlan;
    QPushButton *clearPlan;
    QTreeWidget *teamsTreeWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *sortComboBox;
    QTreeWidget *planTreeWidget;
    QWidget *admin;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *delFoodCityComboBox;
    QComboBox *delTradFoodComboBox;
    QPushButton *delFoodButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_10;
    QComboBox *newCityComboBox;
    QPushButton *addCityButton;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *addFoodCityComboBox;
    QLineEdit *newFoodLineEdit;
    QDoubleSpinBox *addFoodPriceDoubleSpinBox;
    QPushButton *addFoodButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_11;
    QComboBox *cityComboBox;
    QComboBox *tradFoodComboBox;
    QDoubleSpinBox *priceDoubleSpinBox;
    QPushButton *changeFoodPriceButton;
    QPushButton *adminSubmit;
    QTreeWidget *djikstraWidget;
    QTreeWidget *bfsTreeWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_12;
    QLineEdit *recursiveDistTraveled_LineEdit;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_21;
    QLineEdit *dfsDistTraveled;
    QTreeWidget *recursiveWidget;
    QTreeWidget *dfsTreeWidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAccount;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1256, 683);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionPolyLine = new QAction(MainWindow);
        actionPolyLine->setObjectName(QString::fromUtf8("actionPolyLine"));
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionPolygon = new QAction(MainWindow);
        actionPolygon->setObjectName(QString::fromUtf8("actionPolygon"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionCreate_New_Account = new QAction(MainWindow);
        actionCreate_New_Account->setObjectName(QString::fromUtf8("actionCreate_New_Account"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_13);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_15);

        djikstraDistTraveled_LineEdit = new QLineEdit(centralwidget);
        djikstraDistTraveled_LineEdit->setObjectName(QString::fromUtf8("djikstraDistTraveled_LineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(djikstraDistTraveled_LineEdit->sizePolicy().hasHeightForWidth());
        djikstraDistTraveled_LineEdit->setSizePolicy(sizePolicy1);
        djikstraDistTraveled_LineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(djikstraDistTraveled_LineEdit);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_16);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_17);

        bfsDistTraveled = new QLineEdit(centralwidget);
        bfsDistTraveled->setObjectName(QString::fromUtf8("bfsDistTraveled"));
        sizePolicy1.setHeightForWidth(bfsDistTraveled->sizePolicy().hasHeightForWidth());
        bfsDistTraveled->setSizePolicy(sizePolicy1);
        bfsDistTraveled->setReadOnly(true);

        horizontalLayout_5->addWidget(bfsDistTraveled);


        gridLayout->addLayout(horizontalLayout_5, 0, 1, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        traveller = new QWidget();
        traveller->setObjectName(QString::fromUtf8("traveller"));
        gridLayout_11 = new QGridLayout(traveller);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        totalspent_LineEdit = new QLineEdit(traveller);
        totalspent_LineEdit->setObjectName(QString::fromUtf8("totalspent_LineEdit"));
        sizePolicy1.setHeightForWidth(totalspent_LineEdit->sizePolicy().hasHeightForWidth());
        totalspent_LineEdit->setSizePolicy(sizePolicy1);
        totalspent_LineEdit->setAlignment(Qt::AlignCenter);
        totalspent_LineEdit->setReadOnly(true);

        gridLayout_4->addWidget(totalspent_LineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(traveller);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 2, 1, 1);

        updatepurchases_pushButton = new QPushButton(traveller);
        updatepurchases_pushButton->setObjectName(QString::fromUtf8("updatepurchases_pushButton"));
        updatepurchases_pushButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(updatepurchases_pushButton, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 4, 0, 1, 1);

        submitPlan = new QPushButton(traveller);
        submitPlan->setObjectName(QString::fromUtf8("submitPlan"));
        QFont font;
        font.setPointSize(12);
        submitPlan->setFont(font);
        submitPlan->setAutoFillBackground(false);
        submitPlan->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));
        submitPlan->setCheckable(false);

        gridLayout_11->addWidget(submitPlan, 0, 0, 1, 1);

        clearPlan = new QPushButton(traveller);
        clearPlan->setObjectName(QString::fromUtf8("clearPlan"));
        clearPlan->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 #f8c485, stop:1 #f1acc8)"));

        gridLayout_11->addWidget(clearPlan, 1, 0, 1, 1);

        teamsTreeWidget = new QTreeWidget(traveller);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        teamsTreeWidget->setHeaderItem(__qtreewidgetitem);
        teamsTreeWidget->setObjectName(QString::fromUtf8("teamsTreeWidget"));
        sizePolicy2.setHeightForWidth(teamsTreeWidget->sizePolicy().hasHeightForWidth());
        teamsTreeWidget->setSizePolicy(sizePolicy2);
        teamsTreeWidget->setMinimumSize(QSize(400, 0));
        teamsTreeWidget->setAutoFillBackground(true);
        teamsTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout_11->addWidget(teamsTreeWidget, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(traveller);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        sortComboBox = new QComboBox(traveller);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName(QString::fromUtf8("sortComboBox"));
        sizePolicy1.setHeightForWidth(sortComboBox->sizePolicy().hasHeightForWidth());
        sortComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(sortComboBox);


        gridLayout_11->addLayout(horizontalLayout, 2, 0, 1, 1);

        planTreeWidget = new QTreeWidget(traveller);
        planTreeWidget->headerItem()->setText(0, QString());
        planTreeWidget->setObjectName(QString::fromUtf8("planTreeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(planTreeWidget->sizePolicy().hasHeightForWidth());
        planTreeWidget->setSizePolicy(sizePolicy3);
        planTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout_11->addWidget(planTreeWidget, 5, 0, 1, 1);

        tabWidget->addTab(traveller, QString());
        admin = new QWidget();
        admin->setObjectName(QString::fromUtf8("admin"));
        groupBox_4 = new QGroupBox(admin);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 390, 441, 131));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 421, 91));
        gridLayout_9 = new QGridLayout(layoutWidget);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_10, 0, 1, 1, 1);

        delFoodCityComboBox = new QComboBox(layoutWidget);
        delFoodCityComboBox->setObjectName(QString::fromUtf8("delFoodCityComboBox"));

        gridLayout_8->addWidget(delFoodCityComboBox, 1, 0, 1, 1);

        delTradFoodComboBox = new QComboBox(layoutWidget);
        delTradFoodComboBox->setObjectName(QString::fromUtf8("delTradFoodComboBox"));

        gridLayout_8->addWidget(delTradFoodComboBox, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        delFoodButton = new QPushButton(layoutWidget);
        delFoodButton->setObjectName(QString::fromUtf8("delFoodButton"));
        delFoodButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));

        gridLayout_9->addWidget(delFoodButton, 1, 0, 1, 1);

        groupBox = new QGroupBox(admin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(11, 11, 441, 61));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 26, 301, 31));
        gridLayout_10 = new QGridLayout(layoutWidget1);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        newCityComboBox = new QComboBox(layoutWidget1);
        newCityComboBox->setObjectName(QString::fromUtf8("newCityComboBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(newCityComboBox->sizePolicy().hasHeightForWidth());
        newCityComboBox->setSizePolicy(sizePolicy5);
        newCityComboBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout_10->addWidget(newCityComboBox, 0, 0, 1, 1);

        addCityButton = new QPushButton(layoutWidget1);
        addCityButton->setObjectName(QString::fromUtf8("addCityButton"));
        addCityButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));

        gridLayout_10->addWidget(addCityButton, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(admin);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 441, 141));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 32, 421, 101));
        gridLayout_7 = new QGridLayout(layoutWidget2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        addFoodCityComboBox = new QComboBox(layoutWidget2);
        addFoodCityComboBox->setObjectName(QString::fromUtf8("addFoodCityComboBox"));

        gridLayout_2->addWidget(addFoodCityComboBox, 1, 0, 1, 1);

        newFoodLineEdit = new QLineEdit(layoutWidget2);
        newFoodLineEdit->setObjectName(QString::fromUtf8("newFoodLineEdit"));
        sizePolicy5.setHeightForWidth(newFoodLineEdit->sizePolicy().hasHeightForWidth());
        newFoodLineEdit->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(newFoodLineEdit, 1, 1, 1, 1);

        addFoodPriceDoubleSpinBox = new QDoubleSpinBox(layoutWidget2);
        addFoodPriceDoubleSpinBox->setObjectName(QString::fromUtf8("addFoodPriceDoubleSpinBox"));

        gridLayout_2->addWidget(addFoodPriceDoubleSpinBox, 1, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 0, 0, 1, 1);

        addFoodButton = new QPushButton(layoutWidget2);
        addFoodButton->setObjectName(QString::fromUtf8("addFoodButton"));
        addFoodButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));

        gridLayout_7->addWidget(addFoodButton, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(admin);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 441, 151));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 421, 111));
        gridLayout_6 = new QGridLayout(layoutWidget3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_5, 0, 1, 1, 1);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_11, 0, 2, 1, 1);

        cityComboBox = new QComboBox(layoutWidget3);
        cityComboBox->setObjectName(QString::fromUtf8("cityComboBox"));

        gridLayout_5->addWidget(cityComboBox, 1, 0, 1, 1);

        tradFoodComboBox = new QComboBox(layoutWidget3);
        tradFoodComboBox->setObjectName(QString::fromUtf8("tradFoodComboBox"));

        gridLayout_5->addWidget(tradFoodComboBox, 1, 1, 1, 1);

        priceDoubleSpinBox = new QDoubleSpinBox(layoutWidget3);
        priceDoubleSpinBox->setObjectName(QString::fromUtf8("priceDoubleSpinBox"));

        gridLayout_5->addWidget(priceDoubleSpinBox, 1, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        changeFoodPriceButton = new QPushButton(layoutWidget3);
        changeFoodPriceButton->setObjectName(QString::fromUtf8("changeFoodPriceButton"));
        changeFoodPriceButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))"));

        gridLayout_6->addWidget(changeFoodPriceButton, 1, 0, 1, 1);

        adminSubmit = new QPushButton(admin);
        adminSubmit->setObjectName(QString::fromUtf8("adminSubmit"));
        adminSubmit->setGeometry(QRect(10, 540, 441, 31));
        adminSubmit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 #f8c485, stop:1 #f1acc8)"));
        tabWidget->addTab(admin, QString());

        gridLayout->addWidget(tabWidget, 0, 2, 4, 1);

        djikstraWidget = new QTreeWidget(centralwidget);
        djikstraWidget->headerItem()->setText(0, QString());
        djikstraWidget->setObjectName(QString::fromUtf8("djikstraWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(djikstraWidget->sizePolicy().hasHeightForWidth());
        djikstraWidget->setSizePolicy(sizePolicy6);
        djikstraWidget->setMinimumSize(QSize(400, 0));
        djikstraWidget->setAutoFillBackground(true);
        djikstraWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout->addWidget(djikstraWidget, 1, 0, 1, 1);

        bfsTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("BFS from LA Lakers"));
        bfsTreeWidget->setHeaderItem(__qtreewidgetitem1);
        bfsTreeWidget->setObjectName(QString::fromUtf8("bfsTreeWidget"));
        sizePolicy6.setHeightForWidth(bfsTreeWidget->sizePolicy().hasHeightForWidth());
        bfsTreeWidget->setSizePolicy(sizePolicy6);
        bfsTreeWidget->setMinimumSize(QSize(400, 0));
        bfsTreeWidget->setAutoFillBackground(true);
        bfsTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout->addWidget(bfsTreeWidget, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_14);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_12);

        recursiveDistTraveled_LineEdit = new QLineEdit(centralwidget);
        recursiveDistTraveled_LineEdit->setObjectName(QString::fromUtf8("recursiveDistTraveled_LineEdit"));
        sizePolicy1.setHeightForWidth(recursiveDistTraveled_LineEdit->sizePolicy().hasHeightForWidth());
        recursiveDistTraveled_LineEdit->setSizePolicy(sizePolicy1);
        recursiveDistTraveled_LineEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(recursiveDistTraveled_LineEdit);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_20);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_21);

        dfsDistTraveled = new QLineEdit(centralwidget);
        dfsDistTraveled->setObjectName(QString::fromUtf8("dfsDistTraveled"));
        sizePolicy1.setHeightForWidth(dfsDistTraveled->sizePolicy().hasHeightForWidth());
        dfsDistTraveled->setSizePolicy(sizePolicy1);
        dfsDistTraveled->setReadOnly(true);

        horizontalLayout_7->addWidget(dfsDistTraveled);


        gridLayout->addLayout(horizontalLayout_7, 2, 1, 1, 1);

        recursiveWidget = new QTreeWidget(centralwidget);
        recursiveWidget->headerItem()->setText(0, QString());
        recursiveWidget->setObjectName(QString::fromUtf8("recursiveWidget"));
        sizePolicy6.setHeightForWidth(recursiveWidget->sizePolicy().hasHeightForWidth());
        recursiveWidget->setSizePolicy(sizePolicy6);
        recursiveWidget->setMinimumSize(QSize(400, 0));
        recursiveWidget->setAutoFillBackground(true);
        recursiveWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout->addWidget(recursiveWidget, 3, 0, 1, 1);

        dfsTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("DFS From Orlando Magic"));
        dfsTreeWidget->setHeaderItem(__qtreewidgetitem2);
        dfsTreeWidget->setObjectName(QString::fromUtf8("dfsTreeWidget"));
        sizePolicy6.setHeightForWidth(dfsTreeWidget->sizePolicy().hasHeightForWidth());
        dfsTreeWidget->setSizePolicy(sizePolicy6);
        dfsTreeWidget->setMinimumSize(QSize(400, 0));
        dfsTreeWidget->setAutoFillBackground(true);
        dfsTreeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 243, 222);\n"
"QHeaderView::section { background-color: rgb(255, 243, 222); };"));

        gridLayout->addWidget(dfsTreeWidget, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1256, 22));
        menuAccount = new QMenu(menubar);
        menuAccount->setObjectName(QString::fromUtf8("menuAccount"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAccount->menuAction());
        menuAccount->addAction(actionLogin);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionPolyLine->setText(QCoreApplication::translate("MainWindow", "PolyLine", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        actionPolygon->setText(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionCreate_New_Account->setText(QCoreApplication::translate("MainWindow", "Create New Account", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Djikstra", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Distance Traveled (km)", nullptr));
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Distance Traveled (km)", nullptr));
        totalspent_LineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Total Spent (USD)", nullptr));
        updatepurchases_pushButton->setText(QCoreApplication::translate("MainWindow", "Update Purchases", nullptr));
        submitPlan->setText(QCoreApplication::translate("MainWindow", "Submit Plan", nullptr));
        clearPlan->setText(QCoreApplication::translate("MainWindow", "Reset Plan", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Team Name", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Team Name (Eastern)", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Team Name (Southeast Eastern)", nullptr));
        sortComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Arena Name", nullptr));
        sortComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Coach Name", nullptr));
        sortComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Arena Seating Capacity", nullptr));
        sortComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Year Joined League", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(traveller), QCoreApplication::translate("MainWindow", "Traveler", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Delete Traditional Foods", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "City:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Traditional Food:", nullptr));
        delFoodButton->setText(QCoreApplication::translate("MainWindow", "Delete Traditional Food", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add New Team", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Add Traditional Foods", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "City:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Traditional Food:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Price (USD):", nullptr));
        addFoodButton->setText(QCoreApplication::translate("MainWindow", "Add Traditional Food", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Change Traditional Food Prices", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "City:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Traditional Food:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Price (USD):", nullptr));
        changeFoodPriceButton->setText(QCoreApplication::translate("MainWindow", "Change Traditional Food Price", nullptr));
        adminSubmit->setText(QCoreApplication::translate("MainWindow", "Implement Changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(admin), QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Recursion", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Distance Traveled (km)", nullptr));
        label_20->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "Distance Traveled (km)", nullptr));
        menuAccount->setTitle(QCoreApplication::translate("MainWindow", "Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

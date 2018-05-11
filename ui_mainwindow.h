/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTableView *tableView_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *start;
    QPushButton *pause;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_memory;
    QLineEdit *lineEdit_pri;
    QLineEdit *lineEdit_time;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *addprocess;
    QTableWidget *backup;
    QTableWidget *suspend;
    QTableWidget *ready;
    QLabel *label_5;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *pid;
    QLineEdit *name;
    QLineEdit *memory_2;
    QLineEdit *time;
    QLineEdit *priority;
    QPushButton *tosuspend;
    QPushButton *awake;
    QTableWidget *dead;
    QLabel *label_6;
    QLineEdit *select_to_aors;
    QLabel *label_13;
    QTableWidget *memory;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1355, 641);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        tableView_6 = new QTableView(centralWidget);
        tableView_6->setObjectName(QStringLiteral("tableView_6"));
        tableView_6->setGeometry(QRect(20, 310, 311, 231));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(590, 320, 101, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(930, 10, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 10, 101, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 290, 54, 12));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(340, 290, 61, 16));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_8->setFont(font);
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(230, 340, 75, 23));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(230, 390, 75, 23));
        lineEdit_name = new QLineEdit(centralWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(90, 340, 121, 21));
        lineEdit_memory = new QLineEdit(centralWidget);
        lineEdit_memory->setObjectName(QStringLiteral("lineEdit_memory"));
        lineEdit_memory->setGeometry(QRect(90, 370, 121, 21));
        lineEdit_pri = new QLineEdit(centralWidget);
        lineEdit_pri->setObjectName(QStringLiteral("lineEdit_pri"));
        lineEdit_pri->setGeometry(QRect(90, 400, 121, 21));
        lineEdit_time = new QLineEdit(centralWidget);
        lineEdit_time->setObjectName(QStringLiteral("lineEdit_time"));
        lineEdit_time->setGeometry(QRect(90, 430, 121, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 420, 54, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 390, 54, 31));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 360, 54, 31));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 340, 54, 21));
        addprocess = new QPushButton(centralWidget);
        addprocess->setObjectName(QStringLiteral("addprocess"));
        addprocess->setGeometry(QRect(90, 460, 161, 41));
        backup = new QTableWidget(centralWidget);
        backup->setObjectName(QStringLiteral("backup"));
        backup->setGeometry(QRect(10, 30, 441, 231));
        suspend = new QTableWidget(centralWidget);
        suspend->setObjectName(QStringLiteral("suspend"));
        suspend->setGeometry(QRect(590, 340, 441, 231));
        ready = new QTableWidget(centralWidget);
        ready->setObjectName(QStringLiteral("ready"));
        ready->setGeometry(QRect(460, 30, 441, 231));
        ready->horizontalHeader()->setDefaultSectionSize(100);
        ready->horizontalHeader()->setMinimumSectionSize(25);
        ready->verticalHeader()->setMinimumSectionSize(25);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(930, 30, 61, 31));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(930, 70, 61, 31));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(930, 110, 61, 31));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(930, 150, 61, 31));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(930, 190, 61, 31));
        pid = new QLineEdit(centralWidget);
        pid->setObjectName(QStringLiteral("pid"));
        pid->setGeometry(QRect(990, 30, 111, 31));
        name = new QLineEdit(centralWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(990, 70, 111, 31));
        memory_2 = new QLineEdit(centralWidget);
        memory_2->setObjectName(QStringLiteral("memory_2"));
        memory_2->setGeometry(QRect(990, 190, 111, 31));
        time = new QLineEdit(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(990, 110, 111, 31));
        priority = new QLineEdit(centralWidget);
        priority->setObjectName(QStringLiteral("priority"));
        priority->setGeometry(QRect(990, 150, 111, 31));
        tosuspend = new QPushButton(centralWidget);
        tosuspend->setObjectName(QStringLiteral("tosuspend"));
        tosuspend->setGeometry(QRect(740, 260, 61, 31));
        awake = new QPushButton(centralWidget);
        awake->setObjectName(QStringLiteral("awake"));
        awake->setGeometry(QRect(740, 310, 61, 31));
        dead = new QTableWidget(centralWidget);
        dead->setObjectName(QStringLiteral("dead"));
        dead->setGeometry(QRect(1040, 290, 271, 231));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1040, 270, 61, 21));
        select_to_aors = new QLineEdit(centralWidget);
        select_to_aors->setObjectName(QStringLiteral("select_to_aors"));
        select_to_aors->setGeometry(QRect(650, 290, 81, 31));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(650, 270, 61, 21));
        memory = new QTableWidget(centralWidget);
        memory->setObjectName(QStringLiteral("memory"));
        memory->setGeometry(QRect(340, 310, 231, 261));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1355, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\345\220\216\345\244\207\351\230\237\345\210\227", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\214\202\350\265\267\351\230\237\345\210\227", 0));
        label_3->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\350\277\233\347\250\213:", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\260\261\347\273\252\351\230\237\345\210\227", 0));
        label_7->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\346\267\273\345\212\240", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\345\210\206\351\205\215", 0));
        start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264", 0));
        label_10->setText(QApplication::translate("MainWindow", "\344\274\230\345\205\210\347\272\247", 0));
        label_11->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\345\244\247\345\260\217", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\345\220\215", 0));
        addprocess->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\277\233\347\250\213", 0));
        label_5->setText(QApplication::translate("MainWindow", "Pid", 0));
        label_16->setText(QApplication::translate("MainWindow", "name", 0));
        label_17->setText(QApplication::translate("MainWindow", "time", 0));
        label_18->setText(QApplication::translate("MainWindow", "priority", 0));
        label_19->setText(QApplication::translate("MainWindow", "memory", 0));
        tosuspend->setText(QApplication::translate("MainWindow", "\346\214\202\350\265\267", 0));
        awake->setText(QApplication::translate("MainWindow", "\350\247\243\346\214\202", 0));
        label_6->setText(QApplication::translate("MainWindow", "\347\273\210\346\255\242\351\230\237\345\210\227", 0));
        label_13->setText(QApplication::translate("MainWindow", "Pid:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

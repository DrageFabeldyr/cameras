/********************************************************************************
** Form generated from reading UI file 'SimplePlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEPLAYER_H
#define UI_SIMPLEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <VLCQtWidgets/WidgetVideo.h>

QT_BEGIN_NAMESPACE

class Ui_SimplePlayer
{
public:
    QAction *actionQuit;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionOpenLocal;
    QAction *actionOpenUrl;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    VlcWidgetVideo *video;
    QPushButton *openUrl;
    QPushButton *openLocal;
    VlcWidgetVideo *video4;
    VlcWidgetVideo *video3;
    VlcWidgetVideo *video2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimplePlayer)
    {
        if (SimplePlayer->objectName().isEmpty())
            SimplePlayer->setObjectName(QStringLiteral("SimplePlayer"));
        SimplePlayer->resize(1253, 759);
        actionQuit = new QAction(SimplePlayer);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPause = new QAction(SimplePlayer);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionPause->setCheckable(true);
        actionStop = new QAction(SimplePlayer);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionOpenLocal = new QAction(SimplePlayer);
        actionOpenLocal->setObjectName(QStringLiteral("actionOpenLocal"));
        actionOpenUrl = new QAction(SimplePlayer);
        actionOpenUrl->setObjectName(QStringLiteral("actionOpenUrl"));
        centralwidget = new QWidget(SimplePlayer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        video = new VlcWidgetVideo(centralwidget);
        video->setObjectName(QStringLiteral("video"));

        gridLayout_2->addWidget(video, 1, 0, 1, 1);

        openUrl = new QPushButton(centralwidget);
        openUrl->setObjectName(QStringLiteral("openUrl"));

        gridLayout_2->addWidget(openUrl, 0, 1, 1, 1);

        openLocal = new QPushButton(centralwidget);
        openLocal->setObjectName(QStringLiteral("openLocal"));

        gridLayout_2->addWidget(openLocal, 0, 0, 1, 1);

        video4 = new VlcWidgetVideo(centralwidget);
        video4->setObjectName(QStringLiteral("video4"));

        gridLayout_2->addWidget(video4, 2, 1, 1, 1);

        video3 = new VlcWidgetVideo(centralwidget);
        video3->setObjectName(QStringLiteral("video3"));

        gridLayout_2->addWidget(video3, 2, 0, 1, 1);

        video2 = new VlcWidgetVideo(centralwidget);
        video2->setObjectName(QStringLiteral("video2"));

        gridLayout_2->addWidget(video2, 1, 1, 1, 1);

        SimplePlayer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SimplePlayer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SimplePlayer->setStatusBar(statusbar);

        retranslateUi(SimplePlayer);
        QObject::connect(actionQuit, SIGNAL(triggered()), SimplePlayer, SLOT(close()));

        QMetaObject::connectSlotsByName(SimplePlayer);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePlayer)
    {
        SimplePlayer->setWindowTitle(QApplication::translate("SimplePlayer", "Demo Player", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("SimplePlayer", "Quit", Q_NULLPTR));
        actionPause->setText(QApplication::translate("SimplePlayer", "Pause", Q_NULLPTR));
        actionStop->setText(QApplication::translate("SimplePlayer", "Stop", Q_NULLPTR));
        actionOpenLocal->setText(QApplication::translate("SimplePlayer", "Open local file", Q_NULLPTR));
        actionOpenUrl->setText(QApplication::translate("SimplePlayer", "Open URL", Q_NULLPTR));
        openUrl->setText(QApplication::translate("SimplePlayer", "Open URL", Q_NULLPTR));
        openLocal->setText(QApplication::translate("SimplePlayer", "Open local file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimplePlayer: public Ui_SimplePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPLAYER_H

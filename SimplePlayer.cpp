//#include <QFileDialog>
//#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

#include "SimplePlayer.h"
#include "ui_SimplePlayer.h"

SimplePlayer::SimplePlayer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SimplePlayer),
      _media(0)
{
    ui->setupUi(this);
    check_timer = new QTimer(this);
    connect(check_timer, SIGNAL(timeout()), this, SLOT(check_state()));
    check_timer->setInterval(1000); // 1 раз в секунду
    check_timer->start();

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    //_instance2 = new VlcInstance(VlcCommon::args(), this);
    _player2 = new VlcMediaPlayer(_instance);
    _player2->setVideoWidget(ui->video2);

    //_instance3 = new VlcInstance(VlcCommon::args(), this);
    _player3 = new VlcMediaPlayer(_instance);
    _player3->setVideoWidget(ui->video3);

    //_instance4 = new VlcInstance(VlcCommon::args(), this);
    _player4 = new VlcMediaPlayer(_instance);
    _player4->setVideoWidget(ui->video4);

    ui->video->setMediaPlayer(_player);
    ui->video2->setMediaPlayer(_player2);
    ui->video3->setMediaPlayer(_player3);
    ui->video4->setMediaPlayer(_player4);

    connect(ui->openLocal, &QPushButton::clicked, this, &SimplePlayer::openLocal);
    connect(ui->openUrl, &QPushButton::clicked, this, &SimplePlayer::openUrl);
}

SimplePlayer::~SimplePlayer()
{
    delete _player;
    delete _player2;
    //delete _instance2;
    delete _player3;
    //delete _instance3;
    delete _player4;
    //delete _instance4;
    delete _media;
    delete _instance;

    delete ui;
}

void SimplePlayer::openLocal()
{
/*
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath(), tr("Multimedia files(*)"));
    if (file.isEmpty())
        return;

    _media = new VlcMedia(file, true, _instance);
    _player->open(_media);
    */
    QString url = tr("rtsp://192.168.3.154:8554/");

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance);
    _player->open(_media);

    //_media = new VlcMedia(url, _instance2);
    _player2->open(_media);

    //_media = new VlcMedia(url, _instance3);
    _player3->open(_media);

    //_media = new VlcMedia(url, _instance4);
    _player4->open(_media);

}

void SimplePlayer::openUrl()
{
/*
    QString url = QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));
    */
    QString url = "";

    url = tr("rtsp://192.168.3.99:8554/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance);
    _player->open(_media);
    url.clear();

    url = tr("rtsp://192.168.3.99:8558/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance);
    _player2->open(_media);
    url.clear();

    url = tr("rtsp://192.168.3.99:8562/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance);
    _player3->open(_media);
    url.clear();

    url = tr("rtsp://192.168.3.99:8566/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance);
    _player4->open(_media);
}

void SimplePlayer::check_state()
{
     qDebug() << "Текущее состояние:";
     qDebug() << "player1" <<_player->state();
     qDebug() << "player2" <<_player2->state();
     qDebug() << "player3" <<_player3->state();
     qDebug() << "player4" <<_player4->state();
     if (_player->state() == 6 || _player->state() == 7) // если ended или error
     {
        _player->open(_media);
     }
     if (_player2->state() == 6 || _player2->state() == 7) // если ended или error
     {
        _player2->open(_media);
     }
     if (_player3->state() == 6 || _player3->state() == 7) // если ended или error
     {
        _player3->open(_media);
     }
     if (_player4->state() == 6 || _player4->state() == 7) // если ended или error
     {
        _player4->open(_media);
     }
}

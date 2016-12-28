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

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    _instance2 = new VlcInstance(VlcCommon::args(), this);
    _player2 = new VlcMediaPlayer(_instance2);
    _player2->setVideoWidget(ui->video2);

    _instance3 = new VlcInstance(VlcCommon::args(), this);
    _player3 = new VlcMediaPlayer(_instance3);
    _player3->setVideoWidget(ui->video3);

    _instance4 = new VlcInstance(VlcCommon::args(), this);
    _player4 = new VlcMediaPlayer(_instance4);
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
    delete _media;
    delete _instance;

    delete _player2;
    delete _instance2;

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

    _media = new VlcMedia(url, _instance2);
    _player2->open(_media);

    _media = new VlcMedia(url, _instance3);
    _player3->open(_media);

    _media = new VlcMedia(url, _instance4);
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
    _media = new VlcMedia(url, _instance2);
    _player2->open(_media);
    url.clear();

    url = tr("rtsp://192.168.3.99:8562/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance3);
    _player3->open(_media);
    url.clear();

    url = tr("rtsp://192.168.3.99:8566/");
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance4);
    _player4->open(_media);
}

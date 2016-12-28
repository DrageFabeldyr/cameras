//#include <QFileDialog>
//#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

//#include "EqualizerDialog.h"

#include "SimplePlayer.h"
#include "ui_SimplePlayer.h"

SimplePlayer::SimplePlayer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SimplePlayer),
      _media(0)/*,
      _equalizerDialog(new EqualizerDialog(this))*/
{
    ui->setupUi(this);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);
    //_equalizerDialog->setMediaPlayer(_player);
    _instance2 = new VlcInstance(VlcCommon::args(), this);
    _player2 = new VlcMediaPlayer(_instance2);
    _player2->setVideoWidget(ui->video2);

    ui->video->setMediaPlayer(_player);
    ui->video2->setMediaPlayer(_player2);
    //ui->volume->setMediaPlayer(_player);
    //ui->volume->setVolume(50);
    //ui->seek->setMediaPlayer(_player);

    connect(ui->actionOpenLocal, &QAction::triggered, this, &SimplePlayer::openLocal);
    connect(ui->actionOpenUrl, &QAction::triggered, this, &SimplePlayer::openUrl);
    //connect(ui->actionPause, &QAction::toggled, _player, &VlcMediaPlayer::togglePause);
    //connect(ui->actionStop, &QAction::triggered, _player, &VlcMediaPlayer::stop);
    connect(ui->openLocal, &QPushButton::clicked, this, &SimplePlayer::openLocal);
    connect(ui->openUrl, &QPushButton::clicked, this, &SimplePlayer::openUrl);
    //connect(ui->pause, &QPushButton::toggled, ui->actionPause, &QAction::toggle);
    //connect(ui->stop, &QPushButton::clicked, _player, &VlcMediaPlayer::stop);
    //connect(ui->equalizer, &QPushButton::clicked, _equalizerDialog, &EqualizerDialog::show);
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
}

void SimplePlayer::openUrl()
{
/*
    QString url = QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));
    */
    QString url = tr("rtsp://192.168.3.99:8554/");

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance2);
    _player2->open(_media);
}

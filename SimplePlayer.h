#ifndef SIMPLEPLAYER_H_
#define SIMPLEPLAYER_H_

#include <QMainWindow>

namespace Ui {
    class SimplePlayer;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

//class EqualizerDialog;

class SimplePlayer : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimplePlayer(QWidget *parent = 0);
    ~SimplePlayer();

private slots:
    void openLocal();
    void openUrl();

private:
    Ui::SimplePlayer *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;

    VlcInstance *_instance2;
    VlcMediaPlayer *_player2;

    VlcInstance *_instance3;
    VlcMediaPlayer *_player3;

    VlcInstance *_instance4;
    VlcMediaPlayer *_player4;
};

#endif // SIMPLEPLAYER_H_

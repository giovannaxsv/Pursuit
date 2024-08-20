#ifndef PURSUIT_H
#define PURSUIT_H

#include <QMainWindow>

class Cell;
class Player;

QT_BEGIN_NAMESPACE
namespace Ui { class Pursuit; }
QT_END_NAMESPACE

class Pursuit : public QMainWindow {
    Q_OBJECT

public:
    Pursuit(QWidget *parent = nullptr);
    virtual ~Pursuit();

signals:
    void turnEnded();

private:
    Ui::Pursuit *ui;
    Player* m_player;
    Cell* m_board[7][7];

private slots:
    void play(int id);
    void switchPlayer();
    void reset();

    void showAbout();
    void updateStatusBar();

};

#endif // PURSUIT_H

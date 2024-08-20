#include <QMessageBox>
#include <QSignalMapper>

#include "Pursuit.h"
#include "ui_Pursuit.h"
#include "Player.h"

Pursuit::Pursuit(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Pursuit),
      m_player(Player::player(Player::Red)) {
    ui->setupUi(this);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));

    QSignalMapper* map = new QSignalMapper(this);
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            QString cellName = QString("cell%1%2").arg(row).arg(col);
            Cell* cell = this->findChild<Cell*>(cellName);
            Q_ASSERT(cell != nullptr);
            Q_ASSERT(cell->row() == row && cell->col() == col);

            m_board[row][col] = cell;

            int id = row * 7 + col;
            map->setMapping(cell, id);
            QObject::connect(cell, SIGNAL(clicked(bool)), map, SLOT(map()));
        }
    }
#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(play(int)));
#else
    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));
#endif

    // When the turn ends, switch the player.
    QObject::connect(this, SIGNAL(turnEnded()), this, SLOT(switchPlayer()));

    // Reset the game.
    this->reset();

    this->adjustSize();
    this->setFixedSize(this->size());
}

Pursuit::~Pursuit() {
    delete ui;
}

void Pursuit::play(int id) {
    Cell* cell = m_board[id / 7][id % 7];
    if (cell->isBlocked()) {
        cell->setState(Cell::Empty);
        emit turnEnded();
    }
}

void Pursuit::switchPlayer() {
    // Switch the player.
    m_player = m_player->other();

    // Finally, update the status bar.
    this->updateStatusBar();
}

void Pursuit::reset() {
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            Cell* cell = m_board[row][col];
            cell->reset();

            if ((row + col) % 2 == 0)
                cell->setState(Cell::Blocked);
        }
    }

    m_player = Player::player(Player::Red);

    m_board[0][3]->setState(Cell::Blocked);
    m_board[1][3]->setPlayer(m_player);
    m_board[5][3]->setPlayer(m_player->other());
    m_board[6][3]->setState(Cell::Blocked);

    this->updateStatusBar();
}

void Pursuit::showAbout() {
    QMessageBox::information(this, tr("About"),
        tr("Pursuit\n\nAndrei Rimsa Alvares - andrei@cefetmg.br"));
}

void Pursuit::updateStatusBar() {
    ui->statusbar->showMessage(tr("Vez do %1")
        .arg(m_player->name()));
}

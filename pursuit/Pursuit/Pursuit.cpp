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

    // Quando o turno terminar, troca o jogador.
    QObject::connect(this, SIGNAL(turnEnded()), this, SLOT(switchPlayer()));

    // Reseta o jogo.
    this->reset();

    this->adjustSize();
    this->setFixedSize(this->size());

}

Pursuit::~Pursuit() {
    delete ui;
}



void Pursuit::play(int id) {
    Cell* cell = m_board[id / 7][id % 7];
    if (cell->isBlocked() && cell->isPlayable()) {
        cell->setState(Cell::Empty);
        emit turnEnded();
    }else{
        // Se a célula for jogável, mova o jogador para essa célula
         movePlayerToCell(cell);
    }
}
void Pursuit::movePlayerToCell(Cell* cell) {
    bool catchOpponent = false;
    // Verificar se a célula é jogável
    if (cell->isPlayable()) {

        if(cell->player()){
            catchOpponent = true; //capturou o oponente
        }else{
            catchOpponent = false;//capturou o oponente
        }

        // Remover o jogador da célula atual
        for (int row = 0; row < 7; ++row) {
            for (int col = 0; col < 7; ++col) {
                Cell* currentCell = m_board[row][col];
                if (currentCell->player() == m_player) {
                    currentCell->setPlayer(nullptr);
                    break;
                }
            }
        }

        // Mover o jogador para a nova célula
        cell->setPlayer(m_player);
        if(catchOpponent == true){
            gameOver();
        }else{
        // Primeiro, limpar as células jogáveis para mover
         clearPlayableCells();
        // Marcar células bloqueadas adjacentes como jogáveis
         markAdjacentBlockedCells(cell);
        }
    }
}
void Pursuit::clearPlayableCells() {
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            Cell* cell = m_board[row][col];
            if (cell->isPlayable()) {
                cell->setPlayable(false);
            }
        }
    }
}

void Pursuit::markAdjacentBlockedCells(Cell* cell) {
    int row = cell->row();
    int col = cell->col();

    // Coordenadas das direções adjacentes (N, S, E, W, NE, NW, SE, SW)
    int directions[8][2] = {
        {-1,  0}, {1,  0}, {0, -1}, {0,  1},  // N, S, W, E
        {-1, -1}, {-1, 1}, {1, -1}, {1,  1}   // NW, NE, SW, SE
    };

    for (int i = 0; i < 8; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        // Verificar se as novas coordenadas estão dentro do tabuleiro
        if (newRow >= 0 && newRow < 7 && newCol >= 0 && newCol < 7) {
            Cell* neighbor = m_board[newRow][newCol];
            if (neighbor->isBlocked()) {
                neighbor->setPlayable(true);
            }
        }
    }
}



void Pursuit::switchPlayer() {
    // Primeiro, limpar as células jogáveis
        clearPlayableCells();
    // Muda o jogador.
    m_player = m_player->other();

    // Atualiza a barra de status.
    this->updateStatusBar();

    // Reinicia a busca para o próximo jogador
    findPlayablePositions();

    // Verifica se há células jogáveis
        bool hasPlayableCells = false;
        for (int row = 0; row < 7; ++row) {
            for (int col = 0; col < 7; ++col) {
                if (m_board[row][col]->isPlayable()) {
                    hasPlayableCells = true;
                    break;
                }
            }
            if (hasPlayableCells) break;
        }

        // Se não houver células jogáveis, finaliza o jogo
        if (!hasPlayableCells) {
            gameOver();
        } else {
            // Atualiza a barra de status.
            this->updateStatusBar();
        }


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

    // Inicia a busca após o reset
    findPlayablePositions();
}


void Pursuit::gameOver() {
    QString winnerMessage = tr("%1 venceu o jogo!").arg(m_player->name());
    QMessageBox::information(nullptr, "FIM DE JOGO", winnerMessage,
                             QMessageBox::Ok);
    reset();
}


void Pursuit::showAbout() {
    QMessageBox::information(this, tr("About"),
        tr("Pursuit\n\n Giovanna Laura \n Thainá Martins\n"));
}

void Pursuit::updateStatusBar() {
    ui->statusbar->showMessage(tr("Vez do %1")
        .arg(m_player->name()) );
}

void Pursuit::findPlayablePositions() {
    static const int directions[8][2] = {
        {-1, 0},  // Norte
        {1, 0},   // Sul
        {0, -1},  // Oeste
        {0, 1},   // Leste
        {-1, -1}, // Noroeste
        {-1, 1},  // Nordeste
        {1, -1},  // Sudoeste
        {1, 1}    // Sudeste
    };

    int currentRow = -1, currentCol = -1;

    // Encontra a posição atual do jogador
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (m_board[row][col]->player() == m_player) {
                currentRow = row;
                currentCol = col;
                break;
            }
        }
        if (currentRow != -1) break;
    }

    if (currentRow == -1 || currentCol == -1) return; // jogador não encontrado

    // Verifica as direções e encontra as posições mais distantes válidas
    for (int i = 0; i < 8; ++i) {
        int row = currentRow, col = currentCol;
        int furthestRow = -1, furthestCol = -1;
        bool findOpponent = false;
        // Move na direção até encontrar um bloqueio ou a borda do tabuleiro
        while (true) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (newRow < 0 || newRow >= 7 || newCol < 0 || newCol >= 7) break;
            if((m_board[newRow][newCol]->player())){
                m_board[newRow][newCol]->setPlayable(true);
               findOpponent = true;//se encontrar um oponente no caminho, aquela é a posição jogavel
                break;
            }
            else{
            if (m_board[newRow][newCol]->isBlocked()) break;
            }
            row = newRow;
            col = newCol;

            furthestRow = row;
            furthestCol = col;

        }

        // Verifica se a posição mais distante encontrada tem vizinhos bloqueados
        if (furthestRow != -1 && furthestCol != -1 && findOpponent == false) {
            bool hasBlockedNeighbor = false;
            for (int j = 0; j < 8; ++j) {
                int neighborRow = furthestRow + directions[j][0];
                int neighborCol = furthestCol + directions[j][1];

                if (neighborRow < 0 || neighborRow >= 7 || neighborCol < 0 || neighborCol >= 7) continue;

                if (m_board[neighborRow][neighborCol]->isBlocked()) {
                    hasBlockedNeighbor = true;
                    break;
                }
            }
            // Se tiver pelo menos um vizinho bloqueado, marca a célula como jogável
            if (hasBlockedNeighbor) {
                m_board[furthestRow][furthestCol]->setPlayable(true);
            }
        }
    }


}

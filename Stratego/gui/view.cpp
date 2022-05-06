#include "view.hpp"
#include "boardGui.hpp"
#include "ui_stratego.h"
#include <QMessageBox>
#include <QPalette>
#include <QPalette>
#include <QPushButton>
#include <iostream>
#include <string>
#include "case.hpp"
#include "controller.hpp"

namespace strategoGui{
View::View(Facade &f, QWidget *parent)
    : QMainWindow(parent)
    , facade{f}
    , ui(new Ui::View)
    , buttonsClicked{}
    , board(ui, this, facade, parent)

{
    ui->setupUi(this);
    this->setWindowTitle("Stratego - Smolinski Piotr & Noé Delcroix");
    ui->centralwidget->setMinimumSize(1234,781);
    facade.addObserver(this);
    board.setController(ctrl_);
    board.updateBoard();
}

void View::updateGameStatus(QString text){
    ui->gamestatus->setText(text);
}
void View::updateCurrentPlayer(QString text){
    ui->player->setText(text);

}
void View::gameOver(){
    QLayoutItem *child;
    while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    ui->player->setText("");
    ui->winner->setText("Player " + QString::number(facade.getWinner())+" is the winner.");

}
void View::update(const std::string & propertyName){
    if(propertyName=="move"){
        board.updateBoard();
    }else if(propertyName=="game over"){
        gameOver();
    }
}

void View::resizeEvent(QResizeEvent *e){
    ui->gridLayoutWidget->setFixedSize((ui->centralwidget->width()*0.66)+100,ui->centralwidget->height());
    ui->verticalLayoutWidget->setFixedWidth(ui->centralwidget->width()*0.33);

    ui->verticalLayoutWidget->setFixedHeight(ui->centralwidget->height());
    ui->verticalLayoutWidget->move(ui->gridLayoutWidget->size().width()-45,0);
}


View::~View()
{
    //delete ui;
}

}



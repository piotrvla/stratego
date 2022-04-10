#ifndef VIEW_HPP
#define VIEW_HPP

#include <QMainWindow>
#include <vector>
#include "Facade.hpp"
namespace strategoGui {
    class Controller;
}


QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Facade &f, QWidget *parent = nullptr);
    inline void controller(strategoGui::Controller * controller){
        ctrl_ = controller;
    }
    void updateGameStatus(QString text);
    void updateCurrentPlayer(QString text);


    ~View();

private:
    Facade &facade;
    Ui::View *ui;
    std::vector<Position> buttonsClicked;
    strategoGui::Controller * ctrl_= nullptr;
    void on_button_clicked();
    void updateBoard();

private slots:
    void eventHandler(Position pos);

};

#endif // VIEW_HPP

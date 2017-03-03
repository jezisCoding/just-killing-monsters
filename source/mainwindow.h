#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include "gameengine.h"
#include <QFontDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_quitButton_clicked();
    void on_welcomeButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    GameEngine *engine;

    void inputAccepted();
    void keyPressEvent(QKeyEvent *kEvent);
    void putToTextBrowser(std::ostringstream &oss);
    void addToTextBrowser(std::ostringstream &oss, QString what);
};

#endif // MAINWINDOW_H

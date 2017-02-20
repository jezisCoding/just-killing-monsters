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

signals:
    inputAccepted();

private:
    Ui::MainWindow *ui;
    GameEngine *engine;

    void keyPressEvent(QKeyEvent *kEvent);
    void printToTextBrowser(std::ostringstream &oss);
};

#endif // MAINWINDOW_H

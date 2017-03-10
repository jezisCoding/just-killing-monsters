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

    Ui::MainWindow *ui;
    GameEngine *engine;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_welcomeButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_quitButton_clicked();

            //QML SAMOSTATNA APLIKACIA
            //SEM ESTE TEST, SIETE, OPENGL
private:
    void keyPressEvent(QKeyEvent *kEvent);
    void putToTextBrowser(std::ostringstream &first, std::ostringstream &second);
    void addToTextBrowser(std::ostringstream &oss, QString what);
    void inputAccepted();
};

#endif // MAINWINDOW_H

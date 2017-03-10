#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    engine(new GameEngine)
{
    ui->setupUi(this);
    setWindowTitle(QString("Just Killing Mosnters"));
    setFocusPolicy(Qt::StrongFocus);

    ui->consoleTextBrowser->setFont(
                QFontDatabase::systemFont(QFontDatabase::FixedFont));

    engine->welcome();
    putToTextBrowser(sos::bout, sos::iout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete engine;
}

void MainWindow::on_welcomeButton_clicked()
{
    if(!engine->endGame()) engine->welcome();
    putToTextBrowser(sos::bout, sos::iout);
}

void MainWindow::on_saveButton_clicked()
{
    try{
        if(!engine->endGame()) engine->saveGame("gameSave.xml");
        putToTextBrowser(sos::bout, sos::iout);
    } catch (file_error& ex){
        sos::iout << "Exception in MainWindow::on_saveButton_clicked() : "
                  << ex.what() << std::endl;
        putToTextBrowser(sos::bout, sos::iout);
    }
}

void MainWindow::on_loadButton_clicked()
{
    try{
        engine->loadGame("gameSave.xml");
        putToTextBrowser(sos::bout, sos::iout);
    } catch (file_error& ex){
        sos::iout << "Exception in MainWindow::on_loadButton_clicked() : "
                  << ex.what() << std::endl;
        putToTextBrowser(sos::bout, sos::iout);
    }
}

void MainWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::keyPressEvent(QKeyEvent *kEvent)
{
    if(!engine->endGame())
        if(   kEvent->key() == Qt::Key_W || kEvent->key() == Qt::Key_S
           || kEvent->key() == Qt::Key_A || kEvent->key() == Qt::Key_D)
                engine->GUIKeyinput(kEvent->key());
    engine->endGame();  //solely for endgame message w/o another keypress

    putToTextBrowser(sos::bout, sos::iout);
    //inputAccepted();
    //QWidget::keyPressEvent(key);
}

void MainWindow::putToTextBrowser(std::ostringstream &first, std::ostringstream &second)
{
    ui->consoleTextBrowser->setPlainText(QString(first.str().c_str()));
    first.str("");
    ui->consoleTextBrowser->append(QString(second.str().c_str()));
    second.str("");

    ui->consoleTextBrowser->update();

    //ui->OpenGLWidget
}

void MainWindow::addToTextBrowser(std::ostringstream &oss, QString what)
{
    QString out = QString(oss.str().c_str()) + what;

    ui->consoleTextBrowser->clear();
    ui->consoleTextBrowser->setPlainText(out);
    ui->consoleTextBrowser->update();
}

void MainWindow::inputAccepted()
{
    /*if(engine->endGame()){
        engine->;
    }*/
}

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

    ui->consoleTextBrowser->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    engine->welcome();
    putToTextBrowser(StaticOutputStream::wout);

    //connect(this, SIGNAL(inputAccepted()), ui->consoleTextBrowser, SLOT(update()));
    //connect(this, SIGNAL(inputAccepted()), ui->consoleTextBrowser, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* kEvent)
{
    if(engine->endGame()){
        addToTextBrowser(StaticOutputStream::wout, QString("\n\nGame Over."));
    } else if(kEvent->key() == Qt::Key_W || kEvent->key() == Qt::Key_S
           || kEvent->key() == Qt::Key_A || kEvent->key() == Qt::Key_D){
        engine->GUIKeyinput(kEvent->key());
        putToTextBrowser(StaticOutputStream::wout);
    }

    //QWidget::keyPressEvent(key);
}

void MainWindow::putToTextBrowser(std::ostringstream& oss)
{
    QString out = QString(oss.str().c_str());
    oss.str("");
    ui->consoleTextBrowser->clear();
    ui->consoleTextBrowser->setPlainText(out);
    ui->consoleTextBrowser->update();

    inputAccepted();
}

void MainWindow::addToTextBrowser(std::ostringstream &oss, QString what)
{
    QString out = QString(oss.str().c_str()) + what;

    ui->consoleTextBrowser->clear();
    ui->consoleTextBrowser->setPlainText(out);
    ui->consoleTextBrowser->update();

    inputAccepted();
}

void MainWindow::on_quitButton_clicked()
{
    delete engine;
    QCoreApplication::quit();
}

void MainWindow::on_welcomeButton_clicked()
{
    if(engine->endGame()){
        addToTextBrowser(StaticOutputStream::wout, QString("\n\nGame Over."));
    } else {
        engine->welcome();
        putToTextBrowser(StaticOutputStream::wout);
    }
}

void MainWindow::on_saveButton_clicked()
{
    if(engine->endGame()){
        addToTextBrowser(StaticOutputStream::wout, QString("\n\nGame Over."));
    } else {
        engine->saveGame();
        putToTextBrowser(StaticOutputStream::wout);
    }
}

void MainWindow::on_loadButton_clicked()
{
    if(engine->endGame()){
        addToTextBrowser(StaticOutputStream::wout, QString("\n\nGame Over."));
    } else {
        engine->loadGame();
        putToTextBrowser(StaticOutputStream::wout);
    }
}

void MainWindow::inputAccepted()
{
    if(engine->endGame()){
        delete engine;
    }
}

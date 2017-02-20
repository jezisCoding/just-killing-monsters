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
    printToTextBrowser(StaticOutputStream::wout);

    //connect(this, SIGNAL(inputAccepted()), ui->consoleTextBrowser, SLOT(update()));
    //connect(this, SIGNAL(inputAccepted()), ui->consoleTextBrowser, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* kEvent)
{
    if(kEvent->key() == Qt::Key_W || kEvent->key() == Qt::Key_S
    || kEvent->key() == Qt::Key_A || kEvent->key() == Qt::Key_D){
        engine->GUIKeyinput(kEvent->key());
        printToTextBrowser(StaticOutputStream::wout);
    }

    //QWidget::keyPressEvent(key);
}

void MainWindow::printToTextBrowser(std::ostringstream& oss)
{
    QString kappa = QString(oss.str().c_str());
    oss.str("");
    ui->consoleTextBrowser->clear();
    ui->consoleTextBrowser->setPlainText(kappa);
    ui->consoleTextBrowser->update();
    emit inputAccepted();
}

void MainWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_welcomeButton_clicked()
{
    engine->welcome();
    printToTextBrowser(StaticOutputStream::wout);
}

void MainWindow::on_saveButton_clicked()
{
    engine->saveGame();
    printToTextBrowser(StaticOutputStream::wout);
}

void MainWindow::on_loadButton_clicked()
{
    engine->loadGame();
    printToTextBrowser(StaticOutputStream::wout);
}

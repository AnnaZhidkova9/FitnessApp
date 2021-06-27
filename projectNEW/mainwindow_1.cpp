#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "secondwindow2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    this->setStyleSheet("background-color: pink;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sWindow = new SecondWindow();
    sWindow -> show();
    this->close();

}

void MainWindow::on_pushButton_2_clicked()
{
    s2Window = new SecondWindow2();
    s2Window -> show();
    this->close();

}

void MainWindow::on_pushButton_2_pressed()
{

}


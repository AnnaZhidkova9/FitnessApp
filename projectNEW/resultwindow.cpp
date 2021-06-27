#include "resultwindow.h"
#include "ui_resultwindow.h"


ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Fitness App");
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::summaryVariables(QString weight, QString totalKcal, QString totalProteins, QString totalFats, QString totalCarbohydrates)
{
    ui->lineEdit->setText(weight);
    ui->lineEdit_5->setText(totalKcal);
    ui->lineEdit_2->setText(totalProteins);
    ui->lineEdit_3->setText(totalFats);
    ui->lineEdit_4->setText(totalCarbohydrates);

    double totalKcal100 = 0;
    double totalProteins100 = 0;
    double totalFats100 = 0;
    double totalCarbohydrates100 = 0;

    double t = weight.toDouble();

    double u = totalKcal.toDouble();
    totalKcal100 = (u * 100) / t;
    ui->lineEdit_10->setText(QString::number(totalKcal100));

    double u2 = totalProteins.toDouble();
    totalProteins100 = (u2 * 100) / t;
    ui->lineEdit_7->setText(QString::number(totalProteins100));

    double u3 = totalFats.toDouble();
    totalFats100 = (u3 * 100) / t;
    ui->lineEdit_8->setText(QString::number(totalFats100));

    double u4 = totalCarbohydrates.toDouble();
    totalCarbohydrates100 = (u4 * 100) / t;
    ui->lineEdit_9->setText(QString::number(totalCarbohydrates100));
}



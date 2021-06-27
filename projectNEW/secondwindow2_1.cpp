#include "secondwindow2.h"
#include "ui_secondwindow2.h"
#include <QComboBox>
#include <QMessageBox>
#include "QDebug"

SecondWindow2::SecondWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow2)
{
    ui->setupUi(this);

    ui->comboBox->addItem("сидячая работа + отсутствие или редкие занятия фитнесом");
    ui->comboBox->addItem("сидячая работа + занятия фитнесом 1-3 раза/неделю");
    ui->comboBox->addItem("средняя активность + занятия фитнесом 3-5 раз/неделю");
    ui->comboBox->addItem("высокая активность + занятия фитнесом 6-7 раз/неделю");
    ui->comboBox->addItem("тяжёлая физическая работа + занятия фитнесом");

}

SecondWindow2::~SecondWindow2()
{
    delete ui;
}


void SecondWindow2::on_pushButton_clicked()
{
    QString height;
    QString weight;
    QString age;

    QString str1 = ui->height->text();
    QString str2 = ui->weight->text();
    QString str3 = ui->age->text();


//    QMessageBox::information(this,"Title", str1);

    if (ui->radioButton->isChecked())
    {
        double result_Woman =   655 + (1.8 * str1.toDouble()) + (9.6 * str2.toDouble()) - (4.7 * str3.toDouble());

        int index = ui->comboBox->currentIndex();
        if  (index == 1)
             result_Woman *= 1.2;
        if  (index == 2)
             result_Woman *= 1.3;
        if  (index == 3)
             result_Woman *= 1.5;
        if  (index == 4)
             result_Woman *= 1.7;
        if  (index == 5)
             result_Woman *= 1.8;
        ui->lineEdit_4->setText(QString::number(result_Woman));
    }


     if (ui->radioButton_2->isChecked())
     {
         double result_Man = 66 + (5 * str1.toDouble()) + (13.7 * str2.toDouble()) - (6.8 * str3.toDouble());

         int index2 = ui->comboBox->currentIndex();
         if  (index2 == 1)
              result_Man *= 1.2;
         if  (index2 == 2)
              result_Man *= 1.3;
         if  (index2 == 3)
              result_Man *= 1.5;
         if  (index2 == 4)
              result_Man *= 1.7;
         if  (index2 == 5)
              result_Man *= 1.8;
         ui->lineEdit_4->setText(QString::number(result_Man));
     }



}

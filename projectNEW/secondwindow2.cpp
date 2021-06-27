#include "secondwindow2.h"
#include "ui_secondwindow2.h"
#include <QComboBox>
#include <QMessageBox>
#include "QDebug"
#include <stdio.h>
#include <iostream>
using namespace std;

SecondWindow2::SecondWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow2)
{
    ui->setupUi(this);
    this->setWindowTitle("Fitness App");

    ui->comboBox->addItem("сидячая работа + отсутствие или редкие занятия фитнесом"); // предосталяем выбор активности пользователю
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
    QString str1 = ui->height->text();
    QString str2 = ui->weight->text();
    QString str3 = ui->age->text();
    double result_Woman = 0;
    double result_Man = 0;

    if (ui->radioButton_2->isChecked()) // если выбрана кнопка с полом "женщина"
    {
        if ( str1.isEmpty() && str2.isEmpty() && str3.isEmpty() )
        {
            QMessageBox::information(this, tr("Предупреждение"), tr("Вы не ввели параметры!"));
            result_Woman = 0;
            ui->lineEdit_4->setText(QString::number(result_Woman)); // выводим суточную норму калорий для женщины в окно для результата
        }
        else {

            if (str1.isEmpty())
                QMessageBox::information(this, tr("Предупреждение"), tr("Не введен рост!"));
            if (str2.isEmpty())
                QMessageBox::information(this, tr("Предупреждение"), tr("Не введен вес!"));
            if (str3.isEmpty())
                QMessageBox::information(this, tr("Предупреждение"), tr("Не введен возраст!"));

        result_Woman = 655 + (1.8 * str1.toDouble()) + (9.6 * str2.toDouble()) - (4.7 * str3.toDouble()); // переменная для подсчета суточной нормы калорий для женщин

        int index = ui->comboBox->currentIndex(); // индекс физической активности
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

        if (  str1.isEmpty() ||  str2.isEmpty() ||  str3.isEmpty() )
        {
            result_Woman = 0;
            ui->lineEdit_4->setText(QString::number(result_Woman)); // выводим суточную норму калорий для женщины в окно для результата
        }
        else
        ui->lineEdit_4->setText(QString::number(result_Woman)); // выводим суточную норму калорий для женщины в окно для результата
        }
}

     if (ui->radioButton->isChecked()) // если выбрана кнопка с полом "мужчина"
     {

         if ( str1.isEmpty() && str2.isEmpty() && str3.isEmpty() )
         {
             QMessageBox::information(this, tr("Предупреждение"), tr("Вы не ввели параметры!"));
             result_Man = 0;
             ui->lineEdit_4->setText(QString::number(result_Man)); // выводим суточную норму калорий для мужчины в окно для результата
         }
         else {

             if (str1.isEmpty())
                 QMessageBox::information(this, tr("Предупреждение"), tr("Не введен рост!"));
             if (str2.isEmpty())
                 QMessageBox::information(this, tr("Предупреждение"), tr("Не введен вес!"));
             if (str3.isEmpty())
                 QMessageBox::information(this, tr("Предупреждение"), tr("Не введен возраст!"));

         result_Man = 66 + (5 * str1.toDouble()) + (13.7 * str2.toDouble()) - (6.8 * str3.toDouble()); // переменная для подсчета суточной нормы калорий для мужчин

         int index2 = ui->comboBox->currentIndex(); // индекс физической активности
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

         if (  str1.isEmpty() ||  str2.isEmpty() ||  str3.isEmpty() )
         {
             result_Man = 0;
             ui->lineEdit_4->setText(QString::number(result_Man)); // выводим суточную норму калорий для мужчины в окно для результата
         }
         else
         ui->lineEdit_4->setText(QString::number(result_Man)); // выводим суточную норму калорий для мужчины в окно для результата
         }
     }     
}

#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "QDebug"
#include "QInputDialog"
#include "QMessageBox"
#include "string"
#include "resultwindow.h"

using namespace std;

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Fitness App");
    load_catalog(":/product.txt"); // загружаем стандартный справочник
    QObject::connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(load_another_catalog()));
    totalKcal = 0;
    totalProteins = 0;
    totalFats = 0;
    totalCarbohydrates = 0;
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::load_another_catalog()
{
    QString toOpen = QFileDialog::getOpenFileName(this, ("Open"), "/home", ("Files (*.txt)")); // предоставляем возсожность выбора другого справочника
    load_catalog(toOpen);
}

void SecondWindow::load_catalog(QString path)
{
    QFile inFile(path);

    if (!inFile.open(QIODevice::ReadOnly))
        return;

    //готовим справочник
    ui->productList->clear();
    ui->caloryArea->clear();

    QTextStream in(&inFile);
    in.setCodec("UTF-8");

    QString line;
    QString product;
    QString calory;

    //готовим к нахождению калорийности, белков, жиров, углеводов
    products.clear();
    calorys.clear();

    while (!in.atEnd()) { //пока не кончился файл
        line = in.readLine(); //считываем строки файла

        if (!line.isEmpty() && !line[0].isSpace()) //если строка не пуста и начинается не с пробела
        {
            if (!product.isEmpty()) //если слово не пусто
            {
                products.append(product);
                calorys.insert(product, calory);
            }
            product = line.simplified(); //очищаем пробелы в начале и в конце строки
            calory = product; // начинается с самого продукта
        }
        else
            calory = calory + QString("\n") + line;
    }

    if (!product.isEmpty())
    {
        products.append(product);
        calorys.insert(product, calory);
    }

    inFile.close();
    ui->productList->addItems(products);
}

//по какому слову кликнули
void SecondWindow::on_productList_currentTextChanged(const QString &currentText)
{
    ui->caloryArea->setPlainText(calorys[currentText]);

    QString currentString = calorys[currentText];
    int size = currentString.length();
    QString s1;
    int counter = 0; // заводим счетчик для подсчета чисел, которые будем проходить

    for(int i = 0; i < size; ++i)
    {

        if(currentString[i] >= '0' && currentString[i] <= '9') // если цифра
        {
            s1 = s1 + currentString[i];
            i++;
            while(!currentString[i].isSpace())
            {
                s1 = s1 + currentString[i];
                i++;

            }

            counter +=1; // увеличиваем счетчик цифр

            if (counter == 1) // если счетчик = 1,
                ui->kcal->setText(s1); // значит нашли калорийность продукта, записываем в таблицу

            if (counter == 2) // если счетчик = 2,
                ui->proteins->setText(s1); // значит нашли количество белков в продукте, записываем в таблицу

            if (counter == 3) // если счетчик = 3,
                ui->fats->setText(s1); // значит нашли количество жиров в продукте, записываем в таблицу

            if (counter == 4) // если счетчик = 4,
                ui->carbohydrates->setText(s1); // значит нашли количество углеводов в продукте, записываем в таблицу

            s1.clear(); // очищаем строку
        }
    }
}
//поиск по строке
void SecondWindow::on_searchLine_textChanged(const QString &arg1)
{
    QRegExp rx(arg1);
    ui->productList->clear();
    ui->productList->addItems(products.filter(rx));
}

void SecondWindow::on_Add_clicked()
{
    QString weight = ui->weightLine->text(); // масса продукта
    QString kcal = ui->kcal->text(); // калорийность продукта
    QString proteins = ui->proteins->text(); // количество белков в продукте
    QString fats = ui->fats->text(); // количество жиров в продукте
    QString carbohydrates = ui->carbohydrates->text(); // количество углеводоов в продукте

    totalKcal = totalKcal + (weight.toDouble() * kcal.toDouble()) / 100; // расчитываем калорийность готового блюда
    totalProteins = totalProteins + (weight.toDouble() * proteins.toDouble()) / 100; // расчитываем количество белков в готовом блюде
    totalFats = totalFats + (weight.toDouble() * fats.toDouble()) / 100; // расчитываем количество жиров в готовом блюде
    totalCarbohydrates = totalCarbohydrates + (weight.toDouble() * carbohydrates.toDouble()) / 100; // расчитываем количество углеводов в готовом блюде

        qDebug() << totalKcal;
        qDebug() << totalProteins;
        qDebug() << totalFats;
        qDebug() << totalCarbohydrates;
}

void SecondWindow::on_clear_clicked()

{
   ui->weightLine->clear(); //очищаем поле для ввода массы на экране
   ui->kcal->clear(); //очищаем поле для калорийности на экране
   ui->proteins->clear(); //очищаем поле для белков на экране
   ui->fats->clear(); //очищаем поле для жиров на экране
   ui->carbohydrates->clear(); //очищаем поле для углеводов массы на экране
}

void SecondWindow::on_Total_clicked()
{
    s3Window = new ResultWindow();
    // передаем значения в resultwindow
    s3Window->summaryVariables(ui->UTOG->text(), QString::number(totalKcal), QString::number(totalProteins), QString::number(totalFats), QString::number(totalCarbohydrates) );
    s3Window -> show();
    this->close();
}

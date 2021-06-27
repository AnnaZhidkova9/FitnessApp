#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "QDebug"
#include "QInputDialog"
#include "QMessageBox"
#include "string"

using namespace std;



SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    load_dictionary(":/product.txt");
    QObject::connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(load_another_dictionary()));
    totalKcal = 0;
    totalProteins = 0;
    totalFats = 0;
    totalCarbohydrates = 0;
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::load_another_dictionary()
{
    QString toOpen = QFileDialog::getOpenFileName(this, ("Open"), "/home", ("Files (*.txt)"));
    load_dictionary(toOpen);
    }

void SecondWindow::load_dictionary(QString path)
{
    QFile inFile(path);

    if (!inFile.open(QIODevice::ReadOnly)) {
        return;
    }

    //готовим
    ui->wordList->clear();
    ui->translationArea->clear();

    QTextStream in(&inFile);
    in.setCodec("UTF-8");

    QString line;
    QString word;
    QString translation;

    //готовим к переводу
    words.clear();
    translations.clear();

    while (!in.atEnd()) { //пока не кончился файл
        line = in.readLine(); //считываем строки файла

        if (!line.isEmpty() && !line[0].isSpace()) { //если строка не пуста и начинается не с пробела
            if (!word.isEmpty()) { //если слово не пусто
                words.append(word);
                translations.insert(word, translation);
            }
            word = line.simplified(); //очищаем пробелы в начале и в конце строки
            translation = word; // начинается с самого слова
        }
        else {
            translation = translation + QString("\n") + line;
        }
    }

    if (!word.isEmpty()) {
        words.append(word);
        translations.insert(word, translation);
    }

    inFile.close();
    ui->wordList->addItems(words);
}

//по какому слову кликнули
void SecondWindow::on_wordList_currentTextChanged(const QString &currentText)
{
    ui->translationArea->setPlainText(translations[currentText]);

    QString currentString = translations[currentText];
    int size = currentString.length();
    QString s1;
    int counter = 0;

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

            counter +=1;


            if (counter == 1)
                ui->kcal->setText(s1);

            if (counter == 2)
                ui->proteins->setText(s1);

            if (counter == 3)
                ui->fats->setText(s1);

            if (counter == 4)
                ui->carbohydrates->setText(s1);

            s1.clear();

        }
    }

}

//поиск по строке
void SecondWindow::on_searchLine_textChanged(const QString &arg1)
{
    QRegExp rx(arg1);
    ui->wordList->clear();
    ui->wordList->addItems(words.filter(rx));
}


void SecondWindow::on_Add_clicked()
{
    QString weight = ui->weightLine->text();
    QString kcal = ui->kcal->text();
    QString proteins = ui->proteins->text();
    QString fats = ui->fats->text();
    QString carbohydrates = ui->carbohydrates->text();


//    qDebug() << weight;
//    qDebug() << kcal;
//    qDebug() << proteins;
//    qDebug() << fats;
//    qDebug() << carbohydrates;

    totalKcal = totalKcal + (weight.toDouble() * kcal.toDouble()) / 100;
    totalProteins = totalProteins + (weight.toDouble() * proteins.toDouble()) / 100;
    totalFats = totalFats + (weight.toDouble() * fats.toDouble()) / 100;
    totalCarbohydrates = totalCarbohydrates + (weight.toDouble() * carbohydrates.toDouble()) / 100;


        qDebug() << totalKcal;
        qDebug() << totalProteins;
        qDebug() << totalFats;
        qDebug() << totalCarbohydrates;
}

void SecondWindow::on_clear_clicked()

{

   ui->weightLine->clear();
   ui->kcal->clear();
   ui->proteins->clear();
   ui->fats->clear();
   ui->carbohydrates->clear();

}






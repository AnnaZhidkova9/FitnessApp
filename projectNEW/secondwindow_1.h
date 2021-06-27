#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QFileDialog>


namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();


public slots:

    void load_another_dictionary();


private slots:

    void on_wordList_currentTextChanged(const QString &currentText);

    void on_searchLine_textChanged(const QString &arg1);


    void on_Add_clicked();




    void on_clear_clicked();

private:
    Ui::SecondWindow *ui;
    void load_dictionary(QString path);
    QStringList words;
    QHash<QString, QString> translations;

    double totalKcal;
    double totalProteins;
    double totalFats;
    double totalCarbohydrates;
};

#endif // SECONDWINDOW_H

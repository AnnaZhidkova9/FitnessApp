#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QHash>
#include <QFileDialog>
#include "resultwindow.h"

namespace Ui { class SecondWindow; }

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    double totalKcal;
    double totalProteins;
    double totalFats;
    double totalCarbohydrates;

public slots:
    void load_another_catalog();


private slots:
    void on_productList_currentTextChanged(const QString &currentText);
    void on_searchLine_textChanged(const QString &arg1);
    void on_Add_clicked();
    void on_clear_clicked();
    void on_Total_clicked();

private:
    Ui::SecondWindow *ui;
    void load_catalog(QString path);
    QStringList products;
    QHash<QString, QString> calorys;

    ResultWindow *s3Window;
};

#endif // SECONDWINDOW_H

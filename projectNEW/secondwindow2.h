#ifndef SECONDWINDOW2_H
#define SECONDWINDOW2_H
#include <QMainWindow>

namespace Ui { class SecondWindow2; }

class SecondWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow2(QWidget *parent = nullptr);
    ~SecondWindow2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondWindow2 *ui;

};

#endif // SECONDWINDOW2_H

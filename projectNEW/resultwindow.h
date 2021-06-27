#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H
#include <QMainWindow>

namespace Ui { class ResultWindow; }
class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);

    void summaryVariables(QString weight, QString totalKcal, QString totalProteins, QString totalFats, QString totalCarbohydrates);

    ~ResultWindow();

private:
    Ui::ResultWindow *ui;

};





#endif // RESULTWINDOW_H

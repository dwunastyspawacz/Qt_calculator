#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>
#include <QString>


namespace Ui {
class Clicker;
}

class Clicker : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clicker(QWidget *parent = 0);
    ~Clicker();

public slots:

    void loadFile();
    void interpretTheLine(QString myLine);


signals:
    void showTheEquationOnTheLabel(QString myLine);
    void sendLineForInterpretation(QString myLine);
    void sendResultToLCD(int val);

private slots:
    void on_buttonOne_clicked();

    void on_buttonLoad_clicked();

private:
    Ui::Clicker *ui;
};

#endif // CLICKER_H

#include "clicker.h"
#include "ui_clicker.h"
#include <QFileDialog>
#include <QTextStream>
#include "QtScript\QScriptEngine"
#include "QtScript\QScriptValue"


Clicker::Clicker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clicker)
{
    ui->setupUi(this);

    connect(ui->buttonLoad, SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(this, SIGNAL(sendLineForInterpretation()),this, SLOT(interpretTheFile()));
    connect(this, SIGNAL(showTheEquationOnTheLabel(QString)), ui->label, SLOT(setText(QString)));
    connect(this, SIGNAL(sendLineForInterpretation(QString)),this, SLOT(interpretTheLine(QString)));
    connect(this, SIGNAL(sendResultToLCD(int)),ui->lcdDisplay, SLOT(display(int)));
}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::on_buttonOne_clicked()
{

}

void Clicker::on_buttonLoad_clicked()
{

}

void Clicker::loadFile()
{
     QString fileName = QFileDialog::getOpenFileName(this,
     tr("Open .TXT file with the equation"), "",
     tr("Equation file (*.txt);;All Files (*)"));

     QFile myFile(fileName);
     myFile.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&myFile);
     QString myLine = in.readLine();

     emit showTheEquationOnTheLabel(myLine);
     emit sendLineForInterpretation(myLine);
}

void Clicker::interpretTheLine(QString myLine)
{
    QScriptEngine myEngine;
    QScriptValue myVal = myEngine.evaluate(myLine);
    double resVal = myVal.toNumber();

    emit sendResultToLCD(resVal);

}

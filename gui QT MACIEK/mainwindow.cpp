#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtGui>
#include "testbinarny.h"
#include<test_pi.h>

using namespace std;




MainWindow::MainWindow() :
 //   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //
    //text=new QTextEdit;
    //setCentralWidget(text);
   // QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
   //connect(Button,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
   //connect(Button,SIGNAL(clicked()),qApp,SLOT()
    ui->comboBox->addItem("fib");
    ui->comboBox->addItem("gen_blum");
    setWindowTitle("Program testujący");
    ui->comboBox2->addItem("test binarny");
    ui->comboBox2->addItem("test pi");
}



MainWindow::~MainWindow()
{
    delete ui;
}
//*************************
//******w tej funkcji na poczatku sprawdzam jaki test zostal wybrany
//nastepnie wywolywana jest funkcja ktora sprawdza jaki zostal wybrany generator testowanie_bin() lub testoanie_pi()
//po nacisnieciu przycisku wynik wyswietli sie w polu ponizej

void MainWindow:: on_pushButton_clicked()
{
    if((ui->comboBox2->currentText())=="test binarny")
    {
        MainWindow::testowanie_bin();
    }
    else if((ui->comboBox2->currentText())=="test pi")
    {
        MainWindow::testowanie_pi();
    }


}
//*************************
//******funkcja wywołujaca odpowiedni generator jezeli wybralismy testowanie binarne
//*************************
void MainWindow::testowanie_bin()
{
    if((ui->comboBox->currentText())=="fib")
{
    int wynik=testujblum_blum(2);//testowanie generatora fibonaciego
    if(wynik==1)
    {
        ui->label->setText("generator fibonacciego przeszedł test\n");
            }
    else
        ui->label->setText("generator zły");
}
else
{
    int wynik=testujblum_blum(1);//testowanie generatora blum blum
    if(wynik==1)
    {
        ui->label->setText("generator blum blum przeszedł test");
        }
    else
        ui->label->setText("generator zły");

}
}
//***************************
//*******funkcja wywolujaca odpowiedni generator jezeli wybralismy test pi
//****************************
//********************
//**********************
//****UWAGA***
//w tej funkcji jest chyba maly problem poniewaz liczba ktora
//powinna sie wyswietlc jako wynik dzialania testu to obliczona wartosc pi
//jednak wyswietla sie 0
//liczby na jakich jest przeprowadzany test sa z przedzialu [0,1]
//popatrzcie na ta funkcje moze znajdziecie blad
void MainWindow::testowanie_pi()
{
       test_pi T_pi;

        if((ui->comboBox->currentText())=="fib")
        {
           Generator *g=new Fibonacci  (1048575+1);
           T_pi.testuj(g);
            ui->label->setText("tu test pi\tgenerator fibonacciego\n");
           double ww=T_pi.wynik();
           double inte = T_pi.interpretacja();

           ui->label_3->setNum(ww);
        }
        else {
            Generator *g=new Blum_Generator;
            T_pi.testuj(g);
            ui->label->setText("tu test pi\tgenerator blum blum\n");
            double ww=T_pi.wynik();
            double inte = T_pi.interpretacja();

            ui->label_3->setNum(ww);
        }

}

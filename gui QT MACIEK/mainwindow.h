#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QMessageBox>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
    ~MainWindow();
    // void wybor_testu_i_gen();
    void testowanie_bin();
    void testowanie_pi();
private slots:
    void on_pushButton_clicked();
   // void FIBB();
   // void BLUM();

private:
    Ui::MainWindow *ui;
    //QAction *gen_fib;
   // QAction *gen_blum;
     // QPushButton * Button;
    //QTextEdit *text;

};


#endif // MAINWINDOW_H

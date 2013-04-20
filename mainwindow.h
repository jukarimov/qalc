#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtScript>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegExp>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString evaluate(QString str) {
        QScriptEngine eng;
        QScriptValue val = eng.evaluate(str);
        return val.toString();
    }
    
private:
    Ui::MainWindow *ui;

private slots:
    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_B6_clicked();
    void on_B7_clicked();
    void on_B8_clicked();
    void on_B9_clicked();
    void on_B0_clicked();
    void on_BADD_clicked();
    void on_BSUB_clicked();
    void on_BMUL_clicked();
    void on_BDIV_clicked();
    void on_BDOT_clicked();
    void on_BSQR_clicked();
    void on_BPOW_clicked();
    void on_BFAC_clicked();
    void on_BRUN_clicked();
    void on_BCLR_clicked();

    void actionOpen();
    void actionQuit();

    void actionDiscriminant();
    void actionAbout();
};

#endif // MAINWINDOW_H

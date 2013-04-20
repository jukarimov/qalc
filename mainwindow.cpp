#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B1_clicked()
{
    ui->iobox->insertPlainText("1");
}

void MainWindow::on_B2_clicked()
{
    ui->iobox->insertPlainText("2");
}

void MainWindow::on_B3_clicked()
{
    ui->iobox->insertPlainText("3");
}

void MainWindow::on_B4_clicked()
{
    ui->iobox->insertPlainText("4");
}

void MainWindow::on_B5_clicked()
{
    ui->iobox->insertPlainText("5");
}

void MainWindow::on_B6_clicked()
{
    ui->iobox->insertPlainText("6");
}

void MainWindow::on_B7_clicked()
{
    ui->iobox->insertPlainText("7");
}

void MainWindow::on_B8_clicked()
{
    ui->iobox->insertPlainText("8");
}

void MainWindow::on_B9_clicked()
{
    ui->iobox->insertPlainText("9");
}

void MainWindow::on_B0_clicked()
{
    ui->iobox->insertPlainText("0");
}

void MainWindow::on_BADD_clicked()
{
    ui->iobox->insertPlainText("+");
}

void MainWindow::on_BSUB_clicked()
{
    ui->iobox->insertPlainText("-");
}

void MainWindow::on_BMUL_clicked()
{
    ui->iobox->insertPlainText("*");
}

void MainWindow::on_BDIV_clicked()
{
    ui->iobox->insertPlainText("/");
}

void MainWindow::on_BCLR_clicked()
{
    ui->iobox->setText("");
}

void MainWindow::on_BRUN_clicked()
{
    QString str = ui->iobox->toPlainText();
    QString val = this->evaluate(str);
    ui->iobox->setText(val);

    QTextCursor cur = ui->iobox->textCursor();
    cur.movePosition(QTextCursor::EndOfLine);
    ui->iobox->setTextCursor(cur);
}

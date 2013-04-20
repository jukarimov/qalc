#include "mainwindow.h"
#include "ui_mainwindow.h"

const char *QCALC_ABOUT = "Qalc calculator on JS engine in QT\nBy Jalil Karimov <jukarimov@gmail.com>";

const char *JSFUN_DISCRIMINANT =
        "function f(a,b,c) {\n"
        "var D = b*b - 4 * a * c;\n"
        "if (D < 0)  return '//No roots';\n"
        "var x1 = (-b + Math.sqrt(D))/(2*a);\n"
        "var x2 = (-b - Math.sqrt(D))/(2*a);\n"
        "return '//x1=' + x1 + '; x2=' + x2;\n"
        "};\nf(4,5,1);"
        ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *fileMenu = this->menuBar()->addMenu("File");
    fileMenu->addAction("Open", this, SLOT(actionOpen()));
    fileMenu->addAction("Quit", this, SLOT(actionQuit()));

    QMenu *helpMenu = this->menuBar()->addMenu("Help");
    helpMenu->addAction("Discriminant", this, SLOT(actionDiscriminant()));
    helpMenu->addAction("About", this, SLOT(actionAbout()));
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

void MainWindow::on_BDOT_clicked()
{
    QTextCursor cur = ui->iobox->textCursor();
    QChar c = ui->iobox->toPlainText().at(cur.position()-1);
    if (c == '.')
        return;
    ui->iobox->insertPlainText(".");
}

void MainWindow::on_BSQR_clicked()
{
    ui->iobox->insertPlainText("Math.sqrt(n)");
}

void MainWindow::on_BPOW_clicked()
{
    ui->iobox->insertPlainText("Math.pow(b,d)");
}

void MainWindow::on_BFAC_clicked()
{
    ui->iobox->insertPlainText("function fac(n){return n<=1?1:n*fac(n-1);};\nfac(n)\n");
}

void MainWindow::on_BCLR_clicked()
{
    ui->iobox->setText("");
}

void MainWindow::on_BRUN_clicked()
{
    QString str = ui->iobox->toPlainText();

    QRegExp re("alert\\(.*.\\)");
    re.setPatternSyntax(QRegExp::RegExp);
    if (re.exactMatch(str)) {
        qDebug("matched");
        QString alertval = "";
        int i, len = str.length();
        for (i = 6; ; ++i) {
            if (str[i] == ')' && i == len-1)
                break;
            alertval += str[i];
        }

        qDebug() << alertval;
        QString jalertval = this->evaluate(alertval);
        QMessageBox::information(0, "alert", jalertval);

        return;
    }

    QString val = this->evaluate(str);
    //ui->iobox->setText(val);
    ui->iobox->append(val);

    QTextCursor cur = ui->iobox->textCursor();
    cur.movePosition(QTextCursor::End);
    ui->iobox->setTextCursor(cur);
}

void MainWindow::actionOpen()
{
    qDebug("actionOpen");

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open File",
                                                    "",
                                                    "Files (*.js)");

    qDebug() << "file:" << fileName;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Note", file.errorString());
        return;
    }

    QTextStream data(&file);
    QString text = data.readAll();
    file.close();

    ui->iobox->setText(text);
}

void MainWindow::actionQuit()
{
    qDebug("actionQuit");

    QCoreApplication::quit();
}

void MainWindow::actionDiscriminant()
{
    qDebug("actionDiscriminant");

    ui->iobox->setText(JSFUN_DISCRIMINANT);

}

void MainWindow::actionAbout()
{
    qDebug("actionAbout");
    QMessageBox::information(0, "Note", QCALC_ABOUT);
}

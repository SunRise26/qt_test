#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coupi.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->submitBtn->setText(ui->comboBox->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitBtn_released()
{
    static std::string (*func[])(void) = {
        &getFunction1,
        &getFunction2,
        &getFunction3
    };
    QString title = ui->comboBox->currentText();
    QString msg = QString::fromStdString(func[ui->comboBox->currentIndex()]());

    QMessageBox::information(this, title, msg,
                             QMessageBox::Cancel | QMessageBox::Ok);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->submitBtn->setText(arg1);
}

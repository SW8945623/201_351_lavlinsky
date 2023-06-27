#include "authentication.h"
#include "ui_authentication.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include "QFile"


Authentication::Authentication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Authentication)
{
    ui->setupUi(this);
}

Authentication::~Authentication()
{
    delete ui;
}
void Authentication::on_pushButton_clicked()
{

    QString password = ui->Password->text();

    QByteArray password_hash = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toBase64();

    const QByteArray HASH = "pmWkWSBCL51Bfkhn79xPuKBKHz//H6B+mY6G9/eieuM=";


    if(password_hash == HASH){
        promocodes = new Promocodes(password);
        promocodes->show();
        this->close();
    } else {
        QMessageBox::warning(this,"Ошибка","Пин-код введён неверно!");
        ui->Password->clear();
    }


}



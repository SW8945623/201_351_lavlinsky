#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QMainWindow>
#include <promocodes.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Authentication; }
QT_END_NAMESPACE

class Authentication : public QMainWindow
{
    Q_OBJECT

public:
    Authentication(QWidget *parent = nullptr);
    ~Authentication();


private slots:
    void on_pushButton_clicked();

private:
    void check_password_hash();
    Ui::Authentication *ui;
    Promocodes *promocodes;
};
#endif // AUTHENTICATION_H

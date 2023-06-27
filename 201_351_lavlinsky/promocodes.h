#ifndef PROMOCODES_H
#define PROMOCODES_H

#include <QWidget>
#include "cardwidget.h"
#include <QString>

namespace Ui {
class Promocodes;
}

class Promocodes : public QWidget
{
    Q_OBJECT

public:
    explicit Promocodes(QString key, QWidget *parent = nullptr);
    ~Promocodes();

signals:
    void firstWindow();

private slots:
    QString generateRandomString(int length);
    void initPromo();
    void addPromo();
    void addCard(QString promo);
    void on_pushButton_clicked();

private:
    Ui::Promocodes *ui;
    QVector<QString> promos;
    QVector<uint> openedPromos;

    uint fieldSize = 9;
};

#endif // PROMOCODES_H

#ifndef PROMOCODES_H
#define PROMOCODES_H

#include <QWidget>

namespace Ui {
class Promocodes;
}

class Promocodes : public QWidget
{
    Q_OBJECT

public:
    explicit Promocodes(QString key, QWidget *parent = nullptr);
    ~Promocodes();

private:
    Ui::Promocodes *ui;
};

#endif // PROMOCODES_H

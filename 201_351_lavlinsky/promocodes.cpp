#include "promocodes.h"
#include "ui_promocodes.h"
#include <QRandomGenerator>
#include <QDebug>

Promocodes::Promocodes(QString key, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promocodes)
{
    ui->setupUi(this);
    initPromo();
}

Promocodes::~Promocodes()
{
    delete ui;
}

QString Promocodes::generateRandomString(int length)
{
    QString randomString;
    randomString.reserve(length);

    static const QString validChars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int validCharsLength = validChars.length();

    for (int i = 0; i < length; ++i) {
        int randomIndex = QRandomGenerator::global()->bounded(validCharsLength);
        QChar randomChar = validChars.at(randomIndex);
        randomString.append(randomChar);
    }

    qDebug() << randomString;
    return randomString;
}


void Promocodes::initPromo() {
    ui->listWidget->clear();
    for (uint i = 0; i < fieldSize; i++) {
        addPromo();
    }
}

void Promocodes::addPromo() {
    QString promo = generateRandomString(4);
    promos.append(promo);
    addCard(promo);
}

void Promocodes::addCard(QString promo) {
    QListWidgetItem* listItem = new QListWidgetItem();
    CardWidget* itemWidget = new CardWidget(promo, this);

    listItem->setSizeHint(itemWidget->sizeHint());

    ui->listWidget->addItem(listItem);
    ui->listWidget->setItemWidget(listItem, itemWidget);
}

void Promocodes::on_pushButton_clicked()
{
    while (true) {
        uint randomIndex = QRandomGenerator::global()->bounded(0u, fieldSize);
        if (openedPromos.contains(randomIndex)) {
            continue;
        }

        QListWidgetItem* item = ui->listWidget->item(randomIndex);
        CardWidget* itemWidget = qobject_cast<CardWidget*>(ui->listWidget->itemWidget(item));

        itemWidget->showPromo();
        openedPromos.append(randomIndex);
        fieldSize++;

        addPromo();

        break;
    }
}


#include "cardwidget.h"
#include "ui_cardwidget.h"

CardWidget::CardWidget(const QString promo, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);

  ui->pushButton->setText("");
  this->setPromo(promo);
//  this->pinCode = pinCode;
}

CardWidget::~CardWidget() {
  delete ui;
}

const QString CardWidget::getPromo() {
  return promo;
}

void CardWidget::setPromo(const QString promo) {
  this->promo = promo;
}

void CardWidget::showPromo() {
  ui->pushButton->setText(promo);
}

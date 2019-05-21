// Copyright (c) 2014-2019 winking324
//

#include "view/splash_widget.h"

#include <QIcon>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QSpacerItem>


namespace avc {


SplashWidget::SplashWidget(QWidget *parent)
  : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignCenter);

  auto *icon_label = new QLabel(this);
  icon_label->setPixmap(QPixmap(":/icon.png"));

  auto *about_label = new QLabel(tr("Agora Video Call"), this);
  about_label->setStyleSheet("color:#9196A0;font:16px");

  auto *info_label = new QLabel(tr("Powering Real-Time Communications"), this);
  info_label->setStyleSheet("color:#009EEB;font:bold 16px;");

  layout->addWidget(icon_label, 0, Qt::AlignCenter);
  layout->addItem(new QSpacerItem(20, 20));
  layout->addWidget(about_label, 0, Qt::AlignCenter);
  layout->addItem(new QSpacerItem(20, 20));
  layout->addWidget(info_label, 0, Qt::AlignCenter);

  setLayout(layout);
}

void SplashWidget::OnTimer() {
  emit SplashEndEvent();
}

void SplashWidget::showEvent(QShowEvent *event) {
  (void)event;
  QTimer::singleShot(3000, this, SLOT(OnTimer()));
}


}  // namespace avc

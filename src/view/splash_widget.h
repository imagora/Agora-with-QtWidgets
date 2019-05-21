// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QWidget>


namespace avc {


class SplashWidget : public QWidget {
  Q_OBJECT

 public:
  explicit SplashWidget(QWidget *parent = nullptr);

 signals:
  void SplashEndEvent();

 public slots:
  void OnTimer();

 protected:
  virtual void showEvent(QShowEvent *event) override;
};


}  // namespace avc

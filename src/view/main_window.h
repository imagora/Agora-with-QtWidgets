// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QMainWindow>

#include "view/central_widget.h"


namespace avc {


class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);

 private:
  CentralWidget *central_widget_;
};


}  // namespace avc


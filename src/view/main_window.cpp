// Copyright (c) 2014-2019 winking324
//


#include "view/main_window.h"


namespace avc {


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent) {
  central_widget_ = new CentralWidget(this);
  setCentralWidget(central_widget_);
  setFixedSize(600, 600);
}


}  // namespace avc

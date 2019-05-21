// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QWidget>
#include <QStackedLayout>

#include "view/splash_widget.h"
#include "view/join_room_widget.h"
#include "view/in_room_widget.h"


namespace avc {


class CentralWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CentralWidget(QWidget *parent = nullptr);

 signals:

 public slots:
  void OnSplashEnd();

  void OnBack();

  void OnJoin(QString room_name);

  void OnEndCall();

 private:
  QStackedLayout *layout_;

  SplashWidget *splash_widget_;
  JoinRoomWidget *join_room_widget_;
  InRoomWidget *in_room_widget_;
};


}  // namespace avc

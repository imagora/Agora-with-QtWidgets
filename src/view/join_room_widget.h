// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>

#include "model/video_setting.h"


namespace avc {


class JoinRoomWidget : public QWidget {
  Q_OBJECT

 public:
  explicit JoinRoomWidget(QWidget *parent = nullptr);

 signals:
  void BackEvent();

  void JoinEvent(QString room_name);

 public slots:
  void OnBack();

  void OnJoin();

  void OnVideoSetting();

 private:
  QLineEdit *room_name_edit_;
  QPushButton *back_button_;
  QPushButton *join_button_;
  QPushButton *video_setting_button_;

  VideoSetting video_setting_;
};


}  // namespace avc

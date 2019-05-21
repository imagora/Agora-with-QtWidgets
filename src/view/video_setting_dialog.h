// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>

#include "model/video_setting.h"


namespace avc {


class VideoSettingDialog : public QDialog {
  Q_OBJECT

 public:
  VideoSettingDialog(VideoSetting setting, QWidget *parent = nullptr);

  VideoSetting GetVideoSettings();

 signals:
  void VideoSettingEvent();

 private:
  QLineEdit *width_input_;
  QLineEdit *height_input_;
  QLineEdit *framerate_input_;
  QLineEdit *bitrate_input_;
  QDialogButtonBox *buttons_;
};



}  // namespace avc

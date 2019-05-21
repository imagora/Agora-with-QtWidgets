// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QWidget>
#include <QPushButton>

#include "view/video_widget.h"


namespace avc {


class InRoomWidget : public QWidget {
  Q_OBJECT

 public:
  explicit InRoomWidget(QWidget *parent = nullptr);

 signals:
  void EndCallEvent();

  void MuteVideoEvent(bool is_mute);

  void MuteAudioEvent(bool is_mute);

 public slots:
  void OnEndCall();

  void OnMuteVideo();

  void OnMuteAudio();

  void OnDeviceSetting();

 private:
  bool is_audio_mute_;
  bool is_video_mute_;

  QPushButton *end_call_button_;
  QPushButton *mute_audio_button_;
  QPushButton *mute_video_button_;
  QPushButton *device_setting_button_;
  VideoWidget *local_video_widget_;
  std::map<uint32_t, VideoWidget *> remote_video_widget_;
};



}  // namespace avc

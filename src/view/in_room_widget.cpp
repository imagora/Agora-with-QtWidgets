// Copyright (c) 2014-2019 winking324
//

#include "view/in_room_widget.h"
#include <QIcon>
#include <QGridLayout>

#include "view/device_setting_dialog.h"


namespace avc {


InRoomWidget::InRoomWidget(QWidget *parent)
  : QWidget(parent) {
  is_audio_mute_ = false;
  is_video_mute_ = false;

  auto *layout = new QGridLayout(this);
  layout->setAlignment(Qt::AlignCenter);

  local_video_widget_ = new VideoWidget(this);

  device_setting_button_ = new QPushButton(QIcon(":/setting.png"), "", this);
  device_setting_button_->setFixedHeight(40);
  mute_video_button_ = new QPushButton(QIcon(":/video_on.png"), "", this);
  mute_video_button_->setFixedHeight(40);
  mute_audio_button_ = new QPushButton(QIcon(":/audio_on.png"), "", this);
  mute_audio_button_->setFixedHeight(40);
  end_call_button_ = new QPushButton(QIcon(":/end_call.png"), "", this);
  end_call_button_->setFixedHeight(40);

  layout->addWidget(local_video_widget_, 0, 0, 1, 4);
  layout->setRowMinimumHeight(0, maximumHeight() - 60);
  layout->addWidget(device_setting_button_, 1, 0, 1, 1);
  layout->addWidget(mute_video_button_, 1, 1, 1, 1);
  layout->addWidget(mute_audio_button_, 1, 2, 1, 1);
  layout->addWidget(end_call_button_, 1, 3, 1, 1);
  layout->setRowMinimumHeight(1, 60);

  setLayout(layout);

  connect(device_setting_button_, SIGNAL(released()), this,
          SLOT(OnDeviceSetting()));
  connect(mute_video_button_, SIGNAL(released()), this, SLOT(OnMuteVideo()));
  connect(mute_audio_button_, SIGNAL(released()), this, SLOT(OnMuteAudio()));
  connect(end_call_button_, SIGNAL(released()), this, SLOT(OnEndCall()));
}

void InRoomWidget::OnEndCall() {
  emit EndCallEvent();
}

void InRoomWidget::OnMuteVideo() {
  is_video_mute_ = !is_video_mute_;
  if (is_video_mute_) {
    mute_video_button_->setIcon(QIcon(":/video_off.png"));
  } else {
    mute_video_button_->setIcon(QIcon(":/video_on.png"));
  }
  emit MuteVideoEvent(is_video_mute_);
}

void InRoomWidget::OnMuteAudio() {
  is_audio_mute_ = !is_audio_mute_;
  if (is_audio_mute_) {
    mute_audio_button_->setIcon(QIcon(":/audio_off.png"));
  } else {
    mute_audio_button_->setIcon(QIcon(":/audio_on.png"));
  }
  emit MuteAudioEvent(is_audio_mute_);
}

void InRoomWidget::OnDeviceSetting() {
  DeviceSettingDialog setting_dialog(this);
  if (setting_dialog.exec() == QDialog::Accepted) {
  }
}


}  // namespace avc

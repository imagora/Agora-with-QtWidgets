// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QLabel>
#include <QDialog>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>

#include "view/video_widget.h"


namespace avc {


class DeviceSettingDialog : public QDialog {
  Q_OBJECT

 public:
  DeviceSettingDialog(QWidget *parent = nullptr);

 public slots:
  void OnInputVolumeSliderMoved(int value);

  void OnOutputVolumeSliderMoved(int value);

 private:
  QLabel *input_volume_label_;
  QLabel *output_volume_label_;
  QSlider *input_volume_slider_;
  QSlider *output_volume_slider_;
  QComboBox *input_device_combo_;
  QComboBox *output_device_combo_;
  QComboBox *webcam_device_combo_;
  QPushButton *input_test_button_;
  QPushButton *output_test_button_;
  QPushButton *webcam_test_button_;
  QDialogButtonBox *buttons_;
  VideoWidget *webcam_preview_widget_;
};


}  // namespace avc

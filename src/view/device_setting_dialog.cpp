// Copyright (c) 2014-2019 winking324
//

#include "view/device_setting_dialog.h"

#include <QGridLayout>


namespace avc {


DeviceSettingDialog::DeviceSettingDialog(QWidget *parent)
  : QDialog(parent) {
  setModal(true);
  setWindowTitle(tr("Device Setting"));

  auto *layout = new QGridLayout(this);
  layout->setAlignment(Qt::AlignCenter);

  input_volume_label_ = new QLabel(tr("100"), this);
  output_volume_label_ = new QLabel(tr("100"), this);

  input_volume_slider_ = new QSlider(Qt::Orientation::Horizontal, this);
  output_volume_slider_ = new QSlider(Qt::Orientation::Horizontal, this);
  input_volume_slider_->setRange(0, 100);
  input_volume_slider_->setValue(100);
  output_volume_slider_->setRange(0, 100);
  output_volume_slider_->setValue(100);

  input_device_combo_ = new QComboBox(this);
  output_device_combo_ = new QComboBox(this);
  webcam_device_combo_ = new QComboBox(this);

  input_test_button_ = new QPushButton(tr("Test"), this);
  output_test_button_ = new QPushButton(tr("Test"), this);
  webcam_test_button_ = new QPushButton(tr("Test"), this);
  buttons_ = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,
                                  this);

  webcam_preview_widget_ = new VideoWidget(this);

  int row = 0;
  layout->addWidget(new QLabel(tr("Input Device"), this), row++, 0, 1, 1);
  layout->addWidget(input_device_combo_, row, 0, 1, 2);
  layout->addWidget(input_test_button_, row++, 2, 1, 1);
  layout->addWidget(new QLabel(tr("Volume"), this), row++, 0, 1, 1);
  layout->addWidget(input_volume_slider_, row, 0, 1, 2);
  layout->addWidget(input_volume_label_, row++, 2, 1, 1, Qt::AlignLeft);
  layout->addWidget(new QLabel(tr("Output Device"), this), row++, 0, 1, 1);
  layout->addWidget(output_device_combo_, row, 0, 1, 2);
  layout->addWidget(output_test_button_, row++, 2, 1, 1);
  layout->addWidget(new QLabel(tr("Volume"), this), row++, 0, 1, 1);
  layout->addWidget(output_volume_slider_, row, 0, 1, 2);
  layout->addWidget(output_volume_label_, row++, 2, 1, 1, Qt::AlignLeft);
  layout->addWidget(new QLabel(tr("Camera"), this), row++, 0, 1, 1);
  layout->addWidget(webcam_device_combo_, row, 0, 1, 2);
  layout->addWidget(webcam_test_button_, row++, 2, 1, 1);
  layout->addWidget(webcam_preview_widget_, row, 1, 1, 1);
  layout->setRowMinimumHeight(row++, 120);
  layout->setColumnMinimumWidth(1, 160);
  layout->addWidget(buttons_, row++, 0, 1, 3, Qt::AlignCenter);
  setLayout(layout);

  connect(buttons_, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttons_, &QDialogButtonBox::rejected, this, &QDialog::reject);

  connect(input_volume_slider_, SIGNAL(sliderMoved(int)), this,
          SLOT(OnInputVolumeSliderMoved(int)));
  connect(output_volume_slider_, SIGNAL(sliderMoved(int)), this,
          SLOT(OnOutputVolumeSliderMoved(int)));
}

void DeviceSettingDialog::OnInputVolumeSliderMoved(int value) {
  input_volume_label_->setText(QString::number(value));
}

void DeviceSettingDialog::OnOutputVolumeSliderMoved(int value) {
  output_volume_label_->setText(QString::number(value));
}


}  // namespace avc

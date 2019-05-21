// Copyright (c) 2014-2019 winking324
//

#include "view/video_setting_dialog.h"

#include <QLabel>
#include <QRegExp>
#include <QGridLayout>
#include <QRegExpValidator>


namespace avc {


VideoSettingDialog::VideoSettingDialog(VideoSetting setting, QWidget *parent)
  : QDialog(parent) {
  setModal(true);
  setWindowTitle(tr("Video Setting"));

  auto *layout = new QGridLayout(this);
  layout->setAlignment(Qt::AlignCenter);

  auto *validotor = new QRegExpValidator(QRegExp("^\\d+$"), this);

  width_input_ = new QLineEdit(QString(setting.width), this);
  width_input_->setValidator(validotor);
  height_input_ = new QLineEdit(QString(setting.height), this);
  height_input_->setValidator(validotor);
  framerate_input_ = new QLineEdit(QString(setting.framerate), this);
  framerate_input_->setValidator(validotor);
  bitrate_input_ = new QLineEdit(QString(setting.bitrate), this);
  bitrate_input_->setValidator(validotor);
  buttons_ = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel,
                                  this);

  int row = 0;
  layout->addWidget(new QLabel(tr("Resolution"), this), row++, 0, 1, 4);
  layout->addWidget(new QLabel(tr("W"), this), row, 0, 1, 1);
  layout->addWidget(width_input_, row, 1, 1, 1);
  layout->addWidget(new QLabel(tr("H"), this), row, 2, 1, 1);
  layout->addWidget(height_input_, row++, 3, 1, 1);
  layout->addWidget(new QLabel(tr("Max Frame Rate"), this), row++, 0, 1, 4);
  layout->addWidget(framerate_input_, row++, 0, 1, 4);
  layout->addWidget(new QLabel(tr("Max Bit Rate"), this), row++, 0, 1, 4);
  layout->addWidget(bitrate_input_, row++, 0, 1, 4);
  layout->addWidget(buttons_, row++, 0, 1, 4);

  setLayout(layout);

  connect(buttons_, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttons_, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

VideoSetting VideoSettingDialog::GetVideoSettings() {
  VideoSetting setting;
  setting.width = width_input_->text().toInt();
  setting.height = height_input_->text().toInt();
  setting.framerate = framerate_input_->text().toInt();
  setting.bitrate = bitrate_input_->text().toInt();

  return setting;
}


}  // namespace avc

// Copyright (c) 2014-2019 winking324
//

#include "view/join_room_widget.h"

#include <QFont>
#include <QLabel>
#include <QGridLayout>
#include <QSpacerItem>

#include "view/video_setting_dialog.h"


namespace avc {


JoinRoomWidget::JoinRoomWidget(QWidget *parent)
  : QWidget(parent) {
  auto *layout = new QGridLayout(this);
  layout->setAlignment(Qt::AlignCenter);

  auto *about_label = new QLabel(tr("Enter a conference room name"), this);
  about_label->setStyleSheet("color:#009EEB;font:bold 24px;");

  auto *info_lable = new QLabel(tr("If you are the first person to specify ") +
                                tr("this name, the room will be created and ") +
                                tr("you will be placed in it. If it has ") +
                                tr("already been created you will join the ") +
                                tr("conference in progress."), this);
  info_lable->setWordWrap(true);
  info_lable->setStyleSheet("color:#9196A0;font:12px;");

  room_name_edit_ = new QLineEdit(this);
  room_name_edit_->setPlaceholderText("Room name");
  room_name_edit_->setFrame(false);
  room_name_edit_->setFixedHeight(40);
  room_name_edit_->setTextMargins(15, 0, 15, 0);

  back_button_ = new QPushButton("Back", this);
  back_button_->setFixedHeight(40);

  join_button_ = new QPushButton("Join", this);
  join_button_->setFixedHeight(40);

  video_setting_button_ = new QPushButton("720 x 1080, 15fps, 1mbps", this);
  video_setting_button_->setFixedHeight(40);

  int row = 0;
  layout->addWidget(about_label, row, 0, 1, 2, Qt::AlignCenter);
  layout->setRowMinimumHeight(row++, 40);

  layout->addWidget(info_lable, row, 0, 1, 2, Qt::AlignCenter);
  layout->setRowMinimumHeight(row++, 60);

  layout->addItem(new QSpacerItem(20, 20), row++, 0, 1, 2);

  layout->addWidget(room_name_edit_, row, 0, 1, 2);
  layout->setRowMinimumHeight(row++, 40);

  layout->addItem(new QSpacerItem(5, 5), row++, 0, 1, 2);

  layout->addWidget(back_button_, row, 0, 1, 1);
  layout->addWidget(join_button_, row, 1, 1, 1);
  layout->setRowMinimumHeight(row++, 40);

  layout->addItem(new QSpacerItem(40, 40), row++, 0);

  layout->addWidget(video_setting_button_, row, 0, 1, 2);
  layout->setRowMinimumHeight(row++, 40);

  layout->addItem(new QSpacerItem(40, 40), row++, 0);

  layout->addWidget(new QLabel(tr("agora.io"), this),
                    9, 0, 1, 2, Qt::AlignCenter);
  layout->addWidget(new QLabel(tr("v1.0"), this),
                    10, 0, 1, 2, Qt::AlignCenter);

  setLayout(layout);

  connect(back_button_, SIGNAL(released()), this, SLOT(OnBack()));
  connect(join_button_, SIGNAL(released()), this, SLOT(OnJoin()));
  connect(video_setting_button_, SIGNAL(released()), this,
          SLOT(OnVideoSetting()));
}

void JoinRoomWidget::OnBack() {
  emit BackEvent();
}

void JoinRoomWidget::OnJoin() {
  if (room_name_edit_->text().isEmpty()) {
    return;
  }

  emit JoinEvent(room_name_edit_->text());
}

void JoinRoomWidget::OnVideoSetting() {
  VideoSettingDialog setting_dialog(video_setting_, this);
  if (setting_dialog.exec() == QDialog::Accepted) {
    video_setting_ = setting_dialog.GetVideoSettings();
  }
}


}  // namespace avc

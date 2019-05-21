// Copyright (c) 2014-2019 winking324
//

#include "view/central_widget.h"


namespace avc {


enum class StackedWidgetIndex : int {
  kSplash = 0,
  kJoinRoom = 1,
  kInRoom = 2,
};


CentralWidget::CentralWidget(QWidget *parent)
  : QWidget(parent) {
  layout_ = new QStackedLayout(this);

  splash_widget_ = new SplashWidget(this);
  join_room_widget_ = new JoinRoomWidget(this);
  in_room_widget_ = new InRoomWidget(this);

  layout_->insertWidget(static_cast<int>(StackedWidgetIndex::kSplash),
                        splash_widget_);
  layout_->insertWidget(static_cast<int>(StackedWidgetIndex::kJoinRoom),
                        join_room_widget_);
  layout_->insertWidget(static_cast<int>(StackedWidgetIndex::kInRoom),
                        in_room_widget_);

  setLayout(layout_);

  connect(splash_widget_, SIGNAL(SplashEndEvent()), this, SLOT(OnSplashEnd()));
  connect(join_room_widget_, SIGNAL(BackEvent()), this, SLOT(OnBack()));
  connect(join_room_widget_, SIGNAL(JoinEvent(QString)), this,
          SLOT(OnJoin(QString)));
  connect(in_room_widget_, SIGNAL(EndCallEvent()), this, SLOT(OnEndCall()));
}

void CentralWidget::OnSplashEnd() {
  layout_->setCurrentIndex(static_cast<int>(StackedWidgetIndex::kJoinRoom));
}

void CentralWidget::OnBack() {
  layout_->setCurrentIndex(static_cast<int>(StackedWidgetIndex::kSplash));
}

void CentralWidget::OnJoin(QString room_name) {
  layout_->setCurrentIndex(static_cast<int>(StackedWidgetIndex::kInRoom));
}

void CentralWidget::OnEndCall() {
  layout_->setCurrentIndex(static_cast<int>(StackedWidgetIndex::kJoinRoom));
}


}  // namespace avc

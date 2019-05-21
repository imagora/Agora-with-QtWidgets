// Copyright (c) 2014-2019 winking324
//


#include "view/video_widget.h"


namespace avc {


VideoWidget::VideoWidget(QWidget *parent)
  : QWidget(parent) {
}

int VideoWidget::SetViewProperties(int zOrder, float left, float top, float right, float bottom)
{

}

int VideoWidget::DeliverFrame(const agora::media::IVideoFrame &videoFrame, int rotation, bool mirrored)
{

}

void VideoWidget::OnRenderFrame()
{

}

void VideoWidget::OnCleanup()
{

}

void VideoWidget::paintEvent(QPaintEvent *event)
{

}


}  // namespace avc

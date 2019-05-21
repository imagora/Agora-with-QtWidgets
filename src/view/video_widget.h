// Copyright (c) 2014-2019 winking324
//

#pragma once


#include <IAgoraMediaEngine.h>

#include <QWidget>

#include <mutex>
#include <memory>

#include "controller/opengl_renderer.h"


namespace avc {


class VideoWidget : public QWidget {
  Q_OBJECT

 public:
  VideoWidget(QWidget *parent = nullptr);

  int SetViewProperties(int zOrder, float left, float top, float right,
                        float bottom);

  int DeliverFrame(const agora::media::IVideoFrame& videoFrame, int rotation,
                   bool mirrored);

 signals:
  void FrameDeliveredEvent();

  void WidgetInvalidatedEvent();

  void ViewSizeChangedEvent(int width, int height);

 public slots:
  void OnRenderFrame();

  // void OnWindowChanged(QQuickWindow *win);

  void OnCleanup();

 protected:
  virtual void paintEvent(QPaintEvent *event) override;

 private:
  bool mirrored_;
  int rotation_;
  agora::media::IVideoFrame* frame_;
  std::unique_ptr<OpenGLRenderer> renderer_;
  std::mutex frame_mutex_;

};


}  // namespace avc

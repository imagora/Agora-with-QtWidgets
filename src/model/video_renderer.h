// Copyright (c) 2014-2019 winking324
//

#pragma once


#include <IAgoraMediaEngine.h>
#include <QObject>
#include <mutex>

#include "view/video_widget.h"


namespace avc {


class VideoRenderer :
    public QObject,
    public agora::media::IExternalVideoRender {
  Q_OBJECT

 public:
  VideoRenderer(const agora::media::ExternalVideoRenerContext& context);

  ~VideoRenderer();

 public slots:
  void OnWidgetInvalidated();

  void OnViewSizeChanged(int width, int height);

 public:
  virtual void release() override;

  virtual int initialize() override;

  virtual int deliverFrame(const agora::media::IVideoFrame& videoFrame,
                           int rotation, bool mirrored) override;

 private:
  VideoWidget *view_;
  agora::media::IExternalVideoRenderCallback* renderer_callback_;
  std::mutex mutex_;
};


}  // namespace avc


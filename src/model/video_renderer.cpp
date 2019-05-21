// Copyright (c) 2014-2019 winking324
//


#include "model/video_renderer.h"


namespace avc {


VideoRenderer::VideoRenderer(
    const agora::media::ExternalVideoRenerContext &context) {
}

VideoRenderer::~VideoRenderer() {

}

void VideoRenderer::OnWidgetInvalidated() {

}

void VideoRenderer::OnViewSizeChanged(int width, int height) {

}

void VideoRenderer::release() {
  delete this;
}

int VideoRenderer::initialize() {
  return 0;
}

int VideoRenderer::deliverFrame(const agora::media::IVideoFrame &videoFrame,
                                int rotation, bool mirrored) {

}


}  // namespace avc

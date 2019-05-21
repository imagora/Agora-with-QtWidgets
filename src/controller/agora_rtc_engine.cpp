// Copyright (c) 2014-2019 winking324
//


#include "controller/agora_rtc_engine.h"

#include <QMessageBox>

#include "commons/definitions.h"
#include "model/video_renderer.h"


namespace avc {


class AgoraRtcEngineEvent : public agora::rtc::IRtcEngineEventHandler {
 public:
  AgoraRtcEngineEvent(AgoraRtcEngine *rtc_engine) {
    rtc_engine_ = rtc_engine;
  }

 private:
  virtual void onVideoStopped() override {
    emit rtc_engine_->VideoStoppedEvent();
  }

  virtual void onJoinChannelSuccess(const char* channel, uid_t uid,
                                    int elapsed) override {
    emit rtc_engine_->JoinChannelSuccessEvent(channel, uid, elapsed);
  }

  virtual void onUserJoined(uid_t uid, int elapsed) override {
    emit rtc_engine_->UserJoinedEvent(uid, elapsed);
  }

  virtual void onUserOffline(
      uid_t uid, agora::rtc::USER_OFFLINE_REASON_TYPE reason) override {
    emit rtc_engine_->UserOfflineEvent(uid, reason);
  }

  virtual void onFirstLocalVideoFrame(int width, int height,
                                      int elapsed) override {
    emit rtc_engine_->FirstLocalVideoFrameEvent(width, height, elapsed);
  }

  virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height,
                                       int elapsed) override {
    emit rtc_engine_->FirstRemoteVideoFrameEvent(uid, width, height, elapsed);
  }

  virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height,
                                         int elapsed) override {
    emit rtc_engine_->FirstRemoteVideoDecodedEvent(uid, width, height, elapsed);
  }

 private:
  AgoraRtcEngine *rtc_engine_;
};


void AgoraRtcEngine::RtcEngineDeleter::operator()(
    agora::rtc::IRtcEngine *engine) const {
  if (engine != nullptr) {
    engine->release();
  }
}


AgoraRtcEngine::AgoraRtcEngine(QObject *parent)
  : QObject(parent) {
  rtc_engine_.reset(createAgoraRtcEngine());
  event_handler_.reset(new AgoraRtcEngineEvent(this));

  agora::rtc::RtcEngineContext context;
  context.eventHandler = event_handler_.get();
  if (strlen(kAppId) == 0) {
    QMessageBox::critical(nullptr, tr("Agora QT Demo"),
                          tr("You must specify APP ID before using the demo"));
  }
  context.appId = kAppId;
  rtc_engine_->initialize(context);
  agora::util::AutoPtr<agora::media::IMediaEngine> media_engine;
  media_engine.queryInterface(rtc_engine_.get(), agora::AGORA_IID_MEDIA_ENGINE);
  if (media_engine) {
    media_engine->registerVideoRenderFactory(this);
  }
  rtc_engine_->enableVideo();
}

agora::media::IExternalVideoRender *
AgoraRtcEngine::createRenderInstance(
    const agora::media::ExternalVideoRenerContext &context) {
  if (context.view == nullptr) {
    return nullptr;
  }

  return new VideoRenderer(context);
}

}  // namespace avc

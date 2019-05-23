// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <IAgoraRtcEngine.h>
#include <IAgoraMediaEngine.h>
#include <QObject>
#include <memory>


namespace avc {


class AgoraRtcEngine :
    public QObject,
    public agora::media::IExternalVideoRenderFactory {
  Q_OBJECT

 public:
  explicit AgoraRtcEngine(QObject *parent = nullptr);

  void JoinChannel(const QString &token, const QString &channel_name,
                  uint32_t uid);

  int LeaveChannel();

  int MuteLocalAudioStream(bool muted);

 public:
  virtual agora::media::IExternalVideoRender *
  createRenderInstance(const agora::media::ExternalVideoRenerContext &context)
  override;

 signals:
  void JoiningChannelEvent(int status);

  void LeavingChannelEvent();

  void VideoStoppedEvent();

  void JoinChannelSuccessEvent(const char *channel, uint32_t uid, int elapsed);

  void UserJoinedEvent(uint32_t uid, int elapsed);

  void UserOfflineEvent(uint32_t uid,
                        agora::rtc::USER_OFFLINE_REASON_TYPE reason);

  void FirstLocalVideoFrameEvent(int width, int height, int elapsed);

  void FirstRemoteVideoFrameEvent(uint32_t uid, int width, int height,
                                  int elapsed);

  void FirstRemoteVideoDecodedEvent(uint32_t uid, int width, int height,
                                    int elapsed);


 private:
  struct RtcEngineDeleter {
    void operator()(agora::rtc::IRtcEngine *engine) const;
  };

 private:
  std::unique_ptr<agora::rtc::IRtcEngine, RtcEngineDeleter> rtc_engine_;
  std::unique_ptr<agora::rtc::IRtcEngineEventHandler> event_handler_;
};


}  // namespace avc

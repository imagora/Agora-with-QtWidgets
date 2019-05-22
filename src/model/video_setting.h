// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <QString>


namespace avc {


struct VideoSetting {
  int width = 360;
  int height = 640;
  int framerate = 30;
  int bitrate = 800;

  QString ToString() {
    if (bitrate > 1024) {
      return QString("%1x%2, %3fps, %4mbps").arg(width).arg(height).
          arg(framerate).arg(bitrate/1024.0, 0, 'f', 1);
    }
    return QString("%1x%2, %3fps, %4kbps").arg(width).arg(height).
        arg(framerate).arg(bitrate);
  }
};


}  // namespace avc

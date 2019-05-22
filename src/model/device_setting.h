// Copyright (c) 2014-2019 winking324
//

#pragma once


namespace avc {


struct DeviceSetting {
  int input_volume = 100;
  int output_volume = 100;
  int input_device;
  int output_device;
  int webcam_device;
};


}  // namespace avc

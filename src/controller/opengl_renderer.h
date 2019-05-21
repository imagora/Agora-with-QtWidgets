// Copyright (c) 2014-2019 winking324
//

#pragma once

#include <IAgoraMediaEngine.h>

#include <QSize>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>


namespace avc {


class OpenGLRenderer {
 public:
  OpenGLRenderer(int width, int height);

 private:
  bool mirrored_;
  bool reset_gl_vertices_;

  int rotation_;
  int z_order_;
  int render_mode_;

  QSize texture_size_;
  QSize target_size_;

  float m_left;
  float m_top;
  float m_right;
  float m_bottom;

  QOpenGLShaderProgram *program_;
  GLfloat vertices_[20];
  GLuint texture_ids_[3];
};


}  // namespace avc

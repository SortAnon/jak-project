#pragma once

/*!
 * @file opengl.h
 * OpenGL includes.
 */

#define GLFW_INCLUDE_NONE
#include "third-party/glad/include/glad/glad.h"
#include "third-party/glfw/include/GLFW/glfw3.h"

#include "game/graphics/display.h"
#include "game/graphics/gfx.h"

enum GlfwKeyAction {
  Release = GLFW_RELEASE,  // falling edge of key press
  Press = GLFW_PRESS,      // rising edge of key press
  Repeat = GLFW_REPEAT     // repeated input on hold e.g. when typing something
};

class GLDisplay : public GfxDisplay {
  GLFWwindow* m_window;

 public:
  GLDisplay(GLFWwindow* window, bool is_main);
  virtual ~GLDisplay();

  void* get_window() const { return m_window; }
  void get_position(int* x, int* y);
  void get_size(int* w, int* h);
  void get_scale(float* x, float* y);
  void get_screen_size(int vmode_idx, s32* w, s32* h, s32* c);
  GfxDisplayMode get_fullscreen();
  void set_size(int w, int h);
  void update_fullscreen(GfxDisplayMode mode, int screen);
  void render();
};

extern const GfxRendererModule gRendererOpenGL;

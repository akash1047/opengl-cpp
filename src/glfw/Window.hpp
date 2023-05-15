#pragma once

#include <GLFW/glfw3.h>
namespace glfw {
class Window {
    GLFWwindow *window_handle;

    public:
    Window(GLFWwindow *safe_window) : window_handle(safe_window) {}

    ~Window() { glfwDestroyWindow(this->window_handle); }

    inline bool should_close() {
        return glfwWindowShouldClose(this->window_handle);
    }

    inline void set_should_close(int value) {
        glfwSetWindowShouldClose(this->window_handle, value);
    }

    inline void swap_buffers() { glfwSwapBuffers(this->window_handle); }

    inline void make_context_current() {
        glfwMakeContextCurrent(this->window_handle);
    }
};
} // namespace glfw

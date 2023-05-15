#pragma once

#include "Error.hpp"
#include "WindowBuilder.hpp"
#include <GLFW/glfw3.h>

namespace glfw {

class Glfw {
    public:
    Glfw() {
        if (!glfwInit()) {
            throw glfw::Error::get_error();
        }
    }

    ~Glfw() { glfwTerminate(); }

    inline void terminate() { glfwTerminate(); }

    inline void poll_events() { glfwPollEvents(); }

    inline WindowBuilder window_builder() {
        return WindowBuilder();
    }
};

} // namespace glfw

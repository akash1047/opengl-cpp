#pragma once

#include "Error.hpp"
#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>

namespace glfw {

enum class profile : int {
    opengl_core = GLFW_OPENGL_CORE_PROFILE,
    opengl_compat = GLFW_OPENGL_CORE_PROFILE
};

class WindowBuilder {
    public:
    WindowBuilder() = default;

    WindowBuilder &set_size(std::uint16_t width, std::uint16_t height) {
        this->win_width = width;
        this->win_height = height;

        return *this;
    }

    WindowBuilder &set_title(const std::string &title) {
        this->win_title = title;

        return *this;
    }

    // window hints
    inline WindowBuilder hint(glfw::profile opengl_profile) {
        glfwWindowHint(GLFW_OPENGL_PROFILE, (int)opengl_profile);

        return *this;
    }

    inline WindowBuilder context_version(int major, int minor) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);

        return *this;
    }

    glfw::Window build() {
        if (!this->win_width.has_value() || !this->win_height.has_value()) {
            throw std::runtime_error(
                "window size is not provided\n"
                " =help: call `WindowBuilder::set_size(unsigned int, unsigned "
                "int)`");
        }

        GLFWwindow *glfw_window = glfwCreateWindow(
            this->win_width.value(), this->win_height.value(),
            (this->win_title.has_value()) ? this->win_title.value().c_str()
                                          : nullptr,
            nullptr, nullptr);

        if (!glfw_window) {
            throw glfw::Error::get_error();
        }

        return glfw::Window{glfw_window};
    }

    private:
    std::optional<std::uint16_t> win_width{std::nullopt},
        win_height{std::nullopt};
    std::optional<std::string> win_title{std::nullopt};
};

} // namespace glfw

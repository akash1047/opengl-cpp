#define GLFW_INCLUDE_NONE
#include "glfw/Glfw.hpp"
#include "glfw/WindowBuilder.hpp"
#include <glad/gl.h>
#include <iostream>

int main() {
    std::int16_t width = 500;
    std::int16_t height = 200;
    std::string title = "opengl-cpp";

    glfw::Glfw glfw{};

    glfw::Window window = glfw.window_builder()
                              .set_size(width, height)
                              .set_title(title)
                              .context_version(3, 3)
                              .hint(glfw::profile::opengl_core)
                              .build();

    window.make_context_current();

    if (!gladLoaderLoadGL()) {
        std::cout << "falied to load gl binding" << std::endl;
        return -1;
    }

    glClearColor(0.1, 0.3, 0.3, 0.5);

    while (!window.should_close()) {
        glClear(GL_COLOR_BUFFER_BIT);

        window.swap_buffers();
        glfw.poll_events();
    }

    return 0;
}

#pragma once

#include <array>
#include <cstddef>
namespace opengl {

template <std::size_t Size>
class vertex_array {
public:
    vertex_array() {
        glGenVertexArrays(Size, objects.data());
    }

    ~vertex_array() {
        glDeleteVertexArrays(Size, objects.data());
    }

    inline unsigned int operator[](std::size_t index) {
        return objects[index];
    }

    inline void bind(std::size_t index) {
        glBindVertexArray(objects[index]);
    }

private:
    std::array<unsigned int, Size> objects;
};

} // namespace opengl

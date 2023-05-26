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

    unsigned int operator[](std::size_t index) {
        return objects[index];
    }

private:
    std::array<unsigned int, Size> objects;
};

} // namespace opengl

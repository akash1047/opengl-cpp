#pragma once

#include "shader.hpp"

namespace opengl {
namespace shader {

class vertex: public shader {
public:
    constexpr static unsigned int kind = GL_VERTEX_SHADER;

    vertex() : shader(GL_VERTEX_SHADER) {}
};

} // namespace shader
} // namespace opengl

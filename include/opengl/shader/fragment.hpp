#pragma once

#include "shader.hpp"

namespace opengl {
namespace shader {

class fragment: public shader {
public:
    constexpr static unsigned int kind = GL_FRAGMENT_SHADER;

    fragment() : shader(GL_FRAGMENT_SHADER) {}
};

} // namespace shader
} // namespace opengl

#pragma once

#include "opengl/shader/object.hpp"
#include "opengl/shader/shader.hpp"
#include <glad/gl.h>

namespace opengl {
namespace shader {

class program: public object {
public:
    program() : object(glCreateProgram(), glDeleteShader) {}

    // attach shader
    //
    // destroying the shader object after being used
    void attach(shader &&obj) {
        glAttachShader(this->get_id(), obj.get_id());
    }

    // attach shader
    void attach(shader &obj) {
        glAttachShader(this->get_id(), obj.get_id());
    }

    // link shader program
    inline void link() {
        return glLinkProgram(this->get_id());
    }

    // use shader program
    inline void use() {
        return glUseProgram(this->get_id());
    }
};

} // namespace shader
} // namespace opengl

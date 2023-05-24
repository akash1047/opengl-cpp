#pragma once

#include "object.hpp"
#include <filesystem>
#include <glad/gl.h>

namespace opengl {
namespace shader {

class shader: public object {
public:
    class null_source {};
    class syntax_error {};

    shader(int shader_kind)
        : object(glCreateShader(shader_kind), glDeleteShader) {}

    virtual ~shader() {}

    /* query */

    inline int iv(int query) {
        int result;
        glGetShaderiv(this->get_id(), query, &result);
        return result;
    }

    inline int is_compiled() {
        return this->iv(GL_COMPILE_STATUS);
    }

    inline int log_length() {
        return this->iv(GL_INFO_LOG_LENGTH);
    }

    /* query end */

    void add_file_source(std::filesystem::path file_path);

    inline void add_source(const char *source) {
        if (source == nullptr) throw null_source{};
        glShaderSource(this->get_id(), 1, &source, nullptr);
    }

    inline void compile() {
        glCompileShader(this->get_id());
        if (!this->is_compiled()) throw syntax_error{};
    }
};

} // namespace shader
} // namespace opengl

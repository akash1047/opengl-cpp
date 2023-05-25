#pragma once

#include "object.hpp"
#include <exception>
#include <filesystem>
#include <glad/gl.h>
#include <string>

namespace opengl {
namespace shader {

class shader: public object {

public:
    class null_source: public std::exception {
    public:
        const char *what() const noexcept override {
            return "null pointer is passed as shader source";
        }
    };

    class syntax_error: public std::exception {
    public:
        syntax_error(std::string err_msg) : msg(std::move(err_msg)) {}

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };

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

    inline std::string info_log() {
        int len = this->log_length() - 1;
        std::string log(len, '\0');
        glGetShaderInfoLog(this->get_id(), len, nullptr, log.data());
        return log;
    }

    void add_file_source(std::filesystem::path file_path);

    inline void add_source(const char *source) {
        if (source == nullptr) throw null_source{};
        glShaderSource(this->get_id(), 1, &source, nullptr);
    }

    inline void compile() {
        glCompileShader(this->get_id());
        if (!this->is_compiled()) throw syntax_error{this->info_log()};
    }
};

} // namespace shader
} // namespace opengl

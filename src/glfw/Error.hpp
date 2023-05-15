#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <tuple>

namespace glfw {

class Error {
    int code{0};
    std::string msg{};

    public:
    Error(int e_code, const std::string &e_msg) : code(e_code), msg(e_msg) {}

    // retrives last error catchecd by glfw
    // and clear's from glfw error stack
    static Error get_error() {
        int code;
        const char *msg;
        code = glfwGetError(&msg);
        return Error(code, msg);
    }

    inline int get_code() const { return this->code; }

    inline std::string get_message() const { return this->msg; }
};

} // namespace glfw

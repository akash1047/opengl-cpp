#include "../include/opengl/shader/shader.hpp"
#include <fstream>

std::string
opengl::shader::shader::add_file_source(std::filesystem::path file_path) {
    int length;
    std::ifstream file(file_path, std::ios::in);

    if (not file)
        throw std::ios_base::failure(std::string("failed to open file: ") +
                                     file_path.string());

    file.seekg(0, std::ios::end);
    length = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string buffer(length, '\0');
    file.read(&buffer[0], length);

    return buffer;
}

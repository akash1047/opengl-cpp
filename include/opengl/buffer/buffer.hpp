#pragma once

#include <array>
#include <cstddef>
#include <glad/gl.h>

namespace opengl {

namespace buffer {

template <std::size_t Size, int Kind>
class buffer {
public:
    constexpr static int kind = Kind;

    buffer() {
        glGenBuffers(Size, object.data());
    }

    virtual ~buffer() {
        glDeleteBuffers(Size, object.data());
    }

    inline void bind(std::size_t index = 0) {
        glBindBuffer(Kind, object[index]);
    }

private:
    std::array<unsigned int, Size> object;
};

#define IMPL_GL_BUFFER(name, code)                                             \
    template <int size = 1>                                                    \
    using name = buffer<size, GL_##code##_BUFFER>;

IMPL_GL_BUFFER(array, ARRAY)
IMPL_GL_BUFFER(atomic_counter, ATOMIC_COUNTER)
IMPL_GL_BUFFER(copy_read, COPY_READ)
IMPL_GL_BUFFER(copy_write, COPY_WRITE)
IMPL_GL_BUFFER(dispatch_indirect, DISPATCH_INDIRECT)
IMPL_GL_BUFFER(draw_indirect, DRAW_INDIRECT)
IMPL_GL_BUFFER(element_array, ELEMENT_ARRAY)
IMPL_GL_BUFFER(pixel_unpack, PIXEL_UNPACK)
IMPL_GL_BUFFER(query, QUERY)
IMPL_GL_BUFFER(shader_storage, SHADER_STORAGE)
IMPL_GL_BUFFER(texture, TEXTURE)
IMPL_GL_BUFFER(transform_feedback, TRANSFORM_FEEDBACK)
IMPL_GL_BUFFER(uniform, UNIFORM)

#undef IMPL_GL_BUFFER

} // namespace buffer

} // namespace opengl

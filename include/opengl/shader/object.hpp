#pragma once

namespace opengl {
namespace shader {

// shader object
class object {
public:
    object(unsigned int obj_id = 0, void (*destroy_fn)(unsigned int) = nullptr)
        : id(obj_id), destroy(destroy_fn) {}

    object(object &&rhs) {
        if (this == &rhs) return;

        if (this->id != 0 && this->destroy != nullptr) this->destroy(this->id);

        this->id = rhs.id;
        this->destroy = rhs.destroy;

        rhs.id = 0;
        rhs.destroy = nullptr;
    }

    object(const object &) = delete;

    virtual ~object() {
        if (this->destroy != nullptr && this->id != 0) this->destroy(this->id);
    }

    object &operator=(object &&rhs) {
        if (this == &rhs) return *this;

        if (this->id != 0 && this->destroy != nullptr) this->destroy(this->id);

        this->id = rhs.id;
        this->destroy = rhs.destroy;

        rhs.id = 0;
        rhs.destroy = nullptr;

        return *this;
    }

    object &operator=(const object &) = delete;

    // object id
    inline unsigned int get_id() {
        return this->id;
    }

private:
    unsigned int id;
    void (*destroy)(unsigned int);
};

} // namespace shader
} // namespace opengl

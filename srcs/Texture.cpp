#include "Texture.hpp"

Texture::Texture() { }

Texture::Texture(const std::string & path) {
    using dispatcher_t = signals::literal::from<Inputs>;

    if (!loadFromFile(path)) {
        std::cout << "Error loading texture" << std::endl;
        dispatcher_t::emit<Inputs::close>();
    }
}

Texture::~Texture() { }

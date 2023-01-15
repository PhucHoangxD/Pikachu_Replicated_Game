#include "TexturesHolder.h"

TexturesHolder& TexturesHolder::GetInstance() {
    static TexturesHolder instance;
    return instance;
}

TexturesHolder::~TexturesHolder() {
    for (auto& texture : textures) {
        UnloadTexture(texture.second);
    }
}

TexturesHolder::TexturesHolder() {
    for (int i = 0; i < 33; ++i) {
        std::string path = "assets/images/pokemon/" + std::to_string(i + 1) + ".png";
        Texture2D img = LoadTexture(path.c_str());
        textures.insert(std::make_pair(i, img));
    }
}

Texture2D& TexturesHolder::get(int ID) {
    auto img = textures.find(ID);
    if (img == textures.end()) {
        throw std::runtime_error("Texture not found");
    }
    return img->second;
}

const Texture2D& TexturesHolder::get(int ID) const {
    auto img = textures.find(ID);
    if (img == textures.end()) {
        throw std::runtime_error("Texture not found");
    }
    return img->second;
}
//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_IMAGE_HPP
#define MYPNG_IMAGE_HPP

#include <stdint-gcc.h>

namespace myPNG {

    enum class ColorTypes{
        INDEXED,
        TRUE_COLOR,
        GRAYSCALE
    };

    class Image {
    public:
        int width;
        int height;
        bool transparency = false;
        bool greyscale = false;
        unsigned int bit_depth;
        ColorTypes type;
        uint8_t *data = {};
        uint8_t *mask = {};

    };

}

#endif //MYPNG_IMAGE_HPP

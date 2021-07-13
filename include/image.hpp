//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_IMAGE_HPP
#define MYPNG_IMAGE_HPP

#include <stdint-gcc.h>

namespace myPNG {

    enum class ColorTypes{
        GRAYSCALE = 0,
        TRUE_COLOR = 2,
        INDEXED = 3,
        GREYSCALE_ALPHA = 4,
        TRUE_COLOR_ALPHA = 6
    };

    enum class CompressionMethod{
        STANDARD = 0
    };

    enum class FilterMethod{
        STANDARD = 0
    };

    enum class InterlaceMethod{
        STANDARD = 0,
        ADAM7 = 1
    };

    struct ImageData {
        int width = 0;
        int height = 0;
        unsigned int bit_depth = 0;
        ColorTypes type;
        CompressionMethod c_method;
        FilterMethod f_method;
        InterlaceMethod i_method;

    };

    class Image {
    public:

        uint8_t *data = {};
        uint8_t *mask = {};

    };

}

#endif //MYPNG_IMAGE_HPP

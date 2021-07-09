//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_FILTER_HPP
#define MYPNG_FILTER_HPP

#include <cstdint>

namespace myPNG{
    enum class FilterType{
        NONE = 0,
        SUB = 1,
        UP,
        AVERAGE,
        PAETH
    };

    FilterType getFilterType(uint8_t * image_data);
}

#endif //MYPNG_FILTER_HPP
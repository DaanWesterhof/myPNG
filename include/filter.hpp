//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_FILTER_HPP
#define MYPNG_FILTER_HPP

#include <cstdint>
#include "image.hpp"

namespace myPNG{
    enum class FilterType{
        NONE = 0,
        SUB = 1,
        UP,
        AVERAGE,
        PAETH
    };

    FilterType getFilterType(uint8_t * image_data);

    Image undoFilter(uint8_t * image_data, FilterType type);
    Image undoSubFilter(uint8_t * image_data);
    Image undoUpFilter(uint8_t * image_data);
    Image undoAverageFilter(uint8_t * image_data);
    Image undoPaethFilter(uint8_t * image_data);

}

#endif //MYPNG_FILTER_HPP
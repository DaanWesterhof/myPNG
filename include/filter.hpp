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

    void undoFilter(ImageData data,uint8_t * image_data);
    void undoSubFilter(uint8_t *idat_data, size_t size);
    void undoUpFilter(uint8_t *idat_data, uint8_t *idat_data_last, size_t size);
    void undoAverageFilter(uint8_t *idat_data, uint8_t *idat_data_last, size_t size);
    void undoPaethFilter(uint8_t *idat_data, const uint8_t *idat_data_last, size_t size);

}

#endif //MYPNG_FILTER_HPP
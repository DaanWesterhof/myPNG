//
// Created by FlyingPig on 7/9/2021.
//

#include "../include/filter.hpp"

myPNG::FilterType myPNG::getFilterType(uint8_t * image_data){

}

myPNG::Image myPNG::undoFilter(uint8_t *image_data, myPNG::FilterType type) {
    switch(type){
        case FilterType::NONE :
            break;
        case FilterType::SUB:
            return undoSubFilter(image_data);
        case FilterType::UP:
            return undoUpFilter(image_data);
        case FilterType::AVERAGE:
            return undoAverageFilter(image_data);
        case FilterType::PAETH:
            return undoPaethFilter(image_data);
    }
    return myPNG::Image();
}

myPNG::Image myPNG::undoSubFilter(uint8_t *image_data) {
    return myPNG::Image();
}

myPNG::Image myPNG::undoUpFilter(uint8_t *image_data) {
    return myPNG::Image();
}

myPNG::Image myPNG::undoAverageFilter(uint8_t *image_data) {
    return myPNG::Image();
}

myPNG::Image myPNG::undoPaethFilter(uint8_t *image_data) {
    return myPNG::Image();
}

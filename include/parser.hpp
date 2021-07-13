//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_PARSER_HPP
#define MYPNG_PARSER_HPP

#include <stdint-gcc.h>
#include "image.hpp"

namespace myPNG{


    bool fileSignatureIsValid(const uint8_t * image_data);

    ImageData getImageData(uint8_t * image_data);





    Image parseImageData(uint8_t * image_data, ImageData data);







}

#endif //MYPNG_PARSER_HPP

//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_PARSER_HPP
#define MYPNG_PARSER_HPP

#include <stdint-gcc.h>
#include "image.hpp"

namespace myPNG{

    bool fileSignatureIsValid(uint8_t * image_data);

    Image parseImageData(uint8_t * image_data, unsigned int bit_depth, bool alpha, ColorTypes type,  )





}

#endif //MYPNG_PARSER_HPP

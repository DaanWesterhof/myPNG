//
// Created by FlyingPig on 7/9/2021.
//

#ifndef MYPNG_PARSER_HPP
#define MYPNG_PARSER_HPP

#include <stdint-gcc.h>
#include "image.hpp"

namespace myPNG{


    bool fileSignatureIsValid(const uint8_t * image_data);

    uint8_t *fetchChunkPointer(int chunk_number, uint8_t *image_data);

    uint8_t *fetchNextChunk(uint8_t *image_data);




    Image parseImageData(uint8_t * image_data, unsigned int bit_depth, bool alpha, ColorTypes type,  );







}

#endif //MYPNG_PARSER_HPP

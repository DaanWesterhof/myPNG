//
// Created by FlyingPig on 7/13/2021.
//

#ifndef MYPNG_CHUNKS_HPP
#define MYPNG_CHUNKS_HPP


#include <stdint-gcc.h>

namespace myPNG{

    unsigned int getChunkSize(const uint8_t *image_data);

    uint8_t *getChunkByName(uint8_t name[4], uint8_t * image_data);

    uint8_t *fetchChunkPointer(int chunk_number, uint8_t *image_data);

    uint8_t *fetchNextChunk(uint8_t *image_data);


}

#endif //MYPNG_CHUNKS_HPP

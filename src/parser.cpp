//
// Created by FlyingPig on 7/9/2021.
//

#include "../include/parser.hpp"

bool myPNG::fileSignatureIsValid(const uint8_t *image_data) {
    uint8_t signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    for(int i = 0; i < 7; i++){
        if(image_data[i] != signature[i]){
            return false;
        }

    }
    return true;
}

unsigned int getChunkSize(const uint8_t *image_data){
    unsigned int index = 8;
    unsigned int chunk_size = 0u;
    for(int i = 0; i < 3; i++){
        chunk_size |= (unsigned int)(image_data[index + i] << (uint8_t)((3-i)*8));
    }
}

uint8_t *myPNG::fetchChunkPointer(int chunk_number, uint8_t *image_data) {
    unsigned int index = 8;
    int current_chunk = 0;
    unsigned int chunk_size = 0u;
    while(current_chunk != chunk_number){
        for(int i = 0; i < 3; i++){
            chunk_size |= (unsigned int)(image_data[index + i] << (uint8_t)((3-i)*8));
        }
        //add chunk size locations, chunk type and crc
        index += 12;
        index += chunk_size;
        current_chunk++;
    }
    return image_data + index;
}

uint8_t *myPNG::fetchNextChunk(uint8_t *image_data) {
    unsigned int index = 20;
    unsigned int chunk_size = getChunkSize(image_data);
    //add chunk size locations, chunk type and crc
    index += chunk_size;
    return image_data + index;
};

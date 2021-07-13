//
// Created by FlyingPig on 7/13/2021.
//

#include "../include/chunks.hpp"


unsigned int myPNG::getChunkSize(const uint8_t *image_data){
    unsigned int index = 8;
    unsigned int chunk_size = 0u;
    for(int i = 0; i < 3; i++){
        chunk_size |= (unsigned int)(image_data[index + i] << (uint8_t)((3-i)*8));
    }
    return chunk_size;
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
}

bool compareChunkType(const uint8_t left[4], const uint8_t right[4]){
    for(int i = 0; i < 3; i++){
        if(left[i] != right[i]){
            return false;
        }
    }
    return true;
}


uint8_t *myPNG::getChunkByName(uint8_t *name, uint8_t *image_data) {
    uint8_t * chunk = image_data + 8;
    volatile bool not_last = true;
    uint8_t current[4] = {0,0,0,0};
    uint8_t last[4] = {73,69,78,68};
    while(not_last){
        for(int i = 0; i < 3; i++){
            current[i] = chunk[i + 4];
        }
        if(compareChunkType(current, name)){
            return chunk;
        }

        chunk = fetchNextChunk(chunk);

        if(compareChunkType(current, last)){
            not_last = false;
        }
    }
    return nullptr;
};


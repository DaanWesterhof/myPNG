//
// Created by FlyingPig on 7/9/2021.
//

#include "../include/parser.hpp"
#include "../include/chunks.hpp"

bool myPNG::fileSignatureIsValid(const uint8_t *image_data) {
    uint8_t signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    for(int i = 0; i < 7; i++){
        if(image_data[i] != signature[i]){
            return false;
        }

    }
    return true;
}

myPNG::ImageData myPNG::getImageData(uint8_t *image_data) {
    uint8_t chunkname[4] = {'I', 'H', 'D', 'R'};
    uint8_t * IHDR = myPNG::getChunkByName(chunkname, image_data);
    ImageData data;
    data.width = (IHDR[8] <<3u) + (IHDR[9] << 2u) + (IHDR[10] <<1u)  + IHDR[11];
    data.height = (IHDR[12] <<3u) + (IHDR[13] << 2u) + (IHDR[14] <<1u)  + IHDR[15];
    data.bit_depth = IHDR[16];
    data.type = myPNG::ColorTypes(IHDR[17]);
    data.c_method = myPNG::CompressionMethod(IHDR[18]);
    data.f_method = myPNG::FilterMethod(IHDR[19]);
    data.i_method = myPNG::InterlaceMethod(IHDR[20]);
    return data;
}


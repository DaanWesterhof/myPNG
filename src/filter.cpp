//
// Created by FlyingPig on 7/9/2021.
//

#include <cmath>
#include "../include/filter.hpp"

#include "../include/chunks.hpp"

myPNG::FilterType myPNG::getFilterType(uint8_t * image_data){

}

unsigned int getLineLength(myPNG::ImageData data){
    unsigned int length = 0;
    unsigned int temp = 0;
    switch(data.type){
        case myPNG::ColorTypes::GRAYSCALE:
            temp = (data.bit_depth)*data.width;
            if(temp%8 > 0){
                length = (temp)/8 +1;
            }else{
                length = (temp)/8;
            }
            break;
        case myPNG::ColorTypes::TRUE_COLOR:
            length = ((data.bit_depth * 3)/8) * data.width;
            break;
        case myPNG::ColorTypes::INDEXED:
            temp = (data.bit_depth)*data.width;
            if(temp%8 > 0){
                length = (temp)/8 +1;
            }else{
                length = (temp)/8;
            }
            break;
        case myPNG::ColorTypes::GREYSCALE_ALPHA:
            length = ((data.bit_depth * 4)/8) * data.width;
            break;
        case myPNG::ColorTypes::TRUE_COLOR_ALPHA:
            length = ((data.bit_depth * 4)/8) * data.width;
            break;
    }
    return length;
}

void myPNG::undoFilter(ImageData data, uint8_t *image_data) {
    uint8_t * idat_ptr = image_data;
    uint8_t * last_ptr = idat_ptr;
    int scanline_length = getLineLength(data);
    for(int i = 0; i < data.height; i++){
        switch(myPNG::FilterType(idat_ptr[0])){

            case FilterType::NONE:
                break;
            case FilterType::SUB:
                undoSubFilter(idat_ptr+1, scanline_length);
            case FilterType::UP:
                break;
            case FilterType::AVERAGE:
                break;
            case FilterType::PAETH:
                break;
        }
        last_ptr = idat_ptr;
        idat_ptr += scanline_length +1;
    }
}

void myPNG::undoSubFilter(uint8_t *idat_data, size_t size) {
    for(size_t i = 1; i < size; i++){
        idat_data[i] = idat_data[i] + idat_data[i-1];
    }
}

void myPNG::undoUpFilter(uint8_t *idat_data, uint8_t *idat_data_last, size_t size) {
    for(size_t i = 0; i < size; i++) {
        idat_data[i] = idat_data[i] + idat_data_last[i];
    }
}

void myPNG::undoAverageFilter(uint8_t *idat_data, uint8_t *idat_data_last, size_t size) {
    for(size_t i = 0; i < size; i++) {
        if(i == 0){
            idat_data[i] = idat_data[i] + (uint8_t)((idat_data_last[i] + 0)/2);
        }
        idat_data[i] = idat_data[i] + (uint8_t)((idat_data_last[i] + idat_data[i-1])/2);
    }
}

uint8_t paethPredictor(uint8_t a, uint8_t b, uint8_t c){
    int p = a + b - c;
    uint8_t pa = abs(p - a);
    uint8_t pb = abs(p - b);
    uint8_t pc = abs(p - c);
    uint8_t Pr = 0;
    if(pa <= pb and pa <= pc) {
        Pr = a;
    }
    else if (pb <= pc){
        Pr = b;
    }
    else {
        Pr = c;
    }
    return Pr;
}

void myPNG::undoPaethFilter(uint8_t *idat_data, const uint8_t *idat_data_last, size_t size) {
    for(size_t i = 0; i < size; i++) {
        idat_data[i] = idat_data[i] + paethPredictor(idat_data[i-1], idat_data_last[i], idat_data_last[i-1]);
    }
}

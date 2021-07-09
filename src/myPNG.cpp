//
// Created by FlyingPig on 7/9/2021.
//

#include "../include/myPNG.hpp"
#include "../include/parser.hpp"
#include "../include/compression.hpp"
#include "../include/filter.hpp"



myPNG::Image myPNG::decode(uint8_t * image){
    myPNG::Image Image;
    FilterType type = getFilterType(image);


}

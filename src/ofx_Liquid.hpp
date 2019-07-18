//
//  ofx_Liquid.hpp
//  ballon
//
//  Created by Ricardo Matias on 14.07.19.
//

#pragma once

#include "ofMain.h"

class Liquid {
public:
    Liquid(float _x, float _y, float _w, float _h, float _c) : x(_x), y(_y), w(_w), h(_h), c(_c) {};
    
    void display();
    
    float x, y, w, h;
    float c; // coefficient of drag
};

//
//  ofx_Liquid.cpp
//  ballon
//
//  Created by Ricardo Matias on 14.07.19.
//

#include "ofx_Liquid.hpp"

void Liquid::display()
{
    ofFill();
    ofSetColor(32);
    ofSetLineWidth(0.f);
    ofDrawRectangle(x, y, w, h);
}

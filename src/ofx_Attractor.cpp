//
//  ofx_Attractor.cpp
//  gravitation
//
//  Created by Ricardo Matias on 14.07.19.
//

#include "ofx_Attractor.hpp"

void Attractor::display()
{
    ofFill();
    ofSetColor(ofColor::salmon);
    ofDrawEllipse(pos.x, pos.y, mass*2, mass*2);
}

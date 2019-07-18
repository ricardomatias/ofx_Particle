//
//  ofx_Attractor.hpp
//  gravitation
//
//  Created by Ricardo Matias on 14.07.19.
//

#pragma once

#include "ofMain.h"
#include "ofx_Particle.hpp"

class Attractor : public Particle {
public:
    Attractor(glm::vec3 _pos, float _mass) : pos(_pos), mass(_mass) {};
    
    glm::vec3 pos;
    float mass;
    
    void display();
};

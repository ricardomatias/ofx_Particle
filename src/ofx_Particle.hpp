//
//  Particle.hpp
//  bouncing-ball
//
//  Created by Ricardo Matias on 02.07.19.
//
#pragma once

#include <ofMain.h>

class Particle
{
    ofPoint pos;
    ofPoint vel;
    
    float maxSpeed;
    float mass;
    
    vector<ofPoint> forces;
public:
    Particle()
        : pos(ofPoint{0.f}), vel(ofPoint{0.f}), acc(ofPoint{0.f}), maxSpeed(10.f), mass(1.f)
    {};
    
    ~Particle() {
        cout << "[Particle] destroyed" << endl;
    };
    
    void update();
    void checkBoxBoundaries(float offset);
    void checkRectBoundaries(float minX, float minY, float maxX, float maxY);
    
    ofPoint getPosition() const { return pos; };
    ofPoint getVelocity() const { return vel; };
    
    float getMass() const { return mass; };
    
    void applyForce(ofPoint force);
    
    void setPosition(ofPoint _pos) { pos = _pos; };
    void setPosition(float x, float y, float z = 0) { pos = ofPoint(x, y, z); };
    
    void setVelocity(ofPoint _vel) { vel = _vel; };
    
    void setMaxSpeed(float speed) { maxSpeed = speed; };
    void setMass(float _mass) { mass = _mass; };
    
    ofPoint acc;
};

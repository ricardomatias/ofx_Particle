//
//  Particle.hpp
//  bouncing-ball
//
//  Created by Ricardo Matias on 02.07.19.
//
#pragma once

#include <ofMain.h>
#include <ofx_Liquid.hpp>

class Particle
{
    glm::vec3 pos;
    glm::vec3 vel;
    
    float maxSpeed;
    float mass;
    
    vector<glm::vec3> forces;
public:
    Particle()
    : pos(glm::vec3{0.f}), vel(glm::vec3{0.f}), acc(glm::vec3{0.f}), maxSpeed(10.f), mass(1.f)
    {};
    
    ~Particle() {
        cout << "[Particle] destroyed" << endl;
    };
    
    void update();
    void checkBoxBoundaries(float offset);
    void checkRectBoundaries(float minX, float minY, float maxX, float maxY);
    
    glm::vec3 getPosition() const { return pos; };
    glm::vec3 getVelocity() const { return vel; };
    
    float getMass() const { return mass; };
    
    void setPosition(glm::vec3 _pos) { pos = _pos; };
    void setPosition(float x, float y, float z = 0) { pos = glm::vec3(x, y, z); };
    
    void setVelocity(glm::vec3 _vel) { vel = _vel; };
    
    void setMaxSpeed(float speed) { maxSpeed = speed; };
    void setMass(float _mass) { mass = _mass; };
    
    inline float getHeading() { return glm::atan(vel.y, vel.x); };
    
    void applyForce(glm::vec3 force);
    
    void drag(shared_ptr<Liquid> &liquid);
    void gravitate(shared_ptr<Particle> &attractor);
    
    bool isInside(shared_ptr<Liquid> &liquid);
    
    glm::vec3 acc;
};

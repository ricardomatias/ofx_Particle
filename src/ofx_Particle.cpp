//
//  Particle.cpp
//  particles
//
//  Created by Ricardo Matias on 21.05.19.
//
#include "ofx_Particle.hpp"


void Particle::update()
{
    for (auto force = forces.begin(); force != forces.end(); force++)
    {
        acc += *force;
    }
    
    vel += acc;
    
    vel.limit(maxSpeed);
    
    pos += vel;
    
    acc *= 0.f;
    
    forces.clear();
}

void Particle::checkBoxBoundaries(float offset)
{
    // LEFT
    // RIGHT
    if (pos.x < -offset || pos.x > offset)
    {
        acc.x *= -1;
        vel.x *= -1;
    }
    
    // UP
    // BOTTOM
    if (pos.y < -offset || pos.y > offset)
    {
        acc.y *= -1;
        vel.y *= -1;
    }
    
    // FRONT
    // BACK
    if (pos.z < -offset || pos.z > offset)
    {
        acc.z *= -1;
        vel.z *= -1;
    }
}

void Particle::checkRectBoundaries(float minX, float minY, float maxX, float maxY)
{
    // LEFT
    // RIGHT
    if (pos.x < minX)
    {
        vel.x *= -1.f;
        pos.x = minX;
    } else
    if (pos.x > maxX - minX)
    {
        pos.x = maxX - minX;
        vel.x *= -1.f;
    }
    
    // UP
    // BOTTOM
    if (pos.y < minY)
    {
        vel.y *= -1.f;
        pos.y = minY;
    } else
    if (pos.y > maxY - minY)
    {
        vel.y *= -1.f;
        pos.y = maxY - minY;
    }
}

void Particle::applyForce(ofPoint force)
{
    force /= mass;
    
    forces.emplace_back(force);
}

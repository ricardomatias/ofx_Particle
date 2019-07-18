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
    
    // LIMIT VELOCITY
    if (glm::length(vel) > maxSpeed) {
        vel = glm::normalize(vel) * maxSpeed;
    }
    
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
        vel.x *= -.5f;
        pos.x = minX;
    } else
    if (pos.x > maxX - minX)
    {
        pos.x = maxX - minX;
        vel.x *= -.5f;
    }
    
    // UP
    // BOTTOM
    if (pos.y < minY)
    {
        vel.y *= -.5f;
        pos.y = minY;
    } else
    if (pos.y > maxY - minY)
    {
        vel.y *= -.5f;
        pos.y = maxY - minY;
    }
}

void Particle::applyForce(glm::vec3 force)
{
    force /= mass;
    
    forces.emplace_back(move(force));
}

void Particle::drag(shared_ptr<Liquid> &liquid)
{
    glm::vec3 drag;
    
    float speed = glm::length(vel);
    
    if (speed == 0.f) return; // or normalize returns NaN
    
    float dragMagnitude = liquid->c * speed * speed;
    
    drag = vel;
    
    drag *= -1; // invert direction
    
    drag = glm::normalize(drag);
    
    drag *= dragMagnitude;
    
    applyForce(move(drag));
}

void Particle::gravitate(shared_ptr<Particle> &attractor)
{
    if (attractor.get() == this) return;
    
    glm::vec3 attraction;
    
    float G = 1.f;
    
    glm::vec3 target = attractor->pos - pos;
    
    float dist = glm::length(target);
    
    dist = ofClamp(dist, 5.f, 100.f);
    
    target = glm::normalize(target);
    
    float attractionMag = (G * mass * attractor->mass) / (dist * dist);
    
    attraction = attractionMag * target;
    
    applyForce(move(attraction));
}

bool Particle::isInside(shared_ptr<Liquid> &liquid)
{
    if (pos.x > liquid->x && pos.x < liquid->x + liquid->w &&
        pos.y > liquid->y && pos.y < liquid->y + liquid->h)
    {
        return true;
    }
    
    return false;
}

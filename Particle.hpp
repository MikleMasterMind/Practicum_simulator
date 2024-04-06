#ifndef _Particle_H_
#define _Particle_H_

#include "Math_vector.hpp"
#include "Circle.hpp"

namespace Box_with_balls {

    class Particle {

        Math_vector coordinates;
        Math_vector velocity;
        double radius;
        double inv_mass; // better store in this way

    public:

        Particle(double r = 0, double x = 0, double y = 0, double vx = 0, double vy = 0, double mass = 1);

        Particle(double r = 0, Math_vector c = Math_vector(0, 0), Math_vector v = Math_vector(0, 0) , double mass = 1);

        virtual void move(double dt);

        virtual void bound_collision(int up, int down, int left, int rigth);

        virtual bool collision(const Particle* other) const; // find collision with other

        virtual void resolve_collision(Particle* other); // chenge its velocity and other's 

        virtual Circle get_image() const; // for drawing

    };
}

#endif // ! _Particle_H_
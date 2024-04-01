#ifndef _Particle_H_
#define _Particle_H_

#include "Math_vector.hpp"
//#include "AABB.hpp"
//#include "Shape.hpp"
#include "Circle.hpp"

namespace MyNamespace {

    class Particle {

        Math_vector coordinates;
        Math_vector velocity;
        double radius;
        double inv_mass;

    public:

        Particle(double r = 0, double x = 0, double y = 0, double vx = 0, double vy = 0);

        Particle(double r = 0, Math_vector c = Math_vector(0, 0), Math_vector v = Math_vector(0, 0));

        virtual bool collision(const Particle& other) const;

        virtual void resolve_collision(Particle& other);

        virtual Circle get_image() const; // for drawing

    };
}

#endif // ! _Particle_H_
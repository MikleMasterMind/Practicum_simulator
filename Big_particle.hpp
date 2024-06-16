#ifndef _BIG_PARTICLE_H_
#define _BIG_PARTICLE_H_

#include "Particle.hpp"

namespace Box_with_balls {

    class Big_particle : public Particle {
        double radius;
        double inv_mass;
    public:
        Big_particle(double x, double y, double vx, double vy, double r, double m);

        virtual double get_radius() const;

        virtual double get_inv_mass() const; // return 1 / mass

        virtual void bound_collision(int up, int down, int left, int rigth); // particle meet bound

        virtual bool collision(const Particle* other) const; // find collision with other

        virtual void resolve_collision(Particle* other); // change its velocity and other's 
    };
}


#endif // ! _BIG_PARTICLE_H_
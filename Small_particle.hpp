#ifndef _SMALL_PARTICLE_H_
#define _SMALL_PARTICLE_H_

#include "Particle.hpp"

namespace Box_with_balls {

    const double SMALL_RADIUS = 50;
    const double SMALL_MASS = 1;

    class Small_particle : public Particle {
    public:
        Small_particle(double x, double y, double vx, double vy);

        virtual double get_radius() const;

        virtual double get_inv_mass() const; // return 1 / mass

        virtual void bound_collision(int up, int down, int left, int rigth); // particle meet bound

        virtual bool collision(const Particle* other) const; // find collision with other

        virtual void resolve_collision(Particle* other); // change its velocity and other's 
    };
}


#endif // ! _SMALL_PARTICLE_H_
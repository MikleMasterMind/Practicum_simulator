#ifndef _SMALL_PARTICLE_H_
#define _SMALL_PARTICLE_H_

#include "Particle.hpp"

#define SMALL_RADIUS 50
#define SMALL_MASS 1

namespace Box_with_balls {

    class Small_particle : public Particle {
    public:
        Small_particle(double x, double y, double vx, double vy);

        Small_particle(double x, double y, double vx, double vy, double r, double m);
    };
}


#endif // ! _SMALL_PARTICLE_H_
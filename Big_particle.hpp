#ifndef _BIG_PARTICLE_H_
#define _BIG_PARTICLE_H_

#include "Particle.hpp"

namespace Box_with_balls {

    class Big_particle : public Particle {
    public:
        Big_particle(double x, double y, double vx, double vy, double r, double m);
    };
}


#endif // ! _BIG_PARTICLE_H_
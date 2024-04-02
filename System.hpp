#ifndef _System_H_
#define _System_H_

#include "Particle.hpp"
#include <vector>

namespace Box_wiht_balls {

    class System {

        static System* instacne;
        std::vector<Particle*> container;
        int index;
        const double time_step;

        System();

        System(const System&) = delete;

        void operator=(const System&) = delete;

    public:

        ~System();

        static System* getSystem(); // get object

        void add_particle(Particle* particle); // add particle to container

        void set_container(); // prepare to work with container of particles

        Particle* get_particle(); // return poiter to particle from container

        void phisics_update(); // simulation phisics step

    };
}


#endif // ! _System_H_
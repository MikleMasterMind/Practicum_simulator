#ifndef _System_H_
#define _System_H_

#include "Particle.hpp"
#include <vector>

#define TIME_STEP 0.0001
#define UP_BOUND 0
#define DOWN_BOUND 640
#define LEFT_BOUND 0
#define RIGTH_BOUND 1180
#define MAX_SPEED 300
#define MAX_RADIUS 100


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

        void generate_particles(int amount, int seed);

    };
}


#endif // ! _System_H_
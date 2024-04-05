#ifndef _System_H_
#define _System_H_

#include "Particle.hpp"
#include <vector>

#define TIME_STEP 0.016
#define UP_BOUND 20
#define DOWN_BOUND 620
#define LEFT_BOUND 20
#define RIGTH_BOUND 1160
#define MAX_SPEED 400
#define MAX_RADIUS 100
#define MAX_MASS 1000


namespace Box_wiht_balls {

    class System {

        std::vector<Particle*> container;
        int index;
        const double time_step;

    public:

        ~System();

        System();

        void add_particle(Particle* particle); // add particle to container

        void delete_particle(int i = -1);

        void open_container(); // prepare to work with container of particles

        Particle* get_particle(); // return poiter to particle from container

        void phisics_update(); // simulation phisics step

    };
}


#endif // ! _System_H_
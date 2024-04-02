#include "System.hpp"

Box_wiht_balls::System::System() : time_step(TIME_STEP) {}

Box_wiht_balls::System::~System() {
    for (int i = 0; i < container.size(); ++i) {
        delete container[i];
    }
}

Box_wiht_balls::System* Box_wiht_balls::System::getSystem() {
    if (!instacne)
        instacne = new System();
    return instacne;
}

Box_wiht_balls::System *Box_wiht_balls::System::instacne = nullptr;

void Box_wiht_balls::System::add_particle(Box_wiht_balls::Particle *particle) {
    container.push_back(particle);
}

void Box_wiht_balls::System::set_container() {
    index = 0;
}

Box_wiht_balls::Particle *Box_wiht_balls::System::get_particle() {
    if (index >= container.size())
        return nullptr;
    else 
        return container[index++];
}

void Box_wiht_balls::System::phisics_update() {
    for (int i = 0; i < container.size(); ++i) {
        Particle* patrticle = container[i];
        patrticle->move(time_step);
        patrticle->resolve_bound_collision(patrticle->check_bound_collision(UP_BOUND, DOWN_BOUND, LEFT_BOUND, RIGTH_BOUND));
        set_container();
        for (Particle* other = get_particle(); other != nullptr; other = get_particle()) {
            if (patrticle->collision(other))  {
                //patrticle->resolve_collision(other);
            }
        }
    }
}

void Box_wiht_balls::System::generate_particles(int amount, int seed) {
    for (int i = 0; i < amount;) {
        double radius = rand() % MAX_RADIUS;
        double x = abs(rand()) % RIGTH_BOUND;
        double y = abs(rand()) % DOWN_BOUND;
        double vx = abs(rand()) % MAX_SPEED;
        double vy = abs(rand()) % MAX_SPEED;
        Box_wiht_balls::Particle* a = new Box_wiht_balls::Particle(radius, x, y, vx, vy);
        if (a->check_bound_collision(UP_BOUND, DOWN_BOUND, LEFT_BOUND, RIGTH_BOUND) == no_bound) {
            set_container();
            for (Particle* b = get_particle(); b != nullptr; b = get_particle()) {
                if (a->collision(b)) {
                    delete a;
                    a = nullptr;
                    break;
                }
            }
            if (a) {
                add_particle(a);
                ++i;
            }
        }
        
    }
}

#include "System.hpp"

Box_wiht_balls::System::System() : time_step(0.001) {}

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
        set_container();
        Particle* other;
        while (other = get_particle()) {
            if (patrticle->collision(other))
                patrticle->resolve_collision(other);
        }
    }
}

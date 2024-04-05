#include "System.hpp"

Box_wiht_balls::System::System() : time_step(TIME_STEP) {}

Box_wiht_balls::System::~System() {
    for (int i = 0; i < container.size(); ++i) {
        delete container[i];
    }
}

void Box_wiht_balls::System::add_particle(Box_wiht_balls::Particle *particle) {
    container.push_back(particle);
}

void Box_wiht_balls::System::delete_particle(int i) {
    if (container.empty()) return;
    if (i == -1) container.pop_back();
    else container.erase(container.begin() + i);
}

void Box_wiht_balls::System::open_container() {
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
        open_container();
        for (Particle* other = get_particle(); other != nullptr; other = get_particle()) {
            if (patrticle->collision(other))  {
                patrticle->resolve_collision(other);
            }
        }
    }
}



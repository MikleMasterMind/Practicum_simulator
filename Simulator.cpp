#include "Simulator.hpp"

#include <iostream>

Box_wiht_balls::Simulator::Simulator() : Fl_Window(WINDOW_W, WINDOW_H, "") {
    sys = new System;
    pain = new Painter(RIGTH_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);
    begin_btn = new Fl_Button(begin_btn_x, begin_btn_y, btn_w, btn_h, "Begin");
    begin_btn->callback(step_callback, this);
}

void Box_wiht_balls::Simulator::generate_particles(int seed, int amount) {
    srand(seed);
    for (int i = 0; i < amount;) {
        double radius = rand() % MAX_RADIUS;
        double x = abs(rand()) % RIGTH_BOUND + LEFT_BOUND;
        double y = abs(rand()) % DOWN_BOUND + UP_BOUND;
        double vx = abs(rand()) % MAX_SPEED + 100; 
        double vy = abs(rand()) % MAX_SPEED + 100;
        Box_wiht_balls::Particle* a = new Box_wiht_balls::Particle(radius, x, y, vx, vy);
        if (a->check_bound_collision(UP_BOUND, DOWN_BOUND, LEFT_BOUND, RIGTH_BOUND) == no_bound) {
            sys->open_container();
            for (Particle* b = sys->get_particle(); b != nullptr; b = sys->get_particle()) {
                if (a->collision(b)) {
                    delete a;
                    a = nullptr;
                    break;
                }
            }
            if (a) {
                sys->add_particle(a);
                pain->add_particle(a);
                ++i;
            }
        } 
    }
}

void Box_wiht_balls::Simulator::draw() {
    Fl_Window::draw();
    fl_line(LEFT_BOUND, UP_BOUND, RIGTH_BOUND, UP_BOUND);
    fl_line(LEFT_BOUND, DOWN_BOUND, RIGTH_BOUND, DOWN_BOUND);
    fl_line(LEFT_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);
    fl_line(RIGTH_BOUND, UP_BOUND, RIGTH_BOUND, DOWN_BOUND);
}

void Box_wiht_balls::Simulator::step_callback(Fl_Widget* w, void* a) {
    Fl::add_timeout(TIME_STEP, timer_callback, a);
}

void Box_wiht_balls::Simulator::timer_callback(void* a) {
    Simulator* sim = (Simulator*)a;
    sim->sys->phisics_update();
    sim->pain->update_image();
    sim->redraw();
    Fl::add_timeout(TIME_STEP, timer_callback, sim);
}

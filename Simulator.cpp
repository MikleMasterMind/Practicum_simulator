#include "Simulator.hpp"

#include <iostream>

Box_wiht_balls::Simulator::Simulator() : Fl_Window(WINDOW_W, WINDOW_H, "") {
    sys = new System;
    pain = new Painter(RIGTH_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);

    begin_btn = new Fl_Button(btn_x, btn_y, btn_w, btn_h, "Begin");begin_btn->callback(step_callback, this);

    add_particle_btn = new Fl_Button(btn_x + btn_w + spacing, btn_y, btn_w, btn_h, "Add Particle");
    add_particle_btn->callback(show_dialog_add_callback, this);

    delete_particle_btn = new Fl_Button(btn_x + btn_w * 2 + spacing * 2, btn_y, btn_w, btn_h, "Delete Particle");
    delete_particle_btn->callback(show_dialog_delete_callback, this);
}

Box_wiht_balls::Simulator::~Simulator() {
    delete sys;
    delete pain;
    delete begin_btn;
    delete add_particle_btn;
    delete dialog_add;
    delete add_small_particle_btn;
    delete add_big_particle_btn;
    delete delete_particle_btn;
    delete dialog_delete;
    delete delete_small_particle_btn;
    delete delete_big_particle_btn;
}

template<class particleT> 
void Box_wiht_balls::Simulator::add_particle() {
    Particle* a = nullptr;
    while (!a) {
        double radius = rand() % MAX_RADIUS;
        double mass = rand() % MAX_MASS;
        double x = abs(rand()) % RIGTH_BOUND + LEFT_BOUND;
        double y = abs(rand()) % DOWN_BOUND + UP_BOUND;
        double vx = abs(rand()) % MAX_SPEED + 100; 
        double vy = abs(rand()) % MAX_SPEED + 100;
        a = new particleT(x, y, vx, vy, radius, mass);
        if (a->check_bound_collision(UP_BOUND, DOWN_BOUND, LEFT_BOUND, RIGTH_BOUND) != no_bound) {
            delete a;
            a = nullptr;
        } else {
            sys->open_container();
            for (Particle* b = sys->get_particle(); b != nullptr; b = sys->get_particle()) {
                if (a->collision(b)) {
                    delete a;
                    a = nullptr;
                    break;
                }
            }
        } 
    }
    sys->add_particle(a);
    pain->add_particle(a);
}

void Box_wiht_balls::Simulator::generate_particles(int seed, int amount_small, int amount_big) {
    srand(seed);
    for (int i = 0; i < amount_small; ++i)
        add_particle<Small_particle>();
    for (int i = 0; i < amount_big; ++i)
        add_particle<Big_particle>();
    
}

void Box_wiht_balls::Simulator::draw() {
    Fl_Window::draw();
    fl_line(LEFT_BOUND, UP_BOUND, RIGTH_BOUND, UP_BOUND);
    fl_line(LEFT_BOUND, DOWN_BOUND, RIGTH_BOUND, DOWN_BOUND);
    fl_line(LEFT_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);
    fl_line(RIGTH_BOUND, UP_BOUND, RIGTH_BOUND, DOWN_BOUND);
    sys->phisics_update();
    pain->update_image();
}

void Box_wiht_balls::Simulator::step_callback(Fl_Widget* w, void* data) {
    w->callback(nullptr, nullptr); // to turn of button
    Fl::add_timeout(TIME_STEP, timer_callback, data);
}

void Box_wiht_balls::Simulator::timer_callback(void* data) {
    Simulator* sim = (Simulator*)data;
    sim->redraw();
    Fl::add_timeout(TIME_STEP, timer_callback, sim);
}

void Box_wiht_balls::Simulator::show_dialog_add_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->dialog_add = new Fl_Window(200, 150, "Chose particle to add");
    sim->add_small_particle_btn = new Fl_Button(50, 50, 100, 30, "Add Small Particle");
    sim->add_small_particle_btn->callback(add_particle_callback, sim);
    sim->add_big_particle_btn = new Fl_Button(50, 100, 100, 30, "Add Big Particle");
    sim->add_big_particle_btn->callback(add_particle_callback, sim);
    sim->dialog_add->show();
}

void Box_wiht_balls::Simulator::add_particle_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->add_particle<Small_particle>();       
}

void Box_wiht_balls::Simulator::show_dialog_delete_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->dialog_delete = new Fl_Window(200, 150, "Chose particle to delete");
    sim->delete_small_particle_btn = new Fl_Button(50, 50, 100, 30, "Delete Small Particle");
    sim->delete_small_particle_btn->callback(delete_particle_callback, sim);
    sim->delete_big_particle_btn = new Fl_Button(50, 100, 100, 30, "Delete Big Particle");
    sim->delete_big_particle_btn->callback(delete_particle_callback, sim);
    sim->dialog_delete->show();
}

void Box_wiht_balls::Simulator::delete_particle_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->sys->delete_particle();
    sim->pain->delete_particle();
}

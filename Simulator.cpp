#include "Simulator.hpp"

#include <iostream>

Box_with_balls::Simulator::Simulator() : 
    Fl_Window(WINDOW_W, WINDOW_H, ""), dialog_add(nullptr), add_small_particle_btn(nullptr),
    add_big_particle_btn(nullptr), dialog_delete(nullptr), delete_small_particle_btn(nullptr),
    delete_big_particle_btn(nullptr) {
    sys = new System;
    pain = new Painter(RIGTH_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);

    do_steps_btn = new Fl_Button(btn_x, btn_y, btn_w, btn_h, "Begin");
    //do_steps_btn->callback(step_callback, this);

    add_particle_btn = new Fl_Button(btn_x + btn_w + spacing, btn_y, btn_w, btn_h, "Add Particle");
    add_particle_btn->callback(show_dialog_add_callback, this);

    delete_particle_btn = new Fl_Button(btn_x + (btn_w + spacing) * 2, btn_y, btn_w, btn_h, "Delete Particle");
    delete_particle_btn->callback(show_dialog_delete_callback, this);

    step_amount_inp = new Fl_Input(btn_x + (btn_w + spacing) * 3, btn_y, btn_w * 5, btn_h);
    step_amount_inp->callback(set_step_amount_callback, this);
    //step_amount_inp->when(FL_WHEN_ENTER_KEY);
    step_amount_inp->take_focus();
}

Box_with_balls::Simulator::~Simulator() {
    delete sys;
    delete pain;
    delete do_steps_btn;
    delete add_particle_btn;
    delete dialog_add;
    delete add_small_particle_btn;
    delete add_big_particle_btn;
    delete delete_particle_btn;
    delete dialog_delete;
    delete delete_small_particle_btn;
    delete delete_big_particle_btn;
    delete step_amount_inp;
}

template<class particleT> 
void Box_with_balls::Simulator::add_particle() {
    Particle* a = nullptr;
    while (!a) {
        double radius = rand() % MAX_RADIUS;
        double mass = rand() % MAX_MASS;
        double x = abs(rand()) % (RIGTH_BOUND - LEFT_BOUND)+ LEFT_BOUND;
        double y = abs(rand()) % (DOWN_BOUND - UP_BOUND) + UP_BOUND;
        double vx = abs(rand()) % MAX_SPEED + MIN_SPEED; 
        double vy = abs(rand()) % MAX_SPEED + MIN_SPEED;
        a = new particleT(x, y, vx, vy, radius, mass);
        a->bound_collision(UP_BOUND, DOWN_BOUND, LEFT_BOUND, RIGTH_BOUND);
        sys->open_container();
        for (Particle* b = sys->get_particle(); b != nullptr; b = sys->get_particle()) {
            if (a->collision(b)) {
                delete a;
                a = nullptr;
                break;
            }
        } 
    }
    sys->add_particle(a);
    pain->add_particle(a);
}

void Box_with_balls::Simulator::generate_particles(int seed, int amount_small, int amount_big) {
    srand(seed);
    for (int i = 0; i < amount_small; ++i)
        add_particle<Small_particle>();
    for (int i = 0; i < amount_big; ++i)
        add_particle<Big_particle>();
    
}

void Box_with_balls::Simulator::draw() {
    Fl_Window::draw();
    fl_line(LEFT_BOUND, UP_BOUND, RIGTH_BOUND, UP_BOUND);
    fl_line(LEFT_BOUND, DOWN_BOUND, RIGTH_BOUND, DOWN_BOUND);
    fl_line(LEFT_BOUND, UP_BOUND, LEFT_BOUND, DOWN_BOUND);
    fl_line(RIGTH_BOUND, UP_BOUND, RIGTH_BOUND, DOWN_BOUND);
    sys->phisics_update();
    pain->update_image();
}

void Box_with_balls::Simulator::step_callback(Fl_Widget* w, void* data) {
    Fl::add_timeout(TIME_STEP, timer_callback, data);
}

void Box_with_balls::Simulator::timer_callback(void* data) {
    Simulator* sim = (Simulator*)data;
    if (sim->step_count >= sim->step_amount) {
        sim->step_count = 0;
        return;
    }
    else {
        ++sim->step_count;
    }
    sim->redraw();
    Fl::add_timeout(TIME_STEP, timer_callback, sim);
}

void Box_with_balls::Simulator::show_dialog_add_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    if (!sim->dialog_add) 
        sim->dialog_add = new Fl_Window(dialog_win_w, dialog_win_h, "Chose particle to add");
    if (!sim->add_small_particle_btn) 
        sim->add_small_particle_btn = new Fl_Button(dialog_btn_x, dialog_btn_y, dialog_btn_w, dialog_btn_h, "Add Small Particle");
    sim->add_small_particle_btn->callback(add_particle_callback<Small_particle>, sim);
    if (!sim->add_big_particle_btn) 
        sim->add_big_particle_btn = new Fl_Button(dialog_btn_x, dialog_btn_y + dialog_btn_h + dialog_spacing, dialog_btn_w, dialog_btn_h, "Add Big Particle");
    sim->add_big_particle_btn->callback(add_particle_callback<Big_particle>, sim);
    sim->dialog_add->show();
}

template <class particleT>
void Box_with_balls::Simulator::add_particle_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->add_particle<particleT>();       
}

void Box_with_balls::Simulator::show_dialog_delete_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    if (!sim->dialog_delete) 
        sim->dialog_delete = new Fl_Window(dialog_win_w, dialog_win_h, "Chose particle to delete");
    if (!sim->delete_small_particle_btn) 
        sim->delete_small_particle_btn = new Fl_Button(dialog_btn_x, dialog_btn_y, dialog_btn_w, dialog_btn_h, "Delete Small Particle");
    sim->delete_small_particle_btn->callback(delete_particle_callback<Small_particle>, sim);
    if (!sim->delete_big_particle_btn) 
        sim->delete_big_particle_btn = new Fl_Button(dialog_btn_x, dialog_btn_y + dialog_btn_h + dialog_spacing, dialog_btn_w, dialog_btn_h, "Delete Big Particle");
    sim->delete_big_particle_btn->callback(delete_particle_callback<Big_particle>, sim);
    sim->dialog_delete->show();
}

template <class particleT>
void Box_with_balls::Simulator::delete_particle_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    sim->sys->open_container();
    int count = 0;
    for (Particle* a = sim->sys->get_particle(); a != nullptr; a = sim->sys->get_particle()) {
        if (typeid(*a) == typeid(particleT)) {
            sim->sys->delete_particle(count);
            sim->pain->delete_particle(count);
            break;
        }
        ++count;
    }
}

void Box_with_balls::Simulator::set_step_amount_callback(Fl_Widget *w, void *data) {
    Simulator* sim = (Simulator*)data;
    const char* input_data = sim->step_amount_inp->value();
    sim->step_amount = atoi(input_data);
    sim->step_count = 0;
    sim->do_steps_btn->callback(step_callback, sim);
}

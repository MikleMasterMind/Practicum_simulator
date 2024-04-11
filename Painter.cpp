#include "Painter.hpp"

#include <typeinfo>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>

Box_with_balls::Painter::Painter(int x, int y, int w, int h, const char* s) : Fl_Box(x, y, w, h, s) {}

Box_with_balls::Painter::~Painter() {
    for (int i = 0; i < (int)particles.size(); ++i) {
        delete particles[i];
    }
}

void Box_with_balls::Painter::add_particle(Box_with_balls::Particle *particle) {
    particles.push_back(particle);
}

void Box_with_balls::Painter::delete_particle(int i) {
    if (particles.empty()) return;
    if (i == -1) {
        particles.pop_back();
    } else {
        particles.erase(particles.begin() + i);
    }
}

void Box_with_balls::Painter::draw() {
    Fl_Box::draw();
    fl_begin_polygon();
    for (int i = 0; i < (int)particles.size(); ++i) {
        Math_vector coordinates = particles[i]->get_coordinates();
        double radius = particles[i]->get_radius();
        if (typeid(*particles[i]) == typeid(Small_particle)) fl_color(FL_BLUE);
        else if (typeid(*particles[i]) == typeid(Big_particle)) fl_color(FL_RED);
        else fl_color(FL_GREEN);
        fl_circle(coordinates.x, coordinates.y, radius);
    }
    fl_end_polygon();
}

void Box_with_balls::Painter::update_image() {
    redraw();
}

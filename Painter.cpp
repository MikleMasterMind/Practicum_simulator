#include "Painter.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>

Box_wiht_balls::Painter::Painter(int x, int y, int w, int h, const char* s) : Fl_Box(x, y, w, h, s) {}

Box_wiht_balls::Painter::~Painter() {}

void Box_wiht_balls::Painter::add_particle(Box_wiht_balls::Particle *particle) {
    particles.push_back(particle);
}

void Box_wiht_balls::Painter::draw() {
    Fl_Box::draw();
    fl_begin_polygon();
    fl_color(FL_RED);
    for (int i = 0; i < particles.size(); ++i) {
        Circle a = particles[i]->get_image();
        fl_circle(a.x, a.y, a.r);
    }
    fl_end_polygon();
}

void Box_wiht_balls::Painter::update_image() {
    redraw();
}

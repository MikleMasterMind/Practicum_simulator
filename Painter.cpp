#include "Painter.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>

MyNamespace::Painter::Painter(int x, int y, int w, int h, const char* s) : Fl_Box(x, y, w, h, s) {}

MyNamespace::Painter::~Painter() {
    delete instance;
    instance = nullptr;
}

MyNamespace::Painter* MyNamespace::Painter::getPainter(int x, int y, int w, int h, const char* s) {
    if (!instance)
        instance = new Painter(x, y, w, h, s);
    return instance;
}

void MyNamespace::Painter::draw() {

    Particle *particle = new Particle(50, 100, 100, 0, 0);
    particles.push_back(particle);
    
    Fl_Box::draw();
    fl_color(FL_RED);
    fl_begin_polygon();
    for (int i = 0; i < particles.size(); ++i) {
        Circle a = particles[i]->get_image();
        fl_circle(a.x, a.y, a.r);
    }
    fl_end_polygon();

}

void MyNamespace::Painter::update() {
    redraw();
    Fl::add_timeout(0.1, timer_callback, this);
}

void MyNamespace::Painter::timer_callback(void* data) {
    Painter* self = static_cast<Painter*>(data);
    self->update();
}

MyNamespace::Painter* MyNamespace::Painter::instance = nullptr;

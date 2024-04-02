#include <iostream>
#include <unistd.h>
#include "Math_vector.hpp"
#include "Painter.hpp"
#include "System.hpp"

int main() {
    Fl_Window *win =  new Fl_Window(640, 480, "Window");
    Box_wiht_balls::Painter* painter = Box_wiht_balls::Painter::getPainter(0, 0, 640, 480);
    Box_wiht_balls::System* sys = Box_wiht_balls::System::getSystem();
    Box_wiht_balls::Particle* a = new Box_wiht_balls::Particle(100, 100, 100, 20, 20);
    sys->add_particle(a);
    painter->add_particle(a);
    win->show();
    while (win->shown()) {
        Fl::check();
        sys->phisics_update();
        painter->update();
        sleep(0.001);
    }
    return Fl::run();
}

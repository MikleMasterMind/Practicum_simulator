#include <iostream>
#include <unistd.h>
#include <random>
#include "Math_vector.hpp"
#include "Painter.hpp"
#include "System.hpp"


int main() {
    Fl_Window *win =  new Fl_Window(1180, 640 + 200, "Window");
    Box_wiht_balls::Painter* painter = Box_wiht_balls::Painter::getPainter(0, 0, 1180, 640);
    Box_wiht_balls::System* sys = Box_wiht_balls::System::getSystem();

    int seed;
    std::cout << "seed: ";
    std::cin >> seed;
    srand(seed);

    int num;
    std::cout << "amount of particles: ";
    std::cin >> num;

    sys->generate_particles(num, seed);
    sys->set_container();
    for (Box_wiht_balls::Particle* a = sys->get_particle(); a != nullptr; a = sys->get_particle()) {
        painter->add_particle(a);
    }

    win->show();
    while (win->shown()) {
        Fl::check();
        sys->phisics_update();
        painter->update_image();
        sleep(TIME_STEP);
    }
    return Fl::run();
    
}

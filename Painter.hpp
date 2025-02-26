#ifndef _Painter_H_
#define _Painter_H_

#include <vector>
#include "Particle.hpp"
#include "Small_particle.hpp"
#include "Big_particle.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

namespace Box_with_balls {

    class Painter : public Fl_Box {

        std::vector<Particle*> particles; // container with particles to draw
        
    public:

        Painter(int x = 0, int y = 0, int w = 1180, int h = 640 + 200, const char* s = ""); // return pointer to object (object stored in heap)

        ~Painter();

        void add_particle(Particle* particle); // add particle to conteiner

        void delete_particle(int i = -1); // remove particle from conteiner

        void draw(); // to paint shot

        void update_image(); // to udpate movement

    };
}

#endif // ! _Painter_H_
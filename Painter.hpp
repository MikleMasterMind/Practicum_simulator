#ifndef _Painter_H_
#define _Painter_H_

#include <vector>
#include "Particle.hpp"
#include "Circle.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>

namespace Box_wiht_balls {

    class Painter : public Fl_Box {

        static Painter* instance; // keep only 1 object here
        std::vector<Particle*> particles; // container with particles to draw

        Painter(int x, int y, int w, int h, const char* s);

        Painter(const Painter&) = delete;

        void operator=(const Painter&) = delete;
        
    public:

        ~Painter();

        static Painter* getPainter(int x, int y, int w, int h, const char* s = ""); // return pointer to object (object stored in heap)

        void add_particle(Particle* particle);

        void draw(); // to paint shot

        void update_image(); // to udpate movement

        static void timer_callback(void* data); // timer
    };
}

#endif // ! _Painter_H_
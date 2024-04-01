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

namespace MyNamespace {

    class Painter : public Fl_Box {

        static Painter* instance;

        std::vector<Particle*> particles;

        Painter(int x, int y, int w, int h, const char* s);

        Painter(const Painter&) = delete;

        void operator=(const Painter&) = delete;
        
    public:

        ~Painter();

        static Painter* getPainter(int x, int y, int w, int h, const char* s = "mywin");

        void draw();

        void update();

        static void timer_callback(void* data);
    };
}



#endif // ! _Painter_H_
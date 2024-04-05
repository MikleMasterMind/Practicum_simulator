#ifndef _Simulator_H_
#define _Simulator_H_

#include "System.hpp"
#include "Painter.hpp"
#include "Particle.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <random>

#define WINDOW_W RIGTH_BOUND + 40
#define WINDOW_H DOWN_BOUND + 120

namespace Box_wiht_balls {

    enum btn {
        begin_btn_x = 20,
        begin_btn_y = 650,
        btn_w = 100,
        btn_h = 40
    };

    class Simulator: public Fl_Window {

        System* sys;
        Painter* pain;
        Fl_Button* begin_btn;

    public:

        Simulator();

        void generate_particles(int seed, int amount);

        void draw();

        //void simulate_step();

        static void step_callback(Fl_Widget* w, void* a);

        static void timer_callback(void* a);

    };
}



#endif // ! _Simulator_H_
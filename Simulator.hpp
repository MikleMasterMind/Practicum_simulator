#ifndef _Simulator_H_
#define _Simulator_H_

#include "System.hpp"
#include "Painter.hpp"
#include "Particle.hpp"
#include "Small_particle.hpp"
#include "Big_particle.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <random>
#include <string>

#define WINDOW_W RIGTH_BOUND + 40
#define WINDOW_H DOWN_BOUND + 80

namespace Box_with_balls {

    enum win_sizes {
        btn_x = 20,
        btn_y = 650,
        spacing = 50,
        btn_w = 110,
        btn_h = 30
    };

    enum dialog_sizes {
        dialog_win_w = 200,
        dialog_win_h = 150,
        dialog_btn_x = 25,
        dialog_btn_y = 30,
        dialog_btn_w = 150,
        dialog_btn_h = 30,
        dialog_spacing = 20
    };

    class Simulator: public Fl_Window {

        System* sys;
        Painter* pain;
        Fl_Button* begin_btn;
        Fl_Button* add_particle_btn;
        Fl_Window* dialog_add;
        Fl_Button* add_small_particle_btn;
        Fl_Button* add_big_particle_btn;
        Fl_Button* delete_particle_btn;
        Fl_Window* dialog_delete;
        Fl_Button* delete_small_particle_btn;
        Fl_Button* delete_big_particle_btn;
        Fl_Input* step_amount_inp;
        long long step_amount;

    public:

        Simulator();

        ~Simulator();

        template <class particleT>
        void add_particle();

        void generate_particles(int seed, int amount_small, int amount_big);

        void draw();

        static void step_callback(Fl_Widget* w, void* data);

        static void timer_callback(void* a);

        static void show_dialog_add_callback(Fl_Widget* w, void* data);

        template <class particleT>
        static void add_particle_callback(Fl_Widget* w, void* data);

        static void show_dialog_delete_callback(Fl_Widget* w, void* data);

        template <class particleT>
        static void delete_particle_callback(Fl_Widget* w, void* data);

        static void set_step_amount_callback(Fl_Widget* w, void* data);

    };
}



#endif // ! _Simulator_H_
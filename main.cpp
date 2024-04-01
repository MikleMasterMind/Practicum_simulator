#include <iostream>
#include "Math_vector.hpp"
#include "Painter.hpp"

int main() {
    Fl_Window *win =  new Fl_Window(640, 480, "Window");
    MyNamespace::Painter* painter = MyNamespace::Painter::getPainter(0, 0, 640, 480, "AAAA");
    win->show();
    painter->update();
    return Fl::run();
}
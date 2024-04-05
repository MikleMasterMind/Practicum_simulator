#ifndef _Circle_H_
#define _Circle_H_

namespace Box_with_balls {
    struct Circle {
        double x;
        double y;
        double r;

        Circle(double other_x = 0, double other_y = 0, double ohter_r = 0);
    };
}

#endif // ! _Circle_H_
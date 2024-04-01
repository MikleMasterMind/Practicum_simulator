#ifndef _Shape_H_
#define _Shape_H_

#include "Math_vector.hpp"
#include "AABB.hpp"

namespace MyNamespace {

    class Shape {
        AABB aabb;

    public:
        Shape(double max_x = 0, double max_y = 0, double min_x = 0, double min_y = 0);

        void set_aabb(double max_x = 0, double max_y = 0, double min_x = 0, double min_y = 0);

        virtual bool collision(const Shape& other) const; // check collision with other shape

        virtual void paint() = 0; // show shape in window
    };
}

#endif // ! _Shape_H_
#ifndef _Math_vector_H_
#define _Math_vector_H_

#include <cmath>
#include <iostream>

namespace Box_wiht_balls {

    struct Math_vector {
        
        double x;
        double y;

        Math_vector(double other_x, double other_y);

        Math_vector operator*(double n)  const;

        Math_vector operator+(const Math_vector& other) const;

        Math_vector operator-(const Math_vector& other) const;

        double operator*(const Math_vector& other) const; // scalar product

        double squared_module() const; // to get quiqly squared module

        double module() const; // if you need not squared module (else better use squared_module)

        double squared_distance(const Math_vector& other) const; // to get quiqly squared distance

        double distance(const Math_vector& other) const; // if you need not squared distance (else better use squared_distance)

        void print(const char* end = "\n") const;
    };
}

#endif // ! _Math_vector_H_
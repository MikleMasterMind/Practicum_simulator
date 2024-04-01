#ifndef _Math_vector_H_
#define _Math_vector_H_

#include <cmath>
#include <iostream>

namespace MyNamespace {

    struct Math_vector {
        
        double x;
        double y;

        Math_vector(double other_x, double other_y);

        Math_vector operator*(double n)  const;

        Math_vector operator+(const Math_vector& other) const;

        Math_vector operator-(const Math_vector& other) const;

        double operator*(const Math_vector& other) const; // scalar product

        double squared_module() const;

        double module() const;

        double squared_distance(const Math_vector& other) const;

        double distance(const Math_vector& other) const;

        void print(const char* end = "\n") const;
    };
}

#endif // ! _Math_vector_H_
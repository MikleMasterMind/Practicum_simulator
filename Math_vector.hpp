#ifndef _Math_vector_H_
#define _Math_vector_H_

#include <cmath>
#include <iostream>

namespace MyNamespace {

    class Math_vector {
    public:
        double x;
        double y;

        Math_vector(double other_x, double other_y);

        Math_vector operator*(double n)  const;

        Math_vector operator+(const Math_vector& other) const;

        double operator*(const Math_vector& other) const;

        double squared_module() const;

        double module() const;

        void print(const char* end = "\n") const;
    };
}

#endif // ! _Math_vector_H_
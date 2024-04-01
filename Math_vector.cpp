#include "Math_vector.hpp"

MyNamespace::Math_vector::Math_vector(double other_x, double other_y) : x(other_x), y(other_y) {}

MyNamespace::Math_vector MyNamespace::Math_vector::operator*(double n) const {
    return Math_vector(x * n,  y * n);
}

MyNamespace::Math_vector MyNamespace::Math_vector::operator+(const MyNamespace::Math_vector &other) const {
    return Math_vector(x + other.x, y + other.y);
}

double MyNamespace::Math_vector::operator*(const MyNamespace::Math_vector& other) const {
    return x * other.x + y * other.y;
}

double MyNamespace::Math_vector::squared_module() const {
    return x * x + y * y;
}

double MyNamespace::Math_vector::module() const {
    return sqrt(MyNamespace::Math_vector::squared_module());
}

void MyNamespace::Math_vector::print(const char* end) const {
    std::cout << "(" << x << ", " << y << ")" << end;
}
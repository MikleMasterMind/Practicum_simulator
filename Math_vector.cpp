#include "Math_vector.hpp"

Box_wiht_balls::Math_vector::Math_vector(double other_x, double other_y) : x(other_x), y(other_y) {}

Box_wiht_balls::Math_vector Box_wiht_balls::Math_vector::operator*(double n) const {
    return Math_vector(x * n,  y * n);
}

Box_wiht_balls::Math_vector Box_wiht_balls::Math_vector::operator+(const Box_wiht_balls::Math_vector &other) const {
    return Math_vector(x + other.x, y + other.y);
}

Box_wiht_balls::Math_vector Box_wiht_balls::Math_vector::operator-(const Box_wiht_balls::Math_vector &other) const {
    return Math_vector(x - other.x, y - other.y);
}

double Box_wiht_balls::Math_vector::operator*(const Box_wiht_balls::Math_vector& other) const {
    return x * other.x + y * other.y;
}

double Box_wiht_balls::Math_vector::squared_module() const {
    return x * x + y * y;
}

double Box_wiht_balls::Math_vector::module() const {
    return sqrt(Box_wiht_balls::Math_vector::squared_module());
}

double Box_wiht_balls::Math_vector::squared_distance(const Box_wiht_balls::Math_vector &other) const {
    return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y);
}

double Box_wiht_balls::Math_vector::distance(const Box_wiht_balls::Math_vector &other) const {
    return sqrt(Box_wiht_balls::Math_vector::squared_distance(other));
}

void Box_wiht_balls::Math_vector::print(const char* end) const {
    std::cout << "(" << x << ", " << y << ")" << end;
}
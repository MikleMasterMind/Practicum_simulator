#include "Shape.hpp"

MyNamespace::Shape::Shape(double max_x, double max_y, double min_x, double min_y) :
    aabb(max_x, max_y, min_x, min_y) {}

bool MyNamespace::Shape::collision(const MyNamespace::Shape &other) const {
    if(this->aabb.max.x < other.aabb.min.x | this->aabb.min.x > other.aabb.max.x) return false; // horizontally
    if(this->aabb.max.y < other.aabb.min.y | this->aabb.min.y > other.aabb.max.y) return false; // vertically
    return true; // no overlap
}

void MyNamespace::Shape::set_aabb(double max_x, double max_y, double min_x, double min_y) {
    aabb.max.x = max_x;
    aabb.max.y = max_y;
    aabb.min.x = min_x;
    aabb.min.y = min_y;
}
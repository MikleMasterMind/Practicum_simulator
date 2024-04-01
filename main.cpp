#include <iostream>
#include "Math_vector.hpp"

int main() {
    MyNamespace::Math_vector vector(1.0, 2.0);
    MyNamespace::Math_vector vector2(2.0, -10.0);
    MyNamespace::Math_vector vector3 = vector + vector2;
    vector.print();
    vector3.print();
    vector2 = vector2 * 2;
    vector2.print();
    std::cout << vector.module() << " " << vector.squared_module();
    return 0;
}
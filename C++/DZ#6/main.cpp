
#include "Figure.hpp"

int main() {
    Figure *array[4];
    array[0] = new Square(5);
    array[1] = new Circle(3);
    array[2] = new Rectangle(4, 8);
    array[3] = new Triangle(2, 2, 2);
    for (int i = 0; i < 4; ++i) {
        array[i]->show();
        std::cout << std::endl;
    }
    for (int j = 0; j < 4; ++j) {
        delete array[j];
        array[j] = nullptr;
    }
    return 0;
}
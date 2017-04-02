#ifndef DZ_6_FIGURE_HPP
#define DZ_6_FIGURE_HPP

#include <math.h>
#include <iostream>

class Figure {
public:
    virtual double calc_space() = 0;

    virtual void show() = 0;
};

class Square : public Figure {
public:
    Square() = default;

    Square(int s) { side = s; };

    ~Square() = default;

    double calc_space() override {
        return pow(side, 2);
    };

    void show() override {
        std::cout << "Square sides are " << side << std::endl;
        std::cout << "Square space is " << calc_space() << std::endl;

    }

private:
    int side = 0;
};

class Circle : public Figure {
public:
    Circle() = default;

    Circle(int R) {
        radius = R;
    }

    ~Circle() = default;

    double calc_space() override {
        return M_PI * pow(radius, 2);
    }

    void show() override {
        std::cout << "Circle radius is " << radius << std::endl;
        std::cout << "Circle space is " << calc_space() << std::endl;
    }

private:
    int radius = 0;
};

class Triangle : public Figure {
public:
    Triangle() = default;

    Triangle(int s1, int s2, int s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    ~Triangle() = default;

    double calc_space() override {
        int p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    void show() override {
        std::cout << "Triangle sides are " << side1 << ", " << side2 << ", " << side3 << std::endl;
        std::cout << "Triangle space is " << calc_space() << std::endl;
    }

private:
    int side1 = 0;
    int side2 = 0;
    int side3 = 0;
};

class Rectangle : public Figure {
public:
    Rectangle() = default;

    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    ~Rectangle() = default;

    double calc_space() override {
        return width * height;
    }

    void show() override {
        std::cout << "Rectangle width and height are " << width << " and " << height << std::endl;
        std::cout << "Rectangle space is " << calc_space() << std::endl;
    }

private:
    int width = 0;
    int height = 0;
};

#endif

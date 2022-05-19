#include <functional>
#include <iostream>
#include <numbers>

double getCircleArea(int radius) {
    return std::numbers::pi * static_cast<double>(radius * radius);
}

struct triangle {
    int base, height;

    triangle(int b, int h) : base(b), height(h) {}

    double getArea() {
        return static_cast<double>(base * height) / 2.0;
    }

    double getArea(int b, int h) {
        return static_cast<double>(b * h) / 2.0;
    }

    double getVol(int depth) {
        return static_cast<double>(depth) * getArea();
    }
};

int main() {
    double (triangle::*raw_mem_fn_ptr)() = &triangle::getArea;
    triangle t(10, 5);
    std::cout << "raw_mem_fn_ptr(10,5) = " << (t.*raw_mem_fn_ptr)() << "\n";

    std::function<double(triangle&, int)> tVol = &triangle::getVol;
    triangle t2(20, 4);
    std::cout << "tVol(15) = " << (tVol)(t2, 15) << "\n";

    double (*rawFuncPtr)(int) = getCircleArea;
    std::cout << "rawFuncPtr(10) = " << rawFuncPtr(10) << "\n";

    std::function f = getCircleArea;  // use std::function<double(int)>
    std::cout << "f(20) = " << f(20) << "\n";
}
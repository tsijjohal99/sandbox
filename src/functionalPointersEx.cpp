#include <functional>
#include <iostream>
#include <numbers>
#include <string>

double get_circle_area(int radius) {
    return std::numbers::pi * static_cast<double>(radius * radius);
}

struct triangle {
    double get_area(int width, int height) { return static_cast<double>(width * height) / 2.0; }
};

struct stringer {
    std::string operator()(const std::string& str1, const std::string& str2) {
        return str1 + '_' + str2;
    }
};

auto math_lambda = [](int first, int second, int multiplier) { return (first + second) * multiplier; };

template <typename T, typename... Targs>
auto doFunction(T function, Targs... others) {
    return std::invoke(function, others...);
}

int main() {
    system("cls");

    while (true) {
        char input;
        std::cout << "1. Circle area \n";
        std::cout << "2. Triangle area \n";
        std::cout << "3. String concatenation \n";
        std::cout << "4. math lambda \n";
        std::cout << "0. Exit \n";
        std::cin >> input;

        if (input == '1') {
            int radius;
            std::cout << "radius: \n";
            std::cin >> radius;
            std::cout << "radius: " << doFunction(get_circle_area, radius) << "\n";
        } else if (input == '2') {
            const triangle t;
            int width, height;
            std::cout << "width: \n";
            std::cin >> width;
            std::cout << "height: \n";
            std::cin >> height;
            std::cout << "triangle: " << doFunction(&triangle::get_area, t, width, height) << "\n";
        } else if (input == '3') {
            std::string st1, st2;
            std::cout << "first string: \n";
            std::cin >> st1;
            std::cout << "second string: \n";
            std::cin >> st2;
            std::cout << "stringer: " << doFunction(stringer(), st1, st2) << "\n";
        } else if (input == '4') {
            int first, second, multiplier;
            std::cout << "first: \n";
            std::cin >> first;
            std::cout << "second: \n";
            std::cin >> second;
            std::cout << "multiplier: \n";
            std::cin >> multiplier;
            std::cout << "math_lambda: " << doFunction(math_lambda, first, second, multiplier) << "\n";
        } else if (input == '0') {
            break;
        } else {
            std::cout << "try again\n";
        }
    }
}

// auto run_any_func(auto&& f, auto&&... args) {
//     return f(args...);
// }

// // universal reference
// // forwarding reference

// // template <typename F, typename... Args>
// // auto run_any_func(F&& f, Args&&... args)
// //{
// //	return f(std::forward<Args>(args)...);
// // }

// int main() {
//     std::cout << "math_lambda: " << run_any_func(math_lambda, 3, 4, 5) << "\n";

//     std::cout << "get_circle_area: " << run_any_func(get_circle_area, 7) << "\n";

//     trapezoid t;
//     auto p_mem_fn = std::mem_fn(&trapezoid::get_area);
//     std::cout << "get_area: " << run_any_func(p_mem_fn, t, 10, 5) << "\n";

//     stringer s;
//     std::cout << "stringer: " << run_any_func(s, "Bob", "Builder") << "\n";
// }
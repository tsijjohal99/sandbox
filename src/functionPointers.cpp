#include <iostream>
#include <map>
#include <string>

std::map<std::string, void (*)()> animalFuncs = {
    {"cat", []() { std::cout << "meow\n"; }},
    {"dog", []() { std::cout << "woof\n"; }},
    {"pig", []() { std::cout << "oink\n"; }},
    {"horse", []() { std::cout << "neigh\n"; }},
    {"duck", []() { std::cout << "quack\n"; }},
};

void speakAnimal() {
    std::string animal;

    while (true) {
        std::cout << "Select animal: ";
        std::cin >> animal;

        if (animal == "q") {
            break;
        } else if (animalFuncs.contains(animal)) {
            animalFuncs[animal]();
        } else {
            std::cout << "Animal unknown\n";
        }
    }
}

int main() {
    speakAnimal();
}
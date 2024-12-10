#include <stdexcept>
#include "factory_method.h"
#include "./animal/wolf.h"
#include "./animal/rabbit.h"
using namespace std;


unique_ptr<Animal>
animal_factory_method (string const& type, Koord koord, int d, size_t k) {
    unique_ptr<Animal> ptr;
    auto direction = static_cast<Direction> (d);

    if (type == "woolf") {
        ptr.reset (
            new Wolf {koord, direction, k}
        );
    } else if (type == "rabbit") {
        ptr.reset (
            new Rabbit {koord, direction, k}
        );
    } else {
        throw runtime_error (
            "не существует класса производного от Animal с type = " + type
        );
    }

    return ptr;
}
 
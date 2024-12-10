#include "rabbit.h"

Rabbit::Rabbit (Koord koord, Direction d, size_t k) noexcept
    : Victim (koord, d, k)
{}


size_t Rabbit::max_age() const noexcept {
    return 10;
}


Rabbit* Rabbit::new_animal() {
    return new Rabbit {koord, direction, k};
}
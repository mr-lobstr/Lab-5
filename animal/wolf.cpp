#include "wolf.h"

Wolf::Wolf (Koord koord, Direction d, size_t k) noexcept
    : Predator (koord, d, k)
{}


size_t Wolf::max_age() const noexcept {
    return 15;
}


Wolf* Wolf::new_animal() {
    return new Wolf {koord, direction, k};
}
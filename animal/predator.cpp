#include "predator.h"
#include "victim.h"

Predator::Predator (Koord krd, Direction d, size_t k) noexcept
    : Animal (krd, d, k)
{}


void Predator::movement (Field const& field) {
    move_to (field, 2);
}


size_t rnd (size_t, size_t);

void Predator::eating (Animals& all) {
    for (auto& ptr : all) {
        auto& other = *ptr;

        if (this == &other or other.position() != position() or not other.is_alive()) {
            continue;
        }

        if (other.is<Victim>()) {
            other.death();
            ++satiety;
        }
        
        if (other.is<Predator>() and rnd(0, 10000) % 2) {
            other.death(); 
        }       
    }
}


void Predator::reproduction (Animals& all) {
    while (satiety >= 2) {
        all.emplace_back (new_animal());
        satiety -= 2;
    }
}
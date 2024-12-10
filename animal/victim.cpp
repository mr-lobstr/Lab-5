#include "predator.h"
#include "victim.h"

Victim::Victim (Koord krd, Direction d, size_t k) noexcept
    : Animal (krd, d, k)
{}


void Victim::movement (Field const& field) {
    move_to (field, 1);
}


void Victim::eating (Animals& animals) {}


void Victim::reproduction (Animals& animals) {
    if (age() == 5 or age() == 10) {
        animals.emplace_back (new_animal());
    }
}
#include "animal.h"

Animal::Animal (Koord koord_, Direction d, std::size_t k_) noexcept
    : koord (koord_)
    , direction (d)
    , k (k_)
{}


bool Animal::is_alive() const noexcept {
    return imAlive;
}


Koord Animal::position() const noexcept {
    return koord;
}


size_t Animal::age() const noexcept {
    return age_;
}


void Animal::aging() {
    ++age_;
}


void Animal::death() {
    imAlive = false;
}


void Animal::move_to (Field const& field, size_t dist) {
    auto& [x, y] = koord;

    switch (direction)
    {
    case Direction::up:
        dist %= field.height;
        y = (field.height + y - dist) % field.height;
        break;
    
    case Direction::down:
        y = (y + dist) % field.height;
        break;

    case Direction::left:
        dist %= field.width;
        x = (field.width + x - dist) % field.width;
        break;
    
    case Direction::right:
        x = (x + dist) % field.width;
        break;
    }

    if ((age_ + 1) % k == 0) {
        auto d = static_cast<int> (direction);
        d = (d + 1) % 4;
        direction = static_cast<Direction> (d);
    }
}
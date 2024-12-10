#ifndef WOLF_H_GUARD
#define WOLF_H_GUARD

#include "predator.h"

class Wolf: public Predator {
public:
    Wolf (Koord, Direction, std::size_t) noexcept;

    size_t max_age() const noexcept override;

private:
    Wolf* new_animal() override;
};

#endif
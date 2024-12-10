#ifndef RABBIT_H_GUARD
#define RABBIT_H_GUARD

#include "victim.h"

class Rabbit: public Victim {
public:
    Rabbit (Koord, Direction, std::size_t) noexcept;

    size_t max_age() const noexcept override;

private:
    Rabbit* new_animal() override;
};

#endif
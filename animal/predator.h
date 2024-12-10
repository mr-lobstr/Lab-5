#ifndef PREDATOR_H_GUARD
#define PREDATOR_H_GUARD

#include "animal.h"

class Predator: public Animal {
public:
    Predator (Koord, Direction, std::size_t) noexcept;

    void movement (Field const&) override;
    void eating (Animals&) override;
    void reproduction (Animals&) override;

protected:
    std::size_t satiety = 0;
};

#endif
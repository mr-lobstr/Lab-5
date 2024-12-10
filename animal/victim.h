#ifndef VICTIM_H_GUARD
#define VICTIM_H_GUARD

#include "animal.h"

class Victim: public Animal {
public:
    Victim (Koord, Direction, std::size_t) noexcept;
    
    void movement (Field const&) override;
    void eating (Animals&) override;
    void reproduction (Animals&) override;
};

#endif
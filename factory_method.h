#ifndef ANIMAL_FACTORY_METHOD_H_GUARD
#define ANIMAL_FACTORY_METHOD_H_GUARD

#include <string>
#include "./animal/animal.h"

std::unique_ptr<Animal>
animal_factory_method (std::string const&, Koord, int, std::size_t);

#endif
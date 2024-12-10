#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include "factory_method.h"
#include "./animal/predator.h"
#include "./animal/victim.h"
using namespace std;

size_t rnd (size_t, size_t);

unique_ptr<Animal> rand_animal (Field field) {
    size_t x = rnd (0, 10000) % field.width;
    size_t y = rnd (0, 10000) % field.height;
    int d = rnd (0, 10000) % 4;
    size_t k = rnd (0, 10000) % 100;

    string types[] = {"rabbit", "woolf"};
    auto type = types[rnd (0, 10000) % size(types)];

    return animal_factory_method (type, {x, y}, d, k);
}


void clear (Animals& animals) {
    auto it = remove_if (animals.begin(), animals.end(), [] (auto& aPtr) {
        return not aPtr->is_alive();
    });

    animals.erase (it, animals.end());
}

void live (Animals& animals, Field field) {
    for (auto& aPtr : animals) {
        aPtr->movement(field);
    }

    for (auto& aPtr : animals) {
        aPtr->eating (animals);
    }

    clear (animals);

    for (auto& aPtr : animals) {
        aPtr->aging();
    }

    for (size_t i = 0; i < animals.size(); ++i) {
        auto& animal = *animals[i];
        animal.reproduction (animals);

        if (animal.age() == animal.max_age()) {
            animal.death();
        }
    }

    clear (animals);
}

auto output (Animals const& animals, size_t w, size_t h) {
    vector<vector<int>> out (w, vector<int> (h, 0));

    for (auto& aPtr : animals) {
        auto [x, y] = aPtr->position();
        
        if (aPtr->is<Predator>()) {
            --out[x][y];
        } else {
            ++out[x][y];
        }
    }

    string str;

    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            auto n = out[x][y];
            str += (n == 0 ? " * "s : (stringstream{} << setw(3) << n).str());
        }
        str += '\n';
    }

    return str;
}


int main()
{
    size_t N, M, T;
    size_t R, W;
    cin >> N >> M >> T >> R >> W;

    Animals animals;

    for (size_t i = 0; i < R + W; ++i) {
        size_t x, y, d, k;
        cin >> x >> y >> d >> k;

        auto type = (i < R ? "rabbit" : "woolf");

        animals.push_back (animal_factory_method (type, {x, y}, d, k));
    }

    for (size_t i = 0; i < T; ++i) {
        // cout << i << ")\n" << output (animals, N, M) << endl;
        live (animals, {N, M});
    }

    cout << T << ")\n" << output (animals, N, M) << endl;
}
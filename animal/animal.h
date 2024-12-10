#ifndef ANIMAL_H_GUARD
#define ANIMAL_H_GUARD

#include <cstdint>
#include <vector>
#include <memory>


enum class Direction {
    up,
    right,
    down,
    left
};


struct Field {
    std::size_t width;
    std::size_t height;
};


class Animal;
using Animals = std::vector<std::unique_ptr<Animal>>;
using Koord = std::pair<std::size_t, std::size_t>;


class Animal {
public:
    Animal (Koord, Direction, std::size_t) noexcept;
    virtual ~Animal() noexcept = default;

    bool is_alive() const noexcept;
    Koord position() const noexcept;
    std::size_t age() const noexcept;
    
    void aging();
    void death();

    template <class T>
    bool is() const noexcept {
        return dynamic_cast<T const*> (this) != nullptr;
    }

public:
    virtual void movement (Field const&) = 0;
    virtual void eating (Animals&) = 0;
    virtual void reproduction (Animals&) = 0;
    virtual std::size_t max_age() const noexcept = 0;

protected:
    void move_to (Field const&, std::size_t);
    
    virtual Animal* new_animal() = 0;
    
protected:
    Koord koord;
    Direction direction;
    std::size_t k;

private:
    bool imAlive = true;
    std::size_t age_ = 0;
};

#endif
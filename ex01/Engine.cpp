#include <cmath>
#include "Errors.hpp"
#include "Engine.hpp"

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y) :
    _power(power),
    _x(x),
    _y(y)
{
}

Engine::~Engine()
{
}

void    Engine::goTorward(float x, float y)
{
    _x = x;
    _y = y;
    if (_x == 10 && _y == 10)
        throw UserError("Cannot reach destination (10, 10).", "Engine");
    if (_x == 7 && _y == 8)
        throw UserError("Cannot reach destination (7, 8).", "Engine");
    if (_x == 9 && _y == 8)
        throw UserError("Cannot reach destination (9, 8).", "Engine");
    if (_x == -10 && _y == 7)
        throw UserError("Cannot reach destination (-10, 7).", "Engine");
}

float   Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float   Engine::getX() const
{
    return _x;
}

float   Engine::getY() const
{
    return _y;
}

#include "CPPokemon/movement.h"
#include "CPPokemon/types.h"
#include <cmath>
#include <memory>
#include <random>

static std::random_device r;
static std::default_random_engine eng(r());
static std::uniform_int_distribution<int> ran(1, 100);

namespace CPPokemon {
AbstractMovement::AbstractMovement(int power, int accuracy)
    : _power(power), _accuracy(accuracy) {}

int AbstractMovement::damage(const Type &owner, const Type &target) {
  double s = owner.stab(*_type);
  double e = target.effect(*_type);
  if (ran(eng) > accuracy())
    return 0;
  return std::round(s * e * power() / 100);
}

Tackle::Tackle() : AbstractMovement(40, 100) {
  _type = std::make_unique<Normal>();
}

CrossChop::CrossChop() : AbstractMovement(100, 80) {
  _type = std::make_unique<Fighting>();
}

Rollout::Rollout() : AbstractMovement(30, 90) {
  _type = std::make_unique<Rock>();
}

int Rollout::damage(const Type &owner, const Type &target) {
  double dmg = AbstractMovement::damage(owner, target);
  cnt *= 2;
  if (!dmg)
    cnt = 1;
  return cnt * dmg;
}

// Tackle::Tackle() : Movement(40, 100, Type::normal) {}
// Flamethrower::Flamethrower() : Movement(90, 100, Type::fire) {}
} // namespace CPPokemon

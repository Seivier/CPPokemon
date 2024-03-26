#include "CPPokemon/movement.h"
#include "CPPokemon/types.h"
#include "CPPokemon/util/pkm.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <ostream>
#include <random>

static std::random_device r;
static std::default_random_engine eng(r());
static std::uniform_int_distribution<int> ran(1, 100);

namespace CPPokemon {
AbstractMovement::AbstractMovement(int power, int accuracy)
    : _power(power), _accuracy(accuracy) {}

int AbstractMovement::damage(const Type &owner, const Type &target, int chances) {
  double s = owner.stab(*_type);
  double e = target.effect(*_type);
  if (chances > accuracy()) {
    std::cout << "Miss!" << std::endl;
    return 0;
  }
  return std::round(s * e * power() / 5);
}

Tackle::Tackle() : AbstractMovement(40, 100) {
  _type = std::make_unique<Normal>();
}

CrossChop::CrossChop() : AbstractMovement(100, 80) {
  _type = std::make_unique<Fighting>();
}

Rollout::Rollout() : AbstractMovement(30, 90) {
  _type = std::make_unique<Rock>();
  cnt = 1;
}

int Rollout::damage(const Type &owner, const Type &target, int chance) {
  double dmg = AbstractMovement::damage(owner, target, chance);
  if (!dmg) {
    cnt = 1;
    return 0;
  }
  dmg *= cnt;
  cnt *= 2;
  return dmg;
}

std::ostream& operator<<(std::ostream& os, const Pokemon& pok) {
  os << pok.name() << ": " << pok.hp() << "/" << pok.maxHp();
  return os;
}
// Tackle::Tackle() : Movement(40, 100, Type::normal) {}
// Flamethrower::Flamethrower() : Movement(90, 100, Type::fire) {}
} // namespace CPPokemon

#pragma once
#include "CPPokemon/util/mov.h"
#include "CPPokemon/util/types.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>

namespace CPPokemon {

class Pokemon {
public:
  virtual const std::string &name() = 0;
  virtual Type type() = 0;
  inline const std::vector<Movement> movements() { return _mov; }
  inline int attack() { return _attack; }
  inline int defense() { return _defense; }
  void doAttack(Pokemon &target, int mov_id);
  int hp;

private:
  int _maxHp;
  int _attack;
  int _defense;
  std::vector<Movement> _mov;
};

} // namespace CPPokemon

#pragma once
#include "CPPokemon/util/mov.h"
#include "CPPokemon/util/typ.h"
#include <cstddef>

namespace CPPokemon {

struct Pokemon {
  virtual void speak() const = 0;
  virtual int hp() const = 0;
  virtual int maxHp() const = 0;
  virtual const Type& type() const = 0;
  virtual const Movement& operator[](std::size_t idx) const = 0;
  virtual void doAttack(Pokemon& target, Movement& mov) = 0;
};



} // namespace CPPokemon

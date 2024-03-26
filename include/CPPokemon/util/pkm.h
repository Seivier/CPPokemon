#pragma once
#include "CPPokemon/util/mov.h"
#include "CPPokemon/util/typ.h"
#include <cstddef>
#include <ostream>
#include <string>

namespace CPPokemon {

struct Pokemon {
  virtual void speak() const = 0;
  virtual const std::string& name() const = 0;
  virtual int hp() const = 0;
  virtual int maxHp() const = 0;
  virtual const Type& type() const = 0;
  virtual Movement& operator[](std::size_t idx) const = 0;
  virtual void doAttack(Pokemon& target, Movement& mov) = 0;
  virtual void damage(int amount) = 0;
};

std::ostream& operator<<(std::ostream& os, const Pokemon& pok);



} // namespace CPPokemon

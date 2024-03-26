#pragma once
#include "CPPokemon/util/typ.h"

namespace CPPokemon {
struct Movement {
  virtual int power() const = 0;
  virtual int accuracy() const = 0;
  virtual const Type& type() const = 0;
  virtual int damage(const Type& owner, const Type& target) = 0;
};
} // namespace CPPokemon

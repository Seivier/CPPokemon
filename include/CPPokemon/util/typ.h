#pragma once

namespace CPPokemon {
struct Type {
  virtual double stab(const Type&) const = 0;
  virtual double effect(const Type&) const = 0;

  // DD
  virtual double stabFighting() const = 0;
  virtual double stabRock() const = 0;
  virtual double stabNormal() const = 0;

  virtual double effectFighting() const = 0;
  virtual double effectRock() const = 0;
  virtual double effectNormal() const = 0;
};


} // namespace CPPokemon

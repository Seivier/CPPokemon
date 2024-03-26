#pragma once

#include "CPPokemon/util/mov.h"
#include <memory>

namespace CPPokemon {

class AbstractMovement : public Movement {
public:
  AbstractMovement() = delete;
  void operator=(const AbstractMovement &) = delete;
  inline int power() const override { return _power; };
  inline int accuracy() const override { return _accuracy; };
  inline const Type &type() const override { return *_type; };
  int damage(const Type &, const Type &) override;

protected:
  AbstractMovement(int power, int accuracy);
  std::unique_ptr<Type> _type;

private:
  int _power;
  int _accuracy;
};

class Tackle : public AbstractMovement {
public:
  Tackle();
};
class CrossChop : public AbstractMovement {
public:
  CrossChop();
};
class Rollout : public AbstractMovement {
public:
  Rollout();
  int damage(const Type &, const Type &) override;

private:
  int cnt;
};
} // namespace CPPokemon

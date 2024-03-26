#pragma once
#include "CPPokemon/util/typ.h"

namespace CPPokemon {
class AbstractType : public Type {
public:
  inline double stabFighting() const override { return BASIC; }
  inline double stabRock() const override { return BASIC; }
  inline double stabNormal() const override { return BASIC; }

  inline double effectFighting() const override { return BASIC; }
  inline double effectRock() const override { return BASIC; }
  inline double effectNormal() const override { return BASIC; }

protected:
  static constexpr double BASIC = 1.f; 
  static constexpr double BOOST = 1.5f;
  static constexpr double NO_EFFECT = 0.f;
  static constexpr double INEFFECTIVE = 0.5f;
  static constexpr double SUPEREFFECTIVE = 2.f;
};

class Normal : public AbstractType {
  inline double stab(const Type &t) const override { return t.stabNormal(); };
  inline double effect(const Type &t) const override { return t.effectNormal(); };

  inline double stabNormal() const override { return BOOST; }

  inline double effectFighting() const override { return SUPEREFFECTIVE; }
};
class Rock : public AbstractType {
  inline double stab(const Type &t) const override { return t.stabRock(); };
  inline double effect(const Type &t) const override { return t.effectRock(); };

  inline double stabRock() const override { return BOOST; }
  
  inline double effectNormal() const override { return INEFFECTIVE; }
  inline double effectFighting() const override { return SUPEREFFECTIVE; }
};
class Fighting : public AbstractType {
  inline double stab(const Type &t) const override { return t.stabFighting(); };
  inline double effect(const Type &t) const override { return t.effectFighting(); };

  inline double stabFighting() const override { return BOOST; }
};
} // namespace CPPokemon

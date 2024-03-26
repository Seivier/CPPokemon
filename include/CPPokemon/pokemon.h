#pragma once

#include "CPPokemon/util/mov.h"
#include "CPPokemon/util/pkm.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <random>

namespace CPPokemon {

class AbstractPokemon : public Pokemon {
public:
  void doAttack(Pokemon &, Movement &) override;
  inline void damage(int amount) override { _hp = std::max(_hp - amount, 0);};
  inline const std::string& name() const override { return _name;}
  inline int hp() const override { return _hp; };
  inline int maxHp() const override { return _maxHp; };
  inline const Type &type() const override { return *_type; };
  inline Movement& operator[](const std::size_t idx) const override { return *_movs.at(idx); };
  

protected:
  AbstractPokemon(const std::string &name, int hp);
  inline int chance() { return _dist(_eng);};
  std::vector<std::unique_ptr<Movement>> _movs;
  std::unique_ptr<Type> _type;

  std::random_device _rd;
  std::default_random_engine _eng;
  std::uniform_int_distribution<int> _dist;

private:
  int _hp;
  int _maxHp;
  std::string _name;
};

class Bidoof : public AbstractPokemon {
public:
  void speak() const override;
  Bidoof();
  Bidoof(unsigned long seed);
  ~Bidoof() = default;
};
class Mankey : public AbstractPokemon {
public:
  void speak() const override;
  Mankey();
  Mankey(unsigned long seed);
  ~Mankey() = default;
};
} // namespace CPPokemon

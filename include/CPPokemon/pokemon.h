#pragma once

#include "CPPokemon/util/mov.h"
#include "CPPokemon/util/pkm.h"
#include <memory>
#include <string>
#include <vector>

namespace CPPokemon {

class AbstractPokemon : public Pokemon {
public:
  void doAttack(Pokemon &, Movement &) override;
  inline int hp() const override { return _hp; };
  inline int maxHp() const override { return _maxHp; };
  inline const Type &type() const override { return *_type; };
  inline const Movement& operator[](const std::size_t idx) const override { return *_movs.at(idx); };

protected:
  AbstractPokemon(const std::string &name, int hp);
  std::vector<std::unique_ptr<Movement>> _movs;
  std::unique_ptr<Type> _type;

private:
  int _hp;
  int _maxHp;
  std::string _name;
};

class Bidoof : public AbstractPokemon {
public:
  void speak() const override;
  Bidoof();
  ~Bidoof() = default;
};
class Mankey : public AbstractPokemon {
public:
  void speak() const override;
  Mankey();
  ~Mankey() = default;
};
} // namespace CPPokemon

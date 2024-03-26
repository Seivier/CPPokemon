#include "CPPokemon/pokemon.h"
#include "CPPokemon/movement.h"
#include "CPPokemon/types.h"
#include "CPPokemon/util/mov.h"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

namespace CPPokemon {

void AbstractPokemon::doAttack(Pokemon &target, Movement &mov) {
  int c = chance();
  int d = mov.damage(type(), target.type(), c);
  target.damage(d);
}

AbstractPokemon::AbstractPokemon(const std::string &name, int hp)
    : _name(name), _maxHp(hp), _hp(hp), _dist(std::uniform_int_distribution<int>(1, 100)) {}

Bidoof::Bidoof() : AbstractPokemon("Bidoof", 60) {
  _type = std::make_unique<Normal>();
  _movs.push_back(std::make_unique<Tackle>());
  _movs.push_back(std::make_unique<Rollout>());
}
Bidoof::Bidoof(unsigned long seed): Bidoof::Bidoof() {
  _eng.seed(seed);
}

void Bidoof::speak() const {
  std::cout << "Bidoooooof!" << std::endl;
}

Mankey::Mankey() : AbstractPokemon("Mankey", 100) {
  _type = std::make_unique<Fighting>();
  _movs.push_back(std::make_unique<CrossChop>());
}

Mankey::Mankey(unsigned long seed): Mankey::Mankey() {
  _eng.seed(seed);
}

void Mankey::speak() const {
  std::cout << "Mankey." << std::endl;
}


} // namespace CPPokemon

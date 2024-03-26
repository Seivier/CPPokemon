#include "CPPokemon/pokemon.h"
#include "CPPokemon/movement.h"
#include "CPPokemon/types.h"
#include "CPPokemon/util/mov.h"
#include <iostream>
#include <memory>
#include <string>

namespace CPPokemon {

void AbstractPokemon::doAttack(Pokemon &target, Movement &mov) {
  int d = mov.damage(type(), target.type());
  _hp = std::max(_hp - d, 0);
}

AbstractPokemon::AbstractPokemon(const std::string &name, int hp)
    : _name(name), _maxHp(hp), _hp(hp) {}

Bidoof::Bidoof() : AbstractPokemon("Bidoof", 60) {
  _type = std::make_unique<Normal>();
  _movs.push_back(std::make_unique<Tackle>());
  _movs.push_back(std::make_unique<Rollout>());
}

void Bidoof::speak() const {
  std::cout << "Bidoooooof!" << std::endl;
}

Mankey::Mankey() : AbstractPokemon("Mankey", 100) {
  _type = std::make_unique<Fighting>();
  _movs.push_back(std::make_unique<CrossChop>());
}

void Mankey::speak() const {
  std::cout << "Mankey." << std::endl;
}


} // namespace CPPokemon

#include "CPPokemon/pokemon.h"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  CPPokemon::Bidoof sergio;
  CPPokemon::Mankey alberto;

  sergio.speak();
  alberto.speak();
  sergio.doAttack(alberto, sergio[0]);

  std::cout << sergio << std::endl << alberto << std::endl;
  return 0;
}

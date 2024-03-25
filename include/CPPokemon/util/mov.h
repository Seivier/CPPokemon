#pragma once
#include "CPPokemon/util/types.h"

namespace CPPokemon {
  class Movement {
  public:
    virtual Type type();
    int power();
    int accuracy();
  };
}

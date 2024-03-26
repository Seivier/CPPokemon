#include "gtest/gtest.h"
#include "CPPokemon/pokemon.h"
namespace CPPokemon {

TEST(CPPokemonTest, PokemonName) {
  Bidoof sergio;
  ASSERT_EQ(sergio.name(), "Bidoof");
}

TEST(CPPokemonTest, PokemonAttack) {
  Bidoof b(0);
  Mankey m(0);
  m.doAttack(b, m[0]);
  EXPECT_EQ(b.hp(), 30) << "Expected 30 vs. " << b.hp();
}

TEST(CPPokemonTest, PokemonKill) {
  Bidoof b(0);
  Mankey m(0);
  int baseDmg = 12;
  b.doAttack(m, b[1]);
  EXPECT_EQ(m.hp(), m.maxHp() - baseDmg);
  b.doAttack(m, b[1]);
  EXPECT_EQ(m.hp(), m.maxHp() - 3*baseDmg);
  b.doAttack(m, b[1]);
  EXPECT_EQ(m.hp(), m.maxHp() - 7*baseDmg);
}
}


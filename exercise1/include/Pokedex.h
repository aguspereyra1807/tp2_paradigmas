#pragma once

#include <unordered_map>
#include <string>

#include "Pokemon.h"
#include "PokemonInfo.h"

using namespace std;

using u_map_P_PI = unordered_map<Pokemon, PokemonInfo>;

class Pokedex {
    private:
        u_map_P_PI data;
    public:
        Pokedex();
        Pokedex(u_map_P_PI _data);
        ~Pokedex() = default;

        void addPokemon(Pokemon pokemon, PokemonInfo pokemonInfo);

        void showAll() const;
        void show(const Pokemon& pokemon) const;
};
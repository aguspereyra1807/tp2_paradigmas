#pragma once

#include "Pokemon.h"
#include "PokemonInfo.h"
#include <limits>

using u_map_P_PI = std::unordered_map<Pokemon, PokemonInfo>;

class Pokedex {
    private:
        u_map_P_PI data;
        std::string file = "pokedex";
    public:
        Pokedex();
        Pokedex(u_map_P_PI _data);
        Pokedex(const std::string& _file);
        ~Pokedex() = default;

        bool empty() const; 

        void addPokemon(const Pokemon& pokemon, const PokemonInfo& pokemonInfo);

        void showAll() const;
        void show(const Pokemon& pokemon) const;

        void loadFile(const std::string& _file = "pokedex");
        void save() const;
        void saveAs(const std::string& newFile);
};
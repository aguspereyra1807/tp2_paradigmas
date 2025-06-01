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
        string file = "pokedex.bin";
    public:
        Pokedex();
        Pokedex(u_map_P_PI _data);
        Pokedex(const string& _file);
        ~Pokedex() = default;

        bool empty() const; 

        void addPokemon(Pokemon pokemon, PokemonInfo pokemonInfo);

        void showAll() const;
        void show(const Pokemon& pokemon) const;

        void loadFile(const string& _file);
        void save() const;
        void saveAs(const string& newFile);
};
#include <unordered_map>
#include <string>

#include "Pokemon.h"
#include "PokemonInfo.h"

using namespace std;

class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo> data;

        Pokemon searchPokemon(const Pokemon& pokemon) const;
    public:
        Pokedex();
        Pokedex(unordered_map<Pokemon, PokemonInfo> _data);
        ~Pokedex() = default;

        void addPokemon(Pokemon pokemon, PokemonInfo pokemonInfo);

        void showAll() const;
        void show(const Pokemon& pokemon) const;
};
#include "../include/Pokedex.h"

#include <iostream>

using namespace std;

Pokedex::Pokedex() : data({}) {}

Pokedex::Pokedex(u_map_P_PI _data) : data(_data) {}

void Pokedex::addPokemon(Pokemon pokemon, PokemonInfo pokemonInfo) {
    data.insert(pair(pokemon, pokemonInfo));
}

void Pokedex::showAll() const {
    int index = 1;
    for(const auto& [pokemon, pokemonInfo] : data) {
        cout << index << ". " << pokemon << endl << pokemonInfo << endl;
        index++;
    }
}

void Pokedex::show(const Pokemon& pokemon) const {
    cout << "Buscando " << pokemon << " en Pokedex..." << endl;

    auto it = data.find(pokemon);

    if (it != data.end()) {
        cout << it->first << endl << endl << it->second << endl;
    } else {
        cout << "¡Pokemon desconocido!" << endl;
    }
}
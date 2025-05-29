#include "../include/PokemonInfo.h"

#include <unordered_map>
#include <iostream>

PokemonInfo::PokemonInfo(const string& _type, const string& _description, const u_map_str_dmg _attacksByLevel, const vector<experience_t> _nextLevelExperience) : type(_type), description(_description), attacksByLevel(_attacksByLevel), nextLevelExperience(_nextLevelExperience) {}

string PokemonInfo::getType() const {return type;}

string PokemonInfo::getDescription() const {return description;}

u_map_str_dmg PokemonInfo::getAttacksByLevel() const {return attacksByLevel;}

vector<experience_t> PokemonInfo::getNextLevelExperience() const {return nextLevelExperience;}

ostream& operator<<(ostream& os, const PokemonInfo& pokemonInfo) {
    os << "Tipo: " << pokemonInfo.getType() << endl
       << "Descripción: " << pokemonInfo.getDescription() << endl << endl
       << "Ataques según Nivel:" << endl;
    
    auto attacks = pokemonInfo.getAttacksByLevel();
    int index = 1;
    for (const auto& [attack, damage] : attacks) {
        os << "Nivel " << index << ": " << attack << " (Daño: " << damage << ")." << endl;
        index++;
    }
    
    os << endl << "Niveles según Experiencia:" << endl
       << "Nivel 1: " << pokemonInfo.getNextLevelExperience()[0] << " Experiencia." << endl
       << "Nivel 2: " << pokemonInfo.getNextLevelExperience()[1] << " Experiencia." << endl
       << "Nivel 3: " << pokemonInfo.getNextLevelExperience()[2] << " Experiencia." << endl;

    return os;
}
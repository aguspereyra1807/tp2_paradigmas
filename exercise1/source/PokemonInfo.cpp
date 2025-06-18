#include "../include/PokemonInfo.h"

using namespace std;

PokemonInfo::PokemonInfo():
    type("Estándar"),
    description("Breve descripción..."),
    attacksByLevel({{"Ataque 1", 2}, {"Ataque 2", 4}, {"Ataque 3", 8}}),
    nextLevelExperience({0, 500, 1250}) {}

PokemonInfo::PokemonInfo(const string& _type, const string& _description, const u_map_str_dmg& _attacksByLevel, const vector<experience_t>& _nextLevelExperience): type(_type), description(_description), attacksByLevel(_attacksByLevel), nextLevelExperience(_nextLevelExperience) {}

const string& PokemonInfo::getType() const {return type;}

const string& PokemonInfo::getDescription() const {return description;}

const u_map_str_dmg& PokemonInfo::getAttacksByLevel() const {return attacksByLevel;}

const vector<experience_t>& PokemonInfo::getNextLevelExperience() const {return nextLevelExperience;}

void PokemonInfo::serialize(ofstream& out) const {
    size_t len;
    
    len = type.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(type.data(), len);

    len = description.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(description.data(), len);
    
    size_t mapSize = attacksByLevel.size();
    out.write(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));

    for (const auto& [atk, dmg] : attacksByLevel) {
        size_t atkLen = atk.size();
        out.write(reinterpret_cast<char*>(&atkLen), sizeof(atkLen));
        out.write(atk.data(), atkLen);

        damage_t dmgCopy = dmg;
        out.write(reinterpret_cast<char*>(&dmgCopy), sizeof(dmgCopy));
    }

    size_t vecSize = nextLevelExperience.size();
    out.write(reinterpret_cast<char*>(&vecSize), sizeof(vecSize));

    for (experience_t e : nextLevelExperience) {
        out.write(reinterpret_cast<char*>(&e), sizeof(e));
    }
}

void PokemonInfo::deserialize(ifstream& in) {
    size_t len;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    type.resize(len);
    in.read(&type[0], len);
    
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    description.resize(len);
    in.read(&description[0], len);
    
    size_t mapSize;
    in.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));
    attacksByLevel.clear();

    for (size_t i = 0; i < mapSize; ++i) {
        size_t atkLen; in.read(reinterpret_cast<char*>(&atkLen), sizeof(atkLen));
        string atk; atk.resize(atkLen);
        in.read(&atk[0], atkLen);

        damage_t dmg; in.read(reinterpret_cast<char*>(&dmg), sizeof(dmg));
        attacksByLevel[atk] = dmg;
    }

    size_t vecSize;
    in.read(reinterpret_cast<char*>(&vecSize), sizeof(vecSize));
    nextLevelExperience.resize(vecSize);
    
    for (size_t i = 0; i < vecSize; ++i) {
        in.read(reinterpret_cast<char*>(&nextLevelExperience[i]), sizeof(experience_t));
    }
}

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
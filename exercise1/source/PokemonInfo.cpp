#include "../include/PokemonInfo.h"

using namespace std;

// Constructor por defecto, para ahorrar tiempo en las pruebas
PokemonInfo::PokemonInfo():
    type("Estándar"),
    description("Breve descripción..."),
    attacksByLevel{std::make_pair("Ataque 1", 2), std::make_pair("Ataque 2", 4), std::make_pair("Ataque 3", 8)},
    nextLevelExperience{0, 500, 1250} {}

PokemonInfo::PokemonInfo(const string& _type, const string& _description, const arr_str_dmg& _attacksByLevel, const std::array<experience_t, 3>& _nextLevelExperience): type(_type), description(_description), attacksByLevel(_attacksByLevel), nextLevelExperience(_nextLevelExperience) {}

const string& PokemonInfo::getType() const {return type;}

const string& PokemonInfo::getDescription() const {return description;}

const arr_str_dmg& PokemonInfo::getAttacksByLevel() const {return attacksByLevel;}

const std::array<experience_t, 3>& PokemonInfo::getNextLevelExperience() const {return nextLevelExperience;}

const experience_t& PokemonInfo::getNextLevelExperienceByIndex(const size_t i) const {return nextLevelExperience[i];}

void PokemonInfo::serialize(ofstream& out) const {
    size_t len;

    // Escribimos el largo del tipo, y luego los caracteres del tipo
    len = type.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(type.data(), len);

    // Escribimos el largo de la descripción, y luego sus caracteres
    len = description.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(description.data(), len);
    
    // Para arrays de tamaño fijo (3), no necesitamos escribir el tamaño
    // Ya que sabemos que siempre tendremos 3 elementos

    for (const auto& [atk, dmg] : attacksByLevel) {
        // Para cada ataque escribimos el largo del string, y luego sus caracteres
        size_t atkLen = atk.size();
        out.write(reinterpret_cast<const char*>(&atkLen), sizeof(atkLen));
        out.write(atk.data(), atkLen);

        // Escribimos el daño que causa el ataque
        out.write(reinterpret_cast<const char*>(&dmg), sizeof(dmg));
    }

    // Para arrays de tamaño fijo (3), no necesitamos escribir el tamaño
    // Ya que sabemos que siempre tendremos 3 elementos

    for (experience_t e : nextLevelExperience) {
        // Escribimos cada cantidad de experiencia para el próximo nivel
        out.write(reinterpret_cast<const char*>(&e), sizeof(e));
    }
}

void PokemonInfo::deserialize(ifstream& in) {
    size_t len;

    // Leemos el largo del tipo, y luego los caracteres del tipo
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    type.resize(len);
    in.read(&type[0], len);
    
    // Leemos el largo de la descripción, y luego sus caracteres
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    description.resize(len);
    in.read(&description[0], len);
    
    // Para un array fijo de tamaño 3, sabemos exactamente cuántos elementos leer
    // Ya no leemos el tamaño ya que sabemos que siempre son 3
    for (size_t i = 0; i < 3; ++i) {
        // Para cada ataque leemos el largo del string
        size_t atkLen;
        in.read(reinterpret_cast<char*>(&atkLen), sizeof(atkLen));
        
        // Luego leemos el string
        string atk;
        atk.resize(atkLen);
        in.read(&atk[0], atkLen);

        // Leemos el daño del ataque
        damage_t dmg;
        in.read(reinterpret_cast<char*>(&dmg), sizeof(dmg));

        // Guardamos en el array el par de ("Ataque", Daño)
        attacksByLevel[i] = std::make_pair(atk, dmg);
    }
    
    // Para un array fijo de tamaño 3, sabemos exactamente cuántos elementos leer
    // Ya no leemos el tamaño ya que sabemos que siempre son 3
    for (size_t i = 0; i < 3; ++i) {
        // Leemos cada cantidad de experiencia para el próximo nivel
        in.read(reinterpret_cast<char*>(&nextLevelExperience[i]), sizeof(experience_t));
    }
}

// Permite imprimir rápidamente con formato
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
       << "Nivel 1: " << pokemonInfo.getNextLevelExperienceByIndex(0) << " Experiencia." << endl
       << "Nivel 2: " << pokemonInfo.getNextLevelExperienceByIndex(1) << " Experiencia." << endl
       << "Nivel 3: " << pokemonInfo.getNextLevelExperienceByIndex(2) << " Experiencia." << endl;

    return os;
}
#include "../include/Pokemon.h"

using namespace std;

Pokemon::Pokemon(): name(), experience(0) {}

Pokemon::Pokemon(const string& _name): name(_name), experience(0) {}

Pokemon::Pokemon(const string& _name, const experience_t _experience): name(_name), experience(_experience) {}

const string& Pokemon::getName() const {return name;}

const experience_t& Pokemon::getExperience() const {return experience;}

void Pokemon::serialize(ofstream& out) const {
    // Escribimos el largo del nombre
    size_t len = name.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    // Escribimos el nombre en el archivo
    out.write(name.data(), len);

    // Escribimos la experiencia del pokemon
    out.write(reinterpret_cast<const char*>(&experience), sizeof(experience));
}

void Pokemon::deserialize(ifstream& in) {
    // Primero leemos el largo del nombre
    size_t len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));

    // Luego, cambiamos el tamaño del nombre y lo leemos
    name.resize(len);
    in.read(&name[0], len);

    // Leemos la experiencia del pokemon
    in.read(reinterpret_cast<char*>(&experience), sizeof(experience));
}

// Permite usar Pokemon como clave en un unordered_map
bool Pokemon::operator==(const Pokemon& other) const {return name == other.name;}

// Ayuda a imprimir rápidamente con formato
ostream& operator<<(ostream& os, const Pokemon& pokemon) {
    os << pokemon.getName() << " (Experiencia: " << pokemon.getExperience() << ")";
    return os;
}
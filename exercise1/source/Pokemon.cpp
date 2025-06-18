#include "../include/Pokemon.h"

using namespace std;

Pokemon::Pokemon(): name(), experience(0) {}

Pokemon::Pokemon(const string& _name): name(_name), experience(0) {}

Pokemon::Pokemon(const string& _name, const experience_t _experience): name(_name), experience(_experience) {}

string Pokemon::getName() const {return name;}

experience_t Pokemon::getExperience() const {return experience;}

void Pokemon::setExperience(const experience_t _experience) {experience = _experience;}

void Pokemon::serialize(ofstream& out) const {
    size_t len = name.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(name.data(), len);

    out.write(reinterpret_cast<const char*>(&experience), sizeof(experience));
}

void Pokemon::deserialize(ifstream& in) {
    size_t len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));

    name.resize(len);
    in.read(&name[0], len);

    in.read(reinterpret_cast<char*>(&experience), sizeof(experience));
}

bool Pokemon::operator==(const Pokemon& other) const {return name == other.name;}

ostream& operator<<(ostream& os, const Pokemon& pokemon) {
    os << pokemon.getName() << " (Experiencia: " << pokemon.getExperience() << ")";
    return os;
}
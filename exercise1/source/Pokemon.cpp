#include "../include/Pokemon.h"

#include <iostream>

using namespace std;

Pokemon::Pokemon(const string& _name) : name(_name), experience(0) {}

Pokemon::Pokemon(const string& _name, const experience_t _experience) : name(_name), experience(_experience) {}

string Pokemon::getName() const {return name;}

experience_t Pokemon::getExperience() const {return experience;}

void Pokemon::setExperience(const experience_t _experience) {experience = _experience;}

bool Pokemon::operator==(const Pokemon& other) const {return name == other.name;}

ostream& operator<<(ostream& os, const Pokemon& pokemon) {
    os << pokemon.getName() << " (Experiencia: " << pokemon.getExperience() << ")";
    return os;
}
#pragma once

#include <string>
#include <iostream>
#include <fstream>

typedef unsigned int experience_t;

class Pokemon {
    private:
        std::string name;
        experience_t experience;
    public:
        Pokemon();
        Pokemon(const std::string& _name);
        Pokemon(const std::string& _name, const experience_t _experience);
        ~Pokemon() = default;

        std::string getName() const;
        experience_t getExperience() const;

        void setExperience(const experience_t _experience);

        void serialize(std::ofstream& out) const;
        void deserialize(std::ifstream& in);

        bool operator==(const Pokemon& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon);
};

namespace std {
    template<>
    struct hash<Pokemon> {
        size_t operator() (const Pokemon& pokemon) const {
            return hash<string>()(pokemon.getName());
        }
    };
}
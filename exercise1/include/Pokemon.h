#pragma once

#include <string>

using namespace std;

typedef unsigned int experience_t;

class Pokemon {
    private:
        string name;
        experience_t experience;
    public:
        Pokemon();
        Pokemon(const string& _name);
        Pokemon(const string& _name, const experience_t _experience);
        ~Pokemon() = default;

        string getName() const;
        experience_t getExperience() const;

        void setExperience(const experience_t _experience);

        void serialize(ofstream& out) const;
        void deserialize(ifstream& in);

        bool operator==(const Pokemon& other) const;

        friend ostream& operator<<(ostream& os, const Pokemon& pokemon);
};

namespace std {
    template<>
    struct hash<Pokemon> {
        size_t operator() (const Pokemon& pokemon) const {
            return hash<string>()(pokemon.getName());
        }
    };
}
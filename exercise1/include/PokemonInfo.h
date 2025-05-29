#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

using experience_t = unsigned int;
using damage_t = unsigned int;
using u_map_str_dmg = unordered_map<string, damage_t>;

class PokemonInfo {
    private:
        const string type;
        const string description;
        const u_map_str_dmg attacksByLevel;
        const vector<experience_t> nextLevelExperience;
    public:
        PokemonInfo(const string& _type, const string& _description, const u_map_str_dmg _attacksByLevel, const vector<experience_t> _nextLevelExperience);
        ~PokemonInfo() = default;

        string getType() const;
        string getDescription() const;
        u_map_str_dmg getAttacksByLevel() const;
        vector<experience_t> getNextLevelExperience() const;

        friend ostream& operator<<(ostream& os, const PokemonInfo& pokemonInfo);
};

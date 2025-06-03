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
        string type;
        string description;
        u_map_str_dmg attacksByLevel;
        vector<experience_t> nextLevelExperience;
    public:
        PokemonInfo();
        PokemonInfo(const string& _type, const string& _description, const u_map_str_dmg& _attacksByLevel, const vector<experience_t>& _nextLevelExperience);
        ~PokemonInfo() = default;

        string getType() const;
        string getDescription() const;
        u_map_str_dmg getAttacksByLevel() const;
        vector<experience_t> getNextLevelExperience() const;

        void serialize(ofstream& out) const;
        void deserialize(ifstream& in);

        //!! Arreglar orden de mostrar los ataques
        friend ostream& operator<<(ostream& os, const PokemonInfo& pokemonInfo);
};

#pragma once

#include "Pokemon.h"
#include <vector>
#include <unordered_map>

using damage_t = unsigned int;
using u_map_str_dmg = std::unordered_map<std::string, damage_t>;

class PokemonInfo {
    private:
        std::string type;
        std::string description;
        u_map_str_dmg attacksByLevel;
        std::vector<experience_t> nextLevelExperience;
    public:
        PokemonInfo();
        PokemonInfo(const std::string& _type, const std::string& _description, const u_map_str_dmg& _attacksByLevel, const std::vector<experience_t>& _nextLevelExperience);
        ~PokemonInfo() = default;

        const std::string& getType() const;
        const std::string& getDescription() const;
        const u_map_str_dmg& getAttacksByLevel() const;
        const std::vector<experience_t>& getNextLevelExperience() const;

        void serialize(std::ofstream& out) const;
        void deserialize(std::ifstream& in);

        //!! Arreglar orden de mostrar los ataques
        friend std::ostream& operator<<(std::ostream& os, const PokemonInfo& pokemonInfo);
};

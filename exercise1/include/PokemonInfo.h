#pragma once

#include "Pokemon.h"
#include <array>
#include <unordered_map>

// Array de 3 pares de (strings, daño), donde el daño es un unsigned int
using damage_t = unsigned int;
using arr_str_dmg = std::array<std::pair<std::string, damage_t>, 3>;

class PokemonInfo {
    private:
        std::string type;
        std::string description;
        arr_str_dmg attacksByLevel;
        // Array de largo 3, que guarda experiencia (unsigned int)
        std::array<experience_t, 3> nextLevelExperience;
    public:
        PokemonInfo();
        PokemonInfo(const std::string& _type, const std::string& _description, const arr_str_dmg& _attacksByLevel, const std::array<experience_t, 3>& _nextLevelExperience);
        ~PokemonInfo() = default;

        // Getters básicos que mantienen la clase constante, (devuelven referencias constantes)
        const std::string& getType() const;
        const std::string& getDescription() const;
        const arr_str_dmg& getAttacksByLevel() const;
        const std::array<experience_t, 3>& getNextLevelExperience() const;
        const experience_t& getNextLevelExperienceByIndex(const size_t i) const;

        // Permite serializar y deserializar la inforamción del pokemon
        void serialize(std::ofstream& out) const;
        void deserialize(std::ifstream& in);

        // Se sobrecarga << para imprimir rápido y prolijo
        friend std::ostream& operator<<(std::ostream& os, const PokemonInfo& pokemonInfo);
};

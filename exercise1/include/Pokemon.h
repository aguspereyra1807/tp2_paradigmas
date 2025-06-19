#pragma once

#include <string>
#include <iostream>
#include <fstream>

// Tipo que se va a usar para la experiencia
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

        // Los getters mantienen la clase constante
        const std::string& getName() const;
        const experience_t& getExperience() const;

        // Funciones para serializar y deserializar el pokemon
        void serialize(std::ofstream& out) const;
        void deserialize(std::ifstream& in);

        // Permite utilizar .find() en un unordered_map<Pokemon, T>, utiliza solo el nombre para comparar
        bool operator==(const Pokemon& other) const;

        // Formato para imprimir el pokemon rápido y prolijo
        friend std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon);
};

// Template Specialization para el hash del unordered_map del Pokedex con objeto
// Pokemon como key
namespace std {
    template<>
    struct hash<Pokemon> {
        size_t operator() (const Pokemon& pokemon) const {
            // Uso solamente el nombre del pokemon para el hash
            return hash<string>()(pokemon.getName());
        }
    };
}
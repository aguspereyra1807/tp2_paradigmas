#pragma once

#include "Pokemon.h"
#include "PokemonInfo.h"
#include <limits>

// Tipo para guardar los pokemones como clave y su información como valor
using u_map_P_PI = std::unordered_map<Pokemon, PokemonInfo>;

class Pokedex {
    private:
        u_map_P_PI data;

        // Nombre de archivo donde voy a guardar la información del pokedex
        // Siempre está en la carpeta /data y es .bin
        std::string file = "pokedex";
    public:
        Pokedex();
        Pokedex(u_map_P_PI _data);
        Pokedex(const std::string& _file);
        ~Pokedex() = default;

        // Permite conocer rápidamente si el pokedex está vacía
        bool empty() const; 

        // Añade un pokemon con su información al pokedex
        void addPokemon(const Pokemon& pokemon, const PokemonInfo& pokemonInfo);

        // Métodos para mostrar todos los pokemones y solo uno, buscandoló con una instancia de pokemon
        void showAll() const;
        void show(const Pokemon& pokemon) const;

        // Método para cargar un pokedex desde un archivo
        void loadFile(const std::string& _file = "pokedex");

        // Métodos para guardar la información de un pokedex en un archivo
        void save() const;
        void saveAs(const std::string& newFile);
};
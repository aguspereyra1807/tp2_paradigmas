#include "../include/Pokemon.h"
#include "../include/PokemonInfo.h"
#include "../include/Pokedex.h"
#include <array>
#include <utility>

int main() {
    // Se crean los pokemones como se piden en el ejercicio
    Pokemon pokemon1("Squirtle", 100);
    arr_str_dmg ataques1{std::make_pair("Pistola Agua", 4), std::make_pair("Hidrobomba", 6), std::make_pair("Danza Lluvia", 5)};
    std::array<experience_t, 3> niveles1{0, 400, 1000};
    PokemonInfo pokemonInfo1("Agua", "Una tortuga pequeña que lanza chorros de agua.", ataques1, niveles1);

    Pokemon pokemon2("Bulbasaur", 270);
    arr_str_dmg ataques2{std::make_pair("Latigazo", 4), std::make_pair("Hoja Afilada", 6), std::make_pair("Rayo Solar", 5)};
    std::array<experience_t, 3> niveles2{0, 300, 1100};
    PokemonInfo pokemonInfo2("Planta", "Tiene una semilla en su lomo que crece con el tiempo.", ataques2, niveles2);

    Pokemon pokemon3("Charmander", 633);
    arr_str_dmg ataques3{std::make_pair("Ascuas", 4), std::make_pair("Lanzallamas", 6), std::make_pair("Giro Fuego", 5)};
    std::array<experience_t, 3> niveles3{0, 250, 1300};
    PokemonInfo pokemonInfo3("Fuego", "Una lagartija con una llama en su cola.", ataques3, niveles3);
    
    // Se añaden los pokemones al pokedex
    Pokedex pokedex;
    pokedex.addPokemon(pokemon1, pokemonInfo1);
    pokedex.addPokemon(pokemon2, pokemonInfo2);
    pokedex.addPokemon(pokemon3, pokemonInfo3);

    // Se muestran todos los pokemones añadidos al pokedex
    pokedex.showAll();
}
#include "../include/Pokemon.h"
#include "../include/PokemonInfo.h"
#include "../include/Pokedex.h"

int main() {
    Pokemon pokemon1("Squirtle", 870);
    PokemonInfo pokemonInfo1("Agua", "Una tortuga pequeña que lanza chorros de agua.",
        {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}}, {0, 400, 1000});

    Pokemon pokemon2("Bulbasaur", 270);
    PokemonInfo pokemonInfo2("Planta", "Tiene una semilla en su lomo que crece con el tiempo.",
        {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}}, {0, 300, 1100});

    Pokemon pokemon3("Charmander", 633);
    PokemonInfo pokemonInfo3("Fuego", "Una lagartija con una llama en su cola.",
        {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}}, {0, 250, 1300});
    
    Pokedex pokedex;
    pokedex.addPokemon(pokemon1, pokemonInfo1);
    pokedex.addPokemon(pokemon2, pokemonInfo2);
    pokedex.addPokemon(pokemon3, pokemonInfo3);

    pokedex.show(pokemon1);

    Pokemon pokemon4("Pikachu", 390);

    pokedex.show(pokemon4);
}
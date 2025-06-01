#include "../include/Pokedex.h"

#include <iostream>
#include <fstream>

using namespace std;

Pokedex::Pokedex(): data() {
    string load;
    cout << "¿Quiere cargar los datos guardados en el último pokedex? (s/n)" << endl;
    cin >> load;

    if (load == "s") {
        loadFile(file);
        cout << "Datos cargados correctamente." << endl;
    } else {
        cout << "Se creó el pokedex vacío." << endl;
    }
}

Pokedex::Pokedex(u_map_P_PI _data): data(_data) {
    cout << "Se creó un nuevo pokedex con los datos." << endl;
}

Pokedex::Pokedex(const string& _file): data(), file(_file) {
    loadFile(file);
    cout << "Se cargaron los datos del archivo correctamente." << endl;
}

bool Pokedex::empty() const {return data.empty();}

void Pokedex::addPokemon(Pokemon pokemon, PokemonInfo pokemonInfo) {
    data.insert(pair(pokemon, pokemonInfo));
}

void Pokedex::showAll() const {
    int index = 1;
    for(const auto& [pokemon, pokemonInfo] : data) {
        cout << index << ". " << pokemon << endl << pokemonInfo << endl;
        index++;
    }
}

void Pokedex::show(const Pokemon& pokemon) const {
    cout << "Buscando " << pokemon << " en Pokedex..." << endl;

    auto it = data.find(pokemon);

    if (it != data.end()) {
        cout << it->first << endl << endl << it->second << endl;
    } else {
        cout << "¡Pokemon desconocido!" << endl;
    }
}

void Pokedex::loadFile(const string& _file) {
    ifstream inFile(("data/" + _file), ios::binary);

    if (inFile.is_open()) {
        uint32_t n;
        inFile.read(reinterpret_cast<char*>(&n), sizeof(n));

        for (uint32_t i = 0; i < n; i++) {
            Pokemon pokemon;
            PokemonInfo pokemonInfo;

            pokemon.deserialize(inFile);
            pokemonInfo.deserialize(inFile);

            addPokemon(pokemon, pokemonInfo);
        }
    }
}

void Pokedex::save() const {
    ofstream outFile(("data/" + file), ios::binary);
    
    if (outFile.is_open()) {
        uint32_t n = data.size();
        outFile.write(reinterpret_cast<char*>(&n), sizeof(n));

        for (const auto& [pokemon, pokemonInfo] : data) {
            pokemon.serialize(outFile);
            pokemonInfo.serialize(outFile);
        }
        outFile.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    cout << "Se guardaron correctamente los datos en " << file <<  "." << endl;
}

void Pokedex::saveAs(const string& newFile) {
    file = "data/" + newFile;
    save();
}
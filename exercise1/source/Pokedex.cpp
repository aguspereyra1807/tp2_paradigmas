#include "../include/Pokedex.h"

using namespace std;

Pokedex::Pokedex(): data() {}

Pokedex::Pokedex(u_map_P_PI _data): data(_data) {
    cout << "Se creó un nuevo pokedex con los datos." << endl;
}

Pokedex::Pokedex(const string& _file): data(), file(_file) {
    loadFile(file);
    cout << "Se cargaron los datos del archivo correctamente." << endl;
}

bool Pokedex::empty() const {return data.empty();}

void Pokedex::addPokemon(const Pokemon& pokemon, const PokemonInfo& pokemonInfo) {
    data.insert(pair(pokemon, pokemonInfo));
}

void Pokedex::showAll() const {
    int index = 1;
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << index << ". " << it->first << endl << it->second << endl;
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
    ifstream inFile(("data/" + _file + ".bin"), ios::binary);

    if (inFile.is_open()) {
        size_t n;
        inFile.read(reinterpret_cast<char*>(&n), sizeof(n));

        for (size_t i = 0; i < n; i++) {
            Pokemon pokemon;
            PokemonInfo pokemonInfo;

            pokemon.deserialize(inFile);
            pokemonInfo.deserialize(inFile);

            addPokemon(pokemon, pokemonInfo);
        }
    }
}

void Pokedex::save() const {
    ofstream outFile(("data/" + file + ".bin"), ios::binary);
    
    if (outFile.is_open()) {
        size_t n = data.size();
        outFile.write(reinterpret_cast<char*>(&n), sizeof(n));

        for (const auto& [pokemon, pokemonInfo] : data) {
            pokemon.serialize(outFile);
            pokemonInfo.serialize(outFile);
        }
        outFile.close();
        cout << "Se guardaron correctamente los datos en '" << file <<  ".bin'." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void Pokedex::saveAs(const string& newFile) {
    file = newFile;
    save();
}
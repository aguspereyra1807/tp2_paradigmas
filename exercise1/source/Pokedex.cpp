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

    // Se recorre todo el unordered_map imprimiendo todos los pokemones con su inforamción
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << index << ". " << it->first << endl << it->second << endl;
        index++;
    }
}

void Pokedex::show(const Pokemon& pokemon) const {
    cout << "Buscando " << pokemon << " en Pokedex..." << endl;

    // Busca el pokemon gracias a la sobrecarga de ==, en el unordered_map
    auto it = data.find(pokemon);

    // Si el iterador no apunta al final, entonces lo muestra
    if (it != data.end()) {
        cout << it->first << endl << endl << it->second << endl;
    } else {
        cout << "¡Pokemon desconocido!" << endl;
    }
}

void Pokedex::loadFile(const string& _file) {
    // Leemos el archivo binario de la carpeta data/
    ifstream inFile(("data/" + _file + ".bin"), ios::binary);

    if (inFile.is_open()) {
        // Leemos la cantidad de pokemones que vamos a cargar
        size_t n;
        inFile.read(reinterpret_cast<char*>(&n), sizeof(n));

        // Deserializamos cada pokemon y lo agregamos al pokedex
        for (size_t i = 0; i < n; i++) {
            Pokemon pokemon;
            PokemonInfo pokemonInfo;

            pokemon.deserialize(inFile);
            pokemonInfo.deserialize(inFile);

            addPokemon(pokemon, pokemonInfo);
        }

        inFile.close();
        cout << "Se cargaron correctamente los datos desde '" << _file <<  ".bin'." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void Pokedex::save() const {
    // Creamos un archivo binario en la carpeta /data
    // Se abre en modo trunc, entonces sobreescribo todos los datos, sin dejar restos de los guardados anteriores
    ofstream outFile(("data/" + file + ".bin"), ios::binary);
    
    if (outFile.is_open()) {
        // Escribimos la cantidad de pokemones a guardar
        size_t n = data.size();
        outFile.write(reinterpret_cast<char*>(&n), sizeof(n));

        // Serializamos cada pokemon
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
    // Cambiamos el nombre del archivo donde se va a guardar la información
    file = newFile;
    save();
}
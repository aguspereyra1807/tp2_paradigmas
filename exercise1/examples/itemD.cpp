#include "../include/Pokemon.h"
#include "../include/PokemonInfo.h"
#include "../include/Pokedex.h"

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pressEnterToContinue() {
    cin.clear();
    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidIntInput() {
    int input;

    while (!(cin >> input)) {
        cout << "Entrada inválida. Por favor ingrese un número: ";
        clearInputBuffer();
    }

    cout << endl;
    clearInputBuffer();
    return input;
}

bool checkPokedexExists(Pokedex* pokedex) {
    if (pokedex == nullptr) {
        cout << "Primero debe crear una Pokedex (opción 1)." << endl;
        pressEnterToContinue();
        return false;
    } else {return true;}
}

Pokemon createPokemon() {
    string name;
    experience_t exp;
    
    cout << "Ingrese el nombre del Pokémon: ";
    getline(cin, name);
    
    cout << "Ingrese la experiencia del Pokémon: ";
    exp = getValidIntInput();
    
    return Pokemon(name, exp);
}

PokemonInfo createPokemonInfo() {
    string type, description;
    u_map_str_dmg attacks;
    vector<experience_t> expLevels(3);
    
    cout << "Ingrese el tipo del Pokémon: ";
    getline(cin, type);
    
    cout << "Ingrese la descripción del Pokémon: ";
    getline(cin, description);
    
    cout << "Ingrese 3 ataques y sus daños:" << endl;
    for (int i = 0; i < 3; i++) {
        string attackName;
        damage_t damage;
        
        cout << "Nombre del ataque " << (i+1) << ": ";
        getline(cin, attackName);
        
        cout << "Daño del ataque " << (i+1) << ": ";
        damage = getValidIntInput();
        
        attacks[attackName] = damage;
    }
    
    cout << "Ingrese la experiencia necesaria para el nivel 1: ";
    expLevels[0] = getValidIntInput();
    
    cout << "Ingrese la experiencia necesaria para el nivel 2: ";
    expLevels[1] = getValidIntInput();
    
    cout << "Ingrese la experiencia necesaria para el nivel 3: ";
    expLevels[2] = getValidIntInput();
    
    return PokemonInfo(type, description, attacks, expLevels);
}

void showMainMenu() {
    cout << "\n===== POKEDEX MENU =====" << endl;
    cout << "1. Crear una nueva Pokedex" << endl;
    cout << "2. Crear y agregar un Pokémon" << endl;
    cout << "3. Mostrar todos los Pokémon" << endl;
    cout << "4. Buscar un Pokémon" << endl;
    cout << "5. Guardar Pokedex" << endl;
    cout << "6. Guardar Pokedex como" << endl;
    cout << "7. Cargar Pokedex de un archivo" << endl;
    cout << "8. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    Pokedex* pokedex = nullptr;
    Pokemon* tempPokemon = nullptr;
    
    int choice = 0;
    bool exit = false;
    
    cout << "Bienvenido al sistema de prueba de Pokedex" << endl;
    
    while (!exit) {
        showMainMenu();
        choice = getValidIntInput();
        
        switch (choice) {
            case 1: {
                if (pokedex != nullptr) {delete pokedex;}

                pokedex = new Pokedex();
                cout << "Se ha creado una nueva Pokedex." << endl;
                
                string load;
                cout << "¿Quiere cargar los datos guardados en el último pokedex? (s/n)" << endl;
                cin >> load;

                if (load == "s") {
                    pokedex->loadFile();
                    cout << "Datos cargados correctamente." << endl;
                } else {
                    cout << "Se creó el pokedex vacío." << endl;
                }

                pressEnterToContinue();
                break;
            }
            case 2: {
                if (tempPokemon != nullptr) {delete tempPokemon;}
                
                if(!checkPokedexExists(pokedex)) {break;}
                
                tempPokemon = new Pokemon(createPokemon());
                cout << "Pokémon creado: " << *tempPokemon << endl;
                
                cout << "¿Desea detallar la información del Pokémon? (s/n): ";
                string detailChoice;
                cin >> detailChoice;
                clearInputBuffer();

                if (detailChoice == "n") {
                    PokemonInfo pokemonInfo;
                    pokedex->addPokemon(*tempPokemon, pokemonInfo);
                    cout << "Pokémon agregado con información por defecto." << endl;
                    pressEnterToContinue();
                    break;
                }

                PokemonInfo pokemonInfo = createPokemonInfo();
                
                pokedex->addPokemon(*tempPokemon, pokemonInfo);
                cout << "Pokémon agregado correctamente a la Pokedex." << endl;
                pressEnterToContinue();
                break;
            }
            case 3: {
                if(!checkPokedexExists(pokedex)) {break;}
                
                if (pokedex->empty()) {
                    cout << "La Pokedex está vacía. Agregue Pokémon primero (opción 2)." << endl;
                    pressEnterToContinue();
                    break;
                }
                
                cout << "\n===== TODOS LOS POKÉMON EN LA POKEDEX =====" << endl;
                pokedex->showAll();
                pressEnterToContinue();
                break;
            }
            case 4: {
                if(!checkPokedexExists(pokedex)) {break;}
                
                string name;
                cout << "Ingrese el nombre del Pokémon a buscar: ";
                getline(cin, name);
                
                experience_t exp;
                cout << "Ingrese la experiencia del Pokémon a buscar: ";
                exp = getValidIntInput();
                
                Pokemon searchPokemon(name, exp);
                pokedex->show(searchPokemon);
                pressEnterToContinue();
                break;
            }
            case 5: {
                if(!checkPokedexExists(pokedex)) {break;}
                
                pokedex->save();
                pressEnterToContinue();
                break;
            }
            case 6: {
                if(!checkPokedexExists(pokedex)) {break;}
                
                string filename;
                cout << "Ingrese el nombre del archivo: ";
                getline(cin, filename);
                
                pokedex->saveAs(filename);
                pressEnterToContinue();
                break;
            }
            case 7: {
                if (pokedex != nullptr) {delete pokedex;}
                
                string filename;
                cout << "Ingrese el nombre del archivo a cargar (Sin .bin): ";
                getline(cin, filename);

                ifstream fileCheck("data/" + filename + ".bin");
                
                if (!fileCheck.good()) {
                    cout << "El archivo '" << filename << ".bin' no existe o no es accesible." << endl;
                    pokedex = nullptr;
                    pressEnterToContinue();
                    break;
                }

                fileCheck.close();
                
                try {
                    pokedex = new Pokedex(filename);
                    cout << "Pokedex cargada correctamente desde '" << filename << "'." << endl;
                } catch (const exception& e) {
                    cout << "Error al cargar la Pokedex: " << e.what() << endl;
                    pokedex = nullptr;
                }
                
                pressEnterToContinue();
                break;
            }
            case 8: {
                exit = true;
                cout << "¡Gracias por usar el sistema de prueba de Pokedex!" << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Por favor seleccione una opción válida (1-8)." << endl;
                pressEnterToContinue();
                break;
            }
        }
    }
    
    if (pokedex != nullptr) {delete pokedex;}
    
    if (tempPokemon != nullptr) {delete tempPokemon;}
    
    return 0;
}
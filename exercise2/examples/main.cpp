#include "../include/Drone.h"

using namespace std;

using drones_t = vector<Drone>;
using zones_t = vector<zone_ptr>;
using threads_t = vector<thread>;

int main() {
    zones_t zonesArr;
    // Definición de zonas
    for (int i = 0; i < 5; ++i) {
        // Los objetos mutex no pueden ser copiados, entonces usamos un unique_ptr y transferimos ownerships
        zonesArr.push_back(new mutex()); 
    }

    drones_t dronesArr;
    // Instanciación de los 5 drones
    for (int i = 0; i < 5; ++i) {
        auto leftZone = zonesArr[i];
        auto rightZone = (i == 4) ? zonesArr[0] : zonesArr[i+1]; // Si es el último drón, su lado derecho es la primer zona
        auto drone = Drone(i, leftZone, rightZone);
        dronesArr.push_back(drone);
    }

    // Creación de cada thread
    threads_t threadsArr;
    for (auto& drone : dronesArr) {
        threadsArr.emplace_back(&Drone::takeOff, &drone);
    }

    // .join() a cada thread para que todos se ejecuten completamente
    for (auto& thread : threadsArr) {
        thread.join();
    }

    // Se liberan los punteros
    for (auto& zone : zonesArr) {
        delete zone;
    }
    
    return 0;
}
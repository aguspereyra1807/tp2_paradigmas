#include "../include/Drone.h"

using namespace std;

using drones_t = vector<Drone>;
using zones_t = vector<zone_ptr>;
using threads_t = vector<thread>;

int main() {
    // Mutex para verificar que la consola sea usada por un dron a la vez y no superponer ningún cout
    auto consolePermission = new mutex();

    zones_t zonesArr;
    // Definición de zonas
    for (int i = 0; i < 5; ++i) {
        // Los objetos mutex no pueden ser copiados, entonces usamos un unique_ptr y transferimos ownerships
        zonesArr.push_back(new mutex()); 
    }
    cout << " - Zonas creadas correctamente - " << endl;

    drones_t dronesArr;
    // Instanciación de los 5 drones
    for (int i = 0; i < 5; ++i) {
        auto leftZone = zonesArr[i];
        auto rightZone = (i == 4) ? zonesArr[0] : zonesArr[i+1]; // Si es el último drón, su lado derecho es la primer zona
        auto drone = Drone(i, leftZone, rightZone);
        dronesArr.push_back(drone);
    }
    cout << " - Drones seteados correctamente - " << endl;

    cout << " - COMENZANDO PROCESO - " << endl;
    
    // Creación de cada thread
    threads_t threadsArr;
    for (auto& drone : dronesArr) {
        threadsArr.emplace_back(&Drone::takeOff, &drone, consolePermission);
    }

    // .join() a cada thread para que todos se ejecuten completamente
    for (auto& thread : threadsArr) {thread.join();}

    // Se liberan los punteros
    for (auto& zone : zonesArr) {delete zone;}
    delete consolePermission;

    cout << " - TOTAL DE DESPEGUES EXITOSOS -" << endl;
    return 0;
}
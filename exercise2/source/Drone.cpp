#include "../include/Drone.h"

using namespace std;

// Printea el texto dado con el id correspondiente al dron, verificando que ningún otro thread esté printeando (lockea la consola)
void Drone::log(mutex* permission, string text, id_t id) {
    permission->lock();
    cout << "Dron " << id << " " << text << endl;
    permission->unlock();
}

Drone::Drone(id_t _id, zone_ptr _leftZone, zone_ptr _rightZone)
    : id(_id), leftZone(_leftZone), rightZone(_rightZone) {}

// Despega el dron, dejando registro de todo lo que hace. Si en sus zonas laterales está despegando algún otro dron, espera.
// El dron una vez que despega demora 5 segundos en alcanzar los 10m
void Drone::takeOff(mutex* consolePermission) {
    log(consolePermission, string("esperando para despegar..."), id);

    lock(*leftZone, *rightZone); // multiple lock para evitar un deadlock, el dron esperará a que se liberen sus zonas laterales
    
    log(consolePermission, string("despegando..."), id);
    this_thread::sleep_for(chrono::seconds(5)); // 5 segundos hasta alcanzar los 10m de altura
    log(consolePermission, string("alcanzó altura de 10m"), id);

    // Ahora la zonas están liberadas para el resto
    leftZone->unlock();
    rightZone->unlock();
}

Drone::~Drone() {}
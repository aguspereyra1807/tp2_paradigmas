#include "../include/Drone.h"

using namespace std;

Drone::Drone(id_t identification, zone_ptr leftRegion, zone_ptr rightRegion)
    : id(identification), leftZone(leftRegion), rightZone(rightRegion) { }

void Drone::takeOff() {
    cout << "Dron " << id << " esperando para despegar..." << endl;
    lock(*leftZone, *rightZone); // multiple lock para evitar un deadlock, el dron esperará a que se liberen sus zonas laterales
    cout << "Dron " << id << " despegando..." << endl;
    this_thread::sleep_for(chrono::seconds(5)); // 5 segundos hasta alcanzar los 10m de altura
    cout << "Dron " << id << " alcanzó altura de 10m" << endl;
    // Ahora la zonas están liberadas para el resto
    leftZone->unlock();
    rightZone->unlock();
}

Drone::~Drone() {}
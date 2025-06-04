#pragma once
#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>

using id_t = unsigned int;
using zone_ptr = std::mutex*;

class Drone {
    private:
        const id_t id; // De 0 a 4
        zone_ptr leftZone; // Zona de la izquierda
        zone_ptr rightZone; // Zona de la derecha
    public:
        Drone(id_t identification, zone_ptr leftRegion, zone_ptr rightRegion);
        ~Drone();
        void takeOff(); // Despegar
};
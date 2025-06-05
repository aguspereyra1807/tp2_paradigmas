#pragma once
#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>
#include <string>

using id_t = unsigned int;
using zone_ptr = std::mutex*; // Tipo que va a ser el puntero de la "zona"

class Drone {
    private:
        const id_t id; // De 0 a 4
        zone_ptr leftZone; // Zona de la izquierda
        zone_ptr rightZone; // Zona de la derecha
        
        // no ponemos "zone_ptr" xq a pesar de que es el mismo tipo, no lo usamos par a lo mismo
        void log(std::mutex* permission, std::string text, id_t id); 
    
    public:
        Drone(id_t identification, zone_ptr leftRegion, zone_ptr rightRegion);
        void takeOff(std::mutex* consolePermission); // Despegar
        ~Drone();
};
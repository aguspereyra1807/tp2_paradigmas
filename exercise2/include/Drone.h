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
        
        // No ponemos "zone_ptr" porque a pesar de que es el mismo tipo, no lo usamos para lo mismo
        void log(std::mutex* permission, std::string text, id_t id); 
    public:
        Drone(id_t _id, zone_ptr _leftZone, zone_ptr _rightZone);
        ~Drone();

        void takeOff(std::mutex* consolePermission); // Despegar
};
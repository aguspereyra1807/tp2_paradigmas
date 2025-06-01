#pragma once

#include "../include/Zone.h"
#include "../include/Dron.h"

#include <array>
#include <unordered_map>

using namespace std;

using u_map_zone_dron = unordered_map<Zone, Dron&>;

class Hangar {
    private:
        u_map_zone_dron zones;
        array<Dron, 4> drones;
};
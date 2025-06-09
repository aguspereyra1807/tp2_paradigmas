#include "../include/Task.h"

using namespace std;

Task::Task(id_t identification, id_t sensorIdentification, string description)
    : id(identification), sensorId(sensorIdentification), desc(description) {
        this_thread::sleep_for(chrono::milliseconds(150)); // Demora de 150ms
}
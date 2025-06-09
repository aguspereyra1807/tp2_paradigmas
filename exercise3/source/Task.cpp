#include "../include/Task.h"

using namespace std;

Task::Task(id_t _id, id_t _sensorId, std::string _description)
    : id(_id), sensorId(_sensorId), description(_description) {
        this_thread::sleep_for(chrono::milliseconds(150));
}
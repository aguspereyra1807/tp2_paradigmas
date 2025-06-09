#include "../include/Task.h"

using namespace std;
using namespace chrono_literals;

Task::Task(ID_t _id, ID_t _sensorId, string _description)
    : id(_id), sensorId(_sensorId), description(_description) {
        this_thread::sleep_for(150ms);
}
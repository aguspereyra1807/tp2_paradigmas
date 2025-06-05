#pragma once
#include <string>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>

using id_t = const unsigned int;
using task_list_t = std::queue<Task>;

struct Task {
    id_t id;
    id_t sensorId;
    std::string desc; // description
    Task(id_t identification, id_t sensorIdentification, std::string description);
};
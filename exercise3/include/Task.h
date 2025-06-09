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
    std::string description;
    Task(id_t _id, id_t _sensorId, std::string _description);
};
#pragma once
#include <string>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <atomic>

using ID_t = unsigned int;

struct Task {
    ID_t id;
    ID_t sensorId;
    std::string description;
    Task(ID_t _id, ID_t _sensorId, std::string _description);
};
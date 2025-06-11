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

// Constantes globales
#define ROBOT_AMOUNT 3
#define SENSOR_AMOUNT 3
#define TASK_AMOUNT_PER_SENSOR 3

// - Colores para el << cout (ANSI)
#define DEFAULT_C "\033[0m"
#define ROBOT_C "\033[1;36m"
#define SENSOR_C "\033[1;35m"
#define TASK_C "\033[33m"
#define TURN_OFF_C "\033[4;31m"

struct Task {
    ID_t id;
    ID_t sensorId;
    std::string description;
    Task(ID_t _id, ID_t _sensorId, std::string _description);
};
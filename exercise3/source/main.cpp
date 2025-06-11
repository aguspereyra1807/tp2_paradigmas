#include "../include/Task.h"

// Definiciones de tipos
using namespace std;
using namespace chrono_literals;
using task_list_t = queue<Task>;
using jthreads_t = vector<jthread>;

// Constantes globales
#define ROBOT_AMOUNT 3
#define SENSOR_AMOUNT 3
#define TASK_AMOUNT_PER_SENSOR 3

// Colores para el << cout (ANSI)
#define DEFAULT_C "\033[0m"
#define ROBOT_C "\033[1;36m"
#define SENSOR_C "\033[1;35m"
#define TASK_C "\033[33m"
#define TURN_OFF_C "\033[4;31m"

// Variables globales
mutex consolePermission; // Consola para no superponer ningún cout
mutex sensorPermission;
condition_variable cv;
task_list_t tasks;
atomic<int> activeSensors(SENSOR_AMOUNT); // atomic contador de sensores activos (inicializado en el total)
const vector<string> descriptions = {
    "Temperature inspection in zone A",
    "Pressure check in the hydraulic system",
    "Lubricant level review",
    "Motor alignment verification",
    "Diagnosis of abnormal vibrations",
    "Filter condition assessment",
    "Ambient humidity reading",
    "Actuator status control",
    "Airflow monitoring in duct 3",
    "Voltage check in secondary circuit",
    "Current measurement in power module",
    "Structural integrity verification of the support",
    "Visual inspection of the control panel",
    "Ground connection review",
    "Thermal performance evaluation",
    "Optical sensor diagnostics",
    "Pneumatic valve check"
};

// Cada Sensor agrega tareas a la cola
void turnOnSensor(ID_t sensorID) {
    for (int i = 0; i < TASK_AMOUNT_PER_SENSOR; ++i) {
        
        ID_t taskID = sensorID + i;
        string taskDesc = descriptions[rand() % descriptions.size()]; // Descripción aleatoria
        {
            lock_guard<mutex> lg(sensorPermission); // Bloquea el mutex y desbloquea cuando sale del scope
            auto newTask = Task(taskID, sensorID, taskDesc);
            tasks.push(newTask);
        }
        {
            lock_guard<mutex> consoleLock(consolePermission);
            cout << SENSOR_C << "Sensor [#" << setw(2) << setfill('0') << sensorID << "]" << DEFAULT_C << " created   -> " << TASK_C << "Task [#" << 
            setw(2) << setfill('0') << taskID << "]" << DEFAULT_C << " : '" << taskDesc << "'" << endl;
        }
        cv.notify_all();
    }
    {   
        lock_guard<mutex> lg(sensorPermission);
        if (--activeSensors == 0) { // Si terminó el último sensor
            cv.notify_all();
        }
    }
    
}

// Cada Robot procesa las tareas por orden de llegada   
void turnOnRobot(ID_t robotID) {

    while (true) {
        unique_lock<mutex> lock(sensorPermission);
        cv.wait(lock, []{return !tasks.empty() || activeSensors == 0;} ); // espera hasta poder sacar una tarea

        if (!tasks.empty()) {
            auto task = tasks.front();
            tasks.pop();
            lock.unlock();
            this_thread::sleep_for(250ms);
            {
                lock_guard<mutex> consoleLock(consolePermission);
                cout << ROBOT_C << "Robot  [#" << setw(2) << setfill('0') << robotID << "]" << DEFAULT_C << " processed ->" << TASK_C <<" Task [#" << 
                setw(2) << setfill('0') << task.id << "]" << DEFAULT_C << " : '" << task.description << "'" << endl;
            }
        } else if (activeSensors == 0) break;
    } 

    {
        lock_guard<mutex> consoleLock(consolePermission);
        cout << ROBOT_C << "Robot  [#" << setw(2) << setfill('0') << robotID << "] " << TURN_OFF_C << "has turned off" << DEFAULT_C << endl;
    }
}

int main() {
    srand(time(nullptr)); // Semilla para los randoms de las descripciones

    // Jthreads para el join automático
    jthreads_t sensors;
    for (int i = 0; i < SENSOR_AMOUNT; ++i) { sensors.emplace_back(turnOnSensor, i); } // Sensores Id [00 - 0N] 

    jthreads_t robots;
    for (int i = 0; i < ROBOT_AMOUNT; ++i) { robots.emplace_back(turnOnRobot, i*10+i); } // Robots Id [00 - NN]
    
    return 0;
}
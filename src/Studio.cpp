#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"
#include "fstream"
class Studio {
public:
    Studio(const std::string &configFilePath) {
        std::ifstream config(configFilePath.txt);
        std::vector<std::string> trainers;
        std::vector<std::string> workout_options;
        int numOfTrainers;
    }
private;
    bool open;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;

}
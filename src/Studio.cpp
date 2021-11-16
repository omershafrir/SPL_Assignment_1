#include <vector>
#include <string>
#include "../include/Workout.h"
#include "../include/Trainer.h"
#include "../include/Action.h"
#include "../include/File_Reader.h"
#include "../include/Studio.h"
#include "fstream"

using namespace std;

Studio::Studio(){

}
Studio::Studio(const std::string &configFilePath):open(false){
    File_Reader reader;
    workout_options=reader.read_3(configFilePath);

}
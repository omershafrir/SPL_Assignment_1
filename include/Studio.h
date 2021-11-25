#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"


using namespace std;
class Studio{		
public:

	Studio();                                   //default constructor
    Studio(const std::string &configFilePath);  //constructor
    Studio(const Studio &other);                //copy constructor
    Studio(Studio &&other);                     //move constructor
    Studio &operator=(const Studio &studio);    //copy assignment operator
    Studio &operator=(Studio &&studio);         //move assignment operator
    ~Studio();                                  //destructor

    void start();
    int getNumOfTrainers() const;
    Trainer* getTrainer(int tid);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout>& getWorkoutOptions();
    std::vector<Customer*> stringToList(std::string user_input, int* counter, bool is_valid, int trainer_id); // Added as help member
    std::vector<Trainer*> copyTrainers(vector <Trainer*> v);        //side function
    std::vector<BaseAction*> copyActions(vector<BaseAction*> v);   //side function
private:
    bool open;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;
    int numberOfTrainers;   //added as a help member
    int *customer_counter;   //added as a help member
};

#endif
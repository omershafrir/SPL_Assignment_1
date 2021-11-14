#ifndef WORKOUT_H_
#define WORKOUT_H_
#include <string>

enum WorkoutType{
    ANAEROBIC, MIXED, CARDIO , NOTDEFINED=-1
};

class Workout{
public:
    Workout();
    Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type);
    Workout(const Workout &w);
//    Workout& operator=(const Workout &other);    //  - to figure out
    int getId() const;
    std::string getName() const;
    int getPrice() const;
    WorkoutType getType() const;
    void print();       //self-test func
private:
	const int id;
    const std::string name;
    const int price;
    const WorkoutType type;
};


#endif
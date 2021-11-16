#include <iostream>
#include "../include/Workout.h"
    using namespace std;
    Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
    id(w_id),name(w_name),price(w_price),type(w_type)
    {
    }
    int Workout:: getId() const{
        return id;
    }
    std::string Workout:: getName() const{
        return name;
    }
    int Workout:: getPrice() const{
        return price;
    }
    WorkoutType Workout:: getType() const{
        return type;
    }

    void Workout:: print(){     //self-test func
        std::cout << "id : "<< this->id << std::endl;
        std::cout << "name : "<< this->name << std::endl;
        std::cout << "price : "<< this->price << std::endl;
        std::cout << "type : "<< this->type << std::endl;

    }


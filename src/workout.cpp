#include <iostream>
#include "../include/Workout.h"

    Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
    id(w_id),name(w_name),price(w_price),type(w_type)
    {
//        this->id=w_id;
//        this->name=w_name;
//        this->price=w_price;
//        this->type=w_type;
    }
    //copy constructor
//    Workout(const Workout &w):
//    id(w.id),name(w.name),price(w.price),type(w.type)
//    {
//        this->id=w.id;
//        this->name=w.name;
//        this->price=w.price;
//        this->type=w.type;
//    }
    //copy assignment operator
//    Workout& operator=(const Workout &other){
//        this->id=w.id;
//        this->name=w.name;
//        this->price=w.price;
//        this->type=w.type;
//        return *this;
//    }
    //we dont define move constructor since workout does not own resources

    //we dont define move assignment operator since workout does not own resources

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

    void Workout:: print(){
        std::cout << "id "<< this->id << std::endl;
        std::cout << "name "<< this->name << std::endl;
        std::cout << "price "<< this->price << std::endl;
        std::cout << "type"<< this->type << std::endl;

    }

#include "../include/Customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../include/Functions.h"
    using namespace std;
    ////////////////////////////Customer/////////////////////////////////
    //Customer constructor
Customer::Customer(string c_name, int c_id):
    name(c_name) , id(c_id)
{
}
    //Customer copy constructor
Customer::Customer(const Customer &c):
    name(c.name) , id(c.id)
{

}
std::string Customer::getName() const{
    return name;
}
int Customer::getId() const{
    return id;
}

//should they be static?
static bool min_func(const pair<int,int> first, const pair<int,int> sec){
    return (first.second < sec.second);
}
static bool max_func(const pair<int,int> first, const pair<int,int> sec){
    return (first.second < sec.second);
}
////////////////////////////SweatyCustomer/////////////////////////////////
    //SweatyCustomer constructor
SweatyCustomer::SweatyCustomer(string name, int id): Customer(name,id){}
    //SweatyCustomer copy-constructor
SweatyCustomer::SweatyCustomer(const SweatyCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> SweatyCustomer::order (const std::vector<Workout> &workout_options){
    vector<int> output_v;
    for (int i=0;i<workout_options.size();i++){
        Workout w=workout_options[i];
        if(w.getType()==CARDIO)
            output_v.push_back(w.getId());
    }
    return output_v;
}
string SweatyCustomer::toString() const{
    return (getName() + ",swt");
}
Customer* SweatyCustomer::clone(){
    return new SweatyCustomer(*this);
}
///////////////////////////////////CheapCustomer///////////////////////////
//CheapCustomer constructor
CheapCustomer::CheapCustomer(string name, int id): Customer(name,id){}
//CheapCustomer copy-constructor
CheapCustomer::CheapCustomer(const CheapCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> CheapCustomer::order (const std::vector<Workout> &workout_options){
    vector<int> output_v;
    int min_price=workout_options[0].getPrice();
    int min_indx=0;     //index of cheapest workout
    for (int i=1;i<workout_options.size();i++){
        Workout w=workout_options[i];
        if(w.getPrice()<min_price){
            min_price=w.getPrice();
            min_indx=i;
        }
    }
                                                //was changed from
//    output_v.push_back(min_indx);
                                            //to this - sending back the workout id
    output_v.push_back(workout_options[min_indx].getId());
    return output_v;
}
string CheapCustomer::toString() const{
    return (getName() + ",chp");
}
Customer* CheapCustomer::clone(){
    return new CheapCustomer(*this);
}
///////////////////////////////////HeavyMuscleCustomer/////////////////////////
//HeavyMuscleCustomer constructor
HeavyMuscleCustomer::HeavyMuscleCustomer(string name, int id): Customer(name,id){}
//HeavyMuscleCustomer copy-constructor
HeavyMuscleCustomer::HeavyMuscleCustomer(const HeavyMuscleCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> HeavyMuscleCustomer::order (const std::vector<Workout> &workout_options){         //to implement
    vector<pair<int,int>> anaerobic_only;
    vector<int> output;
    for(int i = 0; i < workout_options.size(); i++){
        if(workout_options[i].getType() == ANAEROBIC){
            pair<int,int> w(workout_options[i].getId(),workout_options[i].getPrice());
            anaerobic_only.push_back(w);
        }
    }
    while(!anaerobic_only.empty()){
        //the id of the most expensive workout
        output.push_back(max_element(anaerobic_only.begin(), anaerobic_only.end(), max_func)->first);
        anaerobic_only.erase(max_element(anaerobic_only.begin(), anaerobic_only.end(), max_func));
    }
    return output;
}
string HeavyMuscleCustomer::toString() const{
    return (getName() + ",mcl");
}
Customer* HeavyMuscleCustomer::clone(){
    return new HeavyMuscleCustomer(*this);
}
/////////////////////////////////FullBodyCustomer//////////////////////////
//FullBodyCustomer constructor
FullBodyCustomer::FullBodyCustomer(string name, int id): Customer(name,id){}
//FullBodyCustomer copy-constructor
FullBodyCustomer::FullBodyCustomer(const FullBodyCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> FullBodyCustomer::order (const std::vector<Workout> &workout_options) {
    vector<pair<int,int>> anaerobic_only;
    vector<pair<int,int>> cardio_only;
    vector<pair<int,int>> mix_only;
    vector<int> output;
    for(int i = 0; i < workout_options.size(); i++){
        if(workout_options[i].getType() == CARDIO){
            pair<int,int> w(workout_options[i].getId(),workout_options[i].getPrice());
            cardio_only.push_back(w);
        }
    }
    for(int i = 0; i < workout_options.size(); i++){
        if(workout_options[i].getType() == MIXED){
            pair<int,int> w(workout_options[i].getId(),workout_options[i].getPrice());
            mix_only.push_back(w);
        }
    }
    for(int i = 0; i < workout_options.size(); i++){
        if(workout_options[i].getType() == ANAEROBIC){
            pair<int,int> w(workout_options[i].getId(),workout_options[i].getPrice());
            anaerobic_only.push_back(w);
        }
    }
    //the id of the cheapest cardio
    output.push_back(min_element(cardio_only.begin(), cardio_only.end(), min_func)->first);
    //the id of the most expensive mixed
    output.push_back(max_element(mix_only.begin(), mix_only.end(), max_func)->first);
    //the id of the cheapest enaerobic
    output.push_back(min_element(anaerobic_only.begin(), anaerobic_only.end(), min_func)->first);
    return output;
}
string FullBodyCustomer::toString() const{
    return (getName() + ",fbd");
}
Customer* FullBodyCustomer::clone(){
    return new FullBodyCustomer(*this);
}
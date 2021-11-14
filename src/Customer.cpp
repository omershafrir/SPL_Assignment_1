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
//bool comperator(Workout w1, Workout w2){
//    cout<<"  sdsd";
//    if(w1.getPrice() < w2.getPrice())
//        return true;
//    return false;
//    return (w1.getPrice()  w2.getPrice());
//}
////////////////////////////SweatyCustomer/////////////////////////////////
    //SweatyCustomer constructor
SweatyCustomer::SweatyCustomer(string name, int id): Customer(name,id){}
    //SweatyCustomer copy-constructor
SweatyCustomer::SweatyCustomer(const SweatyCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> SweatyCustomer::order (const std::vector<Workout> &workout_options){
    vector<int> *output_v=new vector<int>;
    for (int i=0;i<workout_options.size();i++){
        Workout w=workout_options[i];
        if(w.getType()==CARDIO)
            output_v->push_back(w.getId());
    }
    return *output_v;
}
string SweatyCustomer::toString() const{
    return "Name: "+getName()+" , Id: "+to_string(getId())+" ";
}
///////////////////////////////////CheapCustomer///////////////////////////
//CheapCustomer constructor
CheapCustomer::CheapCustomer(string name, int id): Customer(name,id){}
//CheapCustomer copy-constructor
CheapCustomer::CheapCustomer(const CheapCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> CheapCustomer::order (const std::vector<Workout> &workout_options){
    vector<int> output_v;
    int min_price=workout_options[0].getPrice(),min_indx=0;     //index of cheapest workout
    for (int i=1;i<workout_options.size();i++){
        Workout w=workout_options[i];
        if(w.getPrice()<min_price){
            min_price=w.getPrice();
            min_indx=i;
        }
    }
    output_v.push_back(min_indx);
    return output_v;
}
string CheapCustomer::toString() const{
    return "Name: "+getName()+" , Id: "+to_string(getId())+" ";
}
///////////////////////////////////HeavyMuscleCustomer/////////////////////////
//HeavyMuscleCustomer constructor
HeavyMuscleCustomer::HeavyMuscleCustomer(string name, int id): Customer(name,id){}
//HeavyMuscleCustomer copy-constructor
HeavyMuscleCustomer::HeavyMuscleCustomer(const HeavyMuscleCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> HeavyMuscleCustomer::order (const std::vector<Workout> &workout_options){
//    vector<Workout> to_sort = workout_options;
//    std::sort(to_sort.begin(),to_sort.end());
    vector<int> *omer = new vector<int>;
    return *omer;
}
string HeavyMuscleCustomer::toString() const{
    return "Name: "+getName()+" , Id: "+to_string(getId())+" ";
}
/////////////////////////////////FullBodyCustomer//////////////////////////
//FullBodyCustomer constructor
FullBodyCustomer::FullBodyCustomer(string name, int id): Customer(name,id){}
//FullBodyCustomer copy-constructor
FullBodyCustomer::FullBodyCustomer(const FullBodyCustomer &c):Customer(c.getName(),c.getId()){}
vector<int> FullBodyCustomer::order (const std::vector<Workout> &workout_options) {
    vector<int> output_v;
//    ANAEROBIC, MIXED, CARDIO
    int mix_id = -1, mix_p = -1;         //catching cheapest, expensive , cheapest
    int anrbic_id = -1, anrbic_p = -1;
    int cardio_id = -1, cardio_p = -1;
    bool firstMix=false , firstCardio=false , firstAnrbic=false;
    for (int i = 0; i < workout_options.size(); i++) {
        Workout w = workout_options[i];
        if (w.getType() == CARDIO) {
            if(!firstCardio) {
                cardio_id = w.getId();
                cardio_p = w.getPrice();
                firstCardio=true;
            }
            else if (cardio_p > w.getPrice()) {
                cardio_id = w.getId();
                cardio_p = w.getPrice();
            }
        }
        if (w.getType() == MIXED ) {
            if(!firstMix) {
                mix_id = w.getId();
                mix_p = w.getPrice();
                firstMix=true;
            }
            else if (mix_p < w.getPrice()) {
                mix_id = w.getId();
                mix_p = w.getPrice();
            }
        }
        if (w.getType() == ANAEROBIC) {
            if(!firstAnrbic) {
                anrbic_id = w.getId();
                anrbic_p = w.getPrice();
                firstAnrbic=true;
            }
            else if (anrbic_p > w.getPrice()) {
                anrbic_id = w.getId();
                anrbic_p = w.getPrice();
            }
        }
    }
        if (cardio_id != -1)
            output_v.push_back(cardio_id);
        if (mix_id != -1)
            output_v.push_back(mix_id);
        if (anrbic_id != -1)
            output_v.push_back(anrbic_id);
        return output_v;
}
string FullBodyCustomer::toString() const{
    return "Name: "+getName()+" , Id: "+to_string(getId())+" ";
}
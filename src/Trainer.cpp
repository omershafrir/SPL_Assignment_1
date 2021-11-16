#include "../include/Trainer.h"
#include "../include/Customer.h"
#include "../include/Studio.h"
#include <vector>
using namespace std;
Trainer::Trainer(int t_capacity):capacity(t_capacity),open(false){
    //customerslist & orderlist will get their values when
    //the "open Trainer" function will get the proper inputs for it
    //should be Initialized when "open studio" is evoked(?)
}
int Trainer:: getCapacity() const{
    return this->capacity;
}

//until studio is ready this function is irrelevant

//void Trainer::addCustomer(Customer* customer) {
//    customersList.push_back(customer);
//    //order func will call the suitable order function
//    // for the specific customer type
//    vector<int> customer_workouts = customer->order(studio.getWorkoutOptions());
//    int c_id = customer->getId();
//    for (int i: customer_workouts) {
//        OrderPair to_add(c_id, &workout_options[i]);
//        orderList.push_back(to_add);
//    }
//}
//void Trainer::removeCustomer(int id){
//    for(int i ; i<customersList.size() ; i++){
//        if (customersList[i]->getId()==id)
//            customersList.erase(customersList.begin()+i);
//    }
//    for(int i ; i<orderList.size() ; i++){
//        if (orderList[i].first->getId()==id)
//            orderList.erase(orderList.begin()+i);
//    }
//}




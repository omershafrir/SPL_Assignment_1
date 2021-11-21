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

//Trainer:: ~Trainer(){
//        delete &customersList;
//        delete &orderList;
//}
int Trainer:: getCapacity() const{
    return this->capacity;
}

//until studio is ready this function is irrelevant

void Trainer::addCustomer(Customer* customer) {
    if(current_capacity<capacity)
        customersList.push_back(customer);
    //order func will call the suitable order function
    // for the specific customer type

    ///////////////////  customer specific workouts will be added to
    ///////////////////  orderList only when order() will be called!
    }

void Trainer::removeCustomer(int id){
    for(int i ; i<customersList.size() ; i++){
        if (customersList[i]->getId() == id) {
            customersList.erase(customersList.begin() + i);
            current_capacity--;
        }
    }
}

Customer* Trainer::getCustomer(int id){
    for(int i=0 ; i<customersList.size() ; i++){
        if (customersList[i]->getId()==id)
            return customersList[i];
    }
    return nullptr;
}

vector<Customer*>& Trainer::getCustomers(){
    //option 1:
    //definding a refrence to the field and returning it
    vector<Customer*> &customer = customersList;
    return customer;
    //option 2:
    //returning the field
    return customersList;
}
vector<OrderPair>& Trainer::getOrders(){
    vector<OrderPair> &orders = orderList;
    return orders;
}
//missing implementaion:
//void Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options){}
void Trainer::openTrainer(){
    open=true;
}
//missing implementaion:
//void Trainer::closeTrainer(){}

//missing implementaion:
//int Trainer::getSalary(){ return 0;}
////////////////////////
bool Trainer::isOpen(){
    return open;
}

void Trainer::printCustomers(){
    if(!open)
        cout<<"Trainer is not open"<<endl;
    else
         for (Customer* customer : customersList)
             cout<<customer->toString()<<endl;
}               //self check function




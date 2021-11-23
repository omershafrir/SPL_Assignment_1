#include "../include/Trainer.h"
#include "../include/Customer.h"
#include "../include/Studio.h"
#include <vector>
using namespace std;
Trainer::Trainer(int t_capacity):capacity(t_capacity) , current_capacity(0) , open(false) , salary(0){
    vector<Customer*> customersList() ;
    vector<OrderPair> orderList;
    //customerslist & orderlist will get their values when
    //the "open Trainer" function will get the proper inputs for it
    //should be Initialized when "open studio" is evoked(?)
}

//Trainer:: ~Trainer(){
////    delete[] &customersList;
//        for (Customer *c : customersList)
//            delete c;
////        for (OrderPair order : orderList)
////            delete &order;
//}
int Trainer:: getCapacity() const{
    return this->capacity;
}

int Trainer::getCurrentCapacity() {
    return current_capacity;
}

void Trainer::addCustomer(Customer* customer) {
    if(current_capacity<capacity) {
        customersList.push_back(customer);
        current_capacity++;
    }
    //order func will call the suitable order function
    // for the specific customer type

    ///////////////////  customer specific workouts will be added to
    ///////////////////  orderList only when order() will be called!
    }

void Trainer::removeCustomer(int id) {
    vector <OrderPair> newOrderList;
    bool found = false;
    for (int i=0; i < customersList.size(); i++) {
        if (customersList[i]->getId() == id) {
            customersList.erase(customersList.begin() + i);
            current_capacity--;
            //replacing the old orderlist with the updated one
            found = true;
            for (OrderPair pair: orderList) {
                if (pair.first != id)                //pairs that stays on the orderList
                    newOrderList.push_back(pair);
                else{
                    //pairs that need to be removed are removed also from the salary calculation
                    salary -= pair.second.getPrice();
                }
            }
        }
    }
    if(found){
        orderList.clear();
        for (OrderPair pair: newOrderList) {
            orderList.push_back(pair);
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
    return customersList;
}
vector<OrderPair>& Trainer::getOrders(){
    return orderList;
}
//missing implementaion:
void Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options){
    for (int i : workout_ids) {
        OrderPair order (customer_id , workout_options[i]);                   //before change
//        OrderPair  order;
//        order = make_pair(customer_id , workout_options[i]) ;
        orderList.push_back(order);
        salary += workout_options[i].getPrice();
    }
}
void Trainer::openTrainer(){
    open=true;
}

//void Trainer::closeTrainer(){}            //missing implementaion:

int Trainer::getSalary(){
    return salary;
}

////////////////////////
bool Trainer::isOpen(){
    return open;
}

void Trainer::printOrder() {                     //added member

    for (int i = 0; i < orderList.size(); i++) {
        cout << getCustomer(orderList[i].first)->getName() << " Is Doing " << orderList[i].second.getName() << endl;
    }
}
void Trainer::printCustomers(){
    if(!open)
        cout<<"Trainer is not open"<<endl;
    else
//        for(customer *c : customersList)
//             cout<<c->toString()<<endl;
         for (int i=0; i<current_capacity ; i++)
             cout<<customersList[i]->toString()<<endl;
}               //self check function
void Trainer::printOrderList(){
    if(!open)
        cout<<"Trainer is not open"<<endl;
    else
        for (OrderPair order : orderList){
            cout<< "ID : "<< order.first << " workout: " << order.second.getName()<<endl;
        }
}               //self check function





#include "../include/Trainer.h"
#include "../include/Customer.h"
#include <vector>
using namespace std;
Trainer::Trainer(int t_capacity)
:capacity(t_capacity),open(false),customersList(),orderList(){
    //customerslist & orderlist will get their values when
    //the "open Trainer" function will get the proper inputs for it
    //should be Initialized when "open studio" is evoked(?)
}
int Trainer:: getCapacity() const{
    return this->capacity;
}

//void Trainer::addCustomer(Customer* customer){
//
//}
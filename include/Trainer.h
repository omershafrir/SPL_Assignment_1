#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include "Customer.h"
#include "Workout.h"

typedef std::pair<int, Workout> OrderPair;

class Trainer{
public:
    Trainer(int t_capacity);                        //constructor
    Trainer (const Trainer &other);                 //copy constructor
    Trainer (Trainer &&other);                      //move constructor
    Trainer operator=(const Trainer &other);        //copy assignment operator
    Trainer &operator=(Trainer &&other);            //move assignment operator
    ~Trainer();                                     //destructor

    int getCapacity() const;
    int getCurrentCapacity() ;      //added member
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options);
    void openTrainer();
    void closeTrainer();
    int getSalary();              //added member
    bool isOpen();
    void printCustomers();        //self check function
    void printOrderList();        //self check function
    void printOrder();            //added member
private:
    int current_capacity;            //added member
    int salary;                      //added member
    int capacity;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order for the trainer - (customer_id, Workout)
};


#endif
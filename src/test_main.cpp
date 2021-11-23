#include <iostream>
#include <vector>
#include "../include/Workout.h"
#include "../include/Customer.h"
#include "../include/Trainer.h"
#include "../include/Studio.h"
#include "../include/Action.h"
#include "../include/File_Reader.h"
#include "../include/File_Reader_Output.h"
#include <fstream>
#include <sstream>
using namespace std;


vector<Customer*> stringToList(string user_input);              //forward declaration
Customer* makeCustomer(string name, int id , string code);      //forward declaration
void printCustomerList(vector<Customer*> customersList);        //forward declaration


//open 2 shalom,swt omer,swt erez,swt moshe,swt micha,swt shmuel,swt
//open 1 shalom,swt rocker,swt
//open 1 shalom,swt omer,swt erez,swt moshe,swt micha,swt shmuel,swt rocker,swt shalom,swt omer,swt erez,swt moshe,swt micha,swt shmuel,swt rocker,swt
int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO

    string path="src/config2.txt";
    Studio *s=new Studio(path);
    s->start();






//    s=nullptr;
//    Trainer t(3);
////    cout<<"sdsddfsd";
//    Customer *c=new SweatyCustomer("omer",1);
////    cout<<"sddfsd";
//    t.addCustomer(c);
////    cout<<"sdsd";
////    delete c;


}



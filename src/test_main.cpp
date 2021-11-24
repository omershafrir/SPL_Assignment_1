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



//open 2 swt,swt fbd,fbd chp,chp mcl,mcl micha,swt shmuel,swt rocker,swt rocker,swt rocker,swt rocker,swt
//open 1 shalom,swt rocker,swt
//open 0 shalom,swt omer,swt erez,swt moshe,swt micha,swt shmuel,swt
int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO

    string path="src/config2.txt";
    Studio *s=new Studio(path);
//    delete s;
//    s = nullptr;
//    free(s);
    s->start();
//    File_Reader_Output input = File_Reader_Output(path);

//        Trainer *t = new Trainer(2);
//        Customer *c = new SweatyCustomer ("d" , 1);
//        t->addCustomer(c);
//        delete t;








//    s=nullptr;
//    Trainer t(3);
////    cout<<"sdsddfsd";
//    Customer *c=new SweatyCustomer("omer",1);
////    cout<<"sddfsd";
//    t.addCustomer(c);
////    cout<<"sdsd";
////    delete c;


}



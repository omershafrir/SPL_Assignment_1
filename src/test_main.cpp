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


// asdsa
vector<Customer*> stringToList(string user_input);              //forward declaration
Customer* makeCustomer(string name, int id , string code);      //forward declaration
void printCustomerList(vector<Customer*> customersList);        //forward declaration


Trainer x(Trainer t){
    Customer *c = new SweatyCustomer("omer" , 2);
    t.addCustomer(c);
    return t;
}





Trainer x2(){
    Trainer *t = new Trainer(217);
    return *t;
}




vector<Trainer*> copyTrainers(vector<Trainer*> v){      //side function
    vector<Trainer*> new_trainers;
    for(Trainer* trainer_from : v){
        Trainer *trainer_to = new Trainer(*trainer_from);
        new_trainers.push_back(trainer_to);
    }
    return new_trainers;
}
Trainer zub(Trainer la);
Trainer zub2() {
    return Trainer(3);
}
//open 2 swt,swt fbd,fbd chp,chp mcl,mcl micha,swt shmuel,swt rocker,swt rocker,swt rocker,swt rocker,swt
//open 1 shalom,swt rocker,swt
//open 0 shalom,swt omer,swt erez,swt moshe,swt micha,swt shmuel,swt
int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO

    string path="src/config.txt";
    Studio *s=new Studio(path);
    s->start();
    delete s;

//    Studio z(zub());
//    Trainer la(std::move(zub2()));
//    cout<< la.getCapacity()<<endl;
//    Trainer s(1);
//    s = zub(Trainer(0));
//    cout << s.getCapacity() << endl;
//        Studio s(Studio("Erez"));
//        Studio s = Studio e
//        cout<<s.getNumOfTrainers()<<endl;


//        Trainer z = Trainer(x2());
//        cout<<"are you open?: "<< z.isOpen()<<endl;
//    Customer *z = new SweatyCustomer("ErezPoper" , 3);
//    vector<Customer*> vec;
//    vec.push_back(c); vec.push_back(z);
//    OpenTrainer *k = new OpenTrainer(0, vec);
////    delete c; delete z;
//        delete k;

//    vector<Customer*> k;
//    k.push_back(z);
//    k.push_back(c);
//    vector<Customer*> aftercopy;
//    aftercopy = k;
//    for(Customer *c : k){
//        cout<<c<<endl;
//    }
//    cout<<""<<endl;
//        cout<<"____________________after copy is down__________--";
//    cout<<""<<endl;
//    for(Customer *c : aftercopy){
//        cout<<c<<endl;
//    }
//
//    Studio *k = s;
//    k = new Studio(path);
//
//    cout<<k->getNumOfTrainers()<<endl;
//    Trainer *t =new Trainer(3);
//    Trainer *t2 =new Trainer(4);
//    *t2 = x(*t);
//
//    t->openTrainer();
//    vector<Trainer*> old;
//
//    old.push_back(t);    old.push_back(t2);
//
//    vector<Trainer*> newv = copyTrainers(old);
//
//
//    for( Trainer* t : old) {
//        cout << t->getCapacity() << endl;
//        t->printCustomers();
//    }
//    cout<<"-------------------------------"<<endl;
//
//    for( Trainer* t : newv) {
//        cout << t->getCapacity() << endl;
//        t->printCustomers();
//    }

//        Customer *c1 = new SweatyCustomer ("a" , 1);
//        Customer *c2 = new CheapCustomer ("b" , 2);
//        Customer *c3 = new CheapCustomer ("c" , 3);
//        t.openTrainer();
//        t.addCustomer(c1);
//        t.addCustomer(c2);
//        t.addCustomer(c3);
//        cout<<"trainer t :"<<endl;
//        t.printCustomers();
//        cout<<"--------------------"<<endl;
//        Trainer t2 = move(t);
//        cout<<"trainer t2 :"<<endl;
//        t2.printCustomers();

}
Trainer zub(Trainer la){
    return la;
}


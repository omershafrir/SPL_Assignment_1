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

void printVector (vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<"Object number "<<i<<" is: "<<v[i]<<endl;
    }
    cout<<endl;
}

vector<int> sort_vec(vector<Workout>& to_sort){
    vector<int> *sorted=new vector<int>;
    for(int i = 0; i < to_sort.size(); i++){
        sorted->push_back(to_sort[i].getPrice());
    }
    return *sorted;
}
int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO

    string path="src/config.txt";
    Studio s=Studio(path);

//    s.start();
    vector<Workout> to_sort = s.getWorkoutOptions();
//    cout<<to_sort[0].getName();
//    printVector(sort_vec(to_sort));
    vector<int> x = sort_vec(to_sort);
//    cout<<x[0];
    printVector(x);
    x.erase(x.begin()+1);
    printVector(x);

//    Customer *omer = new SweatyCustomer("omer",0);
//    Customer *erez = new SweatyCustomer("erez",23);
//    vector<Customer*> v;
//    v.push_back(omer); v.push_back(erez);
//    OpenTrainer open(-1,v);
//    open.act(s);
//    OpenTrainer open2(1,v);
//    open2.act(s);
//    cout<<open.getStatus()<<endl;
//    cout<<open2.getStatus()<<endl;
//    s.getTrainer(0)->printCustomers();
//    delete omer;
//    delete erez;
//    delete &open;
//    delete &open2;
//    delete &v;
//    delete &s;

//    cout<<s.getTrainer(0)->isOpen()<<endl;
//    cout<<s.getTrainer(1)->isOpen()<<endl;
//    cout<<s.getTrainer(0)->isOpen();
//    cout<<open.toString();
//    cout<<s.getTrainer(0)->isOpen();





//    vector<Customer*> v;
//    Customer *omer = new SweatyCustomer("omer",0);
//    Customer *erez = new SweatyCustomer("erez",23);
//    Studio s=Studio(path);
//    OpenTrainer x(0,v);
//    x.act(s);
////    OpenTrainer y(3,v);
//    cout<<s.getTrainer(0)->isOpen()<<" omer";
//    cout<<s.getTrainer(1)->isOpen()<<" erez";
//    delete omer;
//    delete erez;

//cout<<s.numberOfTrainers;
//vector<Workout>  x = s.getWorkoutOptions();
//    cout<<&x<<endl;
//    for( Workout w : x) {
//        w.print();
//    }


//v.push_back(omer);
//v.push_back(erez);
//Trainer t=Trainer(3);
//    t.addCustomer(v[0]);
//    t.addCustomer(v[1]);
//    cout<<t.getCustomers()[0]->getName()<<endl;
//    cout<<t.getCustomers()[1]->getName()<<endl;
//        cout<<t.getCustomer(23)->getName();




//    for(string::reverse_iterator r_iter=s.rbegin();r_iter!=s.rend();++r_iter){  //iterates over price
//       cout<<*r_iter<<endl;
//        }
//    Workout w=reader.convert_w(s,1);
//    int n=reader.read_1();
//    vector<int> v=reader.read_2();
//    printVector(v);




}



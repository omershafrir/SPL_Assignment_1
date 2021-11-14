#include <iostream>
#include <vector>
#include "../include/Workout.h"
#include "../include/Customer.h"
#include "../include/Trainer.h"
#include <algorithm>
using namespace std;

void printVector (vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<"Object number "<<i<<" is: "<<v[i]<<" , ";
    }
    cout<<endl;
}


int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO
    vector<Workout> w;

//    Workout w1= Workout(1,"1",30,CARDIO);
//    Workout w2= Workout(2,"2",300,ANAEROBIC);
//    cout<<w1.getName()<<"    \n"<<w2.getName();
//    w1=w2;
//    cout<<w1.getName()<<"    "<<w2.getName();
//    Workout w3= Workout(3,"soccer",12,MIXED);
//    Workout w4= Workout(4,"baskeyball",1,CARDIO);
//    Workout w5= Workout(5,"baskeyball",195,ANAEROBIC);
//    Workout w6= Workout(6,"baskeyball",125,MIXED);
//    Workout w7= Workout(7,"baskeyball",150,MIXED);
//    Workout w8= Workout(8,"baskeyball",15,ANAEROBIC);

//    w.push_back(w1);
//    w.push_back(w2);
//    w.push_back(w3);

//    w.push_back(w4);
//    w.push_back(w5);
//    w.push_back(w6);
//    w.push_back(w7);
//    w.push_back(w8);

//    if(w1.getPrice() < w2.getPrice())
//        return true;
//    sort(w.begin(),w.end(),[](Workout w1,Workout w2){return w1.getPrice() <= w2.getPrice();});
//    for(Workout x : w){
//        std::cout<<"the price is " << x.getPrice() <<endl;
//    }
//
//
//    FullBodyCustomer a= FullBodyCustomer("omer",1);
//    SweatyCustomer b= SweatyCustomer("erez",2);
//    cout<<a.toString()<<&a<<endl;
//    cout<<b.toString()<<&b<<endl;
//
//    vector<int> v1= b.order(w);
//    printVector (v1);

//    Trainer *t = new Trainer(100000);
//    std::cout<<"the trainer cap"<< (*
//    t).getCapacity()<<endl;


}



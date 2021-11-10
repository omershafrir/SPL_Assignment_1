#include <iostream>
#include <vector>
#include "../include/Workout.h"
using namespace std;

int main(int argc, char** argv) {

    Workout w = Workout(1,"omdfer",25,MIXED);
    Workout w2(w);
    w.print();
    w2.print();
}

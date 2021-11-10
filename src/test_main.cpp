#include <iostream>
#include <vector>
#include "../include/Workout.h"
using namespace std;

int main(int argc, char** argv) {

    Workout w = Workout(1,"omer",25,MIXED);
    w.print();

}

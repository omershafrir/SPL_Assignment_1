#include "../include/Action.h"
#include "../include/Studio.h"
#include "../include/Trainer.h"
#include <sstream>>

using namespace std;
extern Studio* backup = nullptr;
BaseAction::BaseAction(){

}
ActionStatus BaseAction::getStatus() const{
    return status;
}
BaseAction::~BaseAction()
{

}
void BaseAction:: complete(){
    status = COMPLETED;
}

void BaseAction::error(string errorMsg){
    status = ERROR;
    this->errorMsg=errorMsg;
    cout<<"Error: "<<errorMsg<<endl;
}
string BaseAction::getErrorMsg() const{
    return errorMsg;
}


//////////////////////////////////////////////////////OpenTrainer///////////////////////////////////////////////////

OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):trainerId(id){
customers=customersList;
}
void OpenTrainer::act(Studio &studio){
    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
        error("Workout session does not exist or is already open");
    else {
        Trainer *this_trainer = studio.getTrainer(trainerId);
        if (this_trainer->isOpen())                                 //check if trainer is already open
            error("Workout session does not exist or is already open");
        else {
            this_trainer->openTrainer();

            for (Customer *customer : customers){         //adds all the customers received at 'customersList' to the session
                this_trainer->addCustomer(customer);
            }
//            for (Customer *customer : customers){         //adds all the customers received at 'customersList' to the session
//                delete customer;
//            }
            complete();                                 //call for base class method complete()
        }
    }
}
string OpenTrainer::toString() const{
    stringstream ss;
    ss << "open " << to_string(trainerId)<<" ";
    for (Customer* customer : customers){
        ss << customer->toString();
    }
    if(getStatus() == ERROR)
        ss << " Error: Workout session does not exist or is already open";
    else
        ss << " Completed";
    string s = ss.str();
    return s;
}
BaseAction* OpenTrainer::clone(){
    return (new OpenTrainer(trainerId, customers));
}
OpenTrainer::~OpenTrainer(){
}
/////////////////////////////////////////////////////Order///////////////////////////////////////////////////
Order::Order(int id):trainerId(id) {
}
void Order::act(Studio &studio){
    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
        error("Trainer does not exist or is open");
    else if(!studio.getTrainer(trainerId)->isOpen())                    //check if trainer open or closed
        error("Trainer does not exist or is open");
        else{
            Trainer *this_trainer = studio.getTrainer(trainerId);
            vector<Customer*> x =this_trainer->getCustomers();
            for (Customer *c : x){
                vector<int> x =c->order(studio.getWorkoutOptions());
                this_trainer->order(c->getId() , x , studio.getWorkoutOptions());
            }
        this_trainer->printOrder();
        complete();
        }
}
string Order::toString() const{
    stringstream ss;
    ss << "order " << to_string(trainerId);
    if(getStatus() == ERROR)
        ss << " Error: Trainer does not exist or is open";
    else
        ss << " Completed";
    string s = ss.str();
    return s;
}
BaseAction* Order::clone(){
    return (new Order(trainerId));
}
////////////////////////////////////////////////////MoveCustomer//////////////////////////////////////////

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTrainer(src),dstTrainer(dst),id(customerId){}
void MoveCustomer::act(Studio &studio) {
    //if the src trainer doesn't have no one after this move
    //close this trainer!

    //check if trainer exist
    if (srcTrainer > studio.getNumOfTrainers() - 1 || srcTrainer < 0
        || dstTrainer > studio.getNumOfTrainers() - 1 || dstTrainer < 0) {
        error("Cannot move customer");
        return;
    }
    Trainer *src_t = studio.getTrainer(srcTrainer);
    Trainer *dst_t = studio.getTrainer(dstTrainer);
    //check if trainer open or closed
    if (!src_t->isOpen() || !dst_t->isOpen()) {
        error("Cannot move customer");
        return;
    }
    //no one with this id is in the src trainer
    if (src_t->getCustomer(id) == nullptr) {
        error("Cannot move customer");
        return;
    }
    //the dst trainer has no spots
    if (dst_t->getCapacity() <= dst_t->getCurrentCapacity()) {
        error("Cannot move customer");
        return;
    }
    vector<Workout> workout_options = studio.getWorkoutOptions();
    //orders the proper workout from the src to the dst trainer
    //using order function
    dst_t->order(id , src_t->getCustomer(id)->order(workout_options) , workout_options);
    dst_t->addCustomer(src_t->getCustomer(id));
    src_t->removeCustomer(id);
    complete();
    cout<<"Trainer with this capacity "<<src_t->getCapacity()<<" orders are: "<<endl;     ///////////##########################################
    src_t->printOrderList();                          ///////////##########################################
    cout<<"Trainer with this capacity "<<dst_t->getCapacity()<<" orders are: "<<endl;     ///////////##########################################
    dst_t->printOrderList();                         ////////##########################################
}
string MoveCustomer::toString() const{
    stringstream ss;
    ss << "move " <<to_string(srcTrainer)<<" "<<to_string(dstTrainer)<<" "<<to_string(id);
    if(getStatus() == ERROR)
        ss << " Error: Cannot move customer";
    else
        ss << " Completed";
    string s = ss.str();
    return s;
}
BaseAction* MoveCustomer::clone(){
    return (new MoveCustomer(srcTrainer, dstTrainer, id));
}
////////////////////////////////////////////////////Close//////////////////////////////////////////
Close::Close(int id):trainerId(id){}
void Close::act(Studio &studio){
    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
        error("Trainer does not exist or is not open");
    else if(!studio.getTrainer(trainerId)->isOpen())                    //check if trainer open or closed
        error("Trainer does not exist or is not open");
    else{
        Trainer *to_close = studio.getTrainer(trainerId);
        to_close->closeTrainer();
        cout<<"Trainer "<< trainerId << " closed. " << "Salary "<<to_close->getSalary()<<"NIS"<<endl;
        complete();
    }
}
string Close::toString() const{
    stringstream ss;
    ss << "close " <<to_string(trainerId);
    if(getStatus() == ERROR)
        ss << " Error: Trainer does not exist or is not open";
    else
        ss << " Completed";
    string s = ss.str();
    return s;
}
BaseAction* Close::clone(){
    return (new Close(trainerId));
}
/////////////////////////////////////////////////////PrintWorkoutOptions///////////////////////////////////////////////////

PrintWorkoutOptions::PrintWorkoutOptions(){

}
void PrintWorkoutOptions::act(Studio &studio){
    vector<Workout> workout_oprions = studio.getWorkoutOptions();
    for(Workout w : workout_oprions){
        w.print();
    }
    complete();
}
string PrintWorkoutOptions::toString() const{
    return "workout_options";
}
BaseAction* PrintWorkoutOptions::clone(){
    return (new PrintWorkoutOptions());
}
//////////////////////////////////////////////PrintTrainerOptions/////////////////////////////////////


PrintTrainerStatus::PrintTrainerStatus(int id):trainerId(id){

}
void PrintTrainerStatus::act(Studio &studio){
    Trainer *this_trainer = studio.getTrainer(trainerId);
    vector<OrderPair> orders = this_trainer->getOrders();
    string open;
    if(this_trainer->isOpen())
        open = "open";
    else
        open = "closed";
    cout<<"Trainer "<<trainerId<<" status: "<<open<<endl;
    cout<<"Customers:"<<endl;
    for( Customer *c : this_trainer->getCustomers()){
        cout<<c->getId()<<" "<<c->getName()<<endl;
    }
    cout<<"Orders:"<<endl;
    for (OrderPair pair : orders){
        Workout w = pair.second;
        cout<<w.getName()<<" "<<w.getPrice()<<"NIS "<<pair.first<<endl;
    }
    cout<<"Current Trainer's Salary: "<<this_trainer->getSalary()<<"NIS"<<endl;
    complete();
}
string PrintTrainerStatus::toString() const{
    return "status";
}
BaseAction* PrintTrainerStatus::clone(){
    return (new PrintTrainerStatus(trainerId));
}
//////////////////////////////////////////////CloseAll/////////////////////////////////////

CloseAll::CloseAll(){

}
void CloseAll::act(Studio &studio){
    for (int i=0 ; i<studio.getNumOfTrainers() ; i++){
        Trainer *trainer =studio.getTrainer(i);
        if(trainer->isOpen()){
//            cout<<"found:";
            trainer->closeTrainer();
            cout<<"Trainer "<<i<<" closed. Salary "<<trainer->getSalary()<<"NIS"<<endl;
        }
    }
    complete();
    delete &studio;
}
string CloseAll::toString() const{
    return "closeall";
}
BaseAction* CloseAll::clone(){
    return (new CloseAll());
}
//////////////////////////////////////////////PrintActionsLog/////////////////////////////////////

PrintActionsLog::PrintActionsLog(){

}
void PrintActionsLog::act(Studio &studio){
    for (BaseAction* action : studio.getActionsLog()){
        cout<<action->toString()<<endl;
    }
    complete();
}
string PrintActionsLog::toString() const{
    return "log";
}
BaseAction* PrintActionsLog::clone(){
    return (new PrintActionsLog());
}
//////////////////////////////////////////////BackupStudio/////////////////////////////////////

BackupStudio::BackupStudio() {

}
void BackupStudio::act(Studio &studio) {
    if(backup != nullptr){
        delete backup;
        backup = nullptr;
    }
    //using copy constructor of studio
    backup = new Studio(studio);
    complete();
}
std::string BackupStudio::toString() const {
    return "backup";
}
BaseAction* BackupStudio::clone(){
    return (new BackupStudio());
}


//////////////////////////////////////////////RestoreStudio/////////////////////////////////////

RestoreStudio::RestoreStudio(){}
void RestoreStudio::act(Studio &studio){
    if(backup == nullptr){
        error("No backup available");
        return;
    }
    studio = *backup;
    complete();
}
std::string RestoreStudio::toString() const{
    return "restore";
}
BaseAction* RestoreStudio::clone(){
    return (new RestoreStudio());
}

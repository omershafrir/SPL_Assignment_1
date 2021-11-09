class Workout{
    #constractor
public:
    //default constructor
    Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
    id(w_id),name(w_name),price(w_price),type(w_type){
    }
    //copy constructor
    Workout(const Workout &w){
        this->id=w.id;
        this->name=w.name;
        this->price=w.price;
        this->type=w.type;
    }
    //copy assignment operator
    Workout& operator=(const Workout &other){
        this->id=w.id;
        this->name=w.name;
        this->price=w.price;
        this->type=w.type;
        return *this;
    }
    //move constructor
    //move assignment operator

private:
    const int id;
    const std::string name;
    const int price;
    const WorkoutType type;
    #getting_info_from_file

    ###go to file reader and bring me the id,name,price,type
};
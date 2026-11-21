#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Vehicle{protected:std::string reg;double rate;bool rented=false;public:Vehicle(std::string r,double d):reg(std::move(r)),rate(d){}virtual~Vehicle()=default;virtual double charge(int days)const=0;virtual const char* type()const=0;bool rent(){if(rented)return false;rented=true;return true;}void giveBack(){rented=false;}void show()const{std::cout<<type()<<" "<<reg<<" rate="<<rate<<'\n';}};
class Bicycle:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate*d;}const char*type()const override{return "Bicycle";}};
class TwoWheeler:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate*d+50;}const char*type()const override{return "TwoWheeler";}};
class Car:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate*d+200;}const char*type()const override{return "Car";}};
class ElectricCar:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate*d+100;}const char*type()const override{return "ElectricCar";}};
class ElectricBus:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate*d+300;}const char*type()const override{return "ElectricBus";}};
int main(){std::vector<std::unique_ptr<Vehicle>> fleet;fleet.push_back(std::make_unique<Bicycle>("B01",100));fleet.push_back(std::make_unique<TwoWheeler>("T01",250));fleet.push_back(std::make_unique<Car>("C01",1000));fleet.push_back(std::make_unique<ElectricCar>("E01",1200));fleet.push_back(std::make_unique<ElectricBus>("EB01",2000));for(auto&v:fleet){v->show();v->rent();std::cout<<"3-day charge="<<v->charge(3)+100<<'\n';v->giveBack();}}

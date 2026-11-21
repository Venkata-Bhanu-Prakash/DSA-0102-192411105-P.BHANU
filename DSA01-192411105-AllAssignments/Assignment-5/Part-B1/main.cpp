#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Bill{protected:std::string patient;public:explicit Bill(std::string p):patient(std::move(p)){}virtual~Bill()=default;virtual double total()const=0;virtual std::string type()const=0;void print()const{std::cout<<type()<<' '<<patient<<": "<<total()<<'\n';}};
class OutPatient:public Bill{double consult,tests;public:OutPatient(std::string p,double c,double t):Bill(std::move(p)),consult(c),tests(t){}double total()const override{return consult+tests;}std::string type()const override{return "OP";}};
class InPatient:public Bill{int days;double rate,surgery;public:InPatient(std::string p,int d,double r,double s):Bill(std::move(p)),days(d),rate(r),surgery(s){}double total()const override{return days*rate+surgery;}std::string type()const override{return "IP";}};
int main(){std::vector<std::unique_ptr<Bill>> bills;bills.push_back(std::make_unique<OutPatient>("Ravi",500,1200));bills.push_back(std::make_unique<InPatient>("Meena",3,2500,40000));double sum=0;for(const auto&b:bills){b->print();sum+=b->total();}std::cout<<"Total "<<sum<<'\n';}

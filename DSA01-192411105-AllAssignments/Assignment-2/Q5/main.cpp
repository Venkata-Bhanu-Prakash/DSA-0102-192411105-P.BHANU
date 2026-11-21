#include <iostream>
#include <string>
class BusTicket{static int issued; static constexpr int capacity=3; int seat; std::string name;
public: explicit BusTicket(const std::string& n):seat(0),name(n){if(issued<capacity)seat=++issued;}
 static int count(){return issued;} void print()const{std::cout<<name<<": "<<(seat?"Seat "+std::to_string(seat):"Waiting")<<'\n';}};
int BusTicket::issued=0;
int main(){BusTicket t[]={BusTicket("Asha"),BusTicket("Bala"),BusTicket("Chitra"),BusTicket("Dev")};for(const auto& x:t)x.print();std::cout<<"Issued: "<<BusTicket::count()<<'\n';}

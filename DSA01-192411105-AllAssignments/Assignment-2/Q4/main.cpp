#include <iostream>
#include <string>
class SavingsAccount{ std::string id; long long balance; long long tx[10]{}; int count=0; int next=0;
 void record(long long v){tx[next]=v; next=(next+1)%10; if(count<10)++count;}
public: SavingsAccount(std::string a,long long b):id(a),balance(b){}
 void deposit(long long v){if(v>0){balance+=v;record(v);}}
 bool withdraw(long long v){if(v>0&&v<=balance){balance-=v;record(-v);return true;}return false;}
 void miniStatement()const{std::cout<<id<<" balance="<<balance<<"\n"; for(int i=0;i<count;++i)std::cout<<tx[(next-count+i+10)%10]<<"\n";}
};
int main(){SavingsAccount a("AC101",1000);a.deposit(200);a.withdraw(150);a.miniStatement();}

#include <iomanip>
#include <iostream>
class Money{long long p;public:Money(long long r=0,int c=0):p(r*100+c){} Money operator+(const Money&o)const{return Money(0,static_cast<int>(p+o.p));} bool operator==(const Money&o)const{return p==o.p;} friend std::ostream& operator<<(std::ostream&os,const Money&m){return os<<"Rs "<<m.p/100<<'.'<<std::setw(2)<<std::setfill('0')<<m.p%100<<std::setfill(' ');} };
int main(){Money a(120,75),b(79,25),c=a+b;std::cout<<c<<'\n'<<std::boolalpha<<(c==Money(200))<<'\n';}

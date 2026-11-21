#include <iostream>
long long byValue(long long fee,int p){ fee-=fee*p/100; return fee; }
void byReference(long long& fee,int p){ fee-=fee*p/100; }
void byPointer(long long* fee,int p){ if(fee) *fee-=*fee*p/100; }
int main(){ long long a=45000,b=45000,c=45000; std::cout<<byValue(a,10)<<" "<<a<<"\n"; byReference(b,10); byPointer(&c,10); std::cout<<b<<" "<<c<<"\n"; }

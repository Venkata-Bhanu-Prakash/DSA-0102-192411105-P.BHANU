#include <iostream>
class Time{int h,m;public:Time(int hh,int mm):h(hh),m(mm){} friend int minutesBetween(const Time&,const Time&); friend bool earlier(const Time&,const Time&);};
int minutesBetween(const Time&a,const Time&b){int x=a.h*60+a.m,y=b.h*60+b.m;return x>y?x-y:y-x;}
bool earlier(const Time&a,const Time&b){return a.h*60+a.m<b.h*60+b.m;}
int main(){Time d(9,45),a(13,10);std::cout<<minutesBetween(d,a)<<' '<<std::boolalpha<<earlier(a,d)<<'\n';}

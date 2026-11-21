#include <iostream>
#include <stdexcept>
#include <string>
class Time{int s;public:explicit Time(int x=0):s(x){} Time& operator++(){++s;return *this;} Time operator++(int){Time old=*this;++s;return old;} bool operator<(const Time&o)const{return s<o.s;} bool operator==(const Time&o)const{return s==o.s;} int value()const{return s;}};
class Playlist{std::string t[3]={"Song A","Song B","Song C"};public:std::string& operator[](int i){if(i<0||i>=3)throw std::out_of_range("track index");return t[i];}const std::string& operator[](int i)const{if(i<0||i>=3)throw std::out_of_range("track index");return t[i];}};
int main(){Time t(5);Time a=t++;Time b=++t;std::cout<<a.value()<<' '<<b.value()<<' '<<t.value()<<'\n';Playlist p;std::cout<<p[1]<<'\n';}

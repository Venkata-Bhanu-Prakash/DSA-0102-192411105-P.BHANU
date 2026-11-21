#include <cmath>
#include <iostream>
#include <stdexcept>
class Complex{double r,i;public:Complex(double a=0,double b=0):r(a),i(b){} Complex operator+(const Complex&o)const{return {r+o.r,i+o.i};} Complex operator-(const Complex&o)const{return {r-o.r,i-o.i};} Complex operator*(const Complex&o)const{return {r*o.r-i*o.i,r*o.i+i*o.r};} Complex operator/(const Complex&o)const{double d=o.r*o.r+o.i*o.i;if(d==0)throw std::runtime_error("division by zero impedance");return {(r*o.r+i*o.i)/d,(i*o.r-r*o.i)/d};}double magnitude()const{return std::hypot(r,i);}friend std::ostream&operator<<(std::ostream&os,const Complex&z){return os<<z.r<<(z.i<0?" - j":" + j")<<std::abs(z.i);}};
int main(){Complex z1(10,5),z2(4,-2);Complex series=z1+z2,parallel=(z1*z2)/(z1+z2);std::cout<<"Series: "<<series<<" |Z|="<<series.magnitude()<<'\n';std::cout<<"Parallel: "<<parallel<<" |Z|="<<parallel.magnitude()<<'\n';}

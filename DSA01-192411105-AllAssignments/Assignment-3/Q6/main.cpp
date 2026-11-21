#include <cstring>
#include <iostream>
class Text{char* p;public:Text(const char*s=""):p(new char[std::strlen(s)+1]){std::strcpy(p,s);}Text(const Text&o):Text(o.p){}Text& operator=(const Text&o){if(this!=&o){char*n=new char[std::strlen(o.p)+1];std::strcpy(n,o.p);delete[]p;p=n;}return *this;}~Text(){delete[]p;}Text operator+(const Text&o)const{Text r(*this);std::size_t n=std::strlen(p),m=std::strlen(o.p);char*t=new char[n+m+1];std::strcpy(t,p);std::strcat(t,o.p);delete[]r.p;r.p=t;return r;}bool operator==(const Text&o)const{return std::strcmp(p,o.p)==0;}bool operator!=(const Text&o)const{return !(*this==o);}friend std::ostream&operator<<(std::ostream&os,const Text&t){return os<<t.p;}};
int main(){Text a("Hello "),b("Metro");Text c=a+b;std::cout<<c<<' '<<(c!=a)<<'\n';}

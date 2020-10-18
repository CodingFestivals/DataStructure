#include<iostream>
using namespace std;
//Virtual Destructor
class A{
    int *a;
    public:
        virtual ~A(){//for late bind
            delete a;
            cout<<"A destroy"<<endl;
        }
};
class B:public A{
    int *b;
    public:
        ~B(){//no need to use virtual keyword before destructor of B(~B),this work (virtual ~B) will be done automatically
            delete b;
            cout<<"B destroy"<<endl;
        }
};
int fun(){
    A *p=new B;
    delete p;//Will calling destructor of child and parent class because here occure late binding
            //destructor of child class will be calling first then parent class destructor will be called
}
int main(){
    fun();
}


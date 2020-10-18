#include<iostream>
using namespace std;
class A{
    public:
        void f1(){
            cout<<"parent f1 call"<<endl;
        }
        virtual void f2(){
            cout<<"parent f2 call"<<endl;
        }
        virtual void f3(){
            cout<<"parent f3 call"<<endl;
        }
        virtual void f4(){
            cout<<"parent f4 call"<<endl;
        }
};
class B:public A{
    public:
        void f1(){
            cout<<"child f1 call"<<endl;
        }
        void f2(){
            cout<<"child f2 call"<<endl;
        }
        virtual void f4(int x){
            cout<<"child f4 call "<<x<<endl;
        }
};
int main(){
    A *p,o1;
    p=&o1;
    p->f1();
    p->f2();
    p->f3();
    p->f4();
   // p->f4(10);//error: no matching function for call to 'A::f4(int)'|
}

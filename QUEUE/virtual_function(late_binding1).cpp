#include<iostream>
//method overriding problem occuured when parent class pointer contain address of child class object
//method overriding problem removed by virtual function
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
        virtual void f5(){
            cout<<"Parent f5 call"<<endl;
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
        void f4(int x){
            cout<<"child f4 call "<<x<<endl;
        }
        virtual void f5(float x){
            cout<<"Child f5 call"<<endl;
        }
};
int main(){
    A *p;
    B o2;
    p=&o2;
    p->f1();
    p->f2();
    p->f3();
    p->f4();
    p->f5(5.5);
    //p->f4(5);//error: no matching function for call to 'A::f4(int)'|
}


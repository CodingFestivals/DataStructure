#include<iostream>
//when late binding,call a function by which address pointer contain
using namespace std;
class Car{
    public:
        virtual void shiftGear(){
            cout<<"Parent Class"<<endl;
        }
};
class SpotrsCar:public Car{
    public:
        void shiftGear(){
            cout<<"Child Class"<<endl;
        }
};
int main(){
    Car *p;
    SpotrsCar o2;
    p=&o2;//p poiner contain address of o2 object address
    p->shiftGear();//child class shiftGear() function call
}

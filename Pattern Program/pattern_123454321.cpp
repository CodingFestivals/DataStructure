#include<iostream>
using namespace std;
//method declaration
void forwardData(int n);
void backwardData(int n);
int main(){
    //here we print 5 row so loop iterate 5 time
    for(int i=5;i>=1;i--){
        forwardData(i);//1st part print of each row[12345]
        backwardData(i-1);//2nd part print of each row[4321]
        cout<<endl;
    }
}
void forwardData(int n){
    //1st part increasing order
    for(int i=1;i<=n;i++)
        cout<<i;
}
void backwardData(int n){
    //2nd part decreasing order
    for(int i=n;i>=1;i--)
        cout<<i;
}






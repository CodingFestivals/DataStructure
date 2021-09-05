/*
    123454321
    1234321
    12321
    121
    1
*/
#include<iostream>
using namespace std;
int main(){
    //here 5 row so n=5
    int row=5;
    //loop iterate until not print 5 row
    while(row>=1){
        //1st while print first part
        int i=1;
        while(i<row){
            cout<<i;
            i++;
        }
        //2nd while loop print second part
        while(i>=1){
            cout<<i;
            i--;
        }
        cout<<endl;
        //after 1 row print than row will be decrease
        row--;
    }
}






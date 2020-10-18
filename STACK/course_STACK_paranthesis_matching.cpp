#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Stack{
    int top;
    int arraySize;
    char *ptr;
};
void createStack(Stack *st,int len){
     //initially stack is empty
    st->top=-1;
    st->arraySize=len;
    //array create which acts as a stack
    st->ptr=new char[len];
}
void push(Stack *st,char ch){
   //for insert top will be increase and value put in stack
   st->top++;
   st->ptr[st->top]=ch;
}
void pop(Stack *st){
    //top pointer reduce 1
    st->top--;
}
bool isEmpty(Stack *st){
    if(st->top==-1)return true;
    else return false;
}
bool isBalance(Stack *st,char *exp){
     //loop running until expression have character
    for(int i=0;i<st->arraySize;i++){
         //if opening bracket ( is found put in stack
         //if closing bracket ) is found pop from stack
        if(exp[i]=='('){
           push(st,exp[i]);
        }else if(exp[i]==')'){
            //if closing bracket found and opening bracket not found(mean stack is
            //empty) than bracket not matching and return false
            if(isEmpty(st))return false;
            else pop(st);
            //if stack is not empty we pop char(bracket) from stack
        }
    }
    //stack top is -1 mean bracket is balance opening==closing,so return true
    if(st->top==-1)return true;
    else return false;
    //else for opening bracket number less closing bracket
    //example==>())
    //so,bracket not match and return false
}
int main(){
    Stack st;
    char exp[]="((a+b)*(-d))";
    int len=strlen(exp);
    createStack(&st,len);
    if(isBalance(&st,exp))cout<<"Paranthesis matching"<<endl;
    else cout<<"Paranthesis not matching"<<endl;
}

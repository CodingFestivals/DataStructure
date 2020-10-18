#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Stack{
    int top;
    int arraySize;
    char *ptr;
};
//stack creating
void createStack(Stack *st,int len){
    //initially stack is empty
    st->top=-1;
    st->arraySize=len;
    //array create which acts as a stack
    st->ptr=new char[len];
}
bool isEmpty(Stack *st){
    //stack top is -1 that mean stack is empty
    //if stack empty return true,otherwise false
    if(st->top==-1)return true;
    else return false;
}
char pop(Stack *st){
    //top character of stack is store in x
    char x=st->ptr[st->top];
    //and than,top pointer reduce 1
    st->top--;
    //popped character return
    return x;
}
void push(Stack *st,char ch){
    //for insert top will be increase and value put in stack
    st->top++;
    st->ptr[st->top]=ch;
}
bool isBalance(Stack *st,char *exp){
    //balanceBracket will be false if any mismatch parenthesis found
    bool balanceBracket=true;
    //loop running until expression have character
    for(int i=0;i<st->arraySize;i++){
        //if opening bracket (/{/[ is found put in stack
        //if closing bracket )/}/] is found pop from stack
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(st,exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            //if closing bracket found and opening bracket not found(mean stack is
            //empty) than bracket not matching and return false
            if(isEmpty(st))return false;
            else{
                //if stack is not empty we pop char(bracket) from stack and store in x
                char x=pop(st);
                //if ')' found in input that means stack top should have '(' and if have
                //we scan next input(bracket) so continue this process
                //if stack top have { or [ than balance=false and loop terminate
                //and we can say that bracket not matching
                if((exp[i]==')'&&x=='('))continue;
                //if '}' found in input that means stack top should have '{' and if have
                //we scan next input(bracket) so continue this process
                //if stack top have ( or [ than balance=false and loop terminate
                //and we can say that bracket not matching
                else if((exp[i]=='}'&&x=='{'))continue;
                //if ']' found in input that means stack top should have '[' and if have
                //we scan next input(bracket) so continue this process
                //if stack top have ( or { than balance=false and loop terminate
                //and we can say that bracket not matching
                else if((exp[i]==']'&&x=='['))continue;
                balanceBracket=false;
                break;
            }
        }
    }

   // if(balanceBracket==false)return false;

    //balanceBracket is false if bracket is not matching
    //stack top is -1 mean bracket is balance opening==closing,so return true
    if(st->top==-1&&balanceBracket==true)return true;
    else return false;
    //else for opening bracket number less closing bracket
    //example==>({}))
    //so,bracket not match and return false
}
int main(){
    //stack create
    Stack st;
    //input expression
    char exp[]="({([a+b]*[c-d])/e})";//matching
    //char exp[]="([]{()[]})[{}]";//matching
    //char exp[]="([]{()([]})[{}]";//not matching
    int len=strlen(exp);
    //creating stack
    createStack(&st,len);
    //if parenthesis match than return true otherwise false
    if(isBalance(&st,exp))cout<<"Parenthesis matching"<<endl;
    else cout<<"Paranthesis not matching"<<endl;
}

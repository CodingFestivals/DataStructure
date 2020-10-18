#define MAX 100
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char stackk[MAX];
int top=-1;
bool isEmpty(){
    //stack top is -1 that mean stack is empty
    //if stack empty return true,otherwise false
    if(top==-1)return true;
    else return false;
}
char pop(){
    //top character of stack is store in x
    //and than,top pointer reduce 1
    //popped character return
    return stackk[top--];
}
void push(char ch){
    //for insert top will be increase and value put in stack
    stackk[++top]=ch;
}
bool isBalance(char *exp){
    //balanceBracket will be false if any mismatch parenthesis found
    bool balanceBracket=true;
    //loop running until expression have character
    for(int i=0;i<strlen(exp);i++){
        //if opening bracket (/{/[ is found put in stack
        //if closing bracket )/}/] is found pop from stack
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            //if closing bracket found and opening bracket not found(mean stack is
            //empty) than bracket not matching and return false
            if(isEmpty())return false;
            else{
                //if stack is not empty we pop char(bracket) from stack and store in x
                char x=pop();
                //opening bracket(stack top) and closing bracket(from expression)
                //is match that means expression valid and we scan next bracket
                if((x=='('&&exp[i]==')')||(x=='{'&&exp[i]=='}')||(x=='['&&exp[i]==']')){
                    continue;
                }
                balanceBracket=false;
                break;
            }
        }
    }
    //balanceBracket is false if bracket is not matching
    //stack top is -1 mean bracket is balance opening==closing,so return true
    if(top==-1&&balanceBracket==true)return true;
    else return false;
    //else for opening bracket number less closing bracket
    //example==>({}))
    //so,bracket not match and return false
}
int main(){
    //char exp[]="({([a+b]*[c-d])/e})";//matching
    //char exp[]="([]{()[]})[{}]";//matching
    char exp[]="([]{()([]})[{}]";//not matching

    //if parenthesis match than return true otherwise false
    if(isBalance(exp))cout<<"Parenthesis matching"<<endl;
    else cout<<"Paranthesis not matching"<<endl;
}
